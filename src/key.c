/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   keypad driver for C8051F380 based module
   FILE: key.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "platform_options.h"

#include "typedefs.h"

#include "sys.h"
#include "key.h"
#include "main.h"
#include "delay.h"
#include "mode_common.h"
/************************************************************************/
//timer2 interrupt as key scan clock 4ms
/************************************************************************/
void Timer2_init(void)
{
	// initialize Timer0~3
	
	// 8bit timer2, period = 2.000000mS
	T2CR = 0x09;    	// timer setting
	T2DR = 0x7C;    	// period count
	
	TINTCR = 0x40;  	// interrupt enable setting
	IE2 |= 0x20;    	// Enable Timer interrupt
	
	T2CR |= 0x80;   	// enable counter 2
}

void INT_Timer0_3() interrupt 17
{
	if (TIFLAG0 & 0x10) 
	{
		TIFLAG0 &= ~0x10;	// clear T2 match

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

		switch(volume_status)
		{
			case 0:
				if(VOLUME_A!=VOLUME_B) //10 /01
				{
					VA_old = VOLUME_A;
					VB_old = VOLUME_B;
					volume_status++;
				}
				break;
			case 1:
				if(VOLUME_A == 0&&VOLUME_B == 0)//11
				{
					volume_status++;
				}
				break;
			case 2:
				if(VOLUME_A == 1&& VOLUME_B == 1) //00
				{
					if(VA_old == 1)
					{
						//volume_value ++;
						key_value = VOLUME_DEC_KNOBS;
						key_flag = 1;
					}
					else if(VB_old == 1)
					{
						//volume_value --;
						key_value = VOLUME_INC_KNOBS;
						key_flag = 1;
					}
					volume_status = 0;
					knobs_flag = 1;
				}
				break;
			default:
				volume_status = 0;
				break;
		}
		if(select_item_flash_delay >0)
		{
			select_item_flash_delay --;
		}

#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

		if(display_delay_4ms>0)
		{
			display_delay_4ms --;
		}	
		if(display_item_str_4ms>0)
		{
			display_item_str_4ms --;
		}
	}

	if (TIFLAG0 & 0x40) TIFLAG0 &= ~0x40;	// clear T3 match
	if (TIFLAG0 & 0x04) TIFLAG0 &= ~0x04;	// clear T1 match
	if (TIFLAG0 & 0x01) TIFLAG0 &= ~0x01;	// clear T0 match
}
/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
void key_init(void)
{
	u8  i;

	// initialize A/D convertor
	ADCCRL = 0x80;  	// setting
	ADCCRH = 0x02;  	// trigger source, alignment, frequency

	for(i=0;i<2;i++)
	{
		key_vlaue_array[i] = 0x00FF;
	}

	key_down_flag = 0;
	key_up_flag = 0;
	key_value = 0xff;

	key_up_count = 0;
	key_down_count = 0;
	key_flag = 0;

	knobs_count = 0;
	knobs_press_flag = 0;
	temp_knobs = 0;
}
#endif //#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
#ifdef C8051F380_MCU
void key_comparator_init()
{
	u8 i = 0;
	/*
    CPT0CN    = 0x8F;
    for (i = 0; i < 35; i++);  // Wait 10us for initialization
    CPT0CN    &= ~0x30;
    CPT0MX    = 0x33;
    CPT0MD    = 0x30;
*/
	XBR0 |= 0x10;

    CPT0CN    = 0x8F;
    for (i = 0; i < 35; i++);  // Wait 10us for initialization
    CPT0CN    &= ~0x30;
    CPT0MX    = 0x33;
    CPT0MD    = 0x22;
    EIE1      |= 0x20;
}
#endif
#endif //OPTION__INCLUDE_POWER_SAVING_MODE
	
#endif
/**************************************************************************************************

**************************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
u16 ad_convertion(u8 pin_value)
{
	// read A/D convertor
//	unsigned int adcVal;

	// start A/D convertor
	ADCCRL = (ADCCRL & 0xf0) | (pin_value & 0x0f);	// select channel
	ADCCRL |= 0x40; 	// start ADC
	
	while(!(ADCCRL & 0x10));	// wait ADC busy
	return	ADCDRH;
}
#endif//#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI	
/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#define NO_KEY_VALUE_TH		0x0EF
code u8 KEY_PIN_ADDR[2]={0x01,0x00};
code u8 KEY_TABLE[16] = {	DOWN_KEY,		SELECT_KEY,	UP_KEY,			SEEK_DOWN_KEY,	
							CLOCK_KEY,	SEEK_UP_KEY,	HDSEEK_KEY,		BACK_LIGHT_KEY,
							PRESET_DEC_KEY ,ALARM_KEY,PRESET_INC_KEY,	DAB_RESCAN_KEY,
							MODE_KEY,		MENU_KEY,	ON_OFF_KEY,		SNOOZE_KEY};

void key_scan(void)
{
	u8 i;
	u16 ADC_Result_temp[2];
	
	switch(key_mode)
	{
		case KEY_UP_MODE:
			for(i=0;i<2;i++)
			{
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
				wait_us(5);
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

				if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
				{
					key_mode = KEY_DOWN_MODE;
					key_up_count = 0;
				}
			}
			key_down_count = 0;
			key_up_count ++;
			if(key_up_count >KEY_STABLE_VALID_TIME)
			{
				key_up_count = 0;
				key_up_flag = 1;
			}
			break;
		case KEY_DOWN_MODE:
			key_mode = KEY_UP_MODE;
			for(i=0;i<2;i++)
			{
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
				wait_us(5);
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

				if(ADC_Result_temp[i] <NO_KEY_VALUE_TH)
				{
					key_mode = KEY_DOWN_MODE;
					key_down_count ++;
					if(key_down_count >KEY_STABLE_VALID_TIME)
					{
						key_down_flag = 1;
						key_mode ++;
						key_vlaue_array[i] = ADC_Result_temp[i];
					}
				}
			}
			break;
		case KEY_WAIT_MODE://wait for down up or reach to the hold condition
			key_mode = KEY_UP_MODE;
			for(i=0;i<2;i++)
			{
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
				wait_us(5);
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

				if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
				{
					if(key_down_count >KEY_HOLD_VALID_TIME)
					{
						key_down_count = 0;
						key_hold_flag = 1;
						key_mode = KEY_WAIT_UP_MODE;
					}
					else
					{
						key_mode = KEY_WAIT_MODE;
					}
				}
			}
			key_up_count=0;
			break;
		case KEY_WAIT_UP_MODE:
			for(i=0;i<2;i++)
			{
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
				wait_us(5);
				ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

				if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
				{
					key_mode = KEY_WAIT_UP_MODE;
					key_up_count = 0;
				}
				else
				{
					key_up_count ++;
					if(key_up_count >50)
					{
						key_up_count = 0;
						key_mode = KEY_UP_MODE;
					}
				}
			}
			break;
		default:
			key_mode = KEY_UP_MODE;
			break;
	}				
	if(key_mode ==KEY_UP_MODE || key_mode == KEY_WAIT_UP_MODE)
	{					
		if(key_down_flag && (key_up_flag||key_hold_flag))
		{
			key_down_flag = 0;
			key_up_flag= 0;
			key_flag = 1;
			
			wake_up_time = NO_KEY_WAKUP_TIME;

			for(i=0;i<2;i++)
			{
				if(key_vlaue_array[i]>NO_KEY_VALUE_TH)
				{
					;
				}
				else if(key_vlaue_array[i]>0xE4)
				{
					key_value = KEY_TABLE[i*8+7];
					i = 2;//exit the for loop
				}
				else if(key_vlaue_array[i]>0xDB)
				{
					key_value = KEY_TABLE[i*8+6];
					i = 2;//exit the for loop
				}	
				else if(key_vlaue_array[i]>0xC0)
				{
					key_value = KEY_TABLE[i*8+5];
					i = 2;//exit the for loop
				}
				else if(key_vlaue_array[i]>0x7B)
				{
					key_value = KEY_TABLE[i*8+4];
					i = 2;//exit the for loop
				}
				else if(key_vlaue_array[i]>0x63)
				{
					key_value = KEY_TABLE[i*8+3];
					i = 2;//exit the for loop
				}
				else if(key_vlaue_array[i]>0x4D)
				{
					key_value = KEY_TABLE[i*8+2];
					i = 2;//exit the for loop
				}
				else if(key_vlaue_array[i]>0x3B)
				{
					key_value = KEY_TABLE[i*8+1];
					i = 2;//exit the for loop
				}
				else
				{
					key_value = KEY_TABLE[i*8+0];
					i = 2;//exit the for loop
				}
			}
#ifdef ATS_EMBED_CODE
			if(key_flag == 1)
			{
				ats_key = key_value;
				ats_key_flag = 1;
			}
#endif//ATS_EMBED_CODE
			if(key_hold_flag)//handing the hold the key action
			{
				key_hold_flag=0;

				switch(key_value)
				{
					case ON_OFF_KEY://hold these buttons ,the effect as same as press
					case MODE_KEY:
                            break;
					case DAB_RESCAN_KEY:
                            key_value = DAB_RESCAN_HOLD_KEY;
                            break;
                    case HDSEEK_KEY:
                            key_value = HDSEEK_HOLD_KEY;
                            break;
					case BACK_LIGHT_KEY: //hold these buttons ,the effect as same as press
							break;
					case CLOCK_KEY:
							key_value = CLOCK_HOLD_KEY;	
							break;
					case ALARM_KEY:
							key_value = ALARM_HOLD_KEY;
							break;
					case PRESET_INC_KEY:
							key_value = PRESET_INC_HOLD_KEY;
							break;
					case PRESET_DEC_KEY:
							key_value = PRESET_DEC_HOLD_KEY;
							break;
					case SEEK_UP_KEY:
							key_value = SEEK_UP_HOLD_KEY;
							break;
					case SEEK_DOWN_KEY:
							key_value = SEEK_DOWN_HOLD_KEY;
							break;
					default:
							key_flag = 0;
							break;
				}
			}		
			for(i=0;i<2;i++)
			{
				key_vlaue_array[i] = 0x00FF;				
			}
		}
	}
}
#endif //#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
