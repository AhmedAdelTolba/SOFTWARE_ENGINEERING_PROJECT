/*
 * LCD_config.h
 *
 *  Created on: Mar 9, 2016
 *      Author: seif
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/***************************************************************************/
/* Comment!: Data pins*/
/* Range!: DIO_u8PIN0 ~ DIO_u8PIN31 */
#define LCD_u8D0	DIO_u8PIN0
#define LCD_u8D1	DIO_u8PIN1
#define LCD_u8D2	DIO_u8PIN2
#define LCD_u8D3	DIO_u8PIN3
#define LCD_u8D4	DIO_u8PIN4
#define LCD_u8D5	DIO_u8PIN5
#define LCD_u8D6	DIO_u8PIN6
#define LCD_u8D7	DIO_u8PIN7

/* Comment!: control pins*/
/* Range!: DIO_u8PIN0 ~ DIO_u8PIN31 */
#define LCD_u8RS		DIO_u8PIN8
#define LCD_u8RW		DIO_u8PIN9
#define LCD_u8ENABLE	DIO_u8PIN10

/* Comment!: initial state */
/* Range!: LCD_u8ON ~ LCD_u8OFF*/
#define LCD_u8INIT_STATE	DISPON_CURSOFF

/*Comment!: LCD Mode */
/*Range!: LCD_u8_4bit ~ LCD_u8_8bit */
#define LCD_u8Mode		LCD_u8_8bit

#endif /* LCD_CONFIG_H_ */
