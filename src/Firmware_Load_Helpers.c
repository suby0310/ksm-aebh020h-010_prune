/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   si468x firmware loading drivers for C8051F380 based module
   FILE: Firmware_Load_Helpers.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/
#include "common_types.h"
#include "si46xx_firmware_api.h"
#include "Firmware_Load_Helpers.h"
#include "platform_options.h"

RADIO_MODE_TYPE currentMode = UNKNOWN;

#ifdef OPTION__MCU_PLATFORM

#ifdef OPTION__BOOT_FROM_FLASH_FULL
    #include "si46xx_rom00_full_patch.h"
#endif

#ifdef OPTION__BOOT_FROM_FLASH_MINI
    #include "si46xx_rom00_mini_patch.h"
#endif //OPTION__BOOT_FROM_FLASH_MINI

uint16_t numBytesSent;


RETURN_CODE firmwareSetImage(RADIO_MODE_TYPE mode)
{
	currentMode = mode;
    numBytesSent = 0;
	return SUCCESS;
}

uint16_t firmwareGetSegment(uint16_t requestedLength, uint8_t** firmwareSegment)
{
    uint16_t remainingLength;
    uint16_t totalLength;

    #ifdef OPTION__BOOT_FROM_FLASH_FULL
        totalLength = FULLPATCH_LENGTH;
    #endif
    #ifdef OPTION__BOOT_FROM_FLASH_MINI
        totalLength = MINIPATCH_LENGTH;
    #endif

    if(numBytesSent >= totalLength)
    {
        return 0;
    }
	
    #ifdef OPTION__BOOT_FROM_FLASH_FULL
        *firmwareSegment = &fullpatch[numBytesSent];
    #endif
    #ifdef OPTION__BOOT_FROM_FLASH_MINI
        *firmwareSegment = &minipatch[numBytesSent];
    #endif

    if((totalLength - numBytesSent) > FIRMWARE_SEGMENT_MAX_LENGTH)
    {
        if(FIRMWARE_SEGMENT_MAX_LENGTH > requestedLength)
        {
            numBytesSent += requestedLength;
            return requestedLength;
        }
        else
        {
            numBytesSent += FIRMWARE_SEGMENT_MAX_LENGTH;
            return FIRMWARE_SEGMENT_MAX_LENGTH;
        }
    }
    else
    {
        remainingLength = (totalLength - numBytesSent);
        if(remainingLength > requestedLength)
        {
            numBytesSent += requestedLength;
            return requestedLength;
        }
        else
        {
            numBytesSent += remainingLength;
            return remainingLength;
        }
    }
}


//========================================================================
//                   Size   Start
//   Index Size      Max.   Address   Attrib.      CRC32   file name
//========================================================================
//    0     5796     8192 0x00002000 0x00000000 0x296E0CF1 rom00_patch.016.bin
//    1     4128     8192 0x00004000 0x00000000 0xFF2A4716 rom00_patch.009.bin
//    2   489692   524288 0x00006000 0x00000000 0x9B62E4F2 fmhd_radio.3.0.5.bin
//    3   511468   524288 0x00086000 0x00000000 0x2EE2BD94 dab_radio.1.0.6.bin
//========================================================================
#define addr_PATCH_016  0x00002000
#define addr_PATCH_009  0x00004000
#define addr_HD         0x00006000
#define addr_DAB        0x00086000
#define addr_AMHD		0x00106000

#define addr_DMB 0 //No longer included in module boot image

//at first time flashed .the flash need to flash Patch16 by mcu.then the will support the USB flash 
RETURN_CODE firmwareGetFlashAddress(uint32_t* addr)
{
	switch(currentMode)
	{
		case patch_fmhd:
                *addr = addr_PATCH_016;
            break;
        case patch_dmb:
                *addr = addr_PATCH_009;
            break;
        case patch_dab:
                *addr = addr_PATCH_016;
			break;
		case patch_am:
		         *addr = addr_PATCH_016;
			break;
		case patch_amhd:
		         *addr = addr_PATCH_016;
			break;
        case patch_firmware_update:
                *addr = addr_PATCH_016;
			break;
		case fmonly:
		case fmhd:
				*addr = addr_HD;
			break;
		case dab:
				*addr = addr_DAB;
			break;
		case dmb:
				*addr = addr_DMB;
			break;
		case am:
		case amhd:
				*addr = addr_AMHD;
				break;
		default:
			return INVALID_INPUT;
			break;
	}

	return SUCCESS;
}
#endif
