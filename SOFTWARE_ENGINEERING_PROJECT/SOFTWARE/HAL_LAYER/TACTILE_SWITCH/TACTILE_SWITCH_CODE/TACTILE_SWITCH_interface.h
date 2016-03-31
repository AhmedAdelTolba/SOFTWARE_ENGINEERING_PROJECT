/*
 * TACTILE_SWITCH_interface.h
 *
 *  Created on: Feb 25, 2016
 *      Author: Anwar
 */

#ifndef TACTILE_SWITCH_INTERFACE_H_
#define TACTILE_SWITCH_INTERFACE_H_

/**********************************************************/
/******************public definition***********************/
/**********************************************************/

/*Comment!: SWITCH NUMBER */
#define TACTILE_u8SWITCH1 0
#define TACTILE_u8SWITCH2 1
#define TACTILE_u8SWITCH3 2
#define TACTILE_u8SWITCH4 3
#define TACTILE_u8SWITCH5 4
#define TACTILE_u8SWITCH6 5
#define TACTILE_u8SWITCH7 6
#define TACTILE_u8SWITCH8 7


/*Comment!: SWITCH CONNECTION TYPE */
#define TACTILE_u8ACTIVEHIGH 1
#define TACTILE_u8ACTIVELOW  0

/*Comment!: SWITCH CONNECTION TYPE */
#define TACTILE_u8SWITCHPRESSED 1
#define TACTILE_u8SWITCHRELEASED 0

/**********************************************************/
/******************public functions************************/
/**********************************************************/

/*Comment!: INIT SWITCHES */
extern void TACTILE_voidInit(void);

/* Function name:   TACTILE_u8GetState()
 * Usage: 			this function gets switch state

 * Declaration: 	the declaration  of this function is
  					extern void TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal)
 * Parameters:	    Copy_u8SwitchNumber: switch index you want to check state
					Copy_u8PtrToVal:returns pressed or not pressed
 * Return Value: 	error or  not
 */extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal);


#endif /* TACTILE_SWITCH_INTERFACE_H_ */

