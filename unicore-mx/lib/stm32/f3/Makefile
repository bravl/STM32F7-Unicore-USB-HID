##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.
##

LIBNAME		= libucmx_stm32f3
SRCLIBDIR	?= ../..

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
PREFIX	        ?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F3
TGT_CFLAGS      += $(DEBUG_FLAGS)

ARFLAGS		= rcs

OBJS		= rcc.o adc.o i2c.o usart.o dma.o flash.o desig.o

OBJS            += gpio_common_all.o gpio_common_f0234.o \
		   dac_common_all.o crc_common_all.o \
		   iwdg_common_all.o spi_common_all.o dma_common_l1f013.o\
		   timer_common_all.o timer_common_f2347.o flash_common_f234.o \
		   flash.o exti_common_all.o rcc_common_all.o spi_common_f03.o
OBJS		+= adc_common_v2.o adc_common_v2_multi.o
OBJS		+= usart_common_v2.o usart_common_all.o

OBJS		+= usbd.o usbd_ep0.o usbd_transfer.o
OBJS		+= usbd_stm32_fsdev.o usbd_stm32_fsdev_v1.o
OBJS		+= usbd_msc.o

VPATH += ../:../../cm3:../common
VPATH += ../../usbd:../../usbd/class:../../usbd/backend

include ../../Makefile.include
