/*
 * LCD_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: seif
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/**********************************************************/
/******************public definition***********************/
/**********************************************************/

/*Comment!: LCD states */
#define LCD_u8ON	1
#define LCD_u8OFF	0

/*Comment!: LCD control commands*/
#define DISPOFF_CURSOFF		0x08 //clear display without clearing DDRAM
#define DISPON_CURSON		0x0E //display on ,cursor on
#define DISPON_CURSOFF		0x0C //display on ,cursor off
#define DISPON_CURSBLINK	0x0F //display on , cursor blinking
#define SHIFT_DISP_RIGHT	0X18 //shift entire display right
#define SHIFT_DISP_LEFT		0x1C //shift entire display left
#define MOV_CURS_LEFT		0x10 //move cursor one character right
#define MOV_CURS_RIGHT		0x14 //move cursor one character left
#define CLR_DISP			0x01 //also clears DDRAM
#define LCD_SET_CURS		0x80 //set cursor position

/* Comment!: LCD LINES */
#define LCD_u8LINE1		0x80
#define LCD_u8LINE2		0x0c

/* Comment!: LCD displaying locations */
#define LCD_u8LINE1_LOC0		0x80 // line 1 character 0
#define LCD_u8LINE1_LOC1		0x81 // line 1 character 1
#define LCD_u8LINE1_LOC2		0x82 // line 1 character 2
#define LCD_u8LINE1_LOC3		0x83 // line 1 character 3
#define LCD_u8LINE1_LOC4		0x84 // line 1 character 4
#define LCD_u8LINE1_LOC5		0x85 // line 1 character 5
#define LCD_u8LINE1_LOC6		0x86 // line 1 character 6
#define LCD_u8LINE1_LOC7		0x87 // line 1 character 7
#define LCD_u8LINE1_LOC8		0x88 // line 1 character 8
#define LCD_u8LINE1_LOC9		0x89 // line 1 character 9
#define LCD_u8LINE1_LOC10		0x8A // line 1 character 10
#define LCD_u8LINE1_LOC11		0x8B // line 1 character 11
#define LCD_u8LINE1_LOC12		0x8C // line 1 character 12
#define LCD_u8LINE1_LOC13		0x8D // line 1 character 13
#define LCD_u8LINE1_LOC14		0x8E // line 1 character 14
#define LCD_u8LINE1_LOC15		0x8F // line 1 character 15

#define LCD_u8LINE2_LOC0		0xC0 //line 2 character 0
#define LCD_u8LINE2_LOC1		0xC1 //line 2 character 1
#define LCD_u8LINE2_LOC2		0xC2 //line 2 character 2
#define LCD_u8LINE2_LOC3		0xC3 //line 2 character 3
#define LCD_u8LINE2_LOC4		0xC4 //line 2 character 4
#define LCD_u8LINE2_LOC5		0xC5 //line 2 character 5
#define LCD_u8LINE2_LOC6		0xC6 //line 2 character 6
#define LCD_u8LINE2_LOC7		0xC7 //line 2 character 7
#define LCD_u8LINE2_LOC8		0xC8 //line 2 character 8
#define LCD_u8LINE2_LOC9		0xC9 //line 2 character 9
#define LCD_u8LINE2_LOC10		0xCA //line 2 character 10
#define LCD_u8LINE2_LOC11		0xCB //line 2 character 11
#define LCD_u8LINE2_LOC12		0xCC //line 2 character 12
#define LCD_u8LINE2_LOC13		0xCD //line 2 character 13
#define LCD_u8LINE2_LOC14		0xCE //line 2 character 14
#define LCD_u8LINE2_LOC15		0xCF //line 2 character 15


/**********************************************************/
/******************public functions************************/
/**********************************************************/

/* Function name:   LCD_voidInit()
 * Usage:           this function is used to initialize the LCD
 	 	 	 	 	 it sets the functionality of LCD (8 bit mode or 4 bit mode)
 	 	 	 	 	 it sets LCD initial state to be (LCD_ON ,CURSOR_OFF)
 * Declaration:     the declaration  of this function is
                     extern void LCD_voidInit()
 * Parameters:      None
 * Parameters:      None
 */
extern void LCD_voidInit();

/* Function name:   LCD_voidWriteCommand()
 * Usage: 			this function used to send a command to the LCD internal controller

 * Declaration: 	the declaration  of this function is
  					extern void LCD_voidWriteCommand(u8 copy_u8Command)
 * Parameters:	    copy_u8Command: is a variable that holds the 8 bit command to be sent

 * Return Value: None
 */
extern void LCD_voidWriteCommand(u8);

/* Function name:   LCD_voidWriteChar()
 * Usage: 			this function used to send data to be displayed on LCD

 * Declaration: 	the declaration  of this function is
  					extern void LCD_voidWriteChar(u8 copy_u8Data)
 * Parameters:	    copy_u8Data: is a variable that holds the 8 bit data to be displayed
 	 	 	 	 	usually ASCII code for certain character saved in the CGROM of the LCD
 	 	 	 	 	each ASCII is considered address for the character in the CGRAM

 * Return Value:    None
 */
extern void LCD_voidWriteChar(u8);

/* Function name:   LCD_voidWriteString()
 * Usage: 			this function used to send string to be displayed on LCD
 	 	 	 	 	by sending character by character

 * Declaration: 	the declaration  of this function is
  					extern void LCD_voidWriteString(u8* copy_u8String)
 * Parameters:	    copy_u8String: is a pointer to string(character array)

 * Return Value:    None
 */
extern void LCD_voidWriteString(u8*);

/* Function name:   LCD_voidWriteCustomChar()
 * Usage: 			this function used to send string to be displayed on LCD
 	 	 	 	 	by sending character by character

 * Declaration: 	the declaration  of this function is
  					extern void LCD_voidWriteCustomChar(const u8* copy_u8Char, u8 copy_u8charCode)

 * Parameters:	    const u8* copy_u8Char: pointer to array that holds the custom character,each element consider the value of a Row in a custom character

 	 	 	 	 	u8 copy_u8charCode: 8 bit variable thats holds the location of the created custom character in CGRAM

 * Return Value:    None
 */
extern void LCD_voidWriteCustomChar(const u8*, u8);

/* Function name:   LCD_voidClearLine()
 * Usage: 			Clear a specific line in LCD

 * Declaration: 	the declaration  of this function is
  					extern void LCD_voidClearLine(u8 copy_u8Line);

 * Parameters:	    copy_u8Line: 8 bit variable hold the number of line to be cleared (1 or 2)

 * Return Value:    None
 */
extern void LCD_voidClearLine(u8);


#endif /* LCD_INTERFACE_H_ */
