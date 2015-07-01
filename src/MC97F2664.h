//======================================================
//	
//	MC97F2664 Special Function Register assignment
//	
//======================================================

#include	<intrins.h>

#ifndef		_MC97F2664_
#define		_MC97F2664_

//------------------------------------------------- 0x80
sfr			P0			= 0x80;
	sbit	P07			= 0x87;
	sbit	P06			= 0x86;
	sbit	P05			= 0x85;
	sbit	P04			= 0x84;
	sbit	P03			= 0x83;
	sbit	P02			= 0x82;
	sbit	P01			= 0x81;
	sbit	P00			= 0x80;

sfr			SP			= 0x81;
sfr16		DPTR0		= 0x82;
sfr			DPL			= 0x82;
sfr			DPH			= 0x83;
sfr16		DPTR1		= 0x84;
sfr			DPL1		= 0x84;
sfr			DPH1		= 0x85;
sfr			LVICR		= 0x86;
sfr			PCON		= 0x87;

//------------------------------------------------- 0x88
sfr			P1			= 0x88;
	sbit	P17			= 0x8F;
	sbit	P16			= 0x8E;
	sbit	P15			= 0x8D;
	sbit	P14			= 0x8C;
	sbit	P13			= 0x8B;
	sbit	P12			= 0x8A;
	sbit	P11			= 0x89;
	sbit	P10			= 0x88;

sfr			WTDR		= 0x89;
sfr			WTCNT		= 0x89;
sfr			SCCR		= 0x8A;
sfr			BITCR		= 0x8B;
sfr			BITCNT		= 0x8C;
sfr			WDTCR		= 0x8D;
sfr			WDTDR		= 0x8E;
sfr			WDTCNT		= 0x8E;
sfr			WTCR		= 0x8F;

//------------------------------------------------- 0x90
sfr			P2			= 0x90;
	sbit	P27			= 0x97;
	sbit	P26			= 0x96;
	sbit	P25			= 0x95;
	sbit	P24			= 0x94;
	sbit	P23			= 0x93;
	sbit	P22			= 0x92;
	sbit	P21			= 0x91;
	sbit	P20			= 0x90;

sfr			XSP			= 0x91;
sfr			IP0L		= 0x92;
sfr			IP0H		= 0x93;
sfr			TINTCR		= 0x95;
sfr			TIFLAG0		= 0x96;
sfr			TIFLAG1		= 0x97;

//------------------------------------------------- 0x98
sfr			P3			= 0x98;
	sbit	P37			= 0x9F;
	sbit	P36			= 0x9E;
	sbit	P35			= 0x9D;
	sbit	P34			= 0x9C;
	sbit	P33			= 0x9B;
	sbit	P32			= 0x9A;
	sbit	P31			= 0x99;
	sbit	P30			= 0x98;

sfr			P0IO		= 0x99;
sfr			IP1L		= 0x9A;
sfr			IP1H		= 0x9B;
sfr			IP2L		= 0x9C;
sfr			IP2H		= 0x9D;
sfr			IP3L		= 0x9E;
sfr			IP3H		= 0x9F;

//------------------------------------------------- 0xA0
sfr			P4			= 0xA0;
	sbit	P47			= 0xA7;
	sbit	P46			= 0xA6;
	sbit	P45			= 0xA5;
	sbit	P44			= 0xA4;
	sbit	P43			= 0xA3;
	sbit	P42			= 0xA2;
	sbit	P41			= 0xA1;
	sbit	P40			= 0xA0;

sfr			P1IO		= 0xA1;
sfr			EO			= 0xA2;
sfr			EIFLAG0		= 0xA3;
sfr			EIFLAG1		= 0xA4;
sfr			EIFLAG2		= 0xA5;
sfr16		EIPOL0		= 0xA6;
sfr			EIPOL0L		= 0xA6;
sfr			EIPOL0H		= 0xA7;

//------------------------------------------------- 0xA8
sfr			IE			= 0xA8;
	sbit	EA			= 0xAF;
	sbit	INT5E		= 0xAD;
	sbit	INT4E		= 0xAC;
	sbit	INT3E		= 0xAB;
	sbit	INT2E		= 0xAA;
	sbit	INT1E		= 0xA9;
	sbit	INT0E		= 0xA8;

sfr			IE1			= 0xA9;
sfr			IE2			= 0xAA;
sfr			IE3			= 0xAB;
sfr16		EIPOL1		= 0xAC;
sfr			EIPOL1L		= 0xAC;
sfr			EIPOL1H		= 0xAD;
sfr16		EIPOL2		= 0xAE;
sfr			EIPOL2L		= 0xAE;
sfr			EIPOL2H		= 0xAF;

//------------------------------------------------- 0xB0
sfr			P5			= 0xB0;
	sbit	P57			= 0xB7;
	sbit	P56			= 0xB6;
	sbit	P55			= 0xB5;
	sbit	P54			= 0xB4;
	sbit	P53			= 0xB3;
	sbit	P52			= 0xB2;
	sbit	P51			= 0xB1;
	sbit	P50			= 0xB0;

sfr			P2IO		= 0xB1;
sfr			T0CR		= 0xB2;
sfr			T0CNT		= 0xB3;
sfr			T0DR		= 0xB4;
sfr			T0CDR		= 0xB4;
sfr			T1CR		= 0xB5;
sfr			T1CNT		= 0xB6;
sfr			T1DR		= 0xB7;
sfr			T1CDR		= 0xB7;

//------------------------------------------------- 0xB8
sfr			P6			= 0xB8;
	sbit	P67			= 0xBF;
	sbit	P66			= 0xBE;
	sbit	P65			= 0xBD;
	sbit	P64			= 0xBC;
	sbit	P63			= 0xBB;
	sbit	P62			= 0xBA;
	sbit	P61			= 0xB9;
	sbit	P60			= 0xB8;

sfr			P3IO		= 0xB9;
sfr			T2CR		= 0xBA;
sfr			T2CNT		= 0xBB;
sfr			T2DR		= 0xBC;
sfr			T2CDR		= 0xBC;
sfr			T3CR		= 0xBD;
sfr			T3CNT		= 0xBE;
sfr			T3DR		= 0xBF;
sfr			T3CDR		= 0xBF;

//------------------------------------------------- 0xC0
sfr			P7			= 0xC0;
	sbit	P74			= 0xC4;
	sbit	P73			= 0xC3;
	sbit	P72			= 0xC2;
	sbit	P71			= 0xC1;
	sbit	P70			= 0xC0;

sfr			P4IO		= 0xC1;
sfr			SPI2CR		= 0xC2;
sfr			SPI2DR		= 0xC3;
sfr			SPI2SR		= 0xC4;
sfr			SPI3CR		= 0xC5;
sfr			SPI3DR		= 0xC6;
sfr			SPI3SR		= 0xC7;

//------------------------------------------------- 0xC8
sfr			OSCCR		= 0xC8;
	sbit	IRCE		= 0xCA;
	sbit	XCLKE		= 0xC9;
	sbit	SCLKE		= 0xC8;

sfr			P5IO		= 0xC9;
sfr			T4CRL		= 0xCA;
sfr			T4CRH		= 0xCB;
sfr16		T4ADR		= 0xCC;
sfr			T4ADRL		= 0xCC;
sfr			T4ADRH		= 0xCD;
sfr			T4BDRL		= 0xCE;
sfr			T4BDRH		= 0xCF;

//------------------------------------------------- 0xD0
sfr			PSW			= 0xD0;
	sbit	CY			= 0xD7;
	sbit	AC			= 0xD6;
	sbit	F0			= 0xD5;
	sbit	RS1			= 0xD4;
	sbit	RS0			= 0xD3;
	sbit	OV			= 0xD2;
	sbit	F1			= 0xD1;
	sbit	P			= 0xD0;

sfr			P6IO		= 0xD1;
sfr			T5CRL		= 0xD2;
sfr			T5CRH		= 0xD3;
sfr16		T5ADR		= 0xD4;
sfr			T5ADRL		= 0xD4;
sfr			T5ADRH		= 0xD5;
sfr			T5BDRL		= 0xD6;
sfr			T5BDRH		= 0xD7;

//------------------------------------------------- 0xD8
sfr			LVRCR		= 0xD8;
	sbit	LVRST		= 0xDF;
	sbit	LVREN		= 0xD8;

sfr			P7IO		= 0xD9;
sfr			T6CRL		= 0xDA;
sfr			T6CRH		= 0xDB;
sfr			T6ADRL		= 0xDC;
sfr			T6ADRH		= 0xDD;
sfr			T6BDRL		= 0xDE;
sfr			T6BDRH		= 0xDF;

//------------------------------------------------- 0xE0
sfr			ACC			= 0xE0;
sfr			P1DB		= 0xE1;
sfr			T7CRL		= 0xE2;
sfr			T7CRH		= 0xE3;
sfr			T7ADRL		= 0xE4;
sfr			T7ADRH		= 0xE5;
sfr			T7BDRL		= 0xE6;
sfr			T7BDRH		= 0xE7;

//------------------------------------------------- 0xE8
sfr			RSTFR		= 0xE8;
	sbit	PORF		= 0xEF;
	sbit	EXTRF		= 0xEE;
	sbit	WDTRF		= 0xED;
	sbit	OCDRF		= 0xEC;
	sbit	LVRF		= 0xEB;

sfr			P2DB		= 0xE9;
sfr			T8CRL		= 0xEA;
sfr			T8CRH		= 0xEB;
sfr16		T8ADR		= 0xEC;
sfr			T8ADRL		= 0xEC;
sfr			T8ADRH		= 0xED;
sfr			T8BDRL		= 0xEE;
sfr			T8BDRH		= 0xEF;

//------------------------------------------------- 0xF0
sfr			B			= 0xF0;
sfr			P35DB		= 0xF1;
sfr			BUZCR		= 0xF2;
sfr			BUZDR		= 0xF3;
sfr			SPWRL		= 0xF4;
sfr			SPWRH		= 0xF5;
sfr			XSPCR		= 0xF6;
sfr			SINTCR		= 0xF7;

//------------------------------------------------- 0xF8
sfr			XBANK		= 0xF8;
//sfr		X			= 0xF9;
sfr			FSADRH		= 0xFA;
sfr			FSADRM		= 0xFB;
sfr			FSADRL		= 0xFC;
sfr			FIDR		= 0xFD;
sfr			FMCR		= 0xFE;
sfr			MODINR		= 0xFF;

#ifndef		_ASSM_CODE_
	#define	P0OD		*(volatile unsigned char xdata*) 0x1000
	#define	P1OD		*(volatile unsigned char xdata*) 0x1001
	#define	P2OD		*(volatile unsigned char xdata*) 0x1002
	#define	P3OD		*(volatile unsigned char xdata*) 0x1003
	#define	P4OD		*(volatile unsigned char xdata*) 0x1004
	#define	P5OD		*(volatile unsigned char xdata*) 0x1005
	#define	P6OD		*(volatile unsigned char xdata*) 0x1006
	#define	P7OD		*(volatile unsigned char xdata*) 0x1007
	#define	P0PU		*(volatile unsigned char xdata*) 0x1008
	#define	P1PU		*(volatile unsigned char xdata*) 0x1009
	#define	P2PU		*(volatile unsigned char xdata*) 0x100A
	#define	P3PU		*(volatile unsigned char xdata*) 0x100B
	#define	P4PU		*(volatile unsigned char xdata*) 0x100C
	#define	P5PU		*(volatile unsigned char xdata*) 0x100D
	#define	P6PU		*(volatile unsigned char xdata*) 0x100E
	#define	P7PU		*(volatile unsigned char xdata*) 0x100F
	#define	P0FSR		*(volatile unsigned char xdata*) 0x1010
	#define	P1FSR		*(volatile unsigned char xdata*) 0x1011
	#define	P2FSR		*(volatile unsigned char xdata*) 0x1012
	#define	P3FSR		*(volatile unsigned char xdata*) 0x1013
	#define	P4FSR		*(volatile unsigned char xdata*) 0x1014
	#define	P5FSR		*(volatile unsigned char xdata*) 0x1015
	#define	P6FSR		*(volatile unsigned char xdata*) 0x1016
	#define	P7FSR		*(volatile unsigned char xdata*) 0x1017
	#define	USI0CR1		*(volatile unsigned char xdata*) 0x1018
	#define	USI0CR2		*(volatile unsigned char xdata*) 0x1019
	#define	USI0CR3		*(volatile unsigned char xdata*) 0x101A
	#define	USI0CR4		*(volatile unsigned char xdata*) 0x101B

	#define	USI0ST1		*(volatile unsigned char xdata*) 0x1020
	#define	USI0ST2		*(volatile unsigned char xdata*) 0x1021
	#define	USI0BD		*(volatile unsigned char xdata*) 0x1022
	#define	USI0SDHR	*(volatile unsigned char xdata*) 0x1023
	#define	USI0DR		*(volatile unsigned char xdata*) 0x1024
	#define	USI0SCLR	*(volatile unsigned char xdata*) 0x1025
	#define	USI0SCHR	*(volatile unsigned char xdata*) 0x1026
	#define	USI0SAR		*(volatile unsigned char xdata*) 0x1027
	#define	USI1CR1		*(volatile unsigned char xdata*) 0x1028
	#define	USI1CR2		*(volatile unsigned char xdata*) 0x1029
	#define	USI1CR3		*(volatile unsigned char xdata*) 0x102A
	#define	USI1CR4		*(volatile unsigned char xdata*) 0x102B

	#define	USI1ST1		*(volatile unsigned char xdata*) 0x1030
	#define	USI1ST2		*(volatile unsigned char xdata*) 0x1031
	#define	USI1BD		*(volatile unsigned char xdata*) 0x1032
	#define	USI1SDHR	*(volatile unsigned char xdata*) 0x1033
	#define	USI1DR		*(volatile unsigned char xdata*) 0x1034
	#define	USI1SCLR	*(volatile unsigned char xdata*) 0x1035
	#define	USI1SCHR	*(volatile unsigned char xdata*) 0x1036
	#define	USI1SAR		*(volatile unsigned char xdata*) 0x1037
	#define	UART2CR1	*(volatile unsigned char xdata*) 0x1038
	#define	UART2CR2	*(volatile unsigned char xdata*) 0x1039
	#define	UART2CR3	*(volatile unsigned char xdata*) 0x103A
	#define	UART2ST		*(volatile unsigned char xdata*) 0x103B
	#define	UART2BD		*(volatile unsigned char xdata*) 0x103C
	#define	UART2DR		*(volatile unsigned char xdata*) 0x103D

	#define	UART3CR1	*(volatile unsigned char xdata*) 0x1040
	#define	UART3CR2	*(volatile unsigned char xdata*) 0x1041
	#define	UART3CR3	*(volatile unsigned char xdata*) 0x1042
	#define	UART3ST		*(volatile unsigned char xdata*) 0x1043
	#define	UART3BD		*(volatile unsigned char xdata*) 0x1044
	#define	UART3DR		*(volatile unsigned char xdata*) 0x1045
	#define	UART4CR1	*(volatile unsigned char xdata*) 0x1048
	#define	UART4CR2	*(volatile unsigned char xdata*) 0x1049
	#define	UART4CR3	*(volatile unsigned char xdata*) 0x104A
	#define	UART4ST		*(volatile unsigned char xdata*) 0x104B
	#define	UART4BD		*(volatile unsigned char xdata*) 0x104C
	#define	UART4DR		*(volatile unsigned char xdata*) 0x104D

	#define	ADCCRL		*(volatile unsigned char xdata*) 0x1050
	#define	ADCCRH		*(volatile unsigned char xdata*) 0x1051
	#define	ADCDRL		*(volatile unsigned char xdata*) 0x1052
	#define	ADCDRH		*(volatile unsigned char xdata*) 0x1053
	#define	T9CRL		*(volatile unsigned char xdata*) 0x1058
	#define	T9CRH		*(volatile unsigned char xdata*) 0x1059
	#define	T9ADRL		*(volatile unsigned char xdata*) 0x105A
	#define	T9ADRH		*(volatile unsigned char xdata*) 0x105B
	#define	T9BDRL		*(volatile unsigned char xdata*) 0x105C
	#define	T9BDRH		*(volatile unsigned char xdata*) 0x105D
#else
	P0OD				xdata	0x1000
	P1OD				xdata	0x1001
	P2OD				xdata	0x1002
	P3OD				xdata	0x1003
	P4OD				xdata	0x1004
	P5OD				xdata	0x1005
	P6OD				xdata	0x1006
	P7OD				xdata	0x1007
	P0PU				xdata	0x1008
	P1PU				xdata	0x1009
	P2PU				xdata	0x100A
	P3PU				xdata	0x100B
	P4PU				xdata	0x100C
	P5PU				xdata	0x100D
	P6PU				xdata	0x100E
	P7PU				xdata	0x100F
	P0FSR				xdata	0x1010
	P1FSR				xdata	0x1011
	P2FSR				xdata	0x1012
	P3FSR				xdata	0x1013
	P4FSR				xdata	0x1014
	P5FSR				xdata	0x1015
	P6FSR				xdata	0x1016
	P7FSR				xdata	0x1017
	USI0CR1				xdata	0x1018
	USI0CR2				xdata	0x1019
	USI0CR3				xdata	0x101A
	USI0CR4				xdata	0x101B
                
	USI0ST1				xdata	0x1020
	USI0ST2				xdata	0x1021
	USI0BD				xdata	0x1022
	USI0SDHR			xdata	0x1023
	USI0DR				xdata	0x1024
	USI0SCLR			xdata	0x1025
	USI0SCHR			xdata	0x1026
	USI0SAR				xdata	0x1027
	USI1CR1				xdata	0x1028
	USI1CR2				xdata	0x1029
	USI1CR3				xdata	0x102A
	USI1CR4				xdata	0x102B
                
	USI1ST1				xdata	0x1030
	USI1ST2				xdata	0x1031
	USI1BD				xdata	0x1032
	USI1SDHR			xdata	0x1033
	USI1DR				xdata	0x1034
	USI1SCLR			xdata	0x1035
	USI1SCHR			xdata	0x1036
	USI1SAR				xdata	0x1037
	UART2CR1			xdata	0x1038
	UART2CR2			xdata	0x1039
	UART2CR3			xdata	0x103A
	UART2ST				xdata	0x103B
	UART2BD				xdata	0x103C
	UART2DR				xdata	0x103D
                
	UART3CR1			xdata	0x1040
	UART3CR2			xdata	0x1041
	UART3CR3			xdata	0x1042
	UART3ST				xdata	0x1043
	UART3BD				xdata	0x1044
	UART3DR				xdata	0x1045
	UART4CR1			xdata	0x1048
	UART4CR2			xdata	0x1049
	UART4CR3			xdata	0x104A
	UART4ST				xdata	0x104B
	UART4BD				xdata	0x104C
	UART4DR				xdata	0x104D
                
	ADCCRL				xdata	0x1050
	ADCCRH				xdata	0x1051
	ADCDRL				xdata	0x1052
	ADCDRH				xdata	0x1053
	T9CRL				xdata	0x1058
	T9CRH				xdata	0x1059
	T9ADRL				xdata	0x105A
	T9ADRH				xdata	0x105B
	T9BDRL				xdata	0x105C
	T9BDRH				xdata	0x105D
#endif													// _ASSM_CODE_
#endif													//_MC97F2664_

#define		cli()		do{IE &= ~0x80;}while(0)
#define		sei()		do{IE |=  0x80;}while(0)
#define		NOP			_nop_()
