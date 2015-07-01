/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for mcu initialization drivers for C8051F380 based module
   FILE: sys.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _sys_h_
#define _sys_h_

#include "platform_options.h"

#include "MC97F2664.h"

#include "typedefs.h"

void Init_Device(void);
void Timer3_Init_lowpower(void);
void Timer3_Init_buzzer(void);
void Port_IO_lowpower_Init(void);

		/*****************************LCD ***********************/

		#define LCD_SDA			P24
		#define LCD_SCL			P25
//		sbit LCD_RW = P3^1;

		#define LCD_CS			P06

//		#define MUTE LCD_RW

		#define LCD_RS			P05
		#define DISP_BKLIGHT	P04

		/***********************************************************/

		/********************KEY************************************/

		#define VOLUME_B		P15
		#define VOLUME_A		P14

		#define si468x_RST		P44

		#define SYS_ON			P26

#ifdef SPI_BUS_CORRECTED
		#define si468x_SCLK		P72
		#define si468x_MISO		P71
		#define si468x_MOSI		P70
		#define si468x_SSB		P73
#endif //SPI_BUS_CORRECTED
		#define si4680_INTB		P45
#endif
