/*
 * TACTILE_SWITCH_interface.h
 *
 *  Created on: Feb 25, 2016
 *      Author: Anwar
 */

#ifndef TACTILE_SWITCH_INTERFACE_H_
#define TACTILE_SWITCH_INTERFACE_H_



#endif /* TACTILE_SWITCH_INTERFACE_H_ */

#define TACTILE_u8SWITCH1 0
#define TACTILE_u8SWITCH2 1
#define TACTILE_u8SWITCH3 2
#define TACTILE_u8SWITCH4 3
#define TACTILE_u8SWITCH5 4
#define TACTILE_u8SWITCH6 5
#define TACTILE_u8SWITCH7 6
#define TACTILE_u8SWITCH8 7



#define TACTILE_u8ACTIVEHIGH 1
#define TACTILE_u8ACTIVELOW  0


#define TACTILE_u8SWITCHPRESSED 1
#define TACTILE_u8SWITCHRELEASED 0



extern void TACTILE_voidInit(void);

/*Comment!: Get Tactile State */

extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal);
