/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: G
 */
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
/*********************************************************************/
/***********************public def***********************************/
/*******************************************************************/

/*comment!:pin index values*/
#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7
#define DIO_u8PIN8 8
#define DIO_u8PIN9 9
#define DIO_u8PIN10 10
#define DIO_u8PIN11 11
#define DIO_u8PIN12 12
#define DIO_u8PIN13 13
#define DIO_u8PIN14 14
#define DIO_u8PIN15 15
#define DIO_u8PIN16 16
#define DIO_u8PIN17 17
#define DIO_u8PIN18 18
#define DIO_u8PIN19 19
#define DIO_u8PIN20 20
#define DIO_u8PIN21 21
#define DIO_u8PIN22 22
#define DIO_u8PIN23 23
#define DIO_u8PIN24 24
#define DIO_u8PIN25 25
#define DIO_u8PIN26 26
#define DIO_u8PIN27 27
#define DIO_u8PIN28 28
#define DIO_u8PIN29 29
#define DIO_u8PIN30 30
#define DIO_u8PIN31 31
/*******************************************/

/*comment!:PORT index values*/
#define DIO_u8PORT0  0
#define DIO_u8PORT1  1
#define DIO_u8PORT2  2
#define DIO_u8PORT3  3
/***************************/

/*comment!:Digital I/O value */
#define DIO_u8HIGH   1
#define DIO_u8LOW   0
/****************************/

/*comment!:Digital I/O Direction */
#define DIO_u8INPUT   0
#define DIO_u8OUTPUT  1
/*********************************/



/*********************************************************************/
/***************************public function***************************/
/*********************************************************************/
/* Function name:   DIO_u8ReadPinVal()
 * Usage:           this function is used to read pin value
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8ReadPinVal(u8 copy_ChIdx,u8* copy_u8ptrToVal)
 * Parameters:      u8 copy_u8ChIdx this is the pin that i want to write on it
 * 					Range! copy_u8ChIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15
 * 										  16-17-18-19-20-21-22-23-24-25-26-27-
 * 										  28-29-30-31
 *
 * Parameters:		u8 copy_u8portVal this is the value of the pin high = 1 or low = 0
 * 					Range! copy_u8PortVal:0-1
 */
extern u8 DIO_u8ReadPinVal(u8,u8*);

/* Function name:   DIO_u8WritePinVal()
 * Usage:           this function is used to set any pin to high=1 or to set it to low=0
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8WritePinVal(u8 copy_u8ChIdx,u8 copy_u8PinVal)
 * Parameters:      u8 copy_u8ChIdx this is the pin that i want to write on it
 * 					Range! copy_u8ChIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18
 * 					-19-20-21-22-23-24-25-26-27-28-29-30-31
 * Parameters:		u8 copy_u8PinVal this is the value of the pin high = 1 or low = 0
 * 					Range! :copy_u8PtrToDir:any variable
 */
extern u8 DIO_u8WritePinVal(u8,u8);

/* Function name:   DIO_u8ReadPortVal()
 * Usage:           this function is used to read port value
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8ReadPortVal(u8 copy_u8PortIdx,u8* copy_u8ptrToVal)
 * Parameters:      u8 copy_u8PortIdx this is the port that i want to set it's direction
 * 					Range! :copy_u8PinIdx : 0-1-2-3
 * Parameters:		u8* copy_u8PtrToDir this is to take any variable i want to put in it the port direction
 * 					Range! :copy_u8PtrToDir:any variable
 */
extern u8 DIO_u8ReadPortVal(u8,u8*);
/* Function name:   DIO_u8WritePortVal()
 * Usage:           this function is used to set port to high=1 or to set it to low=0
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8WritePortVal(u8 copy_u8PortIdx,u8 copy_u8PortVal)
  * Parameters:     u8 copy_u8PortIdx this is the port that i want to set it's direction
 * 					Range! copy_u8portIdx : 0-1-2-3
 * Parameters:		u8 copy_u8portVal this is the value of the pin high = 1 or low = 0
 * 					Range! copy_u8PortVal:0-1
 */

extern u8 DIO_u8WritePortVal(u8 copy_u8PortIdx,u8 copy_u8PortVal);




/* Function name:   DIO_u8WritePinDir()
 * Usage:           this function is used to set pin direction to input=0 or to output=1
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8WritePinDir(u8 copy_u8PinIdx,u8 copy_u8PinDir)
 * Parameters:      u8 copy_u8PortIdx this is the port that i want to set it's direction
 * 					Range! :copy_u8PinIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-
 * 					18-19-20-21-22-23-24-25-26-27-28-29-30-31
 * Parameters:		u8 copy_u8PinDir this is the value of the pin output = 1 or input = 0
 * 					Range! :copy_u8PinDir:0-1
 */
extern u8 DIO_u8WritePinDir(u8,u8);

/* Function name:   DIO_u8WritePortDir()
 * Usage:           this function is used to set port direction to input=0 or to output=1
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8WritePinDir(u8 copy_u8PinIdx,u8 copy_u8PinDir)
 * Parameters:      u8 copy_u8PortIdx this is the port that i want to set it's direction
 * 					Range! :copy_u8PortIdx : 0-1-2-3
 * Parameters:		u8 copy_u8PortDir this is the value of the port output = 1 or input = 0
 * 					Range! :copy_u8PortDir:0-1
 */
extern u8 DIO_u8WritePortDir(u8,u8);

/* Function name:   DIO_u8ReadPinDir()
 * Usage:           this function is used to read pin direction
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8ReadPinDir(u8 copy_u8PinIdx,u8* copy_u8PtrToDir);
 * Parameters:      u8 copy_u8PinIdx this is the port that i want to set it's direction
 * 					Range! :copy_u8PinIdx : 1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18
 * 					-19-20-21-22-23-24-25-26-27-28-29-30-31
 * Parameters:		u8* copy_u8PtrToDir this is to take any variable i want to put in it the port direction
 * 					Range! :copy_u8PtrToDir:any variable
 */
extern u8 DIO_u8ReadPinDir(u8,u8*);

/* Function name:   DIO_u8ReadPortDir()
 * Usage:           this function is used to read port direction
 * Declaration:     the declaration  of this function is
                    extern u8 DIO_u8ReadPinDir(u8 copy_u8PinIdx,u8* copy_u8PtrToDir);
 * Parameters:      u8 copy_u8PortIdx this is the port that i wante to set it's direction
 * 					Range! :copy_u8PortIdx : 0-1-2-3
 * Parameters:		u8* copy_u8PtrToDir this is to take any variable i want to put in it the port direction
 * 					Range! :copy_u8PtrToDir:any variable
 */
extern u8 DIO_u8ReadPortDir(u8,u8*);

/* Function name:   DIO_VoidInit()
 * Usage:           this function is used to set initial values of port value and direction
 * Declaration:     the declaration  of this function is
                    extern void DIO_VoidInit()
 * Parameters:      NO
 * Parameters:		NO
 */
/****************************NOTE*****************************/
/*to set those in those initial values check the DIO_config.h*/
/***********************************************************/
extern void DIO_VoidInit(void);
#endif /*DIO_INTERFACE_H_*/
/*************************************************************************/

