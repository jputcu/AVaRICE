/*
 *	avarice - The "avarice" program.
 *	Copyright (C) 2001 Scott Finneran
 *      Copyright (C) 2002, 2003, 2004 Intel Corporation
 *	Copyright (C) 2005 Joerg Wunsch
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License Version 2
 *      as published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 * This file contains the JTAG ICE device descriptors of all supported
 * MCU types for both, the mkI and mkII protocol.
 *
 * $Id$
 */

#include <stdlib.h>

#include "avarice.h"
#include "jtag.h"
#include "jtag1.h"

jtag_device_def_type *global_p_device_def;

/* Device descriptor magic from Atmel's documents. Let's hope it's more
   accurate than the rest of that text... */
jtag_device_def_type deviceDefinitions[] = {
    {
        "atmega16",
        0x9403,
        128, 128,    // 16K flash 
        4,   128,    // 512 bytes EEPROM
        0x54,        // 21 interrupt vectors
	DEVFL_NONE,
        atmega16_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xCF, 0xAF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF },
            { 0x87, 0x26, 0xFF, 0xEF, 0xFE, 0xFF, 0x3F, 0xFA },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x31,
            0x57,
            0x00,
            { 128, 0 },
            0,
            { 0x80, 0x1F, 0x00, 0x00 },
            0,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x6F,0xFF,0xFF,0xFE,0xFF,0xFD,0xFF }, // ucReadIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucReadIOShadow
	    { 0x8F,0x26,0xB6,0xFD,0xFE,0xFF,0xBD,0xFA }, // ucWriteIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucWriteIOShadow
	    { 0 },			// ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0 },			// ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x1F80),		// ulBootAddress
	    fill_b2(0),			// uiUpperExtIOLoc
	    fill_b4(0x4000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x4000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x60),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATMEGA_162
    {
        "atmega162",
        0x9404,
        128, 128,    // 16K flash 
        4,   128,    // 512 bytes EEPROM
        0x70,        // 28 interrupt vectors
	DEVFL_NONE,
        atmega162_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xF7, 0x6F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
            { 0xF3, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x02, 0x18, 0x00, 0x30, 0xF3, 0x0F, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x02, 0x18, 0x00, 0x20, 0xF3, 0x0F, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x04,
            0x57,
            0x00,
            { 128, 0 },
            4,
            { 0x80, 0x1F, 0x00, 0x00 },
            0x8B,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xE7,0x6F,0xFF,0xFF,0xFE,0xFF,0xFF,0xEF }, // ucReadIO
	    { 0xC3,0x26,0xB6,0xFD,0xFE,0xFF,0xFF,0xEA }, // ucReadIOShadow
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X10 }, // ucWriteIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X10 }, // ucWriteIOShadow
	    { 0 },			// ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0 },			// ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x04,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x1F80),		// ulBootAddress
	    fill_b2(0xBB),		// uiUpperExtIOLoc
	    fill_b4(0x4000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x4000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATMEGA_169
    {
        "atmega169",
        0x9405,
        128, 128,    // 16K flash 
        4,   128,    // 512 bytes EEPROM
        0x5c,        // 23 interrupt vectors
	DEVFL_NONE,
        atmega169_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xFF, 0xFF, 0xFF, 0xF0, 0xDF, 0x3C, 0xBB, 0xE0 }, 
            { 0xB6, 0x6D, 0x1B, 0xE0, 0xDF, 0x3C, 0xBA, 0xE0 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x43, 0xDA, 0x00, 0xFF, 0xF7, 0x0F, 0x00, 0x00,
              0x00, 0x00, 0x4D, 0x07, 0x37, 0x00, 0x00, 0x00, 
              0xF0, 0xF0, 0xDE, 0x7B },
            { 0x43, 0xDA, 0x00, 0xFF, 0xF7, 0x0F, 0x00, 0x00,
              0x00, 0x00, 0x4D, 0x05, 0x36, 0x00, 0x00, 0x00,
              0xE0, 0xF0, 0xDE, 0x7B },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 }, 
            0x31,
            0x57,
            0x00,
            { 128, 0 },
            4,
            { 0x80, 0x1F, 0x00, 0x00 },
            0xFE,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF0,0xDF,0x3C,0xB9,0xE0 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE0 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xDA,0x01,0xDF,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x07,0x37,0x00,0x00,0x00,0xF0,0xF0,0xDE,0x7B }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xDA,0x01,0xD8,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x05,0x36,0x00,0x00,0x00,0xE0,0xF0,0xDE,0x7B }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x1F80),		// ulBootAddress
	    fill_b2(0xFE),		// uiUpperExtIOLoc
	    fill_b4(0x4000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x4000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATMEGA_323
    {
        "atmega323",
        0x9501,
        128, 256,    // 32K flash 
        4,   256,    // 1K EEPROM
        0x50,        // 20 interrupt vectors
	DEVFL_NONE,
        NULL,        // io reg defs not defined yet
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xCF, 0xAF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF }, 
            { 0x87, 0x26, 0xFF, 0xEF, 0xFE, 0xFF, 0x3F, 0xFA }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x31,
            0x57,
            0x00,
            { 128, 0 },
            0,
            { 0x00, 0x3F, 0x00, 0x00 },
            0,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x6F,0xFF,0xFF,0xFE,0xFF,0xFD,0xFF }, // ucReadIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucReadIOShadow
	    { 0x8F,0x26,0xB6,0xFD,0xFE,0xFF,0xBD,0xFA }, // ucWriteIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucWriteIOShadow
	    { 0 },			// ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0 },			// ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x3F00),		// ulBootAddress
	    fill_b2(0),			// uiUpperExtIOLoc
	    fill_b4(0x8000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x8000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x60),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATMEGA_32
    {
        "atmega32",
        0x9502,
        128, 256,    // 32K flash 
        4,   256,    // 1K EEPROM
        0x54,        // 21 interrupt vectors
	DEVFL_NONE,
        atmega32_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xFF, 0x6F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, 
            { 0xFF, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFA }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x31,
            0x57,
            0x00,
            { 128, 0 },
            4,
            { 0x00, 0x3F, 0x00, 0x00 },
            0,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x6F,0xFF,0xFF,0xFE,0xFF,0xFD,0xFF }, // ucReadIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucReadIOShadow
	    { 0x8F,0x26,0xB6,0xFD,0xFE,0xFF,0xBD,0xFA }, // ucWriteIO
	    { 0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00 }, // ucWriteIOShadow
	    { 0 },			// ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0 },			// ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x3F00),		// ulBootAddress
	    fill_b2(0),			// uiUpperExtIOLoc
	    fill_b4(0x8000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x8000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x60),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },

    // DEV_ATMEGA_64
    {
        "atmega64",
        0x9602,
        256, 256,    // 64K flash 
        8,   256,    // 2K bytes EEPROM
        0x8c,        // 35 interrupt vectors
	DEVFL_NONE,
        atmega128_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xCF, 0x2F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
            { 0xCF, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x3E, 0xB5, 0x1F, 0x37, 0xFF, 0x1F, 0x21, 0x2F,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x3E, 0xB5, 0x0F, 0x27, 0xFF, 0x1F, 0x21, 0x27,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x22,
            0x68,
            0x00,
            { 0, 1 },
            8,
            { 0x00, 0x7E, 0x00, 0x00 },
            0x9D,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x6F,0xFF,0xFF,0xFB,0xFF,0xFF,0xF7 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0x8C,0x26,0xB6,0xFD,0xFB,0xFF,0xBF,0xF6}, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x3E,0xB5,0x1F,0x37,0xFF,0x5F,0x21,0x2F, /* ... */ }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x36,0xB5,0x0F,0x27,0xFF,0x5F,0x21,0x27, /* ... */ }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x22,			// ucIDRAddress
	    0x68,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0x7E00),		// ulBootAddress
	    fill_b2(0x9D),		// uiUpperExtIOLoc
	    fill_b4(0x10000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x10000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATMEGA_128
    {
        "atmega128",
        0x9702,
        256, 512,    // 128K flash 
        8,   512,    // 4K bytes EEPROM
        0x8c,        // 35 interrupt vectors
	DEVFL_NO_SOFTBP,
        atmega128_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xCF, 0x2F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, 
            { 0xCF, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
            { 0x3E, 0xB5, 0x1F, 0x37, 0xFF, 0x1F, 0x21, 0x2F,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x3E, 0xB5, 0x0F, 0x27, 0xFF, 0x1F, 0x21, 0x27,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 }, 
            0x22,
            0x68,
            0x3B,
            { 0, 1 },
            8,
            { 0x00, 0xFE, 0x00, 0x00 },
            0x9D,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x6F,0xFF,0xFF,0xFB,0xFF,0xFF,0xFF }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0x8C,0x26,0xB6,0xFD,0xFB,0xFF,0xBF,0xFE}, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x3E,0xB5,0x1F,0x37,0xFF,0x1F,0x21,0x2F, /* ... */ }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x36,0xB5,0x0F,0x27,0xFF,0x1F,0x21,0x27, /* ... */ }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x22,			// ucIDRAddress
	    0x68,			// ucSPMCRAddress
	    0x3B,			// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0xFE00),		// ulBootAddress
	    fill_b2(0x9D),		// uiUpperExtIOLoc
	    fill_b4(0x20000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x20000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    // fill_b2(0),		// EECRAddress
	},
    },
    // DEV_ATCAN_128
    {
        "at90can128",
        0x9781,
        256, 512,    // 128K flash 
        8,   512,    // 4K bytes EEPROM
        0x94,        // 37 interrupt vectors
	DEVFL_NONE,
        iocan128_io_registers,
        {
            JTAG_C_SET_DEVICE_DESCRIPTOR,
            { 0xFF, 0xFF, 0xFF, 0xF1, 0xDF, 0x7C, 0xBB, 0xE8 }, 
            { 0xFF, 0xFF, 0xFF, 0xF1, 0xDF, 0x7C, 0xBB, 0xE8 }, 
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            { 0x43, 0xC3, 0x33, 0xBF, 0xF7, 0x3F, 0xF7, 0x3F,
              0x00, 0x00, 0x4D, 0x1F, 0x77, 0x77, 0x00, 0xFF,
              0xFF, 0xFF, 0xFF, 0x07 },
            { 0x43, 0xC3, 0x33, 0xBC, 0x77, 0x77, 0xF7, 0x3F,
              0x00, 0x00, 0x4D, 0x1F, 0x00, 0x00, 0x00, 0xCD,
              0x3C, 0xF0, 0xFF, 0x04 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00 },
            0x22,
            0x57,
            0x3B,
            { 0, 1 },
            8,
            { 0x00, 0xFE, 0x00, 0x00 },
            0xFA,
            { JTAG_EOM }
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF1,0xDF,0x3C,0xB9,0xE8 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE8 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x43,0xC6,0x33,0xDF,0xF7,0x3F,0xF7,0x3F,0x00,0x00,0x4D,0x1F,0x37,0x37,0x00,0xFF,0xFF,0xFF,0xFF,0x07 }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x43,0xC6,0x33,0xD8,0xF7,0x3F,0xF7,0x3F,0x00,0x00,0x4D,0x0F,0x36,0x36,0x00,0xC9,0x3C,0xF0,0xFF,0x04 }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0x3B,			// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0xFE00),		// ulBootAddress
	    fill_b2(0xFA),		// uiUpperExtIOLoc
	    fill_b4(0x20000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x20000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    1,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA164
    {
        "atmega164",
        0x9409,
        128, 128,    // 16K flash
        4,   128,    // 512 bytes EEPROM
        28 * 4,      // 28 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x0F,0xE0,0xF8,0xFF,0x3D,0xB9,0xE8 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x0D,0x00,0xE0,0xFF,0x1D,0xB8,0xE8 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xFB,0x9,0xDF,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x3F,0x37 }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xFB,0x9,0xD8,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x2F,0x36 }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x7E00),	/* ? */	// ulBootAddress
	    fill_b2(0xC6),		// uiUpperExtIOLoc
	    fill_b4(0x4000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x4000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA324
    {
        "atmega324",
        0x9509,
        256, 128,    // 32K flash
        4,   256,    // 1K bytes EEPROM
        28 * 4,      // 28 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x0F,0xE0,0xF8,0xFF,0x3D,0xB9,0xE8 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x0D,0x00,0xE0,0xFF,0x1D,0xB8,0xE8 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xFB,0x9,0xDF,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x3F,0x37 }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xFB,0x9,0xD8,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x2F,0x36 }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x7E00),	/* ? */	// ulBootAddress
	    fill_b2(0xC6),		// uiUpperExtIOLoc
	    fill_b4(0x8000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x8000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA644
    {
        "atmega644",
        0x9609,
        256, 256,    // 64K flash
        8,   256,    // 2K bytes EEPROM
        28 * 4,      // 28 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0x0F,0xE0,0xF8,0xFF,0x3D,0xB9,0xE8 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x0D,0x00,0xE0,0xFF,0x1D,0xB8,0xE8 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xFB,0x9,0xDF,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x3F,0x37 }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xFB,0x9,0xD8,0xF7,0xF,0x0,0x0,0x0,0x0,0x5F,0x2F,0x36 }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0x7E00),		// ulBootAddress
	    fill_b2(0xC6),		// uiUpperExtIOLoc
	    fill_b4(0x10000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x10000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0,				// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0,				// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA329
    {
        "atmega329",
        0x9503,
        128, 256,    // 32K flash
        4,   256,    // 1K bytes EEPROM
        23 * 4,      // 23 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF0,0xDF,0x3C,0xB9,0xE0 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE0 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xDA,0x01,0xDF,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x07,0x37,0x00,0x00,0x00,0xF0,0xF0,0xDE,0x7B }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xDA,0x01,0xD8,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x05,0x36,0x00,0x00,0x00,0xE0,0xF0,0xDE,0x7B }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x3F00),		// ulBootAddress
	    fill_b2(0xFE),		// uiUpperExtIOLoc
	    fill_b4(0x8000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x8000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0x40,			// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0x40,			// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA3290
    {
        "atmega3290",
        0x9504,
        128, 256,    // 32K flash
        4,   256,    // 1K bytes EEPROM
        25 * 4,      // 25 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF0,0xDF,0x3C,0xB9,0xE0 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE0 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xFA,0x09,0xDF,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x07,0x37,0x00,0x00,0x3F,0xF0,0xF0,0xFF,0xFF }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xFA,0x09,0xD8,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x05,0x36,0x00,0x00,0x3F,0xE0,0xF0,0xFF,0xFF }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(128),		// uiFlashPageSize
	    4,				// ucEepromPageSize
	    fill_b4(0x3F00),		// ulBootAddress
	    fill_b2(0xFE),		// uiUpperExtIOLoc
	    fill_b4(0x8000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x8000 / 128),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0x40,			// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0x40,			// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA649
    {
        "atmega649",
        0x9603,
        256, 256,    // 64K flash
        8,   256,    // 2K bytes EEPROM
        23 * 4,      // 23 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF0,0xDF,0x3C,0xB9,0xE0 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE0 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xDA,0x01,0xDF,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x07,0x37,0x00,0x00,0x00,0xF0,0xF0,0xDE,0x7B }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xDA,0x01,0xD8,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x05,0x36,0x00,0x00,0x00,0xE0,0xF0,0xDE,0x7B }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0x7E00),		// ulBootAddress
	    fill_b2(0xFE),		// uiUpperExtIOLoc
	    fill_b4(0x10000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x10000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0x40,			// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0x40,			// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // DEV_ATMEGA6490
    {
        "atmega6490",
        0x9604,
        256, 256,    // 64K flash
        8,   256,    // 2K bytes EEPROM
        25 * 4,      // 25 interrupt vectors
	DEVFL_MKII_ONLY,
        NULL,			// not yet defined
        {
	  0			// no mkI support
        },
	{
	    CMND_SET_DEVICE_DESCRIPTOR,
	    { 0xFF,0xFF,0xFF,0xF0,0xDF,0x3C,0xB9,0xE0 }, // ucReadIO
	    { 0 },			// ucReadIOShadow
	    { 0xB6,0x6D,0x1B,0xE0,0xDF,0x1C,0xB8,0xE0 }, // ucWriteIO
	    { 0 },			// ucWriteIOShadow
	    { 0x53,0xFA,0x09,0xDF,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x07,0x37,0x00,0x00,0x3F,0xF0,0xF0,0xFF,0xFF }, // ucReadExtIO
	    { 0 },			// ucReadIOExtShadow
	    { 0x53,0xFA,0x09,0xD8,0xF7,0x0F,0x00,0x00,0x00,0x00,0x4D,0x05,0x36,0x00,0x00,0x3F,0xE0,0xF0,0xFF,0xFF }, // ucWriteExtIO
	    { 0 },			// ucWriteIOExtShadow
	    0x31,			// ucIDRAddress
	    0x57,			// ucSPMCRAddress
	    0,				// ucRAMPZAddress
	    fill_b2(256),		// uiFlashPageSize
	    8,				// ucEepromPageSize
	    fill_b4(0x7E00),		// ulBootAddress
	    fill_b2(0xFE),		// uiUpperExtIOLoc
	    fill_b4(0x10000),		// ulFlashSize
	    { 0 },			// ucEepromInst
	    { 0 },			// ucFlashInst
	    0x3e,			// ucSPHaddr
	    0x3d,			// ucSPLaddr
	    fill_b2(0x10000 / 256),	// uiFlashpages
	    0,				// ucDWDRAddress
	    0x40,			// ucDWBasePC
	    0,				// ucAllowFullPageBitstream
	    fill_b2(0),			// uiStartSmallestBootLoaderSection
	    1,				// EnablePageProgramming
	    0,				// ucCacheType
	    fill_b2(0x100),		// uiSramStartAddr
	    0,				// ucResetType
	    0,				// ucPCMaskExtended
	    0x40,			// ucPCMaskHigh
	    0,				// ucEindAddress
	    fill_b2(0x3f),		// EECRAddress
	},
    },
    // Termination record.
    { 
        NULL,                   // name
        0,                      // id
        0, 0,                   // flash
        0, 0,                   // eeprom
        0,                      // interrupt vectors
	DEVFL_NONE,		// device flags
        NULL,                   // io reg defs
        { 0 },                  // mkI device descriptor information
	{ 0 }                   // mkII device descriptor
    }
};


