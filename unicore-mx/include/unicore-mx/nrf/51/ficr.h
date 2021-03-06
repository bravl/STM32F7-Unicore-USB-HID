/*
 * This file is part of the unicore-mx project.
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

#ifndef NRF51_FICR_H
#define NRF51_FICR_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/memorymap.h>

/* Factory Information Configuration Register */

#define FICR_CODEPAGESIZE			MMIO32(FICR_BASE + 0x010)
#define FICR_CODESIZE			MMIO32(FICR_BASE + 0x014)

/* Deprecated */
#define FICR_CLENR0			MMIO32(FICR_BASE + 0x028)
/* Deprecated */
#define FICR_PPFC			MMIO32(FICR_BASE + 0x02C)

#define FICR_NUMRAMBLOCK			MMIO32(FICR_BASE + 0x034)
#define FICR_SIZERAMBLOCKS			MMIO32(FICR_BASE + 0x038)

/* Deprecated */
#define FICR_SIZERAMBLOCK(n)			MMIO32(FICR_BASE + 0x038 + 0x4 * (n))

#define FICR_CONFIGID			MMIO32(FICR_BASE + 0x05C)

#define FICR_DEVICEID0				MMIO32(FICR_BASE + 0x060)
#define FICR_DEVICEID1				MMIO32(FICR_BASE + 0x064)

/* Encryption Root */
#define FICR_ER(n)			MMIO32(FICR_BASE + 0x080 + 0x4 * (n))
#define FICR_ER0			FICR_ER(0)
#define FICR_ER1			FICR_ER(1)
#define FICR_ER2			FICR_ER(2)
#define FICR_ER3			FICR_ER(3)

/* Identity Root */
#define FICR_IR(n)			MMIO32(FICR_BASE + 0x090 + 0x4 * (n))
#define FICR_IR0			FICR_IR(0)
#define FICR_IR1			FICR_IR(1)
#define FICR_IR2			FICR_IR(2)
#define FICR_IR3			FICR_IR(3)

#define FICR_DEVICEADDRTYPE			MMIO32(FICR_BASE + 0x0A0)
#define FICR_DEVICEADDR0			MMIO32(FICR_BASE + 0x0A4)
#define FICR_DEVICEADDR1			MMIO32(FICR_BASE + 0x0A8)

#define FICR_OVERRIDEEN			MMIO32(FICR_BASE + 0x0AC)

/* Override values for Nordic Semi proprietary NRF 1Mbit mode */
#define FICR_NRF_1MBIT(n)			MMIO32(FICR_BASE + 0x0B0 + 0x4 * (n))
#define FICR_NRF_1MBIT0			FICR_NRF_1MBIT(0)
#define FICR_NRF_1MBIT1			FICR_NRF_1MBIT(1)
#define FICR_NRF_1MBIT2			FICR_NRF_1MBIT(2)
#define FICR_NRF_1MBIT3			FICR_NRF_1MBIT(3)
#define FICR_NRF_1MBIT4			FICR_NRF_1MBIT(4)

/* Override values for BLE 1Mbit mode */
#define FICR_BLE_1MBIT(n)			MMIO32(FICR_BASE + 0x0EC + 0x4 * (n))
#define FICR_BLE_1MBIT0			FICR_BLE_1MBIT(0)
#define FICR_BLE_1MBIT1			FICR_BLE_1MBIT(1)
#define FICR_BLE_1MBIT2			FICR_BLE_1MBIT(2)
#define FICR_BLE_1MBIT3			FICR_BLE_1MBIT(3)
#define FICR_BLE_1MBIT4			FICR_BLE_1MBIT(4)

#define FICR_OVERRIDEEN_NRF_1MBIT			(1 << 0)
#define FICR_OVERRIDEEN_BLE_1MBIT			(1 << 3)

#endif  /* NRF51_FICR_H */
