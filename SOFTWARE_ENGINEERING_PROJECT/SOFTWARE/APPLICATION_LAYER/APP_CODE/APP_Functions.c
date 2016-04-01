/*
 * APP_Functions.c
 *
 *  Created on: Mar 26, 2016
 *      Author: Ahmed
 */
#include "../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include "../../MCAL_LAYER/TIMER/TIMER_CODE/TIMER_interface.h"
#include "../../MCAL_LAYER/DIO/DIO_CODE/DIO_interface.h"
#include "../../HAL_LAYER/LCD/LCD_CODE/LCD_interface.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_CODE/TACTILE_SWITCH_interface.h"
#include "APP_Interface.h"
#include "APP_Private.h"
#include <stdlib.h>
#include<avr/interrupt.h>

volatile static u8 APP_u81MilliCounter = 0;
static u8 App_u8StopWatchFlag = APP_FLAGDOWN;
static u8 App_u8TempTimerFlag = APP_FLAGDOWN;
static u32 APP_u32Timer = APP_u8INITCOUNTER;
static u32 APP_u32StopWatchTimer = 0;
static u32 APP_u32TempTimer = 0;
static u16 APP_u161MilliSecondCounterStopWatch = 0;
static u16 APP_u161MilliSecondTempCounter = 0;
static u8 APP_u8SwitchState[3] =
    {
    TACTILE_u8SWITCHRELEASED, TACTILE_u8SWITCHRELEASED, TACTILE_u8SWITCHRELEASED
    };

void TIMER_ISR(void)
    {

    /*Comment!: increment milliseconds counter */
    APP_u81MilliCounter++;

    return;
    }

void APP_voidInit(void)
    {

    /*Comment!: initialize DIO  */
    DIO_VoidInit();

    /*Comment!: initialize TIMER */
    TIMER_voidInit(TIMER_ISR);

    /*Comment!: initialize LCD */
    LCD_voidInit();

    return;
    }

//check 1ms counter return its value then make it equal 0
extern u8 APP_u8CheckFlag(void)
    {

    u8 Local_u8Result;

    /*Comment!: critical section so global interrupt is disabled */
    cli();

    /*Comment!: check number of milli seconds passed since last timer interrupt */
    Local_u8Result = APP_u81MilliCounter;

    /*Comment!: reset milli seconds counter*/
    APP_u81MilliCounter = 0;

    /*Comment!: end of critical section so global interrupt is enabled */
    sei();

    return Local_u8Result;

    }

extern void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag)
    {

    static u16 Local_u161MilliSecondCounter = 0;

    /*Comment!: increment Local_u161MilliSecondCounter counter */
    /*Comment!: Local_u161MilliSecondCounter represents number of
     * milliseconds passed since last second of timer */
    Local_u161MilliSecondCounter += Copy_u81MilliSecondFlag;

    /*Comment!: check reaching more than or equal 1 second */
    if (Local_u161MilliSecondCounter >= APP_u8ONESECOND)
	{

	/*Comment!: reset Local_u161MilliSecondCounter*/
	Local_u161MilliSecondCounter -= APP_u8ONESECOND;

	/*Comment!: increment number of seconds passed since clock started*/
	APP_u32Timer++;

	}
    else
	{

	}

    /*Comment!: check reaching end of the day*/
    if (APP_u32Timer == APP_u8FULLDAY)
	{

	/*Comment!: reset timer*/
	APP_u32Timer = APP_u8INITCOUNTER;

	}

    return;
    }

extern void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag)
    {

    /*Comment!: increment APP_u161MilliSecondCounterStopWatch counter */
    /*Comment!: APP_u161MilliSecondCounterStopWatch represents number of milliseconds
     *  passed since last second of stop watch */
    APP_u161MilliSecondCounterStopWatch += Copy_u81MilliSecondFlag;

    /*Comment!: check reaching more than or equal 1 second */
    if (APP_u161MilliSecondCounterStopWatch >= APP_u8ONESECOND)
	{

	/*Comment!: reset APP_u161MilliSecondCounterStopWatch*/
	APP_u161MilliSecondCounterStopWatch -= APP_u8ONESECOND;

	/*Comment!: increment number of seconds passed since Stop watch started*/
	APP_u32StopWatchTimer++;

	}
    else
	{

	}

    return;
    }

extern void APP_u8TempCounterUpdate(u8 Copy_u81MilliSecondFlag)
    {

    /*Comment!: increment APP_u161MilliSecondTempCounter counter */
    /*Comment!: APP_u161MilliSecondTempCounter represents number of milliseconds
     *  passed since last second of temp counter */
    APP_u161MilliSecondTempCounter += Copy_u81MilliSecondFlag;

    /*Comment!: check reaching more than or equal 1 second */
    if (APP_u161MilliSecondTempCounter >= APP_u8ONESECOND)
	{

	/*Comment!: reset APP_u161MilliSecondTempCounter*/
	APP_u161MilliSecondTempCounter -= APP_u8ONESECOND;

	/*Comment!: increment number of seconds passed since Stop watch started*/
	APP_u32TempTimer++;

	}
    else
	{

	}

    return;

    }

extern void APP_voidUpdateTimers(void)

    {

    u8 Local_u81MilliSecondFlag;

    /*Comment!: check if at least one millisecond have passed since
     * last update for system counters  */
    Local_u81MilliSecondFlag = APP_u8CheckFlag();

    /*Comment!: update system time */
    APP_u8TimeUpdate(Local_u81MilliSecondFlag);

    /*Comment!: check if stop watch should be updated*/
    if (App_u8StopWatchFlag == APP_FLAGUP)
	{

	/*Comment!: update stop watch*/
	APP_u8StopWatchUpdate(Local_u81MilliSecondFlag);

	}
    else
	{

	}

    /*Comment!: check if temp counter should be updated*/
    if (App_u8TempTimerFlag == APP_FLAGUP)
	{

	/*Comment!:update temp counter */
	APP_u8TempCounterUpdate(Local_u81MilliSecondFlag);

	}
    else
	{

	}

    return;

    }

//convert to 12hours system
void APP_voidConvertto12HoursSystem(u32 Copy_APP_u32Timer, u8* Copy_Local_u8Time)
    {

    u32 Local_u32Timer;

    /*Comment!: convert time to hours only*/
    Local_u32Timer = Copy_APP_u32Timer / 3600;

    /*Comment!: check if time should be A.M or P.M*/
    if (Local_u32Timer >= 1 && Local_u32Timer < 13)
	{

	/*Comment!:Write AM  */
	Copy_Local_u8Time[APP_u8AMPMFLAG] = APP_u8AM;

	/*Comment!: if time is 12 hours so it turns to P.M not A.M*/
	if (Local_u32Timer == 12UL)
	    {

	    Copy_Local_u8Time[APP_u8AMPMFLAG] = APP_u8PM;

	    }
	else
	    {
	    }

	Local_u32Timer = Copy_APP_u32Timer;

	}

    else if (Local_u32Timer >= 13)
	{

	/*Comment!: Write P.M*/

	Copy_Local_u8Time[APP_u8AMPMFLAG] = APP_u8PM;

	/*Comment!: if hours=24 so time should be A.M not P.M*/
	if (Local_u32Timer == 24UL)
	    {

	    Copy_Local_u8Time[APP_u8AMPMFLAG] = APP_u8AM;

	    }

	else
	    {
	    }

	/*Comment!:after choosing P.M so number of hours = hours-(12 hour) */
	Local_u32Timer = Copy_APP_u32Timer - (12 * 60 * 60UL);

	}

    else
	{

	/*Comment!:i don't remember why i added this one ,i will leave it till i remember */
	Local_u32Timer = Copy_APP_u32Timer;

	}

    /*Comment!:get number of hours */
    Copy_Local_u8Time[APP_HOURS] = Local_u32Timer / 3600;

    /*Comment!:get number of minutes */
    Copy_Local_u8Time[APP_MinuteS] = (Local_u32Timer % 3600) / 60;

    /*Comment!:get number of seconds */
    Copy_Local_u8Time[APP_Seconds] = ((Local_u32Timer % 3600) % 60);

    return;
    }

extern u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId)
    {

    u8 local_u8CurrentSwitchState;

    u8 Local_u8Result;

    /*Comment!:Read Switch */
    TACTILE_u8GetState(Copy_u8SwitchId, &local_u8CurrentSwitchState);

    /*Comment!:if current_read=released & previous_read=pressed
     * so return pressed else return released  */
    if ((local_u8CurrentSwitchState == TACTILE_u8SWITCHRELEASED) && (APP_u8SwitchState[Copy_u8SwitchId] !=
    TACTILE_u8SWITCHRELEASED))
	{

	Local_u8Result = TACTILE_u8SWITCHPRESSED;

	}
    else
	{

	Local_u8Result = TACTILE_u8SWITCHRELEASED;

	}

    /*Comment!:previous state of switch=current state */
    APP_u8SwitchState[Copy_u8SwitchId] = local_u8CurrentSwitchState;

    return Local_u8Result;

    }

extern void APP_voidDisplay(u8* Copy_u8Time)

    {

    char Local_u8TempChar[6];

    /*Comment!:go to start of first line */
    LCD_voidWriteCommand(LCD_u8LINE1);

    /*Comment!:write time to lcd (write character by character)*/
    itoa(Copy_u8Time[APP_HOURS] / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Copy_u8Time[APP_HOURS] % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    LCD_voidWriteChar(':');

    itoa(Copy_u8Time[APP_MinuteS] / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Copy_u8Time[APP_MinuteS] % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    LCD_voidWriteChar(':');

    itoa(Copy_u8Time[APP_Seconds] / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Copy_u8Time[APP_Seconds] % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    if (Copy_u8Time[APP_u8AMPMFLAG] == APP_u8PM)
	{
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar('P');
	LCD_voidWriteChar('M');

	}

    else if (Copy_u8Time[APP_u8AMPMFLAG] == APP_u8AM)
	{
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar('A');
	LCD_voidWriteChar('M');

	}
    else
	{

	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');

	}

    return;
    }

u8 APP_u8Timer(void)
    {

    u8 Local_u8Time[4];
    u8 Local_u8SwitchResult;

    do
	{

	/*Comment!:update system timer */
	APP_voidUpdateTimers();

	/*Comment!:convert time to 12 hours system */
	APP_voidConvertto12HoursSystem(APP_u32Timer, &Local_u8Time);

	/*Comment!:write time to lcd */
	APP_voidDisplay(&Local_u8Time);

	/*Comment!:read mode switch */
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	} while (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED);

    /*Comment!:go to APP_STOP_WATCH_STANDBY state */
    return APP_STOP_WATCH_STANDBY;

    }

u8 APP_u8APP_STOP_WATCH_STANDBY(void)
    {

    u8 Local_u8Time[4];
    u8 Local_u8SwitchResult;
    u8 Local_u8ReturnCase = APP_STOP_WATCH_STANDBY;

    do
	{

	/*Comment!:update system counter*/
	APP_voidUpdateTimers();

	/*Comment!:convert time(0) to 12 hours system*/
	APP_voidConvertto12HoursSystem(0, &Local_u8Time);

	/*Comment!:write any garbage to prevent writing A.M or P.M to lcd */
	Local_u8Time[3] = 'x';

	/*Comment!:write time(0) to lcd*/
	APP_voidDisplay(&Local_u8Time);

	/*Comment!:read mode switch */
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	/*Comment!:if pressed go to APP_EDIT_TIME mode */
	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

	    {

	    Local_u8ReturnCase = APP_EDIT_TIME;

	    }

	else
	    {

	    /*Comment!:read Start_StopWatch */
	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8Start_StopWatch);

	    /*Comment!:if pressed go to APP_STOP_WATCH mode*/
	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		Local_u8ReturnCase = APP_STOP_WATCH;

		}
	    else
		{
		}

	    }

	} while (Local_u8ReturnCase == APP_STOP_WATCH_STANDBY);

    return Local_u8ReturnCase;

    }

extern u8 APP_u8APP_STOP_WATCH(void)
    {

    u8 Local_u8Time[4];
    u8 Local_u8SwitchResult;
    u8 Local_u8ReturnCase = APP_STOP_WATCH;

    App_u8StopWatchFlag = APP_FLAGUP;

    do
	{

	/*Comment!:update system time*/
	APP_voidUpdateTimers();

	/*Comment!:convert stop watch time to 12 hours mode*/
	APP_voidConvertto12HoursSystem(APP_u32StopWatchTimer, &Local_u8Time);

	/*Comment!:write garbage to prevent writing A.M or P.M to lcd*/
	Local_u8Time[3] = 'x';

	/*Comment!:write stop watch time to lcd*/
	APP_voidDisplay(&Local_u8Time);

	/*Comment!:read mode switch*/
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

	    {

	    /*Comment!:reset stop watch */
	    APP_u32StopWatchTimer = 0;

	    /*Comment!:stop updating stop watch*/
	    App_u8StopWatchFlag = APP_FLAGDOWN;

	    /*Comment!:if pressed go to APP_EDIT_TIME state*/
	    Local_u8ReturnCase = APP_EDIT_TIME;

	    }

	else
	    {
	    /*Comment!:read Start_StopWatch switch*/
	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8Start_StopWatch);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		/*Comment!:if pressed go to APP_STOP_WATCH_PAUSE state*/
		Local_u8ReturnCase = APP_STOP_WATCH_PAUSE;

		/*Comment!:stop updating stop watch*/
		App_u8StopWatchFlag = APP_FLAGDOWN;

		}
	    else
		{
		}

	    }

	} while (Local_u8ReturnCase == APP_STOP_WATCH);

    return Local_u8ReturnCase;

    }

extern u8 APP_u8APP_STOP_WATCH_PAUSE(void)
    {

    u8 Local_u8Time[4];
    u8 Local_u8SwitchResult;
    u8 Local_u8ReturnCase = APP_STOP_WATCH_PAUSE;

    do
	{

	/*Comment!:update system time*/
	APP_voidUpdateTimers();

	/*Comment!:convert to 12 hours system*/
	APP_voidConvertto12HoursSystem(APP_u32StopWatchTimer, &Local_u8Time);

	/*Comment!:write garbage to prevent writing A.M or P.M to lcd*/
	Local_u8Time[3] = 'x';

	/*Comment!:write stop watch time to lcd*/
	APP_voidDisplay(&Local_u8Time);

	/*Comment!:read mode switch*/
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

	    {

	    /*Comment!:reset stop watch counter*/
	    APP_u32StopWatchTimer = 0;

	    /*Comment!:change state*/
	    Local_u8ReturnCase = APP_EDIT_TIME;

	    }

	else
	    {

	    /*Comment!:read Start_StopWatch switch*/
	    TACTILE_u8GetState(APP_u8Start_StopWatch, &Local_u8SwitchResult);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		/*Comment!:change state*/
		Local_u8ReturnCase = APP_RESUME_STAND_BY;

		/*Comment!:start temp counter*/
		App_u8TempTimerFlag = APP_FLAGUP;

		}
	    else
		{
		}

	    }

	} while (Local_u8ReturnCase == APP_STOP_WATCH_PAUSE);

    return Local_u8ReturnCase;

    }

extern u8 APP_u8APP_RESUME_STAND_BY(void)

    {

    u8 Local_u8Time[4];
    u8 Local_u8SwitchResult;
    u8 Local_u8ReturnCase = APP_RESUME_STAND_BY;

    do
	{

	/*Comment!:update system time*/
	APP_voidUpdateTimers();

	/*Comment!:convert to 12 hours mode*/

	APP_voidConvertto12HoursSystem(APP_u32StopWatchTimer, &Local_u8Time);

	/*Comment!:write garbage to prevent writing A.M or P.M to lcd*/
	Local_u8Time[3] = 'x';

	/*Comment!:write stop watch time to lcd*/
	APP_voidDisplay(&Local_u8Time);

	/*Comment!:read Start_StopWatch switch state*/
	TACTILE_u8GetState(APP_u8Start_StopWatch, &Local_u8SwitchResult);

	if (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED)

	    {

	    /*Comment!:Stop updating temp counter*/
	    App_u8TempTimerFlag = APP_FLAGDOWN;

	    if (APP_u32TempTimer >= APP_u8MaxSwitchTime)
		{

		/*Comment!:Change state*/
		Local_u8ReturnCase = APP_STOP_WATCH;

		/*Comment!:reset APP_u161MilliSecondTempCounter*/
		APP_u161MilliSecondTempCounter = 0;

		/*Comment!:reset APP_u32TempCounter*/
		APP_u32TempTimer = 0;

		}
	    else
		{

		/*Comment!:Change state*/
		Local_u8ReturnCase = APP_STOP_WATCH;

		/*Comment!:reset APP_u161MilliSecondTempCounter*/
		APP_u161MilliSecondTempCounter = 0;

		/*Comment!:reset APP_u32TempCounter*/
		APP_u32TempTimer = 0;

		/*Comment!:reset APP_u161MilliSecondCounterStopWatch*/
		APP_u161MilliSecondCounterStopWatch = 0;

		/*Comment!:reset APP_u32StopWatch*/
		APP_u32StopWatchTimer = 0;

		}

	    }

	else
	    {

	    }

	} while (Local_u8ReturnCase == APP_RESUME_STAND_BY);

    return Local_u8ReturnCase;

    }

extern u8 APP_u8APP_EDIT_TIME(void)

    {

    u8 Local_u8Time[4];
    u8 Local_u8TimeView[4];
    u8 Local_u8SwitchResult;
    u32 Local_u32TimeSnapShot;
    u32 Local_u32Temp;
    u8 Local_u8NumOfPresses = 0;

    /*Comment!:store snapshot of timer*/
    Local_u32TimeSnapShot = APP_u32Timer;

    /*Comment!:Convert time to 12 hours mode*/
    APP_voidConvertto12HoursSystem(Local_u32TimeSnapShot, &Local_u8Time);

    do
	{

	/*Comment!:update system time*/
	APP_voidUpdateTimers();

	/*Comment!:make copy of time*/
	for (u8 Local_u8LoopCounter = 0; Local_u8LoopCounter < 4; Local_u8LoopCounter++)
	    {
	    Local_u8TimeView[Local_u8LoopCounter] = Local_u8Time[Local_u8LoopCounter];
	    }

	/*Comment!:write the copy of time to lcd*/
	APP_voidDisplayFlasher(&Local_u8TimeView);

	/*Comment!:read mode switch*/
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	if (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED)

	    {

	    /*Comment!:read increment switch*/
	    TACTILE_u8GetState(APP_u8IncreamentSwitch, &Local_u8SwitchResult);

	    if (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED)
		{
		}

	    else
		{

		/*Comment!:start temp counter*/
		App_u8TempTimerFlag = APP_FLAGUP;

		/*Comment!:increment time */
		APP_voidChangeTime(Local_u8Time, Local_u8NumOfPresses, APP_u8Increament);

		}

	    /*Comment!:read decrement switch*/
	    TACTILE_u8GetState(APP_u8DecreamentSwitch, &Local_u8SwitchResult);

	    if (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED)
		{
		}

	    else
		{

		/*Comment!:start temp counter*/
		App_u8TempTimerFlag = APP_FLAGUP;

		/*Comment!:decrement time*/
		APP_voidChangeTime(Local_u8Time, Local_u8NumOfPresses, APP_u8Decreament);

		}

	    }

	else
	    {

	    /*Comment!:increment number of presses of mode switch*/
	    Local_u8NumOfPresses++;

	    }

	/*Comment!:Change modified time to 24 hours system*/
	Local_u32Temp = APP_u32Convertto24hourssystem(Local_u8Time);

	/*Comment!:check if time was modified or not*/
	if (Local_u32Temp != Local_u32TimeSnapShot)

	    {

	    APP_u32Timer = Local_u32Temp;

	    }

	else
	    {

	    }

	} while (Local_u8NumOfPresses < 4);

    /*Comment!:go to APP_TIMER state*/
    return APP_TIMER;

    }

extern void APP_voidDisplayFlasher(u8*Copy_u8TimeView)
    {

    /*Comment!:write time to lcd*/
    APP_voidDisplay(Copy_u8TimeView);

    return;
    }

extern void APP_voidChangeTime(u8* Copy_u8Time, u8 Copy_u8Index, u8 Copy_u8State)
    {

    u8 Local_u8SwitchResult;
    u8 Local_u8Counter = 0;
    u8 Local_u8Time_LIMITS[4] =
	{
	12, 59, 59, 1
	};
    u8 Local_SingleEditFlag = APP_FLAGUP;

    do
	{

	/*Comment!:update system time*/
	APP_voidUpdateTimers();

	/*Comment!:write time to lcd */
	APP_voidDisplayFlasher(Copy_u8Time);

	/*Comment!:read increment or decrement switch based on
	 * passed parameters to the function*/
	TACTILE_u8GetState(Copy_u8State, &Local_u8SwitchResult);

	/*Comment!:switch is pressed more than certain time  */
	if (APP_u32TempTimer >= APP_u8TimeOfPressingSwitch)
	    {

	    /*Comment!:this counter is used to slow down changing numbers on screen */
	    Local_u8Counter++;

	    /*Comment!:check if time should be incremented*/
	    if (Copy_u8State == APP_u8Increament && Local_u8Counter == APP_u8ChangingSpeed)
		{

		/*Comment!:reset counter*/
		Local_u8Counter = 0;

		/*Comment!:increment time item*/
		Copy_u8Time[Copy_u8Index]++;

		    /*Comment!:check if time item exceed its limit */
		if (Copy_u8Time[Copy_u8Index] > Local_u8Time_LIMITS[Copy_u8Index])
		    {

		    /*Comment!:fixing a bug that hours shouldn't be zero */
		    if (Copy_u8Index != APP_HOURS)
			{

			Copy_u8Time[Copy_u8Index] = 0;

			}
		    else
			{
			Copy_u8Time[Copy_u8Index] = 1;
			}

		    }
		else
		    {

		    }

		}
	    else if (Copy_u8State == APP_u8Decreament && Local_u8Counter == APP_u8ChangingSpeed)
		{

		    /*Comment!:reset counter */
		Local_u8Counter = 0;

		if (Copy_u8Time[Copy_u8Index] > 0)
		    {
		    Copy_u8Time[Copy_u8Index]--;
		    }
		else
		    {
		    Copy_u8Time[Copy_u8Index] = Local_u8Time_LIMITS[Copy_u8Index];
		    }

		    /*Comment!:fixing a bug that hours shouldn't be zero */
		if (Copy_u8Time[Copy_u8Index] == 0 && Copy_u8Index == APP_HOURS)
		    {
		    Copy_u8Time[Copy_u8Index] = Local_u8Time_LIMITS[Copy_u8Index];

		    }
		else
		    {
		    }

		}
	    else
		{

		}

	    /*Comment!: don't edit time again*/
	    Local_SingleEditFlag = APP_FLAGDOWN;

	    }
	else
	    {

	    }

	} while (Local_u8SwitchResult != TACTILE_u8SWITCHRELEASED);

    /*Comment!:check if time should be edited */
    if (Local_SingleEditFlag == APP_FLAGUP)
	{

	if (Copy_u8State == APP_u8Increament)
	    {
	    Copy_u8Time[Copy_u8Index]++;

	    if (Copy_u8Time[Copy_u8Index] > Local_u8Time_LIMITS[Copy_u8Index])
		{

		if (Copy_u8Index != APP_HOURS)
		    {

		    Copy_u8Time[Copy_u8Index] = 0;

		    }
		else
		    {
		    Copy_u8Time[Copy_u8Index] = 1;
		    }

		}
	    else
		{

		}
	    }
	else if (Copy_u8State == APP_u8Decreament)
	    {

	    if (Copy_u8Time[Copy_u8Index] > 0)
		{
		Copy_u8Time[Copy_u8Index]--;
		}
	    else
		{
		Copy_u8Time[Copy_u8Index] = Local_u8Time_LIMITS[Copy_u8Index];
		}

	    if (Copy_u8Time[Copy_u8Index] == 0 && Copy_u8Index == APP_HOURS)
		{
		Copy_u8Time[Copy_u8Index] = Local_u8Time_LIMITS[Copy_u8Index];

		}
	    else
		{
		}

	    }
	else
	    {

	    }
	}

    else
	{

	}

    APP_u32TempTimer = 0;

    APP_u161MilliSecondTempCounter = 0;

    App_u8TempTimerFlag = APP_FLAGDOWN;

    return;
    }

extern u32 APP_u32Convertto24hourssystem(u8* Local_u8Time)
    {

    u32 Local_u32Timer = APP_u8INITCOUNTER;

    Local_u32Timer = Local_u8Time[APP_HOURS] * 3600UL;

    Local_u32Timer += Local_u8Time[APP_MinuteS] * 60UL;

    Local_u32Timer += Local_u8Time[APP_Seconds];

    if (Local_u8Time[APP_u8AMPMFLAG] == APP_u8PM && (Local_u8Time[APP_HOURS]!=12))
	{

	Local_u32Timer += (3600UL * 12UL);

	}

    if (Local_u8Time[APP_u8AMPMFLAG] == APP_u8AM && (Local_u8Time[APP_HOURS]==12))
   	{

   	Local_u32Timer += (3600UL * 12UL);

   	}

    return Local_u32Timer;
    }
