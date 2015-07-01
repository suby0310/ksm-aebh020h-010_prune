/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI specific type definitions
   FILE: typedefs.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _typed_h_
#define _typed_h_

typedef  unsigned char u8;
typedef  unsigned int  u16;
typedef  unsigned long  u32;

#define false 0
#define true  1

typedef struct _time_struct
{
 	u8 sec;
 	u8 min;
 	u8 hour;
 	u8 day;
 	u8 week;
 	u8 month;
 	u8 year;
}time_struct;

typedef struct _dab_preset_struct
{
	u8 valid;
	u8 freq_index;	
	u32 service_id;
	u16 component_id;
	u8 label_str[17];//16+1 the last one character is '\n'
}dab_preset_struct;

typedef struct _fmhd_preset_struct
{
	u8 valid;
	u16 frequency;
	u8 component_id;
	u8 service_name[6];//if service_name == 0xFF,0xFF... mean it is a analog station,not digital
}fmhd_preset_struct;

typedef struct _amhd_preset_struct
{
	u8 valid;
	u16 frequency;
	u8 component_id;
	u8 service_name[6];//if service_name == 0xFF,0xFF... mean it is a analog station,not digital
}amhd_preset_struct;

//----------------------------------------------------------------------------------
// 		Number characters
//----------------------------------------------------------------------------------
#define 	_0000_0000	0x00
#define 	_0000_0001	0x01
#define 	_0000_0010	0x02
#define 	_0000_0011	0x03
#define 	_0000_0100	0x04
#define 	_0000_0101	0x05
#define 	_0000_0110	0x06
#define 	_0000_0111	0x07
#define 	_0000_1000	0x08
#define 	_0000_1001	0x09
#define 	_0000_1010	0x0A
#define 	_0000_1011	0x0B
#define 	_0000_1100	0x0C
#define 	_0000_1101	0x0D
#define 	_0000_1110	0x0E
#define 	_0000_1111	0x0F
#define 	_0001_0000	0x10
#define 	_0001_0001	0x11
#define 	_0001_0010	0x12
#define 	_0001_0011	0x13
#define 	_0001_0100	0x14
#define 	_0001_0101	0x15
#define 	_0001_0110	0x16
#define 	_0001_0111	0x17
#define 	_0001_1000	0x18
#define 	_0001_1001	0x19
#define 	_0001_1010	0x1A
#define 	_0001_1011	0x1B
#define 	_0001_1100	0x1C
#define 	_0001_1101	0x1D
#define 	_0001_1110	0x1E
#define 	_0001_1111	0x1F
#define 	_0010_0000	0x20
#define 	_0010_0001	0x21
#define 	_0010_0010	0x22
#define 	_0010_0011	0x23
#define 	_0010_0100	0x24
#define 	_0010_0101	0x25
#define 	_0010_0110	0x26
#define 	_0010_0111	0x27
#define 	_0010_1000	0x28
#define 	_0010_1001	0x29
#define 	_0010_1010	0x2A
#define 	_0010_1011	0x2B
#define 	_0010_1100	0x2C
#define 	_0010_1101	0x2D
#define 	_0010_1110	0x2E
#define 	_0010_1111	0x2F
#define 	_0011_0000	0x30
#define 	_0011_0001	0x31
#define 	_0011_0010	0x32
#define 	_0011_0011	0x33
#define 	_0011_0100	0x34
#define 	_0011_0101	0x35
#define 	_0011_0110	0x36
#define 	_0011_0111	0x37
#define 	_0011_1000	0x38
#define 	_0011_1001	0x39
#define 	_0011_1010	0x3A
#define 	_0011_1011	0x3B
#define 	_0011_1100	0x3C
#define 	_0011_1101	0x3D
#define 	_0011_1110	0x3E
#define 	_0011_1111	0x3F
#define 	_0100_0000	0x40
#define 	_0100_0001	0x41
#define 	_0100_0010	0x42
#define 	_0100_0011	0x43
#define 	_0100_0100	0x44
#define 	_0100_0101	0x45
#define 	_0100_0110	0x46
#define 	_0100_0111	0x47
#define 	_0100_1000	0x48
#define 	_0100_1001	0x49
#define 	_0100_1010	0x4A
#define 	_0100_1011	0x4B
#define 	_0100_1100	0x4C
#define 	_0100_1101	0x4D
#define 	_0100_1110	0x4E
#define 	_0100_1111	0x4F
#define 	_0101_0000	0x50
#define 	_0101_0001	0x51
#define 	_0101_0010	0x52
#define 	_0101_0011	0x53
#define 	_0101_0100	0x54
#define 	_0101_0101	0x55
#define 	_0101_0110	0x56
#define 	_0101_0111	0x57
#define 	_0101_1000	0x58
#define 	_0101_1001	0x59
#define 	_0101_1010	0x5A
#define 	_0101_1011	0x5B
#define 	_0101_1100	0x5C
#define 	_0101_1101	0x5D
#define 	_0101_1110	0x5E
#define 	_0101_1111	0x5F
#define 	_0110_0000	0x60
#define 	_0110_0001	0x61
#define 	_0110_0010	0x62
#define 	_0110_0011	0x63
#define 	_0110_0100	0x64
#define 	_0110_0101	0x65
#define 	_0110_0110	0x66
#define 	_0110_0111	0x67
#define 	_0110_1000	0x68
#define 	_0110_1001	0x69
#define 	_0110_1010	0x6A
#define 	_0110_1011	0x6B
#define 	_0110_1100	0x6C
#define 	_0110_1101	0x6D
#define 	_0110_1110	0x6E
#define 	_0110_1111	0x6F
#define 	_0111_0000	0x70
#define 	_0111_0001	0x71
#define 	_0111_0010	0x72
#define 	_0111_0011	0x73
#define 	_0111_0100	0x74
#define 	_0111_0101	0x75
#define 	_0111_0110	0x76
#define 	_0111_0111	0x77
#define 	_0111_1000	0x78
#define 	_0111_1001	0x79
#define 	_0111_1010	0x7A
#define 	_0111_1011	0x7B
#define 	_0111_1100	0x7C
#define 	_0111_1101	0x7D
#define 	_0111_1110	0x7E
#define 	_0111_1111	0x7F
#define 	_1000_0000	0x80
#define 	_1000_0001	0x81
#define 	_1000_0010	0x82
#define 	_1000_0011	0x83
#define 	_1000_0100	0x84
#define 	_1000_0101	0x85
#define 	_1000_0110	0x86
#define 	_1000_0111	0x87
#define 	_1000_1000	0x88
#define 	_1000_1001	0x89
#define 	_1000_1010	0x8A
#define 	_1000_1011	0x8B
#define 	_1000_1100	0x8C
#define 	_1000_1101	0x8D
#define 	_1000_1110	0x8E
#define 	_1000_1111	0x8F
#define 	_1001_0000	0x90
#define 	_1001_0001	0x91
#define 	_1001_0010	0x92
#define 	_1001_0011	0x93
#define 	_1001_0100	0x94
#define 	_1001_0101	0x95
#define 	_1001_0110	0x96
#define 	_1001_0111	0x97
#define 	_1001_1000	0x98
#define 	_1001_1001	0x99
#define 	_1001_1010	0x9A
#define 	_1001_1011	0x9B
#define 	_1001_1100	0x9C
#define 	_1001_1101	0x9D
#define 	_1001_1110	0x9E
#define 	_1001_1111	0x9F
#define 	_1010_0000	0xA0
#define 	_1010_0001	0xA1
#define 	_1010_0010	0xA2
#define 	_1010_0011	0xA3
#define 	_1010_0100	0xA4
#define 	_1010_0101	0xA5
#define 	_1010_0110	0xA6
#define 	_1010_0111	0xA7
#define 	_1010_1000	0xA8
#define 	_1010_1001	0xA9
#define 	_1010_1010	0xAA
#define 	_1010_1011	0xAB
#define 	_1010_1100	0xAC
#define 	_1010_1101	0xAD
#define 	_1010_1110	0xAE
#define 	_1010_1111	0xAF
#define 	_1011_0000	0xB0
#define 	_1011_0001	0xB1
#define 	_1011_0010	0xB2
#define 	_1011_0011	0xB3
#define 	_1011_0100	0xB4
#define 	_1011_0101	0xB5
#define 	_1011_0110	0xB6
#define 	_1011_0111	0xB7
#define 	_1011_1000	0xB8
#define 	_1011_1001	0xB9
#define 	_1011_1010	0xBA
#define 	_1011_1011	0xBB
#define 	_1011_1100	0xBC
#define 	_1011_1101	0xBD
#define 	_1011_1110	0xBE
#define 	_1011_1111	0xBF
#define 	_1100_0000	0xC0
#define 	_1100_0001	0xC1
#define 	_1100_0010	0xC2
#define 	_1100_0011	0xC3
#define 	_1100_0100	0xC4
#define 	_1100_0101	0xC5
#define 	_1100_0110	0xC6
#define 	_1100_0111	0xC7
#define 	_1100_1000	0xC8
#define 	_1100_1001	0xC9
#define 	_1100_1010	0xCA
#define 	_1100_1011	0xCB
#define 	_1100_1100	0xCC
#define 	_1100_1101	0xCD
#define 	_1100_1110	0xCE
#define 	_1100_1111	0xCF
#define 	_1101_0000	0xD0
#define 	_1101_0001	0xD1
#define 	_1101_0010	0xD2
#define 	_1101_0011	0xD3
#define 	_1101_0100	0xD4
#define 	_1101_0101	0xD5
#define 	_1101_0110	0xD6
#define 	_1101_0111	0xD7
#define 	_1101_1000	0xD8
#define 	_1101_1001	0xD9
#define 	_1101_1010	0xDA
#define 	_1101_1011	0xDB
#define 	_1101_1100	0xDC
#define 	_1101_1101	0xDD
#define 	_1101_1110	0xDE
#define 	_1101_1111	0xDF
#define 	_1110_0000	0xE0
#define 	_1110_0001	0xE1
#define 	_1110_0010	0xE2
#define 	_1110_0011	0xE3
#define 	_1110_0100	0xE4
#define 	_1110_0101	0xE5
#define 	_1110_0110	0xE6
#define 	_1110_0111	0xE7
#define 	_1110_1000	0xE8
#define 	_1110_1001	0xE9
#define 	_1110_1010	0xEA
#define 	_1110_1011	0xEB
#define 	_1110_1100	0xEC
#define 	_1110_1101	0xED
#define 	_1110_1110	0xEE
#define 	_1110_1111	0xEF
#define 	_1111_0000	0xF0
#define 	_1111_0001	0xF1
#define 	_1111_0010	0xF2
#define 	_1111_0011	0xF3
#define 	_1111_0100	0xF4
#define 	_1111_0101	0xF5
#define 	_1111_0110	0xF6
#define 	_1111_0111	0xF7
#define 	_1111_1000	0xF8
#define 	_1111_1001	0xF9
#define 	_1111_1010	0xFA
#define 	_1111_1011	0xFB
#define 	_1111_1100	0xFC
#define 	_1111_1101	0xFD
#define 	_1111_1110	0xFE
#define 	_1111_1111	0xFF	
#endif