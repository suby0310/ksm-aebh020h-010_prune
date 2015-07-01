/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   control interface driver for C8051F380 based module
   FILE: si468x_bus.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/
#include "platform_options.h"

#include "typedefs.h"
#include "sys.h"
#include "delay.h"
#include "si468x_bus.h"
#include "LCD.h"


#define WAIT 2
/************************************************************************

*************************************************************************/
void si468x_reset(void)
{
	si468x_RST = 0;
	wait_ms(100);
	si468x_RST = 1;
	wait_ms(200);
}

void si468x_disable(void)
{
   	si468x_RST = 0;
}

/************************************************************************

*************************************************************************/
#ifdef OPTION__MCU_HARDWARE_SPI
#define SPI_CLOCK	0
void spi0_init(void)
{
	SPI3CR=0
		|(1<<7)		// spien 
		|(0<<6)		// 0:MSB first, 1:LSB first
		|(1<<5)		// 0:slave, 1:master
		|(0<<4)		// pol
		|(0<<3)		// pha
		|(1<<0)		// closk setting
		;
		
	SPI3SR=0
		|(0<<3)		//0:No effect, 1: Exchange MOSI2 and MISO2 function
		|(1<<2)		// ssena 
		;
}
/************************************************************************
*************************************************************************/
void si468x_write(u8 in_data)
{
	u8 ret;

	SPI3DR = in_data;	
	
	while(!(SPI3SR&0x80));
	
	ret = SPI3DR;
}
/************************************************************************
*************************************************************************/
u8 si468x_read(void)
{
	SPI3DR = 0xFF;
	
	while(!(SPI3SR&0x80));
	
	return SPI3DR;
}
#endif //OPTION__MCU_HARDWARE_SPI
/************************************************************************

*************************************************************************/
#ifndef OPTION__MCU_HARDWARE_SPI
void si468x_write(u8 in_data)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		si468x_SCLK = 0;
		NOP();
		si468x_MOSI = !!(0x80 & in_data);
		NOP();
		si468x_SCLK = 1;
		in_data <<=1;
	}
}
/************************************************************************

*************************************************************************/
u8 si468x_read(void)
{
	u8 i;
	u8 out_data;
	out_data = 0;
	for(i=0;i<8;i++)
	{
		out_data <<=1;
		si468x_SCLK = 0;
		NOP();
		si468x_SCLK = 1;
		NOP();
		out_data |= si468x_MISO;
		NOP();	
	}
	return out_data;
}
#endif //undef OPTION__MCU_HARDWARE_SPI

/************************************************************************

*************************************************************************/
void si468x_writeCommand (u16 len,u8* buffer)
{	
	u16 i;
	i = 0;
	si468x_SSB = 0;
	while(len--)
	{
		si468x_write(buffer[i++]);
	}
	si468x_SSB = 1;	
}
/************************************************************************

*************************************************************************/
void si468x_readReply (u16 len,u8* buffer)
{
	u16 i;
	i = 0;
	si468x_SSB = 1;
	wait_us(20);
	si468x_SSB = 0;
	si468x_write(0x00);
	while(len--)
	{
		buffer[i++]=si468x_read();
	}	
	si468x_SSB = 1;
}
