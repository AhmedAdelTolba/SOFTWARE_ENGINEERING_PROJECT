/*
 * LCD_prog.c
 *
 *  Created on: Mar 9, 2016
 *      Author: seif
 */
#include "../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include "../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/mydelay.h"
#include "../../../MCAL_LAYER/DIO/DIO_CODE/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

const u8 LCD_u8dataPins[] =
    {
    LCD_u8D0, LCD_u8D1, LCD_u8D2, LCD_u8D3, LCD_u8D4, LCD_u8D5, LCD_u8D6, LCD_u8D7
    };

/* Comment!: Initialize LCD */
extern void LCD_voidInit()
    {
    // commands that initialize the LCD module
    Delay(20);
    LCD_voidWriteCommand(FUNC_SET_1LINE);
    Delay(5);
    LCD_voidWriteCommand(FUNC_SET_1LINE);
    Delay(1);
    LCD_voidWriteCommand(FUNC_SET_1LINE);
    LCD_voidWriteCommand(FUNC_SET_2LINE);
    LCD_voidWriteCommand(0b00000110);
    LCD_voidWriteCommand(LCD_u8INIT_STATE); // initial state of LCD defined in config file

    }

/* Comment!:function that write command to LCD controller */
extern void LCD_voidWriteCommand(u8 copy_u8Command)
    {
    u8 Local_u8Counter; //loop counter
    //takes the command hex value and send the first bit to the corresponding pin then shift it to get the second bit
    for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
	if (copy_u8Command & 0b00000001)
	    {
	    //LSB is 1 so output high
	    DIO_u8WritePinVal(LCD_u8dataPins[Local_u8Counter], DIO_u8HIGH);
	    }
	else
	    {
	    //LSB is 0 so output high
	    DIO_u8WritePinVal(LCD_u8dataPins[Local_u8Counter], DIO_u8LOW);
	    }
	copy_u8Command = copy_u8Command >> 1; 		//shift command hex value by 1
	}
    DIO_u8WritePinVal(LCD_u8RS, DIO_u8LOW); //select the command register by sending LOW to RS pin(register selection pin
    DIO_u8WritePinVal(LCD_u8RW, DIO_u8LOW);		//choose the write operation by putting low on RW pin
    //send high to E pin to tell LCD to receive data on its dataPins
    DIO_u8WritePinVal(LCD_u8ENABLE, DIO_u8HIGH);
   Delay(1);
    //send low to E to tell LCD to process received data
    DIO_u8WritePinVal(LCD_u8ENABLE, DIO_u8LOW);

    }

/* Comment!:function that write data to be displayed on LCD */
extern void LCD_voidWriteChar(u8 copy_u8Data)
    {
    u8 Local_u8Counter;
    //takes the data hex value and send the first bit to the corresponding pin then shift it to get the second bit
    for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
	if (copy_u8Data & 0b00000001)
	    {
	    //MSB is 1 so output high
	    DIO_u8WritePinVal(LCD_u8dataPins[Local_u8Counter], DIO_u8HIGH);
	    }
	else
	    {
	    //MSB is 0 so output LOW
	    DIO_u8WritePinVal(LCD_u8dataPins[Local_u8Counter], DIO_u8LOW);
	    }
	copy_u8Data = copy_u8Data >> 1;	//shift data hex value by 1
	}
    DIO_u8WritePinVal(LCD_u8RS, DIO_u8HIGH);//select the data register by sending HIGH to RS pin(register selection pin
    DIO_u8WritePinVal(LCD_u8RW, DIO_u8LOW); //choose the write operation by putting low on RW pin

    DIO_u8WritePinVal(LCD_u8ENABLE, DIO_u8HIGH); //send high to E pin to tell LCD to receive data on its dataPins
   Delay(1);
    DIO_u8WritePinVal(LCD_u8ENABLE, DIO_u8LOW); //send low to E to tell LCD to process received data

    }

/* Comment!: write string function */
extern void LCD_voidWriteString(u8 copy_u8String[])
    {
    volatile u8 Local_u8Counter = 0;
    while (copy_u8String[Local_u8Counter] != 0)
	{
	LCD_voidWriteChar(copy_u8String[Local_u8Counter]); //write character by character on LCD
	Local_u8Counter++; 	//increment counter to get next character in string
	}
    }

/* Comment!: Write Custom character to CGRAM */
extern void LCD_voidWriteCustomChar(const u8* copy_u8Char, u8 copy_u8charCode)
    {
    u8 Local_u8Counter;
    // check if the location within 0~7
    if (copy_u8charCode < LCD_u8CGRAM_LOCATIONS)
	{
	u8 local_u8Char_address = ( LCD_u8CGRAM_ADD | (copy_u8charCode << 3));

	LCD_voidWriteCommand(local_u8Char_address); //go to the CGRAM location in which the custom char will be put in
	// write the character to the specified location
	for (Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++)
	    {
	    LCD_voidWriteChar(copy_u8Char[Local_u8Counter]); //write char to CGRAM
	    }
	}
    }
/* Comment!: function that clear specific line*/
extern void LCD_voidClearLine(u8 copy_u8line)
    {
    LCD_voidWriteCommand(copy_u8line); // go to the line
    LCD_voidWriteString("               "); // print 16 space
    }
