/** @defgroup rcc_file RCC
 *
 * @ingroup STM32F2xx
 *
 * @section rcc_f2_api_ex Reset and Clock Control API.
 *
 * @brief <b>unicore-mx STM32F2xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran at seznam.cz>
 *
 * @date 18 Jun 2013
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <unicore-mx/cm3/assert.h>
#include <unicore-mx/stm32/rcc.h>
#include <unicore-mx/stm32/flash.h>

/**@{*/

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 16000000;
uint32_t rcc_apb1_frequency = 16000000;
uint32_t rcc_apb2_frequency = 16000000;

const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 120MHz */
		.pllm = 8,
		.plln = 240,
		.pllp = 2,
		.pllq = 5,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.flash_config = FLASH_ACR_ICE | FLASH_ACR_DCE |
				FLASH_ACR_LATENCY_3WS,
		.apb1_frequency = 30000000,
		.apb2_frequency = 60000000,
	},
};

void rcc_osc_ready_int_clear(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case RCC_HSI:
		return ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
	case RCC_LSE:
		return ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case RCC_LSI:
		return ((RCC_CIR & RCC_CIR_LSIRDYF) != 0);
		break;
	}

	cm3_assert_not_reached();
}

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

void rcc_wait_for_osc_ready(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
		break;
	case RCC_HSE:
		while ((RCC_CR & RCC_CR_HSERDY) == 0);
		break;
	case RCC_HSI:
		while ((RCC_CR & RCC_CR_HSIRDY) == 0);
		break;
	case RCC_LSE:
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0);
		break;
	case RCC_LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
}

void rcc_wait_for_sysclk_status(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_PLL);
		break;
	case RCC_HSE:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_HSE);
		break;
	case RCC_HSI:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_HSI);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(osc_t osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_osc_bypass_enable(osc_t osc)
{
	switch (osc) {
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case RCC_PLL:
	case RCC_HSI:
	case RCC_LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_osc_bypass_disable(osc_t osc)
{
	switch (osc) {
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case RCC_PLL:
	case RCC_HSI:
	case RCC_LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC_CFGR = (reg32 | clk);
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(1 << 22);
	RCC_PLLCFGR = (reg32 | (pllsrc << 22));
}

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 13) | (1 << 14) | (1 << 15));
	RCC_CFGR = (reg32 | (ppre2 << 13));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 10) | (1 << 11) | (1 << 12));
	RCC_CFGR = (reg32 | (ppre1 << 10));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
	RCC_CFGR = (reg32 | (hpre << 4));
}

void rcc_set_rtcpre(uint32_t rtcpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20));
	RCC_CFGR = (reg32 | (rtcpre << 16));
}

void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		RCC_PLLCFGR_PLLSRC |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR & 0x000c) >> 2;
}

void rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_main_pll_hse(clock->pllm, clock->plln,
			     clock->pllp, clock->pllq);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	flash_set_ws(clock->flash_config);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}

/**@}*/