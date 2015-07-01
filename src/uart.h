/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for uart driver for C8051F380 based module
   FILE: uart.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _uart_h_
#define _uart_h_

#include "platform_options.h"

u8 check_sum(u8* buf,u8 len);
void uart0_init(void);
void uart0_send(u8* buf,u8 len);
void ats_cmd_process(void);
void ats_send_cmd(u8* cmd,u8 len);
void uart1_send(u8* buf,u8 len);
u8 freq_to_dab_index(u32 freq);

#define CMD_ACK						0x00
#define CMD_NACK					0x01

#define CMD_SET_IO_LEVEL			0x00
#define CMD_GET_IO_STATUS			0x01
#define CMD_ENTER_ENCODE_TEST_MODE	0x02
#define CMD_ENTER_KEYPAD_TEST_MODE	0x03
#define CMD_MODE_SWITCH				0x04
#define CMD_TUNE_FREQ				0x05
#define CMD_START_HD_BER			0x06
#define CMD_GET_SERVICE_ID_DAB		0x07
#define CMD_TUNE_DAB_ID				0x08	
#define CMD_START_DAB_BER			0x09
#define CMD_EXIT_ATS_TEST			0x0A
#define CMD_START_ATS_TEST			0x0B
#define CMD_GET_MODE				0x0C
#define CMD_GET_SIGNAL_ERR			0x0D
#define CMD_GET_RDS_VALID			0x0E
#define CMD_TUNE_DAB_FREQ			0x0F


#define CMD_SHIP_ATS_INTERFACE      0xF1



#define RSP_SET_IO_LEVEL			0x80
#define RSP_GET_IO_STATUS			0x81
#define RSP_ENTER_ENCODE_TEST_MODE	0x82
#define RSP_ENTER_KEYPAD_TEST_MODE	0x83
#define RSP_MODE_SWITCH				0x84
#define RSP_TUNE_FREQ				0x85
#define RSP_START_HD_BER			0x86
#define RSP_GET_SERVICE_ID_DAB		0x87
#define RSP_TUNE_DAB_ID				0x88	
#define RSP_START_DAB_BER			0x89
#define RSP_EXIT_ATS_TEST			0x8A
#define RSP_START_ATS_TEST			0x8B
#define RSP_GET_MODE				0x8C
#define RSP_GET_SIGNAL_ERR			0x8D
#define RSP_GET_RDS_VALID			0x8E
#define RSP_DAB_TUNE_FREQ			0x8F


//keypad parser
#define ATS_NO_KEY					0x00
#define ATS_DOWN_KEY				0x01
#define ATS_SELECT_KEY				0x02
#define ATS_UP_KEY					0x03
#define ATS_BKL_TOG_KEY				0x04
#define ATS_SK_DOWN_KEY				0x05
#define ATS_CLOCK_KEY				0x06
#define ATS_SK_UP_KEY				0x07
#define ATS_HD_SEEK_KEY				0x08
#define ATS_PERSET_DEC_KEY			0x09
#define ATS_ALARM_KEY				0x0A
#define ATS_PERSET_INC_KEY			0x0B
#define ATS_DAB_RESCAN_KEY			0x0C
#define ATS_MODE_KEY				0x0D
#define ATS_MENU_KEY				0x0E
#define ATS_ON_OFF_KEY				0x0F
#define ATS_SNOOZE_KEY				0x10

//encode key
#define ATS_EN_TUNE_UP_KEY			0x01
#define ATS_EN_TUNE_DOWN_KEY		0x02
#define ATS_EN_TUNE_SELECT_KEY		0x03
#define ATS_EN_VOLUME_UP_KEY		0x04
#define ATS_EN_VOLUME_DOWN_KEY		0x05
#define ATS_EN_VOLUME_SELECT_KEY	0x06

// UCTRL1 reg
#define UART_MODE		0x00

#define NOPARITY		0x00
#define EVENPARITY		0x20
#define ODDPARITY		0x30

#define USIZE5			0x00
#define USIZE6			0x02
#define USIZE7			0x04
#define USIZE8			0x06
#define USIZE9			0x0e

// UCTRL2 reg
#define UDRIE			0x80
#define TXCIE			0x40
#define RXCIE			0x20
#define WAKEIE			0x10
#define TXE				0x08
#define RXE				0x04
#define USARTEN			0x02
#define U2X				0x01

// UCTRL3 reg
#define MASTER			0x80
#define LOOPS			0x40
#define DISXCK			0x20
#define SPISS			0x10
#define SOFTRST			0x08
#define USBS			0x04

// USTAT reg
#define UDRE			0x80
#define TXC				0x40
#define RXC				0x20
#define WAKE			0x10
#define DOR				0x04
#define FE				0x02
#define PE				0x01

#endif