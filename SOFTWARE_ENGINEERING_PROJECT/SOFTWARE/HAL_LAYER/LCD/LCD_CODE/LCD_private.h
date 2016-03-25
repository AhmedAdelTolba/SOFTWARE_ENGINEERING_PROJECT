/*
 * LCD_private.h
 *
 *  Created on: Mar 9, 2016
 *      Author: seif
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
/* functionality set command */
#if LCD_u8Mode == LCD_u8_8bit
#define FUNC_SET_1LINE		0x30	//set lcd to work in 1 line mode
#define FUNC_SET_2LINE		0x38    //set lcd to work in 2 line mode
#else
#define FUNC_SET_1LINE		0x20	//set lcd to wok in 1 line mode
#define FUNC_SET_2LINE		0x28	//set lcd to work in 2 line mode
#endif

/*Comment!: CGRAM number of locations */
#define LCD_u8CGRAM_LOCATIONS	8

/*Comment!: CGRAM first location */
#define LCD_u8CGRAM_ADD		0x40

#endif /* LCD_PRIVATE_H_ */
