/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   mcu initialization drivers for C8051F380 based module
   FILE: sys.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/
#include "platform_options.h"

#include "typedefs.h"

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	#define OPTION__UART_DRIVER
#endif

#ifdef ATS_EMBED_CODE
	#define OPTION__UART_DRIVER
#endif

#include "delay.h"
#include "sys.h"
#include "LCD.h"
#include "key.h"
#include "si468x_bus.h"
#include "main.h"
#include "uart.h"
#include "mode_common.h"
/*****************************************************************************\
Sysclk_Init()
Description: Initialize the system and USB clock.
Inputs: None
Outputs: None
\*****************************************************************************/
void Sysclk_Init(void)
{	
	u16 i;
	// internal RC clock (8.000000MHz)
	OSCCR=0	//Oscillator Control Register
		|(4<<3)	//0:int_0_5Mhz, 1:int_1Mhz, 2:int_2Mhz, 3:int_4Mhz, 4:int_8Mhz, 5:int_16Mhz 
		|(0<<2)	//0:int_osc enable, 1:int_osc disable
		|(0<<1)	//0:main_osc disable, 1:main_osc enable
		|(1<<0)	//0:sub_osc disable, 1:sub_osc enable
		;
#if 0
	// need sub stable time about 1Sec
	for (i=0;i<10;i++)
	{
		BITCR=(1<<3)|(7<<0);	// BIT counter clear!!
		while((BITCR&0x80)==0);	// BIT ¾ÈÁ¤È­ 128ms wait time @ int_osc 8Mhz
	}
	BITCR=(1<<3)|(4<<0);	// BIT counter clear!!	128ms --> 16ms BIT
#endif	

	T6CRH = 0x00;   	// timer setting High
	T6CRL = 0xC1;   	// timer setting Low

}

void WT_init()
{
	t500msec = 0; 
	
	WTCR=0
		|(1<<5)	// enable WTIE
		|(2<<2) // 2^14
		|(0<<0) // fsub
		;

	IE3|=(0x04); // wt interrupt
	WTCR|=(1<<7); // wt enable
}

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
void INT_WT_SP() interrupt 20
{
	if (WTCR&0x10)
	{
		WTCR&=~0x10; // clear flag

		t500msec++;
		if(t500msec%2 == 0)
			time_sec_flag = 1;
	}
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/************************************************************************
timer3 use external crystal 32768/8=4096 as timer3 source 
1/32768/8 = 244us 244us*50 = 12.2ms ADC window conversion period
for ADC window detect for Button scan when in idle mode
**************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#ifdef C8051F380_MCU
void Timer3_Init_lowpower(void)
{
    TMR3CN    = 0x01;
    TMR3RLL   = 0xCD;
    TMR3RLH   = 0xFF;
    TMR3L     = 0xCD;
    TMR3H     = 0xFF;
	TMR3CN   |= 0x04;
    EIE1   &= ~0x80;
}

/*******************************************************************************
sysclk/12 = 2MHZ ~=500ns
********************************************************************************/
#define BUZZER_INTERVALU_COUNT_VALUE	500 //(0.1*60000)

void Timer3_Init_buzzer(void)
{
    TMR3CN    = 0x04;
    TMR3RLL   = (65535-400);
    TMR3RLH   = (65535-400)>>8;
    TMR3L     = (65535-400);
    TMR3H     = (65535-400)>>8;

	EIE1      |= 0x80;

 	buzzer_on_flag = 1 ;
 	buzzer_interval_count = BUZZER_INTERVALU_COUNT_VALUE;
}
/**********************************************************************************
wave : __---__---__---_______interval ct1/2_____________---__---__--__________________
the wave frequency is 2K____
***********************************************************************************/
void Timer3_isr(void) interrupt INTERRUPT_TIMER3
{
	TMR3CN = 0x04;

	if(buzzer_interval_count >0)
	{	
		buzzer_interval_count --;
	}
	else
	{
		buzzer_on_flag ^=1;
		buzzer_interval_count = BUZZER_INTERVALU_COUNT_VALUE;
	}	
	if(buzzer_on_flag)
	{
		ALARM_BUZZER_PIN ^=1;
	}
	else
	{
		ALARM_BUZZER_PIN = 0;
	}
}
#endif
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************
*********************************************************************/
// Peripheral specific initialization functions,
// Called from the Init_Device() function
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
#ifdef C8051F380_MCU
void Port_IO_lowpower_Init()
{

	P0 = 0x00;
	P0MDIN = 0X00;
	P0MDOUT = 0X00;

	P1 = 0x00;
	P1MDIN = 0x00;
	P1MDOUT = 0x00;

	P2 = 0x00;
	P2MDIN = 0x00;
	P2MDOUT = 0x00;

	P3 = 0x00;
	P3MDIN = 0x00;
	P3MDOUT = 0x00;


	P3 = 0x00;
	P3MDIN = 0x00;
	P3MDOUT = 0x00;


	P4 = 0x00;
	P4MDIN = 0x00;
	P4MDOUT = 0x00;

/*
	P4 = 0x00;
	P4MDIN = 0x00;
    P4MDOUT   = 0x18;
*/

    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    P3SKIP    = 0xFF;

	XBR0      = 0x10;//enable compratator
	XBR1	  = 0xc0 ;
	XBR2      = 0;

//   POLL_WRITE_BYTE(POWER,  0x08);   // Force Asynchronous USB Reset

//	REN0 = 0;//enable receive interrupt
//	ES0 = 0;                            // Enable UART0 interrupt
//CLKMUL = 0;

}
#endif
#endif
void Port_IO_Init()
{
	// init port assign

//	LVRCR=1; // LVR disable

	P0FSR=0
		|(0<<7)	// 0:I/O port P07, 1:AN14
		|(0<<6) // 0:I/O port P06, 1:AN13
		|(0<<5) // 0:I/O port P05, 1:AN12
		|(0<<4) // 0:I/O port P04, 1:AN11
		|(0<<3) // 0:I/O port P03, 1:AN10
		|(0<<2) // 0:I/O port P02, 1:AN9
		|(0<<1) // 0:I/O port P01, 1:AN8
		|(0<<0) // 0:I/O port P00, 1:AVREF
		;
	P0IO=_1111_1111;  // direction       0:input, 1:output
	P0PU=_0111_0000;  // pullup on/off   0:off,   1:on
	P0OD=_0000_0000;  // open drain      0:off,   1:on
	P0  =_0000_0000;  // port            0:'0',   1:'1'
/////////////////////////////////////////////////////////////
	P1FSR=0
		|(1<<7)	// 0:I/O port P17, 1:AN7
		|(0<<6) // 0:I/O port P16, 1:AN6
		|(0<<5) // 0:I/O port P15, 1:AN5
		|(0<<4) // 0:I/O port P14, 1:AN4
		|(0<<3) // 0:I/O port P13, 1:AN3
		|(0<<2) // 0:I/O port P12, 1:AN2
		|(1<<1) // 0:I/O port P11, 1:AN1
		|(1<<0) // 0:I/O port P10, 1:AN0
		;
	P1IO=_0100_1100;  // direction       0:input, 1:output
	P1PU=_0011_0000;  // pullup on/off   0:off,   1:on
	P1OD=_0000_0000;  // open drain      0:off,   1:on
	P1DB=_0000_0000;  // debounce        0:off,   1:on
	P1  =_0000_0000;  // port            0:'0',   1:'1'	
/////////////////////////////////////////////////////////////
	P2FSR=0
		|(1<<3) // 0:I/O port P23, 1:TXD4
		|(0<<2) // 0:I/O port P22, 1:T9O/PWM9O
		|(0<<1) // 0:I/O port P21, 1:T8O/PWM8O
		|(0<<0) // 0:I/O port P20, 1:T7O/PWM7O
		;
	P2IO=_1111_1111;  // direction       0:input, 1:output
	P2PU=_0111_0000;  // pullup on/off   0:off,   1:on
	P2OD=_0000_0000;  // open drain      0:off,   1:on
	P2DB=_0000_0000;  // debounce        0:off,   1:on
	P2  =_0011_0000;  // port            0:'0',   1:'1'	
/////////////////////////////////////////////////////////////
	P3FSR=0
		|(0<<7)	// 0:I/O port P36, 1:SCK2
		|(0<<6) // 0:I/O port P35, 1:MISO2
		|(0<<5) // 0:I/O port P34, 1:MOSI2
		|(0<<3) // 0:I/O port P33, 1:BUZO, 2:EC6, 3: Not used
		|(0<<2) // 0:I/O port P32, 1:T6O/PWM6O
		|(0<<1) // 0:I/O port P31, 1:T5O/PWM5O
		|(0<<0) // 0:I/O port P30, 1:T4O/PWM4O
		;
	P3IO =_1111_1111;  // direction       0:input, 1:output
	P3PU =_0000_0000;  // pullup on/off   0:off,   1:on
	P3OD =_0000_0000;  // open drain      0:off,   1:on
	P35DB=_0000_0000;  // debounce        0:off,   1:on
	P3   =_0000_0000;  // port            0:'0',   1:'1'
/////////////////////////////////////////////////////////////
	P4FSR=0
		|(0<<4) // 0:I/O port P46, 1:TXD3
		|(0<<3) // 0:I/O port P44, 1:TXD2
		|(0<<2) // 0:I/O port P42, 1:SCK1
		|(1<<1) // 0:I/O port P41, 1:RXD1/SCL1/MISO1
		|(1<<0) // 0:I/O port P40, 1:TXD1/SA1/MOSI1
		;
	P4IO=_1111_1100;  // direction       0:input, 1:output
	P4PU=_1111_0000;  // pullup on/off   0:off,   1:on
	P4OD=_0000_0000;  // open drain      0:off,   1:on
	P4  =_1111_0000;  // port            0:'0',   1:'1'
/////////////////////////////////////////////////////////////
	P5FSR=0
		|(0<<3) // 0:I/O port P53, 1:T3O/PWM3O
		|(0<<2) // 0:I/O port P52, 1:T2O/PWM2O
		|(0<<1) // 0:I/O port P51, 1:T1O/PWM1O
		|(0<<0) // 0:I/O port P50, 1:T0O/PWM0O
		;
	P5IO=_0111_1111;  // direction       0:input, 1:output
	P5PU=_1000_0000;  // pullup on/off   0:off,   1:on
	P5OD=_0000_0000;  // open drain      0:off,   1:on
	P5  =_0000_0000;  // port            0:'0',   1:'1'
/////////////////////////////////////////////////////////////
	P6FSR=0
		|(1<<6) // 0:I/O port P67, 1:SXOUT
		|(1<<5) // 0:I/O port P66, 1:SXIN
		|(0<<4) // 0:I/O port P65, 1:XIN
		|(0<<3) // 0:I/O port P64, 1:XOUT
		|(0<<2) // 0:I/O port P63, 1:TXD0/SDA0/MOSI0
		|(0<<1) // 0:I/O port P62, 1:RXD0/SCL0/MISO0
		|(0<<0) // 0:I/O port P61, 1:SCK0
		;
	P6IO=_1111_1111;  // direction       0:input, 1:output
	P6PU=_0000_0000;  // pullup on/off   0:off,   1:on
	P6OD=_0000_0000;  // open drain      0:off,   1:on
	P6  =_0000_0000;  // port            0:'0',   1:'1'	
/////////////////////////////////////////////////////////////
	P7FSR=0
		|(0<<3) // 0:I/O port P73, 1:EC6
		|(1<<2) // 0:I/O port P72, 1:SCK3
		|(1<<1) // 0:I/O port P71, 1:MISO3
		|(1<<0) // 0:I/O port P70, 1:MOSI3
		;
	P7IO=_1111_1111;  // direction       0:input, 1:output
	P7PU=_0000_0000;  // pullup on/off   0:off,   1:on
	P7OD=_0000_0000;  // open drain      0:off,   1:on
	P7  =_0000_0000;  // port            0:'0',   1:'1'
}

/********************************************************************************
system init include port clock 
*********************************************************************************/
void Init_Device(void)
{
	if(power_flag == 1)
	{
		return;
	}
	
	cli();          	// disable INT. during peripheral setting

    Port_IO_Init();
	
    Sysclk_Init();                            // Initialize oscillator

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	key_init();
	LCD_init();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__MCU_HARDWARE_SPI
	spi0_init();
#endif

	Timer2_init();

#ifdef OPTION__UART_DRIVER
	uart0_init();
#endif

	WT_init();      	// initialize Watch timer

	SYS_ON = 1;
//	MUTE = 0;

	sei();          	// enable INT.
}
