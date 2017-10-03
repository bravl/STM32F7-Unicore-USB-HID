/*
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#ifndef UNICOREMX_EFM32_CMU_H
#define UNICOREMX_EFM32_CMU_H

#include <unicore-mx/efm32/memorymap.h>
#include <unicore-mx/cm3/common.h>

#define CMU_CTRL			MMIO32(CMU_BASE + 0x000)
#define CMU_HFCORECLKDIV		MMIO32(CMU_BASE + 0x004)
#define CMU_HFPERCLKDIV			MMIO32(CMU_BASE + 0x008)
#define CMU_HFRCOCTRL			MMIO32(CMU_BASE + 0x00C)
#define CMU_LFRCOCTRL			MMIO32(CMU_BASE + 0x010)
#define CMU_AUXHFRCOCTRL		MMIO32(CMU_BASE + 0x014)
#define CMU_CALCTRL			MMIO32(CMU_BASE + 0x018)
#define CMU_CALCNT			MMIO32(CMU_BASE + 0x01C)
#define CMU_OSCENCMD			MMIO32(CMU_BASE + 0x020)
#define CMU_CMD				MMIO32(CMU_BASE + 0x024)
#define CMU_LFCLKSEL			MMIO32(CMU_BASE + 0x028)
#define CMU_STATUS			MMIO32(CMU_BASE + 0x02C)
#define CMU_IF				MMIO32(CMU_BASE + 0x030)
#define CMU_IFS				MMIO32(CMU_BASE + 0x034)
#define CMU_IFC				MMIO32(CMU_BASE + 0x038)
#define CMU_IEN				MMIO32(CMU_BASE + 0x03C)
#define CMU_HFCORECLKEN0		MMIO32(CMU_BASE + 0x040)
#define CMU_HFPERCLKEN0			MMIO32(CMU_BASE + 0x044)
#define CMU_SYNCBUSY			MMIO32(CMU_BASE + 0x050)
#define CMU_FREEZE			MMIO32(CMU_BASE + 0x054)
#define CMU_LFACLKEN0			MMIO32(CMU_BASE + 0x058)
#define CMU_LFBCLKEN0			MMIO32(CMU_BASE + 0x060)
#define CMU_LFAPRESC0			MMIO32(CMU_BASE + 0x068)
#define CMU_LFBPRESC0			MMIO32(CMU_BASE + 0x070)
#define CMU_PCNTCTRL			MMIO32(CMU_BASE + 0x078)
#define CMU_LCDCTRL			MMIO32(CMU_BASE + 0x07C)
#define CMU_ROUTE			MMIO32(CMU_BASE + 0x080)
#define CMU_LOCK			MMIO32(CMU_BASE + 0x084)

/* CMU_CTRL */
#define CMU_CTRL_HFLE			(1 << 30)
#define CMU_CTRL_DBGCLK			(1 << 28)


#define CMU_CTRL_CLKOUTSEL1_SHIFT	(23)
#define CMU_CTRL_CLKOUTSEL1_MASK	(0x7 << CMU_CTRL_CLKOUTSEL1_SHIFT)
#define CMU_CTRL_CLKOUTSEL1(v)		\
	(((v) << CMU_CTRL_CLKOUTSEL1_SHIFT) & CMU_CTRL_CLKOUTSEL1_MASK)
#define CMU_CTRL_CLKOUTSEL1_LFRCO	CMU_CTRL_CLKOUTSEL1(0)
#define CMU_CTRL_CLKOUTSEL1_LFXO	CMU_CTRL_CLKOUTSEL1(1)
#define CMU_CTRL_CLKOUTSEL1_HFCLK	CMU_CTRL_CLKOUTSEL1(2)
#define CMU_CTRL_CLKOUTSEL1_LFXOQ	CMU_CTRL_CLKOUTSEL1(3)
#define CMU_CTRL_CLKOUTSEL1_HFXOQ	CMU_CTRL_CLKOUTSEL1(4)
#define CMU_CTRL_CLKOUTSEL1_LFRCOQ	CMU_CTRL_CLKOUTSEL1(5)
#define CMU_CTRL_CLKOUTSEL1_HFRCOQ	CMU_CTRL_CLKOUTSEL1(6)
#define CMU_CTRL_CLKOUTSEL1_AUXHFRCOQ	CMU_CTRL_CLKOUTSEL1(7)

#define CMU_CTRL_CLKOUTSEL0_SHIFT	(23)
#define CMU_CTRL_CLKOUTSEL0_MASK	(0x7 << CMU_CTRL_CLKOUTSEL0_SHIFT)
#define CMU_CTRL_CLKOUTSEL0(v)		\
	(((v) << CMU_CTRL_CLKOUTSEL0_SHIFT) & CMU_CTRL_CLKOUTSEL0_MASK)
#define CMU_CTRL_CLKOUTSEL0_HFRCO	CMU_CTRL_CLKOUTSEL0(0)
#define CMU_CTRL_CLKOUTSEL0_HFXO	CMU_CTRL_CLKOUTSEL0(1)
#define CMU_CTRL_CLKOUTSEL0_HFCLK2	CMU_CTRL_CLKOUTSEL0(2)
#define CMU_CTRL_CLKOUTSEL0_HFCLK4	CMU_CTRL_CLKOUTSEL0(3)
#define CMU_CTRL_CLKOUTSEL0_HFCLK8	CMU_CTRL_CLKOUTSEL0(4)
#define CMU_CTRL_CLKOUTSEL0_HFCLK16	CMU_CTRL_CLKOUTSEL0(5)
#define CMU_CTRL_CLKOUTSEL0_ULFRCO	CMU_CTRL_CLKOUTSEL0(6)
#define CMU_CTRL_CLKOUTSEL0_AUXHFRCO	CMU_CTRL_CLKOUTSEL0(7)

#define CMU_CTRL_LFXOTIMEOUT_SHIFT	(18)
#define CMU_CTRL_LFXOTIMEOUT_MASK	(0x3 << CMU_CTRL_LFXOTIMEOUT_SHIFT)
#define CMU_CTRL_LFXOTIMEOUT(v)		\
	(((v) << CMU_CTRL_LFXOTIMEOUT_SHIFT) & CMU_CTRL_LFXOTIMEOUT_MASK)
#define CMU_CTRL_LFXOTIMEOUT_8CYCLES	CMU_CTRL_LFXOTIMEOUT(0)
#define CMU_CTRL_LFXOTIMEOUT_1KCYCLES	CMU_CTRL_LFXOTIMEOUT(1)
#define CMU_CTRL_LFXOTIMEOUT_16KCYCLES	CMU_CTRL_LFXOTIMEOUT(2)
#define CMU_CTRL_LFXOTIMEOUT_32KCYCLES	CMU_CTRL_LFXOTIMEOUT(3)

#define CMU_CTRL_LFXOBUFCUR		(1 << 17)

#define CMU_CTRL_HFCLKDIV_SHIFT		(14)
#define CMU_CTRL_HFCLKDIV_MASK		(0x7 << CMU_CTRL_HFCLKDIV_SHIFT)
#define CMU_CTRL_HFCLKDIV(v)		\
	(((v) << CMU_CTRL_HFCLKDIV_SHIFT) & CMU_CTRL_HFCLKDIV_MASK)
#define CMU_CTRL_HFCLKDIV_NODIV		CMU_CTRL_HFCLKDIV(0)
#define CMU_CTRL_HFCLKDIV_DIV2		CMU_CTRL_HFCLKDIV(1)
#define CMU_CTRL_HFCLKDIV_DIV3		CMU_CTRL_HFCLKDIV(2)
#define CMU_CTRL_HFCLKDIV_DIV4		CMU_CTRL_HFCLKDIV(3)
#define CMU_CTRL_HFCLKDIV_DIV5		CMU_CTRL_HFCLKDIV(4)
#define CMU_CTRL_HFCLKDIV_DIV6		CMU_CTRL_HFCLKDIV(5)
#define CMU_CTRL_HFCLKDIV_DIV7		CMU_CTRL_HFCLKDIV(6)
#define CMU_CTRL_HFCLKDIV_DIV8		CMU_CTRL_HFCLKDIV(7)

#define CMU_CTRL_LFXOBOOST		(1 << 13)

#define CMU_CTRL_LFXOMODE_SHIFT		(11)
#define CMU_CTRL_LFXOMODE_MASK		(0x3 << CMU_CTRL_LFXOMODE_SHIFT)
#define CMU_CTRL_LFXOMODE(v)		\
	(((v) << CMU_CTRL_LFXOMODE_SHIFT) & CMU_CTRL_LFXOMODE_MASK)
#define CMU_CTRL_LFXOMODE_XTAL		CMU_CTRL_LFXOMODE(0)
#define CMU_CTRL_LFXOMODE_BUFEXTCLK	CMU_CTRL_LFXOMODE(1)
#define CMU_CTRL_LFXOMODE_DIGEXTCLK	CMU_CTRL_LFXOMODE(2)

#define CMU_CTRL_HFXOTIMEOUT_SHIFT	(9)
#define CMU_CTRL_HFXOTIMEOUT_MASK	(0x3 << CMU_CTRL_HFXOTIMEOUT_SHIFT)
#define CMU_CTRL_HFXOTIMEOUT(v)		\
	(((v) << CMU_CTRL_HFXOTIMEOUT_SHIFT) & CMU_CTRL_HFXOTIMEOUT_MASK)
#define CMU_CTRL_HFXOTIMEOUT_8CYCLES	CMU_CTRL_HFXOTIMEOUT(0)
#define CMU_CTRL_HFXOTIMEOUT_256CYCLES	CMU_CTRL_HFXOTIMEOUT(1)
#define CMU_CTRL_HFXOTIMEOUT_1KCYCLES	CMU_CTRL_HFXOTIMEOUT(2)
#define CMU_CTRL_HFXOTIMEOUT_16KCYCLES	CMU_CTRL_HFXOTIMEOUT(3)

#define CMU_CTRL_HFXOGLITCHDETEN	(1 << 7)

#define CMU_CTRL_HFXOBUFCUR_SHIFT	(5)
#define CMU_CTRL_HFXOBUFCUR_MASK	(0x3 << CMU_CTRL_HFXOBUFCUR_SHIFT)
#define CMU_CTRL_HFXOBUFCUR(v)		\
	(((v) << CMU_CTRL_HFXOBUFCUR_SHIFT) & CMU_CTRL_HFXOBUFCUR_MASK)
#define CMU_CTRL_HFXOBUFCUR_BOOSTUPTO32MHZ	CMU_CTRL_HFXOBUFCUR(1)
#define CMU_CTRL_HFXOBUFCUR_BOOSTABOVE32MHZ	CMU_CTRL_HFXOBUFCUR(3)

#define CMU_CTRL_HFXOBOOST_SHIFT	(2)
#define CMU_CTRL_HFXOBOOST_MASK		(0x3 << CMU_CTRL_HFXOBOOST_SHIFT)
#define CMU_CTRL_HFXOBOOST(v)		\
	(((v) << CMU_CTRL_HFXOBOOST_SHIFT) & CMU_CTRL_HFXOBOOST_MASK)
#define CMU_CTRL_HFXOBOOST_50PCENT	CMU_CTRL_HFXOBOOST(0)
#define CMU_CTRL_HFXOBOOST_70PCENT	CMU_CTRL_HFXOBOOST(1)
#define CMU_CTRL_HFXOBOOST_80PCENT	CMU_CTRL_HFXOBOOST(2)
#define CMU_CTRL_HFXOBOOST_100PCENT	CMU_CTRL_HFXOBOOST(3)

#define CMU_CTRL_HFXOMODE_SHIFT		(0)
#define CMU_CTRL_HFXOMODE_MASK		(0x3 << CMU_CTRL_HFXOMODE_SHIFT)
#define CMU_CTRL_HFXOMODE(v)		\
	(((v) << CMU_CTRL_HFXOMODE_SHIFT) & CMU_CTRL_HFXOMODE_MASK)
#define CMU_CTRL_HFXOMODE_XTAL		CMU_CTRL_HFXOMODE(0)
#define CMU_CTRL_HFXOMODE_BUFEXTCLK	CMU_CTRL_HFXOMODE(1)
#define CMU_CTRL_HFXOMODE_DIGEXTCLK	CMU_CTRL_HFXOMODE(2)

/* CMU_HFCORECLKDIV */
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV		(1 << 8)

#define CMU_HFCORECLKDIV_HFCORECLKDIV_SHIFT	(0)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_MASK	\
	(0xF << CMU_HFCORECLKDIV_HFCORECLKDIV_SHIFT)
#define CMU_HFCORECLKDIV_HFCORECLKDIV(v)	\
	(((v) << CMU_HFCORECLKDIV_HFCORECLKDIV_SHIFT) & \
	CMU_HFCORECLKDIV_HFCORECLKDIV_MASK)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(0)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK2	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(1)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK4	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(2)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK8	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(3)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK16	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(4)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK32	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(5)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK64	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(6)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK128	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(7)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK256	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(8)
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK512	\
	CMU_HFCORECLKDIV_HFCORECLKDIV(9)

#define CMU_HFCORECLKDIV_HFCORECLKDIV_NODIV	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV2	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK2
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV4	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK4
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV8	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK8
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV16	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK16
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV32	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK32
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV64	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK64
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV128	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK128
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV256	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK256
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DIV512	\
	CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK512

/* CMU_HFPERCLKDIV */
#define CMU_HFPERCLKDIV_HFPERCLKEN 		(1 << 8)

#define CMU_HFPERCLKDIV_HFPERCLKDIV_SHIFT	(0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_MASK	\
	(0xF << CMU_HFPERCLKDIV_HFPERCLKDIV_SHIFT)
#define CMU_HFPERCLKDIV_HFPERCLKDIV(v)		\
	(((v) << CMU_HFPERCLKDIV_HFPERCLKDIV_SHIFT) & \
	 CMU_HFPERCLKDIV_HFPERCLKDIV_MASK)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK	CMU_HFPERCLKDIV_HFPERCLKDIV(0)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK2	CMU_HFPERCLKDIV_HFPERCLKDIV(1)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK4	CMU_HFPERCLKDIV_HFPERCLKDIV(2)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK8	CMU_HFPERCLKDIV_HFPERCLKDIV(3)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK16	CMU_HFPERCLKDIV_HFPERCLKDIV(4)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK32	CMU_HFPERCLKDIV_HFPERCLKDIV(5)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK64	CMU_HFPERCLKDIV_HFPERCLKDIV(6)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK128	CMU_HFPERCLKDIV_HFPERCLKDIV(7)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK256	CMU_HFPERCLKDIV_HFPERCLKDIV(8)
#define CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK512	CMU_HFPERCLKDIV_HFPERCLKDIV(9)

/* CMU_HFPERCLKDIV_HFPERCLKHFCLK_HFCLK* to CMU_HFPERCLKDIV_HFPERCLKHFCLK_DIV* */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_NODIV	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV2	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK2
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV4	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK4
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV8	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK8
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV16	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK16
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV32	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK32
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV64	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK64
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV128	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK128
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV256	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK256
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DIV512	\
	CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK512

/* CMU_HFRCOCTRL */
#define CMU_HFRCOCTRL_SUDELAY_SHIFT	(12)
#define CMU_HFRCOCTRL_SUDELAY_MASK	(0x1F << CMU_HFRCOCTRL_SUDELAY_SHIFT)
#define CMU_HFRCOCTRL_SUDELAY(v)	\
	((((v) << CMU_HFRCOCTRL_SUDELAY_SHIFT) & CMU_HFRCOCTRL_SUDELAY_MASK))

#define CMU_HFRCOCTRL_BAND_SHIFT	(8)
#define CMU_HFRCOCTRL_BAND_MASK		(0x7 << CMU_HFRCOCTRL_BAND_SHIFT)
#define CMU_HFRCOCTRL_BAND(v)		\
	(((v) << CMU_HFRCOCTRL_BAND_SHIFT) & CMU_HFRCOCTRL_BAND_MASK)
#define CMU_HFRCOCTRL_BAND_1MHZ		CMU_HFRCOCTRL_BAND(0)
#define CMU_HFRCOCTRL_BAND_7MHZ		CMU_HFRCOCTRL_BAND(1)
#define CMU_HFRCOCTRL_BAND_11MHZ	CMU_HFRCOCTRL_BAND(2)
#define CMU_HFRCOCTRL_BAND_14MHZ	CMU_HFRCOCTRL_BAND(3)
#define CMU_HFRCOCTRL_BAND_21MHZ	CMU_HFRCOCTRL_BAND(4)
#define CMU_HFRCOCTRL_BAND_28MHZ	CMU_HFRCOCTRL_BAND(5)

#define CMU_HFRCOCTRL_TUNING_SHIFT	(0)
#define CMU_HFRCOCTRL_TUNING_MASK	(0xFF << CMU_HFRCOCTRL_TUNING_SHIFT)
#define CMU_HFRCOCTRL_TUNING(v)		\
	(((v) << CMU_HFRCOCTRL_TUNING_SHIFT) & CMU_HFRCOCTRL_TUNING_MASK)

/* CMU_LFRCOCTRL */
#define CMU_LFRCOCTRL_TUNING_SHIFT	(0)
#define CMU_LFRCOCTRL_TUNING_MASK	(0xFF << CMU_LFRCOCTRL_TUNING_SHIFT)
#define CMU_LFRCOCTRL_TUNING(v)			\
	(((v) << CMU_LFRCOCTRL_TUNING_SHIFT) & CMU_LFRCOCTRL_TUNING_MASK)

/* CMU_AUXHFRCOCTRL */
#define CMU_AUXHFRCOCTRL_BAND_SHIFT	(8)
#define CMU_AUXHFRCOCTRL_BAND_MASK	(0x7 << CMU_AUXHFRCOCTRL_BAND_SHIFT)
#define CMU_AUXHFRCOCTRL_BAND(v)	\
	(((v) << CMU_AUXHFRCOCTRL_BAND_SHIFT) & CMU_AUXHFRCOCTRL_BAND_MASK)
#define CMU_AUXHFRCOCTRL_BAND_1MHZ	CMU_AUXHFRCOCTRL_BAND(0)
#define CMU_AUXHFRCOCTRL_BAND_7MHZ	CMU_AUXHFRCOCTRL_BAND(1)
#define CMU_AUXHFRCOCTRL_BAND_11MHZ	CMU_AUXHFRCOCTRL_BAND(2)
#define CMU_AUXHFRCOCTRL_BAND_14MHZ	CMU_AUXHFRCOCTRL_BAND(3)
#define CMU_AUXHFRCOCTRL_BAND_28MHZ	CMU_AUXHFRCOCTRL_BAND(4)
#define CMU_AUXHFRCOCTRL_BAND_21MHZ	CMU_AUXHFRCOCTRL_BAND(5)

#define CMU_AUXHFRCOCTRL_TUNING_SHIFT	(0)
#define CMU_AUXHFRCOCTRL_TUNING_MASK	(0xFF << CMU_AUXHFRCOCTRL_TUNING_SHIFT)
#define CMU_AUXHFRCOCTRL_TUNING(v)	\
	(((v) << CMU_AUXHFRCOCTRL_TUNING_SHIFT) & CMU_AUXHFRCOCTRL_TUNING_MASK)

/* CMU_CALCTRL */
#define CMU_CALCTRL_CONT		(1 << 6)

#define CMU_CALCTRL_DOWNSEL_SHIFT	(3)
#define CMU_CALCTRL_DOWNSEL_MASK	(0x7 << CMU_CALCTRL_DOWNSEL_SHIFT)
#define CMU_CALCTRL_DOWNSEL(v)		\
	(((v) << CMU_CALCTRL_DOWNSEL_SHIFT) & CMU_CALCTRL_DOWNSEL_MASK)
#define CMU_CALCTRL_DOWNSEL_HFCLK	CMU_CALCTRL_DOWNSEL(0)
#define CMU_CALCTRL_DOWNSEL_HFXO	CMU_CALCTRL_DOWNSEL(1)
#define CMU_CALCTRL_DOWNSEL_LFXO	CMU_CALCTRL_DOWNSEL(2)
#define CMU_CALCTRL_DOWNSEL_HFRCO	CMU_CALCTRL_DOWNSEL(3)
#define CMU_CALCTRL_DOWNSEL_LFRCO	CMU_CALCTRL_DOWNSEL(4)
#define CMU_CALCTRL_DOWNSEL_AUXHFRCO	CMU_CALCTRL_DOWNSEL(5)

#define CMU_CALCTRL_UPSEL_SHIFT		(3)
#define CMU_CALCTRL_UPSEL_MASK		(0x7 << CMU_CALCTRL_UPSEL_SHIFT)
#define CMU_CALCTRL_UPSEL(v)		\
	(((v) << CMU_CALCTRL_UPSEL_SHIFT) & CMU_CALCTRL_UPSEL_MASK)
#define CMU_CALCTRL_UPSEL_HFXO		CMU_CALCTRL_UPSEL(0)
#define CMU_CALCTRL_UPSEL_LFXO		CMU_CALCTRL_UPSEL(1)
#define CMU_CALCTRL_UPSEL_HFRCO		CMU_CALCTRL_UPSEL(2)
#define CMU_CALCTRL_UPSEL_LFRCO		CMU_CALCTRL_UPSEL(3)
#define CMU_CALCTRL_UPSEL_AUXHFRCO	CMU_CALCTRL_UPSEL(4)

/* CMU_CALCNT */
#define CMU_CALCNT_CALCNT_SHIFT		(0)
#define CMU_CALCNT_CALCNT_MASK		(0xFFFFF << CMU_CALCNT_CALCNT_SHIFT)
#define CMU_CALCNT_CALCNT(v)		\
	(((v) << CMU_CALCNT_CALCNT_SHIFT) & CMU_CALCNT_CALCNT_MASK)

/* CMU_OSCENCMD */
#define CMU_OSCENCMD_LFXODIS		(1 << 9)
#define CMU_OSCENCMD_LFXOEN		(1 << 8)
#define CMU_OSCENCMD_LFRCODIS		(1 << 7)
#define CMU_OSCENCMD_LFRCOEN		(1 << 6)
#define CMU_OSCENCMD_AUXHFRCODIS	(1 << 5)
#define CMU_OSCENCMD_AUXHFRCOEN		(1 << 4)
#define CMU_OSCENCMD_HFXODIS		(1 << 3)
#define CMU_OSCENCMD_HFXOEN		(1 << 2)
#define CMU_OSCENCMD_HFRCODIS		(1 << 1)
#define CMU_OSCENCMD_HFRCOEN		(1 << 0)

/* CMU_CMD */
#define CMU_CMD_USBCCLKSEL_SHIFT	(5)
#define CMU_CMD_USBCCLKSEL_MASK		(0x3 << CMU_CMD_USBCCLKSEL_SHIFT)
#define CMU_CMD_USBCCLKSEL(v)		\
	(((v) << CMU_CMD_USBCCLKSEL_SHIFT) & CMU_CMD_USBCCLKSEL_MASK)
#define CMU_CMD_USBCCLKSEL_HFCLKNODIV	CMU_CMD_USBCCLKSEL(1)
#define CMU_CMD_USBCCLKSEL_LFXO		CMU_CMD_USBCCLKSEL(2)
#define CMU_CMD_USBCCLKSEL_LFRCO	CMU_CMD_USBCCLKSEL(3)

#define CMU_CMD_CALSTOP			(1 << 4)
#define CMU_CMD_CALSTART		(1 << 3)

#define CMU_CMD_HFCLKSEL_SHIFT		(0)
#define CMU_CMD_HFCLKSEL_MASK		(0x7 << CMU_CMD_HFCLKSEL_SHIFT)
#define CMU_CMD_HFCLKSEL(v)		\
	(((v) << CMU_CMD_HFCLKSEL_SHIFT) & CMU_CMD_HFCLKSEL_MASK)
#define CMU_CMD_HFCLKSEL_HFRCO		CMU_CMD_HFCLKSEL(1)
#define CMU_CMD_HFCLKSEL_HFXO		CMU_CMD_HFCLKSEL(2)
#define CMU_CMD_HFCLKSEL_LFRCO		CMU_CMD_HFCLKSEL(3)
#define CMU_CMD_HFCLKSEL_LFXO		CMU_CMD_HFCLKSEL(4)

/* CMU_LFCLKSEL */
#define CMU_LFCLKSEL_LFBE		(1 << 20)
#define CMU_LFCLKSEL_LFAE 		(1 << 16)

#define CMU_LFCLKSEL_LFB_SHIFT		(2)
#define CMU_LFCLKSEL_LFB_MASK		(0x3 << CMU_LFCLKSEL_LFB_MASK)
#define CMU_LFCLKSEL_LFB(v)		\
	(((v) << CMU_LFCLKSEL_LFB_MASK) & CMU_LFCLKSEL_LFB_MASK)

#define CMU_LFCLKSEL_LFA_SHIFT		(0)
#define CMU_LFCLKSEL_LFA_MASK		(0x3 << CMU_LFCLKSEL_LFA_MASK)
#define CMU_LFCLKSEL_LFA(v)		\
	(((v) << CMU_LFCLKSEL_LFA_MASK) & CMU_LFCLKSEL_LFA_MASK)

/* CMU_STATUS */
#define CMU_STATUS_USBCLFRCOSEL		(1 << 17)
#define CMU_STATUS_USBCLFXOSEL		(1 << 16)
#define CMU_STATUS_USBCHFCLKSEL		(1 << 15)
#define CMU_STATUS_CALBSY		(1 << 14)
#define CMU_STATUS_LFXOSEL		(1 << 13)
#define CMU_STATUS_LFRCOSEL		(1 << 12)
#define CMU_STATUS_HFXOSEL		(1 << 11)
#define CMU_STATUS_HFRCOSEL		(1 << 10)
#define CMU_STATUS_LFXORDY		(1 << 9)
#define CMU_STATUS_LFXOENS		(1 << 8)
#define CMU_STATUS_LFRCORDY		(1 << 7)
#define CMU_STATUS_LFRCOENS		(1 << 6)
#define CMU_STATUS_AUXHFRCORDY		(1 << 5)
#define CMU_STATUS_AUXHFRCOENS		(1 << 4)
#define CMU_STATUS_HFXORDY		(1 << 3)
#define CMU_STATUS_HFXOENS		(1 << 2)
#define CMU_STATUS_HFRCORDY		(1 << 1)
#define CMU_STATUS_HFRCOENS		(1 << 0)

/* CMU_IF */
#define CMU_IF_USBCHFCLKSEL		(1 << 7)
#define CMU_IF_CALOF			(1 << 6)
#define CMU_IF_CALRDY			(1 << 5)
#define CMU_IF_AUXHFRCORDY		(1 << 4)
#define CMU_IF_LFXORDY			(1 << 3)
#define CMU_IF_LFRCORDY			(1 << 2)
#define CMU_IF_HFXORDY			(1 << 1)
#define CMU_IF_HFRCORDY			(1 << 0)

/* CMU_IFS */
#define CMU_IFS_USBCHFCLKSEL		(1 << 7)
#define CMU_IFS_CALOF			(1 << 6)
#define CMU_IFS_CALRDY			(1 << 5)
#define CMU_IFS_AUXHFRCORDY		(1 << 4)
#define CMU_IFS_LFXORDY			(1 << 3)
#define CMU_IFS_LFRCORDY		(1 << 2)
#define CMU_IFS_HFXORDY			(1 << 1)
#define CMU_IFS_HFRCORDY		(1 << 0)

/* CMU_IFC */
#define CMU_IFC_USBCHFCLKSEL		(1 << 7)
#define CMU_IFC_CALOF			(1 << 6)
#define CMU_IFC_CALRDY			(1 << 5)
#define CMU_IFC_AUXHFRCORDY		(1 << 4)
#define CMU_IFC_LFXORDY			(1 << 3)
#define CMU_IFC_LFRCORDY		(1 << 2)
#define CMU_IFC_HFXORDY			(1 << 1)
#define CMU_IFC_HFRCORDY		(1 << 0)

/* CMU_IEN */
#define CMU_IEN_USBCHFCLKSEL		(1 << 7)
#define CMU_IEN_CALOF			(1 << 6)
#define CMU_IEN_CALRDY			(1 << 5)
#define CMU_IEN_AUXHFRCORDY		(1 << 4)
#define CMU_IEN_LFXORDY			(1 << 3)
#define CMU_IEN_LFRCORDY		(1 << 2)
#define CMU_IEN_HFXORDY			(1 << 1)
#define CMU_IEN_HFRCORDY		(1 << 0)

/* CMU_HFCORECLKEN0 */
#define CMU_HFCORECLKEN0_EBI		(1 << 5)
#define CMU_HFCORECLKEN0_LE		(1 << 4)
#define CMU_HFCORECLKEN0_USB		(1 << 3)
#define CMU_HFCORECLKEN0_USBC		(1 << 2)
#define CMU_HFCORECLKEN0_AES		(1 << 1)
#define CMU_HFCORECLKEN0_DMA		(1 << 0)

/* CMU_HFPERCLKEN0 */
#define CMU_HFPERCLKEN0_DAC0		(1 << 17)
#define CMU_HFPERCLKEN0_ADC0		(1 << 16)
#define CMU_HFPERCLKEN0_PRS		(1 << 15)
#define CMU_HFPERCLKEN0_VCMP		(1 << 14)
#define CMU_HFPERCLKEN0_GPIO		(1 << 13)
#define CMU_HFPERCLKEN0_I2C1		(1 << 12)
#define CMU_HFPERCLKEN0_I2C0		(1 << 11)
#define CMU_HFPERCLKEN0_ACMP1		(1 << 10)
#define CMU_HFPERCLKEN0_ACMP0		(1 << 9)
#define CMU_HFPERCLKEN0_TIMER3		(1 << 8)
#define CMU_HFPERCLKEN0_TIMER2		(1 << 7)
#define CMU_HFPERCLKEN0_TIMER1		(1 << 6)
#define CMU_HFPERCLKEN0_TIMER0		(1 << 5)
#define CMU_HFPERCLKEN0_UART1		(1 << 4)
#define CMU_HFPERCLKEN0_UART0		(1 << 3)
#define CMU_HFPERCLKEN0_USART2		(1 << 2)
#define CMU_HFPERCLKEN0_USART1		(1 << 1)
#define CMU_HFPERCLKEN0_USART0		(1 << 0)

/* CMU_SYNCBUSY */
#define CMU_SYNCBUSY_LFBPRESC0		(1 << 6)
#define CMU_SYNCBUSY_LFBCLKEN0		(1 << 4)
#define CMU_SYNCBUSY_LFAPRESC0		(1 << 2)
#define CMU_SYNCBUSY_LFACLKEN0		(1 << 0)

/* CMU_FREEZE */
#define CMU_FREEZE_REGFREEZE		(1 << 0)

/* CMU_LFACLKEN0 */
#define CMU_LFACLKEN0_LCD		(1 << 3)
#define CMU_LFACLKEN0_LETIMER0		(1 << 2)
#define CMU_LFACLKEN0_RTC		(1 << 1)
#define CMU_LFACLKEN0_LESENSE		(1 << 0)

/* CMU_LFBCLKEN0 */
#define CMU_LFBCLKEN0_LEUART1		(1 << 1)
#define CMU_LFBCLKEN0_LEUART0		(1 << 0)

/* CMU_LFAPRESC0 */
#define CMU_LFAPRESC0_LCD_SHIFT		(12)
#define CMU_LFAPRESC0_LCD_MASK		(0x3 << CMU_LFAPRESC0_LCD_SHIFT)
#define CMU_LFAPRESC0_LCD(v)		\
	(((v) << CMU_LFAPRESC0_LCD_SHIFT) & CMU_LFAPRESC0_LCD_MASK)
#define CMU_LFAPRESC0_LCD_DIV16		CMU_LFAPRESC0_LCD(0)
#define CMU_LFAPRESC0_LCD_DIV32		CMU_LFAPRESC0_LCD(1)
#define CMU_LFAPRESC0_LCD_DIV64		CMU_LFAPRESC0_LCD(2)
#define CMU_LFAPRESC0_LCD_DIV128	CMU_LFAPRESC0_LCD(3)

#define CMU_LFAPRESC0_LETIMER0_SHIFT	(8)
#define CMU_LFAPRESC0_LETIMER0_MASK	(0xF << CMU_LFAPRESC0_LETIMER0_SHIFT)
#define CMU_LFAPRESC0_LETIMER0(v)	\
	(((v) << CMU_LFAPRESC0_LETIMER0_SHIFT) & CMU_LFAPRESC0_LETIMER0_MASK)
#define CMU_LFAPRESC0_LETIMER0_DIV1	CMU_LFAPRESC0_LETIMER0(0)
#define CMU_LFAPRESC0_LETIMER0_DIV2	CMU_LFAPRESC0_LETIMER0(1)
#define CMU_LFAPRESC0_LETIMER0_DIV4	CMU_LFAPRESC0_LETIMER0(2)
#define CMU_LFAPRESC0_LETIMER0_DIV8	CMU_LFAPRESC0_LETIMER0(3)
#define CMU_LFAPRESC0_LETIMER0_DIV16	CMU_LFAPRESC0_LETIMER0(4)
#define CMU_LFAPRESC0_LETIMER0_DIV32	CMU_LFAPRESC0_LETIMER0(5)
#define CMU_LFAPRESC0_LETIMER0_DIV64	CMU_LFAPRESC0_LETIMER0(6)
#define CMU_LFAPRESC0_LETIMER0_DIV128	CMU_LFAPRESC0_LETIMER0(7)
#define CMU_LFAPRESC0_LETIMER0_DIV256	CMU_LFAPRESC0_LETIMER0(8)
#define CMU_LFAPRESC0_LETIMER0_DIV512	CMU_LFAPRESC0_LETIMER0(9)
#define CMU_LFAPRESC0_LETIMER0_DIV1024	CMU_LFAPRESC0_LETIMER0(10)
#define CMU_LFAPRESC0_LETIMER0_DIV2048	CMU_LFAPRESC0_LETIMER0(11)
#define CMU_LFAPRESC0_LETIMER0_DIV4096	CMU_LFAPRESC0_LETIMER0(12)
#define CMU_LFAPRESC0_LETIMER0_DIV8192	CMU_LFAPRESC0_LETIMER0(13)
#define CMU_LFAPRESC0_LETIMER0_DIV16384	CMU_LFAPRESC0_LETIMER0(14)
#define CMU_LFAPRESC0_LETIMER0_DIV32768	CMU_LFAPRESC0_LETIMER0(15)
#define CMU_LFAPRESC0_LETIMER0_NODIV	CMU_LFAPRESC0_LETIMER0_DIV1

#define CMU_LFAPRESC0_RTC_SHIFT		(4)
#define CMU_LFAPRESC0_RTC_MASK		(0xF << CMU_LFAPRESC0_RTC_SHIFT)
#define CMU_LFAPRESC0_RTC(v)		\
	(((v) << CMU_LFAPRESC0_RTC_SHIFT) & CMU_LFAPRESC0_RTC_MASK)
#define CMU_LFAPRESC0_RTC_DIV1		CMU_LFAPRESC0_RTC(0)
#define CMU_LFAPRESC0_RTC_DIV2		CMU_LFAPRESC0_RTC(1)
#define CMU_LFAPRESC0_RTC_DIV4		CMU_LFAPRESC0_RTC(2)
#define CMU_LFAPRESC0_RTC_DIV8		CMU_LFAPRESC0_RTC(3)
#define CMU_LFAPRESC0_RTC_DIV16		CMU_LFAPRESC0_RTC(4)
#define CMU_LFAPRESC0_RTC_DIV32		CMU_LFAPRESC0_RTC(5)
#define CMU_LFAPRESC0_RTC_DIV64		CMU_LFAPRESC0_RTC(6)
#define CMU_LFAPRESC0_RTC_DIV128	CMU_LFAPRESC0_RTC(7)
#define CMU_LFAPRESC0_RTC_DIV256	CMU_LFAPRESC0_RTC(8)
#define CMU_LFAPRESC0_RTC_DIV512	CMU_LFAPRESC0_RTC(9)
#define CMU_LFAPRESC0_RTC_DIV1024	CMU_LFAPRESC0_RTC(10)
#define CMU_LFAPRESC0_RTC_DIV2048	CMU_LFAPRESC0_RTC(11)
#define CMU_LFAPRESC0_RTC_DIV4096	CMU_LFAPRESC0_RTC(12)
#define CMU_LFAPRESC0_RTC_DIV8192	CMU_LFAPRESC0_RTC(13)
#define CMU_LFAPRESC0_RTC_DIV16384	CMU_LFAPRESC0_RTC(14)
#define CMU_LFAPRESC0_RTC_DIV32768	CMU_LFAPRESC0_RTC(15)
#define CMU_LFAPRESC0_RTC_NODIV		CMU_LFAPRESC0_RTC_DIV1

#define CMU_LFAPRESC0_LESENSE_SHIFT	(12)
#define CMU_LFAPRESC0_LESENSE_MASK	(0x3 << CMU_LFAPRESC0_LESENSE_SHIFT)
#define CMU_LFAPRESC0_LESENSE(v)	\
	(((v) << CMU_LFAPRESC0_LESENSE_SHIFT) & CMU_LFAPRESC0_LESENSE_MASK)
#define CMU_LFAPRESC0_LESENSE_DIV1	CMU_LFAPRESC0_LESENSE(0)
#define CMU_LFAPRESC0_LESENSE_DIV2	CMU_LFAPRESC0_LESENSE(1)
#define CMU_LFAPRESC0_LESENSE_DIV4	CMU_LFAPRESC0_LESENSE(2)
#define CMU_LFAPRESC0_LESENSE_DIV8	CMU_LFAPRESC0_LESENSE(3)
#define CMU_LFAPRESC0_LESENSE_NODIV	CMU_LFAPRESC0_LESENSE_DIV1

/* CMU_LFBPRESC0 */
#define CMU_LFBPRESC0_LEUART1_SHIFT	(4)
#define CMU_LFBPRESC0_LEUART1_MASK	(0x3 << CMU_LFBPRESC0_LEUART1_SHIFT)
#define CMU_LFBPRESC0_LEUART1(v)	\
	(((v) << CMU_LFBPRESC0_LEUART1_SHIFT) & CMU_LFBPRESC0_LEUART1_MASK)
#define CMU_LFBPRESC0_LEUART1_DIV1	CMU_LFBPRESC0_LEUART1(0)
#define CMU_LFBPRESC0_LEUART1_DIV2	CMU_LFBPRESC0_LEUART1(1)
#define CMU_LFBPRESC0_LEUART1_DIV4	CMU_LFBPRESC0_LEUART1(2)
#define CMU_LFBPRESC0_LEUART1_DIV8	CMU_LFBPRESC0_LEUART1(3)
#define CMU_LFBPRESC0_LEUART1_NODIV	CMU_LFBPRESC0_LEUART1_DIV1

#define CMU_LFBPRESC0_LEUART0_SHIFT	(0)
#define CMU_LFBPRESC0_LEUART0_MASK	(0x3 << CMU_LFBPRESC0_LEUART0_SHIFT)
#define CMU_LFBPRESC0_LEUART0(v)	\
	(((v) << CMU_LFBPRESC0_LEUART0_SHIFT) & CMU_LFBPRESC0_LEUART0_MASK)
#define CMU_LFBPRESC0_LEUART0_DIV1	CMU_LFBPRESC0_LEUART0(0)
#define CMU_LFBPRESC0_LEUART0_DIV2	CMU_LFBPRESC0_LEUART0(1)
#define CMU_LFBPRESC0_LEUART0_DIV4	CMU_LFBPRESC0_LEUART0(2)
#define CMU_LFBPRESC0_LEUART0_DIV8	CMU_LFBPRESC0_LEUART0(3)
#define CMU_LFBPRESC0_LEUART0_NODIV	CMU_LFBPRESC0_LEUART0_DIV1

/* CMU_PCNTCTRL */
#define CMU_PCNTCTRL_PCNT2CLKSE		(1 << 5)
#define CMU_PCNTCTRL_PCNT2CLKEN		(1 << 4)
#define CMU_PCNTCTRL_PCNT1CLKSEL	(1 << 3)
#define CMU_PCNTCTRL_PCNT1CLKEN		(1 << 2)
#define CMU_PCNTCTRL_PCNT0CLKSEL	(1 << 1)
#define CMU_PCNTCTRL_PCNT0CLKEN		(1 << 0)

/* CMU_LCDCTRL */
#define CMU_LCDCTRL_VBFDIV_SHIFT	(4)
#define CMU_LCDCTRL_VBFDIV_MASK		(0xF << CMU_LCDCTRL_VBFDIV_SHIFT)
#define CMU_LCDCTRL_VBFDIV(v)		\
	(((v) << CMU_LCDCTRL_VBFDIV_SHIFT) & CMU_LCDCTRL_VBFDIV_MASK)
#define CMU_LCDCTRL_VBFDIV_DIV1		CMU_LCDCTRL_VBFDIV(0)
#define CMU_LCDCTRL_VBFDIV_DIV2		CMU_LCDCTRL_VBFDIV(1)
#define CMU_LCDCTRL_VBFDIV_DIV4		CMU_LCDCTRL_VBFDIV(2)
#define CMU_LCDCTRL_VBFDIV_DIV8		CMU_LCDCTRL_VBFDIV(3)
#define CMU_LCDCTRL_VBFDIV_DIV16	CMU_LCDCTRL_VBFDIV(4)
#define CMU_LCDCTRL_VBFDIV_DIV32	CMU_LCDCTRL_VBFDIV(5)
#define CMU_LCDCTRL_VBFDIV_DIV64	CMU_LCDCTRL_VBFDIV(6)
#define CMU_LCDCTRL_VBFDIV_DIV128	CMU_LCDCTRL_VBFDIV(7)
#define CMU_LCDCTRL_VBFDIV_NODIV	CMU_LCDCTRL_VBFDIV_DIV1

#define CMU_LCDCTRL_VBOOSTEN		(1 << 3)

#define CMU_LCDCTRL_FDIV_SHIFT		(0)
#define CMU_LCDCTRL_FDIV_MASK		(0x3 << CMU_LCDCTRL_FDIV_SHIFT)
#define CMU_LCDCTRL_FDIV(v)		\
	(((v) & CMU_LCDCTRL_FDIV_MASK) << CMU_LCDCTRL_FDIV_SHIFT)

/* CMU_ROUTE */
#define CMU_ROUTE_LOCATION_SHIFT	(2)
#define CMU_ROUTE_LOCATION_MASK		(0x7 << CMU_ROUTE_LOCATION_SHIFT)
#define CMU_ROUTE_LOCATION_LOCx(i)	\
	(((i) << CMU_ROUTE_LOCATION_SHIFT) & CMU_ROUTE_LOCATION_MASK)
#define CMU_ROUTE_LOCATION_LOC0		CMU_ROUTE_LOCATION_LOCx(0)
#define CMU_ROUTE_LOCATION_LOC1		CMU_ROUTE_LOCATION_LOCx(1)
#define CMU_ROUTE_LOCATION_LOC2		CMU_ROUTE_LOCATION_LOCx(2)

#define CMU_ROUTE_CLKOUT1PEN		(1 << 1)
#define CMU_ROUTE_CLKOUT0PEN		(1 << 0)

/* CMU_LOCK */
#define CMU_LOCK_LOCKKEY_SHIFT		(0)
#define CMU_LOCK_LOCKKEY_MASK		(0xFFFF << CMU_LOCK_LOCKKEY_SHIFT)
#define CMU_LOCK_LOCKKEY_UNLOCKED	(0x0000 << CMU_LOCK_LOCKKEY_SHIFT)
#define CMU_LOCK_LOCKKEY_LOCKED		(0x0001 << CMU_LOCK_LOCKKEY_SHIFT)
#define CMU_LOCK_LOCKKEY_LOCK		(0x0000 << CMU_LOCK_LOCKKEY_SHIFT)
#define CMU_LOCK_LOCKKEY_UNLOCK		(0x580E << CMU_LOCK_LOCKKEY_SHIFT)

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum cmu_periph_clken {
	/* CMU_PCNTCTRL */
	CMU_PCNT2	= _REG_BIT(0x078, 4),
	CMU_PCNT1	= _REG_BIT(0x078, 2),
	CMU_PCNT0	= _REG_BIT(0x078, 0),

	/* CMU_LFBCLKEN0 */
	CMU_LEUART1	= _REG_BIT(0x060, 1),
	CMU_LEUART0	= _REG_BIT(0x060, 0),

	/* CMU_LFACLKEN0 */
	CMU_LCD		= _REG_BIT(0x058, 3),
	CMU_LETIMER0	= _REG_BIT(0x058, 2),
	CMU_RTC		= _REG_BIT(0x058, 1),
	CMU_LESENSE	= _REG_BIT(0x058, 0),

	/* CMU_HFPERCLKEN0 */
	CMU_DAC0	= _REG_BIT(0x044, 17),
	CMU_ADC0	= _REG_BIT(0x044, 16),
	CMU_PRS		= _REG_BIT(0x044, 15),
	CMU_VCMP	= _REG_BIT(0x044, 14),
	CMU_GPIO	= _REG_BIT(0x044, 13),
	CMU_I2C1	= _REG_BIT(0x044, 12),
	CMU_I2C0	= _REG_BIT(0x044, 11),
	CMU_ACMP1	= _REG_BIT(0x044, 10),
	CMU_ACMP0	= _REG_BIT(0x044, 9),
	CMU_TIMER3	= _REG_BIT(0x044, 8),
	CMU_TIMER2	= _REG_BIT(0x044, 7),
	CMU_TIMER1	= _REG_BIT(0x044, 6),
	CMU_TIMER0	= _REG_BIT(0x044, 5),
	CMU_UART1	= _REG_BIT(0x044, 4),
	CMU_UART0	= _REG_BIT(0x044, 3),
	CMU_USART2	= _REG_BIT(0x044, 2),
	CMU_USART1	= _REG_BIT(0x044, 1),
	CMU_USART0	= _REG_BIT(0x044, 0),

	/* CMU_HFCORECLKEN0 */
	CMU_EBI		= _REG_BIT(0x040, 5),
	CMU_LE		= _REG_BIT(0x040, 4),
	CMU_USB		= _REG_BIT(0x040, 3),
	CMU_USBC	= _REG_BIT(0x040, 2),
	CMU_AES		= _REG_BIT(0x040, 1),
	CMU_DMA		= _REG_BIT(0x040, 0)
};

enum cmu_osc {
	HFRCO,		/**< Internal, 1 - 28Mhz */
	LFRCO,		/**< Internal, 32.768kHz */
	ULFRCO,		/**< Internal, 1Khz      */
	HFXO,		/**< External, 4-48Mhz   */
	LFXO,		/**< External, 32.768kHz */
	AUXHFRCO,	/**< Internal, 1-28Mhz   */
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void cmu_enable_lock(void);
void cmu_disable_lock(void);
bool cmu_get_lock_flag(void);

void cmu_periph_clock_enable(enum cmu_periph_clken periph);
void cmu_periph_clock_disable(enum cmu_periph_clken periph);

/* TODO: CMU_CTRL, CMU_HFCORECLKDIV, CMU_HFPERCLKDIV, CMU_HFRCOCTRL,
 *       CMU_LFRCOCTRL, CMU_AUXHFRCOCTRL, CMU_CALCTRL, CMU_CALCNT
 */

void cmu_osc_on(enum cmu_osc osc);
void cmu_osc_off(enum cmu_osc osc);

/* TODO: CMU_CMD, CMU_LFCLKSEL */

/* TODO: portions of CMU_STATUS */
bool cmu_osc_ready_flag(enum cmu_osc osc);
void cmu_wait_for_osc_ready(enum cmu_osc osc);
void cmu_set_hfclk_source(enum cmu_osc osc);
void cmu_set_usbclk_source(enum cmu_osc osc);
enum cmu_osc cmu_get_hfclk_source(void);

/* TODO: CMU_IF, CMU_IFS, CMU_IFC, CMU_IEN */

/* TODO: CMU_SYNCBUSY, CMU_FREEZE, CMU_LFACLKEN0 */

/* TODO: CMU_LFAPRESC0, CMU_LFBPRESC0, CMU_PCNTCTRL, CMU_LCDCTRL, CMU_ROUTE */

void cmu_clock_setup_in_hfxo_out_48mhz(void);

END_DECLS

#endif
