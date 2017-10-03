/**
 * @defgroup usbd_msc_defines USB MSC Type Definitions
 *
 * @brief <b>Defined Constants and Types for the USB MSC Type Definitions</b>
 *
 * @ingroup USBD_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Weston Schmidt <weston_schmidt@alumni.purdue.edu>
 * Pavol Rusnak <stick@gk2.sk>
 *
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * @date 14 September 2016
 *
 * LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the unicore-mx project.
 *
 * Copyright (C) 2013 Weston Schmidt <weston_schmidt@alumni.purdue.edu>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
 * Copyright (C) 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

/**@{*/

#ifndef UNICOREMX_USBD_MSC_H
#define UNICOREMX_USBD_MSC_H

#include <unicore-mx/usbd/usbd.h>
#include <unicore-mx/usb/class/msc.h>

typedef struct usbd_msc usbd_msc;
typedef struct usbd_msc_backend usbd_msc_backend;

/**
 * Information to be provided application code
 * @param vendor_id The SCSI vendor ID to return.  Maximum used length is 8.
 * @param product_id The SCSI product ID to return.  Maximum used length is 16.
 * @param product_recv The SCSI product revision level to return.
 *      Maximum used length is 4.
 * @param block_count The number of 512-byte blocks available.
 * @param read_block The function called when the host requests to read a LBA
 *      block.  Must _NOT_ be NULL.
 * @param write_block The function called when the host requests to write a
 *      LBA block.  Mandatory - Must _NOT_ be NULL.
 * @param format_unit Format the unit (Optional - can be NULL)
 * @param lock Lock. Optional - can be NULL
 * @param unlock Unlock. Optional - can be NULL
 */
struct usbd_msc_backend {
	const char *vendor_id;
	const char *product_id;
	const char *product_rev;
	uint32_t block_count;
	int (*read_block)(const usbd_msc_backend *backend,
							uint32_t lba, void *copy_to);
	int (*write_block)(const usbd_msc_backend *backend,
							uint32_t lba, const void *copy_from);
	int (*format_unit)(const usbd_msc_backend *backend);
	int (*lock)(void);
	int (*unlock)(void);
};

usbd_msc *usbd_msc_init(usbd_device *dev,
				uint8_t ep_in, uint8_t ep_in_size,
				uint8_t ep_out, uint8_t ep_out_size,
				const usbd_msc_backend *backend);

bool usbd_msc_setup_ep0(usbd_msc *ms,
				const struct usb_setup_data *setup_data);

void usbd_msc_start(usbd_msc *ms);

#endif

/**@}*/
