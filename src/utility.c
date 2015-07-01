/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   misc utilities for C8051F380 based module
   FILE: utility.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/
#include "platform_options.h"

#include "Sys.h"
#include "typedefs.h"
#include "utility.h"


#define coderom  ((unsigned char volatile code  *) 0)
#define pagebuff ((unsigned char volatile xdata  *) 0x8000)

unsigned char flashCount;
unsigned int flashAddress;

//-------------------------
// Flash functions
//-------------------------
void flash_page_erase(unsigned int address)
{
	u8 i = 0;

	FMCR=0x01; // page buffer clear
	
	for(i=0; i<64; i++)
	{
		pagebuff[i]=0x00;			
	}

	FSADRL = (unsigned char)(address);
	FSADRM = (unsigned char)(address>>8);
	FSADRH = 0x00;
	
	FIDR = 0xA5; //dentification value
	FMCR = 0x02; //Start flash erase mode
	_nop_();
	_nop_();
	_nop_();		
}

void flash_write(unsigned int address, unsigned char data1, unsigned char end)
{
	if(flashCount == 0)	
	{
		FMCR=0x01; // page buffer clear		
		flashAddress = address;
	}

	pagebuff[flashCount++]=data1;

	if(end) 
	{
		flashCount = 64;
	}

	if(flashCount < 64) 
	{
		return;
	}

	flashCount = 0;

	FSADRL = (unsigned char)(flashAddress);
	FSADRM = (unsigned char)(flashAddress>>8);
	FSADRH = 0x00;
	
	FIDR = 0xA5; //dentification value
	FMCR = 0x03; //Start sector write
	_nop_();
	_nop_();
	_nop_();	
}
 
unsigned char flash_read(unsigned int address)
{
	return coderom[address];
}
