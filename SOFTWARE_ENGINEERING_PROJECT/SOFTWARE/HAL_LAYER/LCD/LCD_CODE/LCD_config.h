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
#define LCD_u8D0	DIO_u8PIN8
#define LCD_u8D1	DIO_u8PIN9
#define LCD_u8D2	DIO_u8PIN10
#define LCD_u8D3	DIO_u8PIN11
#define LCD_u8D4	DIO_u8PIN12
#define LCD_u8D5	DIO_u8PIN13
#define LCD_u8D6	DIO_u8PIN14
#define LCD_u8D7	DIO_u8PIN15

/* Comment!: control pins*/
/* Range!: DIO_u8PIN0 ~ DIO_u8PIN31 */
#define LCD_u8RS		DIO_u8PIN24
#define LCD_u8RW		DIO_u8PIN25
#define LCD_u8ENABLE	DIO_u8PIN26

/* Comment!: initial state */
/* Range!: LCD_u8ON ~ LCD_u8OFF*/
#define LCD_u8INIT_STATE	DISPON_CURSOFF

/*Comment!: LCD Mode */
/*Range!: LCD_u8_4bit ~ LCD_u8_8bit */
#define LCD_u8Mode		LCD_u8_8bit

#endif /* LCD_CONFIG_H_ */
