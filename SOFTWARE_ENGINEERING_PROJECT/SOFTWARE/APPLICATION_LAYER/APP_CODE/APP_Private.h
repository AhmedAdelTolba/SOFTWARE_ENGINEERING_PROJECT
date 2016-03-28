/*
 * APP_Private.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Ahmed
 */

#ifndef SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_PRIVATE_H_
#define SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_PRIVATE_H_

#define APP_HOURS 0

#define APP_MinuteS 1

#define APP_Seconds 2

#define APP_u8AMPMFLAG 3

#define APP_u8PM 0

#define APP_u8AM  1

#define APP_FLAGUP 1

#define APP_FLAGDOWN 0

#define APP_u8FULLDAY  90000UL

#define APP_u8INITCOUNTER 3600UL

#define APP_u8ModeSwitch TACTILE_u8SWITCH1

#define APP_u8Start_StopWatch TACTILE_u8SWITCH2


#define APP_u8MaxSwitchTime 3UL

extern void APP_voidUpdateCounters (void);

extern void APP_voidDisplay(u8* Copy_u8Time);

extern u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId);

extern void APP_Convert12HoursSystem(u32 Copy_APP_u32Timer, u8* Copy_Local_u8Time);

extern void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag);

extern u8 APP_u8CheckFlag(void);

extern void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag);




#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_PRIVATE_H_ */
