#include <stdio.h>
#include <unicore-mx/stm32/rcc.h>
#include <unicore-mx/stm32/gpio.h>
#include <unicore-mx/cm3/nvic.h>
#include <unicore-mx/cm3/systick.h>
#include <unicore-mx/usbd/usbd.h>
#include <unicore-mx/usb/class/hid.h>
#include <unicore-mx/stm32/otg_fs.h>

#include "usbhid_target.h"

#define SYSCLK 216000000 //Hz

static usbd_device *usbd_dev;

static const uint8_t hid_report_descriptor[] = {
	0x05, 0x01, /* USAGE_PAGE (Generic Desktop)         */
	0x09, 0x02, /* USAGE (Mouse)                        */
	0xa1, 0x01, /* COLLECTION (Application)             */
	0x09, 0x01, /*   USAGE (Pointer)                    */
	0xa1, 0x00, /*   COLLECTION (Physical)              */
	0x05, 0x09, /*     USAGE_PAGE (Button)              */
	0x19, 0x01, /*     USAGE_MINIMUM (Button 1)         */
	0x29, 0x03, /*     USAGE_MAXIMUM (Button 3)         */
	0x15, 0x00, /*     LOGICAL_MINIMUM (0)              */
	0x25, 0x01, /*     LOGICAL_MAXIMUM (1)              */
	0x95, 0x03, /*     REPORT_COUNT (3)                 */
	0x75, 0x01, /*     REPORT_SIZE (1)                  */
	0x81, 0x02, /*     INPUT (Data,Var,Abs)             */
	0x95, 0x01, /*     REPORT_COUNT (1)                 */
	0x75, 0x05, /*     REPORT_SIZE (5)                  */
	0x81, 0x01, /*     INPUT (Cnst,Ary,Abs)             */
	0x05, 0x01, /*     USAGE_PAGE (Generic Desktop)     */
	0x09, 0x30, /*     USAGE (X)                        */
	0x09, 0x31, /*     USAGE (Y)                        */
	0x09, 0x38, /*     USAGE (Wheel)                    */
	0x15, 0x81, /*     LOGICAL_MINIMUM (-127)           */
	0x25, 0x7f, /*     LOGICAL_MAXIMUM (127)            */
	0x75, 0x08, /*     REPORT_SIZE (8)                  */
	0x95, 0x03, /*     REPORT_COUNT (3)                 */
	0x81, 0x06, /*     INPUT (Data,Var,Rel)             */
	0xc0,       /*   END_COLLECTION                     */
	0x09, 0x3c, /*   USAGE (Motion Wakeup)              */
	0x05, 0xff, /*   USAGE_PAGE (Vendor Defined Page 1) */
	0x09, 0x01, /*   USAGE (Vendor Usage 1)             */
	0x15, 0x00, /*   LOGICAL_MINIMUM (0)                */
	0x25, 0x01, /*   LOGICAL_MAXIMUM (1)                */
	0x75, 0x01, /*   REPORT_SIZE (1)                    */
	0x95, 0x02, /*   REPORT_COUNT (2)                   */
	0xb1, 0x22, /*   FEATURE (Data,Var,Abs,NPrf)        */
	0x75, 0x06, /*   REPORT_SIZE (6)                    */
	0x95, 0x01, /*   REPORT_COUNT (1)                   */
	0xb1, 0x01, /*   FEATURE (Cnst,Ary,Abs)             */
	0xc0        /* END_COLLECTION                       */
};

static const struct usb_string_descriptor string_lang_list = {
	.bLength = USB_DT_STRING_SIZE(1),
	.bDescriptorType = USB_DT_STRING,
	.wData = {
		USB_LANGID_ENGLISH_UNITED_STATES
	}
};

/* string descriptor string_[0..2] generated using usb-string.py */

static const struct usb_string_descriptor string_0 = {
	.bLength = USB_DT_STRING_SIZE(16),
	.bDescriptorType = USB_DT_STRING,
	/* Mad Resistor LLP */
	.wData = {
		0x004d, 0x0061, 0x0064, 0x0020, 0x0052, 0x0065, 0x0073, 0x0069,
		0x0073, 0x0074, 0x006f, 0x0072, 0x0020, 0x004c, 0x004c, 0x0050
	}
};

static const struct usb_string_descriptor string_1 = {
	.bLength = USB_DT_STRING_SIZE(8),
	.bDescriptorType = USB_DT_STRING,
	/* HID Demo */
	.wData = {
		0x0048, 0x0049, 0x0044, 0x0020, 0x0044, 0x0065, 0x006d, 0x006f
	}
};

static const struct usb_string_descriptor string_2 = {
	.bLength = USB_DT_STRING_SIZE(4),
	.bDescriptorType = USB_DT_STRING,
	/* DEMO */
	.wData = {
		0x0044, 0x0045, 0x004d, 0x004f
	}
};

static const struct usb_string_descriptor **string_data[1] = {
	(const struct usb_string_descriptor *[]){&string_0, &string_1, &string_2},
};

static const struct usbd_info_string string = {
	.lang_list = &string_lang_list,
	.count = 3,
	.data = string_data
};

static const struct {
	struct usb_config_descriptor config;
	struct usb_interface_descriptor hid_iface;
	struct {
		struct usb_hid_descriptor hid_descriptor;
		struct {
			uint8_t bReportDescriptorType;
			uint16_t wDescriptorLength;
		} __attribute__((packed)) hid_report;
	} __attribute__((packed)) hid_function;
	struct usb_endpoint_descriptor hid_endpoint;
} config_descr = {
	.config = {
		.bLength = USB_DT_CONFIGURATION_SIZE,
		.bDescriptorType = USB_DT_CONFIGURATION,
		.wTotalLength = sizeof(config_descr),
		.bNumInterfaces = 1,
		.bConfigurationValue = 1,
		.iConfiguration = 0,
		.bmAttributes = 0xC0,
		.bMaxPower = 0x32,
	},

	.hid_iface = {
		.bLength = USB_DT_INTERFACE_SIZE,
		.bDescriptorType = USB_DT_INTERFACE,
		.bInterfaceNumber = 0,
		.bAlternateSetting = 0,
		.bNumEndpoints = 1,
		.bInterfaceClass = USB_CLASS_HID,
		.bInterfaceSubClass = 1, /* boot */
		.bInterfaceProtocol = 2, /* mouse */
		.iInterface = 0,
	},

	.hid_function = {
		.hid_descriptor = {
			.bLength = sizeof(struct usb_hid_descriptor) + 3,
			.bDescriptorType = USB_DT_HID,
			.bcdHID = 0x0100,
			.bCountryCode = 0,
			.bNumDescriptors = 1,
		},
		.hid_report = {
			.bReportDescriptorType = USB_DT_REPORT,
			.wDescriptorLength = sizeof(hid_report_descriptor),
		}
	},

	.hid_endpoint = {
		.bLength = USB_DT_ENDPOINT_SIZE,
		.bDescriptorType = USB_DT_ENDPOINT,
		.bEndpointAddress = 0x81,
		.bmAttributes = USB_ENDPOINT_ATTR_INTERRUPT,
		.wMaxPacketSize = 4,
		.bInterval = 0x02,
	},
};

const struct usb_device_descriptor dev_descr = {
	.bLength = USB_DT_DEVICE_SIZE,
	.bDescriptorType = USB_DT_DEVICE,
	.bcdUSB = 0x0200,
	.bDeviceClass = 0,
	.bDeviceSubClass = 0,
	.bDeviceProtocol = 0,
	.bMaxPacketSize0 = 64,
	.idVendor = 0x0483,
	.idProduct = 0x5710,
	.bcdDevice = 0x0200,
	.iManufacturer = 1,
	.iProduct = 2,
	.iSerialNumber = 3,
	.bNumConfigurations = 1
};

static const struct usbd_info info = {
	.device = {
		.desc = &dev_descr,
		.string = &string
	},

	.config = {{
		.desc = (const struct usb_config_descriptor *) &config_descr,
		.string = &string
	}}
};

static bool hid_setup_callback(usbd_device *dev,
				const struct usb_setup_data *setup_data)
{
	if(	(setup_data->bmRequestType != 0x81) ||
		(setup_data->bRequest != USB_REQ_GET_DESCRIPTOR) ||
		(setup_data->wValue != 0x2200)) {
		return false;
	}

	/* Handle the HID report descriptor. */
	usbd_ep0_transfer(dev, setup_data, (void *) hid_report_descriptor,
			sizeof(hid_report_descriptor), NULL);
	return true;
}

static void setup_callback(usbd_device *dev, uint8_t ep_addr,
						const struct usb_setup_data *setup_data)
{
	(void) ep_addr; /* assuming ep_addr == 0 */

	if (hid_setup_callback(dev, setup_data)) {
		return;
	}

	usbd_ep0_setup(dev, setup_data);
}

static void hid_set_config(usbd_device *dev,
				const struct usb_config_descriptor *cfg)
{
	(void)cfg;

	usbd_ep_prepare(dev, 0x81, USBD_EP_INTERRUPT, 4, 2, USBD_EP_NONE);

#if defined(__ARM_ARCH_6M__)
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
	/* SysTick interrupt every N clock pulses: set reload to N-1 */
	systick_set_reload(99999*8);
#else
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);
	/* SysTick interrupt every N clock pulses: set reload to N-1 */
	systick_set_reload(99999);
#endif
	systick_interrupt_enable();
	systick_counter_enable();
}

void __attribute__((weak))
usbhid_target_usbd_after_init_and_before_first_poll(void) { return;}

uint32_t SystemCoreClock = SYSCLK;

static void clock_setup(void)
{
	/* Base board frequency, set to 216MHz */
	rcc_clock_setup_hse_3v3(&rcc_hse_25mhz_3v3);

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_GPIOH);
	rcc_periph_clock_enable(RCC_GPIOI);
	rcc_periph_clock_enable(RCC_GPIOJ);
	rcc_periph_clock_enable(RCC_USART6);
	/* rcc_periph_clock_enable(RCC_OTGHS); */
	/* rcc_periph_clock_enable(RCC_OTGHSULPI); */
	rcc_periph_clock_enable(RCC_OTGFS);
	rcc_periph_clock_enable(RCC_TIM6);
}

static void nvic_setup(void)
{
#define IRQ2NVIC_PRIOR(x)	((x)<<4)
	nvic_set_priority(NVIC_SYSTICK_IRQ, IRQ2NVIC_PRIOR(1));
	nvic_set_priority(NVIC_OTG_FS_IRQ, IRQ2NVIC_PRIOR(1));
}

static void ulpi_pins(uint32_t gpioport, uint16_t gpiopins)
{
	gpio_mode_setup(gpioport, GPIO_MODE_AF, GPIO_PUPD_NONE, gpiopins);
	gpio_set_output_options(gpioport, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, gpiopins);
	gpio_set_af(gpioport, GPIO_AF10, gpiopins);
}

static void gpio_setup(void)
{
	/* OTG_HS */
	/*
	 * ULPI   GPIO
	 *  D0  -> PA3
	 *  D1  -> PB0
	 *  D2  -> PB1
	 *  D3  -> PB10
	 *  D4  -> PB11
	 *  D5  -> PB12
	 *  D6  -> PB13
	 *  D7  -> PB5
	 *  CK  -> PA5
	 *  STP -> PC0
	 *  NXT -> PH4
	 *  DIR -> PI11
	 */
	ulpi_pins(GPIOA, GPIO3 | GPIO5);
	ulpi_pins(GPIOB, GPIO0 | GPIO1 | GPIO5  | GPIO10 | GPIO11 | GPIO12 | GPIO13);
	ulpi_pins(GPIOC, GPIO0);
	ulpi_pins(GPIOH, GPIO4);
	ulpi_pins(GPIOI, GPIO11);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE,
			GPIO9 | GPIO11 | GPIO12);
        gpio_set_af(GPIOA, GPIO_AF10, GPIO9 | GPIO11 | GPIO12);

}

const usbd_backend *usbhid_target_usb_driver(void)
{
	return USBD_STM32_OTG_FS;
}

int main(void)
{

        clock_setup();
	gpio_setup();
 	nvic_setup();
        printf("Setup done\n");

	usbd_dev = usbd_init(usbhid_target_usb_driver(), NULL, &info);

        printf("Init done\n");

	usbd_register_set_config_callback(usbd_dev, hid_set_config);
	usbd_register_setup_callback(usbd_dev, setup_callback);

	usbhid_target_usbd_after_init_and_before_first_poll();

	while (1) {
		usbd_poll(usbd_dev, 0);
	}
        return 0;
}

/* Fake Version */
void __attribute__((weak))
usbhid_target_accel_get(int16_t *out_x, int16_t *out_y, int16_t *out_z)
{
	(void)out_y;
	(void)out_z;

	static int x = 0;
	static int dir = 1;

	if (out_x != NULL) {
		*out_x = dir;
	}

	x += dir;
	if (x > 30) {
		dir = -dir;
	}
	if (x < -30) {
		dir = -dir;
	}
}

static usbd_urb_id last_urb_id = USBD_INVALID_URB_ID;

static void transfer_callback(usbd_device *_usbd_dev,
	const usbd_transfer *transfer, usbd_transfer_status status,
	usbd_urb_id urb_id)
{
	(void) _usbd_dev;
	(void) transfer;
	(void) status;
	(void) urb_id;
	last_urb_id = USBD_INVALID_URB_ID;
}

void sys_tick_handler(void)
{
	if (last_urb_id != USBD_INVALID_URB_ID) {
		return;
	}

	int16_t x = 0, y = 0, z = 0;
	static uint8_t buf[4];

	usbhid_target_accel_get(&x, &y, &z);

	buf[0] = 0;
	buf[1] = x;
	buf[2] = y;
	buf[3] = z;

	const usbd_transfer transfer = {
		.ep_type = USBD_EP_INTERRUPT,
		.ep_addr = 0x81,
		.ep_size = 4,
		.ep_interval = 2,
		.buffer = buf,
		.length = 4,
		.flags = USBD_FLAG_NONE,
		.timeout = USBD_TIMEOUT_NEVER,
		.callback = transfer_callback,
	};

	last_urb_id = usbd_transfer_submit(usbd_dev, &transfer);
}
