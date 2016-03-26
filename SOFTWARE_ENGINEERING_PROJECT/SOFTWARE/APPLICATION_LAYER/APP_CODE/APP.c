/*
 * APP.c
 *
 *  Created on: Mar 26, 2016
 *      Author: Ahmed
 */
#include"../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_CODE/TACTILE_SWITCH_interface.h"
#include"APP_Interface.h"

#define APP_STOP_WATCH_STANDBY 1
#define APP_TIMER      0
#define APP_STOP_WATCH 2
#define APP_STOP_WATCH_PAUSE 3
#define APP_RESUME_STAND_BY  4
#define APP_EDIT_TIME        5

#define APP_u8Start_StopWatch TACTILE_u8SWITCH2

#define APP_FLAGUP     1
#define APP_FLAGDOWN     0

int main(void)
    {

    u8 Local_u8State = APP_EDIT_TIME;
    u8 Local_u81MilliSecondFlag;
    u8 Local_u8StopWatchFlag = APP_FLAGDOWN;
    u8 Local_u8SwitchResult;
    u8 Local_u8ResumeFlag = APP_FLAGDOWN;
    u32 Local_u32timer;

    APP_voidInit();

    while (1)
	{

	Local_u81MilliSecondFlag = APP_u8CheckFlag();

	APP_u8TimeUpdate(Local_u81MilliSecondFlag);

	if (Local_u8StopWatchFlag == APP_FLAGUP)
	    {
	    APP_u8StopWatchUpdate(Local_u81MilliSecondFlag);

	    }
	else
	    {

	    }

	if (Local_u8ResumeFlag == APP_FLAGUP)
	    {

	    APP_u8ResumeCounterUpdate(Local_u81MilliSecondFlag);

	    }
	else
	    {

	    }

	switch (Local_u8State)

	    {

	case APP_TIMER:

	    APP_voidDisplay(APP_u8Time);

	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{
		Local_u8State = APP_STOP_WATCH_STANDBY;
		}
	    else
		{

		}

	    break;

	case APP_STOP_WATCH_STANDBY:

	    APP_voidDisplay(APP_u8StopWatch);

	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		Local_u8State = APP_EDIT_TIME; ///till now return to timer but at the future should go to edit mode

		}

	    else
		{

		Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8Start_StopWatch);

		if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		    {

		    Local_u8State = APP_STOP_WATCH;

		    }
		else
		    {
		    }

		}

	    break;

	case APP_STOP_WATCH:

	    Local_u8StopWatchFlag = APP_FLAGUP;

	    APP_voidDisplay(APP_u8StopWatch);

	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		APP_voidEraseStopWatchCounter(); //can be used to make stop watch disabled or enabled all the time
		Local_u8StopWatchFlag = APP_FLAGDOWN;

		Local_u8State = APP_EDIT_TIME; ///till now return to timer but at the future should go to edit mode

		}
	    else
		{

		Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8Start_StopWatch);

		if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		    {

		    Local_u8StopWatchFlag = APP_FLAGDOWN;

		    Local_u8State = APP_STOP_WATCH_PAUSE;

		    }
		else
		    {

		    }

		}

	    break;

	case APP_STOP_WATCH_PAUSE:

	    Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	    if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		{

		Local_u8State = APP_EDIT_TIME; ///till now return to timer but at the future should go to edit mode

		APP_voidEraseStopWatchCounter(); //can be used to make stop watch disabled or enabled all the time
		Local_u8StopWatchFlag = APP_FLAGDOWN;
		}
	    else
		{

		TACTILE_u8GetState(APP_u8Start_StopWatch, &Local_u8SwitchResult);

		if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		    {

		    Local_u8ResumeFlag = APP_FLAGUP;

		    Local_u8State = APP_RESUME_STAND_BY;

		    }
		else
		    {

		    }

		}
	    break;

	case APP_RESUME_STAND_BY:

	    TACTILE_u8GetState(APP_u8Start_StopWatch, &Local_u8SwitchResult);

	    if (Local_u8SwitchResult != TACTILE_u8SWITCHPRESSED)

		{

		Local_u8ResumeFlag = APP_FLAGDOWN;

		if (APP_u32ReadResumeCounter() > 3UL) //more than 3 seconds
		    {
		    Local_u8State = APP_STOP_WATCH;
		    APP_voidEraseResumeCounter();

		    }
		else
		    {
		    Local_u8State = APP_STOP_WATCH;

		    APP_voidEraseStopWatchCounter();

		    APP_voidEraseResumeCounter();

		    }

		}
	    else
		{

		}

	    break;

	case APP_EDIT_TIME:

	    Local_u32timer=APP_u32ReadTimer();

	    APP_voidEdittime(Local_u32timer);


	    Local_u8State = APP_TIMER;


	    break;

	default:
	    break;

	    }

	}
    return 0;

    }
