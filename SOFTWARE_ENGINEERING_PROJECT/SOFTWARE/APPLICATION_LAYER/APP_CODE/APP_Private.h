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

#define APP_u8ModeSwitch TACTILE_u8SWITCH1

extern void APP_voidUpdateCounters (void);

extern void APP_Convert12HoursSystem(u32 APP_u32Timer,u8* Local_u8Time);



#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_PRIVATE_H_ */
