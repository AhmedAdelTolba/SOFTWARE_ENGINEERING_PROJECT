/*
 * TACTILE_SWITCH_prog.c
 *
 *  Created on: Feb 25, 2016
 *      Author: Anwar
 */
#include"../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"TACTILE_SWITCH_config.h"
#include"TACTILE_SWITCH_interface.h"
#include"TACTILE_SWITCH_private.h"
#include"../../../MCAL_LAYER/DIO/DIO_CODE/DIO_interface.h"


const u8 TACTILE_u8SwitchType[TACTILE_MAXSWITCH] = { TACTILE_u8SWITCH1TYPE,
TACTILE_u8SWITCH2TYPE, TACTILE_u8SWITCH3TYPE, TACTILE_u8SWITCH4TYPE,
TACTILE_u8SWITCH5TYPE, TACTILE_u8SWITCH6TYPE, TACTILE_u8SWITCH7TYPE,
TACTILE_u8SWITCH8TYPE, TACTILE_u8SWITCH9TYPE,
TACTILE_u8SWITCH10TYPE, TACTILE_u8SWITCH11TYPE, TACTILE_u8SWITCH12TYPE,
TACTILE_u8SWITCH13TYPE, TACTILE_u8SWITCH14TYPE, TACTILE_u8SWITCH15TYPE,
TACTILE_u8SWITCH16TYPE };

const u8 TACTILE_u8SwitchPin[TACTILE_MAXSWITCH] = { TACTILE_u8SWITCH1PIN,
TACTILE_u8SWITCH2PIN, TACTILE_u8SWITCH3PIN, TACTILE_u8SWITCH4PIN,
TACTILE_u8SWITCH5PIN, TACTILE_u8SWITCH6PIN, TACTILE_u8SWITCH7PIN,
TACTILE_u8SWITCH8PIN, TACTILE_u8SWITCH9PIN,
TACTILE_u8SWITCH10PIN, TACTILE_u8SWITCH11PIN, TACTILE_u8SWITCH12PIN,
TACTILE_u8SWITCH13PIN, TACTILE_u8SWITCH14PIN, TACTILE_u8SWITCH15PIN,
TACTILE_u8SWITCH16PIN };

u8 TACTILE_u8SwitchState[TACTILE_MAXSWITCH] = { TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED };

u8 TACTILE_u8ReturnVal[TACTILE_MAXSWITCH] = { TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED, TACTILE_u8SWITCHSTATERELEASED,
TACTILE_u8SWITCHSTATERELEASED };

u8 TACTILE_u8SwitchCountUp[TACTILE_MAXSWITCH] = { TACTILE_u8COUNTINITVAL };

u8 TACTILE_u8SwitchCountDown[TACTILE_MAXSWITCH] = { TACTILE_u8COUNTINITVAL };

extern void TACTILE_voidInit(void) {

}
/*Comment!: Get Tactile State */

extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal) {

	u8 copy_u8SwitchVal = DIO_u8LOW;

	switch (TACTILE_u8SwitchState[Copy_u8SwitchNumber]) {

	case TACTILE_u8SWITCHSTATERELEASED:
		TACTILE_u8ReturnVal[Copy_u8SwitchNumber] =
				TACTILE_u8SWITCHRELEASED;
		*Copy_u8PtrToVal=TACTILE_u8ReturnVal[Copy_u8SwitchNumber];
		DIO_u8ReadPinVal(TACTILE_u8SwitchPin[Copy_u8SwitchNumber],
				&copy_u8SwitchVal);
		if (copy_u8SwitchVal == TACTILE_u8SwitchType[Copy_u8SwitchNumber]) {
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATEDEBOUNCING;
		} else {
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATERELEASED;
		}
		break;

	case TACTILE_u8SWITCHSTATEDEBOUNCING:

		DIO_u8ReadPinVal(TACTILE_u8SwitchPin[Copy_u8SwitchNumber],
				&copy_u8SwitchVal);
		if (copy_u8SwitchVal == TACTILE_u8SwitchType[Copy_u8SwitchNumber]) {
			TACTILE_u8SwitchCountUp[Copy_u8SwitchNumber]++;
			TACTILE_u8SwitchCountDown[Copy_u8SwitchNumber] = 0;
		} else {
			TACTILE_u8SwitchCountUp[Copy_u8SwitchNumber] = 0;
			TACTILE_u8SwitchCountDown[Copy_u8SwitchNumber]++;
		}

		if (TACTILE_u8SwitchCountUp[Copy_u8SwitchNumber] >= MAX_COUNT) {
			TACTILE_u8SwitchCountUp[Copy_u8SwitchNumber] = 0;
			TACTILE_u8SwitchCountDown[Copy_u8SwitchNumber] = 0;
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATEPRESSED;
		}
		if (TACTILE_u8SwitchCountDown[Copy_u8SwitchNumber] >= MAX_COUNT) {
			TACTILE_u8SwitchCountUp[Copy_u8SwitchNumber] = 0;
			TACTILE_u8SwitchCountDown[Copy_u8SwitchNumber] = 0;
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATERELEASED;
		}
		break;

	case TACTILE_u8SWITCHSTATEPRESSED:
		TACTILE_u8ReturnVal[Copy_u8SwitchNumber] = TACTILE_u8SWITCHPRESSED;
		*Copy_u8PtrToVal=TACTILE_u8ReturnVal[Copy_u8SwitchNumber];
		DIO_u8ReadPinVal(TACTILE_u8SwitchPin[Copy_u8SwitchNumber],
				&copy_u8SwitchVal);
		if (copy_u8SwitchVal == TACTILE_u8SwitchType[Copy_u8SwitchNumber]) {
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATEPRESSED;
		} else {
			TACTILE_u8SwitchState[Copy_u8SwitchNumber] =
			TACTILE_u8SWITCHSTATEDEBOUNCING;
		}
		break;
	}

	return TACTILE_u8ReturnVal[Copy_u8SwitchNumber];

}