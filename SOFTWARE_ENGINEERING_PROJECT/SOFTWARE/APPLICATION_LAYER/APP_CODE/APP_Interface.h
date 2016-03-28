/*
 * APP.h
 *
 *  Created on: Mar 26, 2016
 *      Author: Ahmed
 */

#ifndef SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_
#define SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_

//#define APP_u8FlagDown 0
//
//#define APP_u8FlagUp   1
//
//
//#define APP_u8PM  0
//
//#define  APP_u8AM       1


///////////////////////

//#define APP_u8Time 0
//
//#define APP_u8StopWatch 1
//
//
//
///////////////////////
#define APP_TIMER              0

#define APP_STOP_WATCH_STANDBY 1

#define APP_STOP_WATCH         2

#define APP_EDIT_TIME          3

#define APP_STOP_WATCH_PAUSE   4

#define APP_RESUME_STAND_BY   5
//
//
//
///////////////////////////
extern void APP_voidInit(void);

extern u8 APP_u8Timer(void);

extern u8 APP_u8APP_STOP_WATCH_STANDBY(void);

extern u8 APP_u8APP_STOP_WATCH(void);

extern u8 APP_u8APP_STOP_WATCH_PAUSE(void);

extern u8 APP_u8APP_RESUME_STAND_BY(void);



//
//extern u8 APP_u8CheckFlag (void);
//
//extern void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag);
//
//extern void APP_voidDisplay(u8 Copy_u8Time);
//
//extern void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag);
//
//extern u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId);
//
//extern void APP_u8ResumeCounterUpdate(u8 Copy_u81MilliSecondFlag);
//
//extern u32 APP_u32ReadResumeCounter(void);
//
//extern void APP_voidEraseResumeCounter(void);
//
//extern void APP_voidEraseStopWatchCounter(void);
//
//extern u32 APP_u32ReadTimer(void);
//
//extern void APP_voidEdittime(u32 Local_u32timer);




#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_INTERFACE_H_ */
