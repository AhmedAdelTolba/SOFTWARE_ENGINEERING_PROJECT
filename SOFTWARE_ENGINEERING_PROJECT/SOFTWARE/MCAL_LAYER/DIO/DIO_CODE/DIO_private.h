/*
 * DIO_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: G
 */

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*comment!:ports*/
#define DIO_PORTSNUMBER 4

/*comment!:ports*/
#define DIO_MASKPINS 2

/*comment!:pins*/
#define DIO_PINSNUMBER 8

/*comment!:concatnation*/
#define conc(x7,x6,x5,x4,x3,x2,x1,x0)	        conchelper(x7,x6,x5,x4,x3,x2,x1,x0)
#define conchelper(x7,x6,x5,x4,x3,x2,x1,x0 )	0b##x7##x6##x5##x4##x3##x2##x1##x0

/*comment!:port direction*/
#define DIO_u8PortADir conc(DIO_u8PIN7_INITDIR,DIO_u8PIN6_INITDIR,DIO_u8PIN5_INITDIR,DIO_u8PIN4_INITDIR,DIO_u8PIN3_INITDIR,DIO_u8PIN2_INITDIR,DIO_u8PIN1_INITDIR,DIO_u8PIN0_INITDIR)
#define DIO_u8PortBDir conc(DIO_u8PIN15_INITDIR,DIO_u8PIN14_INITDIR,DIO_u8PIN13_INITDIR,DIO_u8PIN12_INITDIR,DIO_u8PIN11_INITDIR,DIO_u8PIN10_INITDIR,DIO_u8PIN9_INITDIR,DIO_u8PIN8_INITDIR)
#define DIO_u8PortCDir conc(DIO_u8PIN23_INITDIR,DIO_u8PIN22_INITDIR,DIO_u8PIN21_INITDIR,DIO_u8PIN20_INITDIR,DIO_u8PIN19_INITDIR,DIO_u8PIN18_INITDIR,DIO_u8PIN17_INITDIR,DIO_u8PIN16_INITDIR)
#define DIO_u8PortDDir conc(DIO_u8PIN31_INITDIR,DIO_u8PIN30_INITDIR,DIO_u8PIN29_INITDIR,DIO_u8PIN28_INITDIR,DIO_u8PIN27_INITDIR,DIO_u8PIN26_INITDIR,DIO_u8PIN25_INITDIR,DIO_u8PIN24_INITDIR)


/*comment!:port VAL*/
#define DIO_u8PortAVal conc(DIO_u8PIN7_INITVAL,DIO_u8PIN6_INITVAL,DIO_u8PIN5_INITVAL,DIO_u8PIN4_INITVAL,DIO_u8PIN3_INITVAL,DIO_u8PIN2_INITVAL,DIO_u8PIN1_INITVAL,DIO_u8PIN0_INITVAL)
#define DIO_u8PortBVal conc(DIO_u8PIN15_INITVAL,DIO_u8PIN4_INITVAL,DIO_u8PIN13_INITVAL,DIO_u8PIN12_INITVAL,DIO_u8PIN11_INITVAL,DIO_u8PIN10_INITVAL,DIO_u8PIN9_INITVAL,DIO_u8PIN8_INITVAL)
#define DIO_u8PortCVal conc(DIO_u8PIN23_INITVAL,DIO_u8PIN22_INITVAL,DIO_u8PIN21_INITVAL,DIO_u8PIN20_INITVAL,DIO_u8PIN19_INITVAL,DIO_u8PIN18_INITVAL,DIO_u8PIN17_INITVAL,DIO_u8PIN16_INITVAL)
#define DIO_u8PortDVal conc(DIO_u8PIN31_INITVAL,DIO_u8PIN30_INITVAL,DIO_u8PIN29_INITVAL,DIO_u8PIN28_INITVAL,DIO_u8PIN27_INITVAL,DIO_u8PIN26_INITVAL,DIO_u8PIN25_INITVAL,DIO_u8PIN24_INITVAL)

//////////////////////////////////////////////////////////////////////////////////
#define DIO_u8PORTA ((volatile u8*)(0x3B))
#define DIO_u8PORTB ((volatile u8*)(0x38))
#define DIO_u8PORTC ((volatile u8*)(0x35))
#define DIO_u8PORTD ((volatile u8*)(0x32))
/////////////////////////////////////////////////////////////////////////////////
#define DIO_u8DDRA ((volatile u8*)(0x3A))
#define DIO_u8DDRB ((volatile u8*)(0x37))
#define DIO_u8DDRC ((volatile u8*)(0x34))
#define DIO_u8DDRD ((volatile u8*)(0x31))
/////////////////////////////////////////////////////////////////////////////////
#define DIO_u8PINA ((volatile u8*)(0x39))
#define DIO_u8PINB ((volatile u8*)(0x36))
#define DIO_u8PINC ((volatile u8*)(0x33))
#define DIO_u8PIND ((volatile u8*)(0x30))
/////////////////////////////////////////////////////////////////////////////////
/*comment!:SET masks*/
#define DIO_u8MASKSETPINO 0B00000001
#define DIO_u8MASKSETPIN1 0B00000010
#define DIO_u8MASKSETPIN2 0B00000100
#define DIO_u8MASKSETPIN3 0B00001000
#define DIO_u8MASKSETPIN4 0B00010000
#define DIO_u8MASKSETPIN5 0B00100000
#define DIO_u8MASKSETPIN6 0B01000000
#define DIO_u8MASKSETPIN7 0B10000000
/*comment!:CLR masks*/
#define DIO_u8MASKCLRPINO 0B11111110
#define DIO_u8MASKCLRPIN1 0B11111101
#define DIO_u8MASKCLRPIN2 0B11111011
#define DIO_u8MASKCLRPIN3 0B11110111
#define DIO_u8MASKCLRPIN4 0B11101111
#define DIO_u8MASKCLRPIN5 0B11011111
#define DIO_u8MASKCLRPIN6 0B10111111
#define DIO_u8MASKCLRPIN7 0B01111111
///////////////////////////////////////////////////////////////////////////////
#define getbit(reg,bitno) (((reg)>>(bitno))&0x01)


#endif /*DIO_PRIVATE_H_*/
