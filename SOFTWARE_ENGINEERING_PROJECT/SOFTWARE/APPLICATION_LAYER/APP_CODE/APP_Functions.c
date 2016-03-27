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
#include <stdlib.h>

static u8 APP_u8SwitchState[3] =
    {
    TACTILE_u8SWITCHRELEASED, TACTILE_u8SWITCHRELEASED, TACTILE_u8SWITCHRELEASED
    };
static u8 APP_u81MilliFlag = APP_u8FlagDown;
static u32 APP_u32Timer = 0;
static u32 APP_u32StopWatch = 0;
static u32 APP_u32Resume = 0;

void TIMER_ISR(void)
    {

    APP_u81MilliFlag++;

    return;
    }

void APP_voidInit(void)
    {

    DIO_VoidInit();
    LCD_voidInit();
    TIMER_voidInit(TIMER_ISR);

    return;
    }

u8 APP_u8CheckFlag(void)
    {

    u8 Local_u8Result;

    Local_u8Result = APP_u81MilliFlag;

    APP_u81MilliFlag = 0;

    return Local_u8Result;

    }

void APP_u8TimeUpdate(u8 Copy_u81MilliSecondFlag)
    {

    static u16 Local_u161MilliSecondCounter = 0;

    Local_u161MilliSecondCounter += Copy_u81MilliSecondFlag;

    if (Local_u161MilliSecondCounter >= 1000) //default 1000
	{
	Local_u161MilliSecondCounter -= 1000; //default 1000

	APP_u32Timer++;

	}
    else
	{

	}

    if (APP_u32Timer == 86400)
	{

	APP_u32Timer = 0;

	}

    return;
    }

extern void APP_voidDisplay(u8 Copy_u8Time)

    {
    char Local_u8Hours;
    char Local_u8Minutes;
    char Local_u8Seconds;
    char Local_u812HourFlag = 0;
    u32 Local_u32Timer;
    char Local_u8TempChar[10];

    if (Copy_u8Time == APP_u8Time)

	{
	Local_u8Hours = APP_u32Timer / 3600;

	if (Local_u8Hours > 12)
	    {

	    Local_u32Timer = APP_u32Timer - (12 * 60 * 60UL);

	    Local_u812HourFlag = APP_u8PM;
	    }
	else
	    {

	    Local_u32Timer = APP_u32Timer;

	    Local_u812HourFlag = APP_u8AM;

	    }

	}
    else if (Copy_u8Time == APP_u8StopWatch)
	{
	Local_u32Timer = APP_u32StopWatch;
	}

//write to lcd

    LCD_voidWriteCommand(LCD_u8LINE1);

    Local_u8Hours = Local_u32Timer / 3600;
    itoa(Local_u8Hours / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Local_u8Hours % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    LCD_voidWriteChar(':');

    Local_u8Minutes = (Local_u32Timer % 3600) / 60;
    itoa(Local_u8Minutes / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Local_u8Minutes % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    LCD_voidWriteChar(':');

    Local_u8Seconds = ((Local_u32Timer % 3600) % 60);
    itoa(Local_u8Seconds / 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);
    itoa(Local_u8Seconds % 10, Local_u8TempChar, 10);
    LCD_voidWriteChar(Local_u8TempChar[0]);

    if (Local_u812HourFlag == APP_u8PM && Copy_u8Time == APP_u8Time)
	{
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar('P');
	LCD_voidWriteChar('M');

	}

    else if (Local_u812HourFlag == APP_u8AM && Copy_u8Time == APP_u8Time)
	{
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar('A');
	LCD_voidWriteChar('M');

	}
    else if (Copy_u8Time == APP_u8StopWatch)
	{
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');
	LCD_voidWriteChar(' ');

	}
    return;
    }

void APP_u8StopWatchUpdate(u8 Copy_u81MilliSecondFlag)
    {

    static u16 Local_u161SWMilliSecondCounter = 0;

    Local_u161SWMilliSecondCounter += Copy_u81MilliSecondFlag;

    if (Local_u161SWMilliSecondCounter >= 1000) //default 1000
	{
	Local_u161SWMilliSecondCounter -= 1000; //default 1000

	APP_u32StopWatch++;

	}
    else
	{

	}

//overflow isn't handled
    return;
    }

u8 APP_u8ReadSwitch(u8 Copy_u8SwitchId)
    {

    u8 local_u8CurrentSwitchState;

    u8 Local_u8Result;

    TACTILE_u8GetState(Copy_u8SwitchId, &local_u8CurrentSwitchState);

    if ((local_u8CurrentSwitchState == TACTILE_u8SWITCHRELEASED) && (APP_u8SwitchState[Copy_u8SwitchId] !=
    TACTILE_u8SWITCHRELEASED))
	{

	Local_u8Result = TACTILE_u8SWITCHPRESSED;

	}
    else
	{

	Local_u8Result = TACTILE_u8SWITCHRELEASED;

	}

    APP_u8SwitchState[Copy_u8SwitchId] = local_u8CurrentSwitchState;

    return Local_u8Result;

    }

void APP_u8ResumeCounterUpdate(u8 Copy_u81MilliSecondFlag)
    {

    static u16 Local_u161MilliSecondCounter = 0;

    Local_u161MilliSecondCounter += Copy_u81MilliSecondFlag;

    if (Local_u161MilliSecondCounter >= 1000) //default 1000
	{
	Local_u161MilliSecondCounter -= 1000; //default 1000

	APP_u32Resume++;

	}
    else
	{

	}

    return;
    }

extern u32 APP_u32ReadResumeCounter(void)

    {

    return APP_u32Resume;

    }

extern void APP_voidEraseResumeCounter(void)

    {

    APP_u32Resume = 0;
    return;

    }

extern void APP_voidEraseStopWatchCounter(void)

    {

    APP_u32StopWatch = 0;

    return;

    }

extern u32 APP_u32ReadTimer(void)
    {

    return APP_u32Timer;
    }

extern void APP_voidEdittime(u32 Local_u32Timer)
    {


    u8 Local_u8TempChar[10];
    u8 Local_u8Time[4];
    u8 Local_u8Numpresses = 0;
    u8 Local_u8SwitchResult;
    u8 Local_u8Time_LIMITS[4]={12,59,59,1};

    u8 Local_u81MilliSecondFlag;
    //Local_u8Hours
    Local_u8Time[0] = Local_u32Timer / 3600;


    if (Local_u8Time[0]  > 12)
    	    {

	Local_u8Time[0]  = Local_u8Time[0]  - (12 * 60 * 60UL);

	Local_u8Time[3]  = APP_u8PM;
    	    }
    	else
    	    {

    	Local_u8Time[3]  = APP_u8AM;

    	    }


    //Local_u8Minutes
    Local_u8Time[1] = (Local_u32Timer % 3600) / 60;

    //Local_u8Seconds
    Local_u8Time[2] = ((Local_u32Timer % 3600) % 60);


    do
	{


	////////////////// keep updating time


	Local_u81MilliSecondFlag = APP_u8CheckFlag();

		APP_u8TimeUpdate(Local_u81MilliSecondFlag);





	//////////
	Local_u8SwitchResult = APP_u8ReadSwitch(APP_u8ModeSwitch);

	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

	    {

	    Local_u8Numpresses++;

	    }

	Local_u8SwitchResult = APP_u8ReadSwitch(TACTILE_u8SWITCH2);
	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)

		    {

		    Local_u8Time[Local_u8Numpresses]++;

		    if(Local_u8Time[Local_u8Numpresses]>Local_u8Time_LIMITS[Local_u8Numpresses])
			{

			Local_u8Time[Local_u8Numpresses]=0;

			}
		    else{

			}

		    }

	Local_u8SwitchResult = APP_u8ReadSwitch(TACTILE_u8SWITCH3);
	if (Local_u8SwitchResult == TACTILE_u8SWITCHPRESSED)
	    {


	    if(Local_u8Time[Local_u8Numpresses]>0)
	   			{

		    Local_u8Time[Local_u8Numpresses]--;

	   			}
	    else{
		Local_u8Time[Local_u8Numpresses]=Local_u8Time_LIMITS[Local_u8Numpresses];
	    }

	    ///////////////////////////////////
	    }

	    //write to lcd

	        LCD_voidWriteCommand(LCD_u8LINE1);

	        itoa( Local_u8Time[0] / 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);
	        itoa(Local_u8Time[0] % 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);

	        LCD_voidWriteChar(':');

	        itoa(Local_u8Time[1] / 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);
	        itoa(Local_u8Time[1] % 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);

	        LCD_voidWriteChar(':');

	        itoa(Local_u8Time[2] / 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);
	        itoa(Local_u8Time[2] % 10, Local_u8TempChar, 10);
	        LCD_voidWriteChar(Local_u8TempChar[0]);



	        if (Local_u8Time[3]==APP_u8PM)
	    	{
	    	LCD_voidWriteChar(' ');
	    	LCD_voidWriteChar('P');
	    	LCD_voidWriteChar('M');

	    	}

	        else if (Local_u8Time[3]==APP_u8AM)
	    	{
	    	LCD_voidWriteChar(' ');
	    	LCD_voidWriteChar('A');
	    	LCD_voidWriteChar('M');

	    	}


	    //////////////////////////////////////////


	} while (Local_u8Numpresses < 4);


    return;
    }

