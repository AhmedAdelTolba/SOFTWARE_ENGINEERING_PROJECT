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

#define APP_u8ONESECOND 1000UL

#define APP_u8ModeSwitch TACTILE_u8SWITCH1

#define APP_u8Start_StopWatch TACTILE_u8SWITCH2

#define APP_u8IncreamentSwitch TACTILE_u8SWITCH2

#define APP_u8DecreamentSwitch TACTILE_u8SWITCH3

#define APP_u8Increament 1

#define APP_u8Decreament 2

#define APP_u8TimeOfPressingSwitch 3

#define APP_u8ChangingSpeed 30

#define APP_u8MaxSwitchTime 3UL

    /*Comment!: add a second to the timer if  it reached 1000 millisecond*/
extern void APP_voidUpdateTimers (void);

/*Comment!: display time at lcd*/
extern void APP_voidDisplay(u8* Copy_u8Time);

/*Comment!: read switch at single press mode*/
extern u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId);

/*Comment!: Convert to 12 hours system*/
extern void APP_voidConvertto12HoursSystem(u32 Copy_APP_u32Timer, u8* Copy_Local_u8Time);

/*Comment!: update system's clock*/
extern void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag);

/*Comment!: update number of seconds passed since this function was called*/
extern u8 APP_u8CheckFlag(void);

/*Comment!: update stop watch clock*/
extern void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag);

/*Comment!: Display time at lcd*/
extern void APP_voidDisplayFlasher(u8*Local_u8TimeView);

/*Comment!: change time item(hours,minutes,seconds,AM or PM)*/
extern void APP_voidChangeTime(u8* Copy_u8Time,u8 Copy_u8Index,u8 Copy_u8State);

extern u32 APP_u32Convertto24hourssystem(u8* Local_u8Time);


#endif /* SOFTWARE_APPLICATION_LAYER_APP_CODE_APP_PRIVATE_H_ */
