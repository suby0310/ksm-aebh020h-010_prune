/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Compile options for the overall SDK project
   FILE: platform_options.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/



#ifndef __PLATFORM_OPTIONS__
#define __PLATFORM_OPTIONS__

#include "platform_selector.h"

//#define OPTION__IMAGETYPE__DAB_FM_AM
#define OPTION__IMAGETYPE__DAB_FM
//#define OPTION__IMAGETYPE__FMHD_AMHD
//#define OPTION__IMAGETYPE__FMHD
#define OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
#define OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
#define OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
#define OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
#define OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
#define OPTION__BOOT_FROM_FLASH_MINI
//#define OPTION__INCLUDE_POWER_SAVING_MODE
//#define OPTION__BOOT_FROM_FLASH_FULL
#define OPTION__AUDIO_ANALOG_ENABLE
//#define OPTION__AUDIO_I2S_ENABLE
//****************************************************
    // Set Master or Slave (Master 1, Slave 0)
    #define OPTION__AUDIO_I2S__MASTER_SLAVE 0
    //Set Sample Rate (32000 - 48000)
    #define OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ 48000
    //Set Sample Size (2 - 24)
    #define OPTION__AUDIO_I2S__SAMPLE_SIZE 16
    //Set Framing Format (I2S 0, DSP 6, Left Justified DSP 7, Left Justified 8, Right Justified 9)
    #define OPTION__AUDIO_I2S__FRAMING_FORMAT 0
//****************************************************
//#define OPTION__INTB_ENABLE
#define OPTION__SMALL_SPI_BUFFER
#define OPTION__MCU_PLATFORM
#define OPTION__32BIT_IS_LONG
#define OPTION__CONVERT_BIG_ENDIAN
#define OPTION__RDS_DECODE_ADVANCED
#define OPTION__DECODE_SIS
#define OPTION__DECODE_PSD
#define OPTION__DECODE_HD_ALERTS
#define OPTION__DECODE_DLS
#define OPTION__FORCE_MEMORY_SPACES
#define OPTION__DECODE_FMHD_SERVICE_LIST
#define OPTION__DECODE_DAB_SERVICE_LIST
#define OPTION__SERVICE_LIST_SMALL
#define OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS 3000         //The total time to allow for DAB Tune before Timeout
#define OPTION__DAB_SERVICE_LIST_SCVLIST_MS 5000              //The total time to allow for DAB Service List Update before timeout
#define OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS 100  //The amount of time between dab bandscan callbacks to the MMI

#define OPTION__DAB_SERVICE_START_TIMEOUT_MS 1200              //The total time to allow for DAB Service Start before Timeout
#define OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS 20          //The amount of time between attempting to start a service

#define OPTION__FM_TIMEOUT_SEEK_MS 30000
#define OPTION__FM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

#define OPTION__AM_TIMEOUT_SEEK_MS 30000
#define OPTION__AM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

//#define OPTION__DAB_SUPPORT_DAB_DAB_LINKING
//#define OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
#define OPTION__DAB_SERVICE_LIST_PERSISTENCE
#define OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD 20
#define OPTION__AMHD_SEEK_HDLEVEL_THRESHOLD 35//the HD LEVEL undulate of AM is greater than FMHD
#define OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER 0x20
//#define OPTION__OPERATE_AS_SLAVE_NO_MMI
//#define OPTION__ADVANCED_METRICS
#define OPTION__MCU_HARDWARE_SPI
//#define OPTION__DAB_PRESETS_AS_FAVORITES
//#define OPTION__FM_SHOW_STATION_NAME_PST
//#define OPTION__TIME_SETTING
#define OPTION__MENU_SETTING
//#define OPTION__RADIODNS
//#define OPTION__NVMSPI_RATE_MHZ 40
#define OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD 6
#define OPTION__DAB_VALID_FAST_DETECT_TIME_MS 35
#define OPTION__DAB_VALID_SYNC_TIME_MS 1200
#define OPTION__DAB_VALID_ACQ_TIME_MS 2000
#define	OPTION__DAB_FUNCTION_PRUNE		// Should Be Improved

#ifdef OPTION__IMAGETYPE__FM
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
    #undef OPTION__INCLUDE_MODE__AMHD
    #undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
#endif
#ifdef OPTION__IMAGETYPE__DAB_FM
    #define OPTION__INCLUDE_MODE__FM
    #define OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
	#undef OPTION__INCLUDE_MODE__AMHD
	#undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
#endif

#ifdef OPTION__IMAGETYPE__DAB_FM_AM
	#define OPTION__INCLUDE_MODE__FM
	#define OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
    #undef OPTION__INCLUDE_MODE__AMHD
	#define OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
	#undef OPTION__MENU_SETTING
#endif

#ifdef OPTION__IMAGETYPE__FMHD
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #define OPTION__INCLUDE_MODE__FMHD
	#undef OPTION__INCLUDE_MODE__AMHD
	#undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
#endif

#ifdef OPTION__IMAGETYPE__FMHD_AMHD
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #define OPTION__INCLUDE_MODE__FMHD
	#define OPTION__INCLUDE_MODE__AMHD
	#define OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
#endif


#ifdef OPTION__IMAGETYPE__ALL
    #define OPTION__INCLUDE_MODE__FM
    #define OPTION__INCLUDE_MODE__FMHD
    #define OPTION__INCLUDE_MODE__DAB
	#define OPTION__INCLUDE_MODE__AM
	#define OPTION__INCLUDE_MODE__AMHD
    #define OPTION__INCLUDE_MODE__ANY
#endif

#endif
