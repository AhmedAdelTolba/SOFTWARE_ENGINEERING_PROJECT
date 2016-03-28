#include"../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"APP_Interface.h"

int main(void)
    {

    u8 Local_u8State = APP_TIMER;

    APP_voidInit();

    while (1)
	{

	switch (Local_u8State)

	    {

	case APP_TIMER:

	    Local_u8State = APP_u8Timer();

	    break;

	case APP_STOP_WATCH_STANDBY:

	    Local_u8State = APP_u8APP_STOP_WATCH_STANDBY();

	    break;

	case APP_STOP_WATCH:

	    Local_u8State = APP_u8APP_STOP_WATCH();

	    break;

	case APP_STOP_WATCH_PAUSE:

	    Local_u8State = APP_u8APP_STOP_WATCH_PAUSE();

	    break;

	case APP_RESUME_STAND_BY:

	    Local_u8State = APP_u8APP_RESUME_STAND_BY();

	    break;
//
//	case APP_EDIT_TIME:
//
//	    Local_u32timer=APP_u32ReadTimer();
//
//	    APP_voidEdittime(Local_u32timer);
//
//
//	    Local_u8State = APP_TIMER;
//
//
//	    break;

	default:
	    break;

	    }

	}
    return 0;

    }
