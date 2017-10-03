/*
 * This file is part of the unicore-mx project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015, 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dwc_otg_private.h"
#include "../usbd_private.h"

#include <string.h>
#include <unicore-mx/cm3/common.h>
#include <unicore-mx/stm32/otg_fs.h>
#include <unicore-mx/stm32/rcc.h>
#include <unicore-mx/usbd/usbd.h>

static usbd_device *init(const usbd_backend_config *config);

static struct usbd_device _usbd_dev;

const struct usbd_backend usbd_stm32_otg_fs = {
	.init = init,
	.set_address = dwc_otg_set_address,
	.get_address = dwc_otg_get_address,
	.ep_prepare_start = dwc_otg_ep_prepare_start,
	.ep_prepare = dwc_otg_ep_prepare,
	.ep_prepare_end = dwc_otg_ep_prepare_end,
	.set_ep_dtog = dwc_otg_set_ep_dtog,
	.get_ep_dtog = dwc_otg_get_ep_dtog,
	.set_ep_stall = dwc_otg_set_ep_stall,
	.get_ep_stall = dwc_otg_get_ep_stall,
	.urb_submit = dwc_otg_urb_submit,
	.urb_cancel = dwc_otg_urb_cancel,
	.poll = dwc_otg_poll,
	.enable_sof = dwc_otg_enable_sof,
	.disconnect = dwc_otg_disconnect,
	.frame_number  = dwc_otg_frame_number,
	.get_speed = dwc_otg_get_speed,
	.set_address_before_status = true,
	.base_address = USB_OTG_FS_BASE,
};

#define REBASE(REG, ...)	REG(usbd_stm32_otg_fs.base_address, ##__VA_ARGS__)

static const usbd_backend_config _config = {
	.ep_count = 6,
	.priv_mem = 1280, /* 1.25KB * 1024 */
	.speed = USBD_SPEED_FULL,
	.feature = USBD_FEATURE_NONE
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *init(const usbd_backend_config *config)
{
	rcc_periph_clock_enable(RCC_OTGFS);

	if (config == NULL) {
		config = &_config;
	}

	_usbd_dev.backend = &usbd_stm32_otg_fs;
	_usbd_dev.config = config;

	if (config->feature & USBD_VBUS_SENSE) {
		if (OTG_FS_CID >= 0x00002000) { /* 2.0 */
			/* Enable VBUS detection */
			OTG_FS_GCCFG |= OTG_GCCFG_VBDEN;
		} else { /* 1.x */
			/* Enable VBUS sensing in device mode */
			OTG_FS_GCCFG |= OTG_GCCFG_VBUSBSEN;
		}
	} else {
		if (OTG_FS_CID >= 0x00002000) { /* 2.0 */
			/* Disable VBUS detection. */
			OTG_FS_GCCFG &= ~OTG_GCCFG_VBDEN;
			REBASE(DWC_OTG_GOTGCTL) |= DWC_OTG_GOTGCTL_BVALOEN |
											DWC_OTG_GOTGCTL_BVALOVAL;
		} else { /* 1.x */
			/* Disable VBUS sensing in device mode. */
			OTG_FS_GCCFG |= OTG_GCCFG_NOVBUSSENS | OTG_GCCFG_VBUSBSEN;
		}
	}

	/* Power up the PHY */
	OTG_FS_GCCFG |= OTG_GCCFG_PWRDWN;

	/* Internal PHY */
	REBASE(DWC_OTG_GUSBCFG) |= DWC_OTG_GUSBCFG_PHYSEL;

	/* Full speed device. */
	REBASE(DWC_OTG_DCFG) |= (REBASE(DWC_OTG_DCFG) & ~DWC_OTG_DCFG_DSPD_MASK) |
								DWC_OTG_DCFG_DSPD_FULL_1_1;

	dwc_otg_init(&_usbd_dev);

	return &_usbd_dev;
}
