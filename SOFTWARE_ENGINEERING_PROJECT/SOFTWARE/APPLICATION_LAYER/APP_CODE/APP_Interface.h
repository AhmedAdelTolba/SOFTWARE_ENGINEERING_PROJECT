/*
 * APP.h
 *
 *  Created on: Mar 26, 2016
 *      Author: Ahmed
 */

#ifndef SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_
#define SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_

#define APP_u8FlagDown 0

#define APP_u8FlagUp   1


#define APP_u8PM  0

#define  APP_u8AM       1


///////////////////////

#define APP_u8Time 0

#define APP_u8StopWatch 1








/////////////////////////
extern void APP_voidInit(void);

extern u8 APP_u8CheckFlag (void);

extern void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag);

extern void APP_voidDisplay(u8 Copy_u8Time);

extern void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag);

extern u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId);

extern void APP_u8ResumeCounterUpdate(u8 Copy_u81MilliSecondFlag);

extern u32 APP_u32ReadResumeCounter(void);

extern void APP_voidEraseResumeCounter(void);

extern void APP_voidEraseStopWatchCounter(void);





#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_ */
