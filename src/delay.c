/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   delay driver for C8051F380 based module
   FILE: delay.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "platform_options.h"

#include "Sys.h"

#include "typedefs.h"
#include "delay.h"

#if 0
void Delay(void)
{
        volatile int x;
        for(x = 0;x < 500;x)
                x++;	
}
#endif
//-----------------------------------------------------------------------------
// Delay routine based on hardware timer
//
// Inputs:
//              Delay in microseconds
//
//-----------------------------------------------------------------------------
void wait_us(u16 us)
{
		u16 j;

		j = 8*us - 1;
		T6ADRH = j >> 8;  	// period count High
		T6ADRL = j;  	// period count Low
		TIFLAG1 &= ~0x01;	// clear T6 match	
		T6CRH |= 0x80;  	// start 4
		while ( !(TIFLAG1 & 0x01));		
		TIFLAG1 &= ~0x01;	// clear T6 match
		T6CRH = 0x00;
}

//-----------------------------------------------------------------------------
// delay routine for long delays
//
// Inputs:
//              Delay in milliseconds
//
//-----------------------------------------------------------------------------
void wait_ms(u16 ms)
{
        int i;

        for (i=0; i<ms; i++)
        {
                wait_us(1000);
        }
}