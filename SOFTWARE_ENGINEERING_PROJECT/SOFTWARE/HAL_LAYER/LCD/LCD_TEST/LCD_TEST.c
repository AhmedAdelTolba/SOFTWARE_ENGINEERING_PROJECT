/*
 * main.c
 *
 *  Created on: Mar 9, 2016
 *      Author: seif
 */

#include "../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include "../../../MCAL_LAYER/DIO/DIO_CODE/DIO_interface.h"
#include "../LCD_CODE/LCD_interface.h"


int main(void)
{
	DIO_VoidInit();
	LCD_voidInit();

	u8 char1[]={0x0,0x0,0x15,0x15,0x1f,0x0,0x0};
	u8 char2[]={0x0,0x0,0x0,0x4,0x1f,0x0,0x18};
	u8 char3[]={0x1,0x0,0x3,0x11,0x1f,0x0,0x0};

	LCD_voidWriteChar('A');

	LCD_voidWriteCustomChar(char1,0);
	LCD_voidWriteCustomChar(char2,1);
	LCD_voidWriteCustomChar(char3,2);

	LCD_voidWriteCommand(0xcf);
	LCD_voidWriteChar(0x00);
	LCD_voidWriteCommand(0xce);
	LCD_voidWriteChar(0x01);
	LCD_voidWriteCommand(0xcd);
	LCD_voidWriteChar(0x02);
	LCD_voidWriteCommand(0xcc);
	LCD_voidWriteChar(0x03);

	while(1)
	{}
	return 0;

}

