/*
 * Test.c
 *
 *  Created on: Mar 25, 2016
 *      Author: Anwar
 */

#include"../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"../TACTILE_SWITCH_CODE/TACTILE_SWITCH_interface.h"
#include"../../../MCAL_LAYER/DIO/DIO_CODE/DIO_interface.h"

int main() {
	DIO_VoidInit();

	u8 Local_Switch1 = 0;
	u8 Local_Switch2 = 0;
	u8 Local_Switch3 = 0;

	while (1) {
		TACTILE_u8GetState(TACTILE_u8SWITCH1, &Local_Switch1);
		TACTILE_u8GetState(TACTILE_u8SWITCH2, &Local_Switch2);
		TACTILE_u8GetState(TACTILE_u8SWITCH3, &Local_Switch3);

		if (Local_Switch1 == TACTILE_u8SWITCHPRESSED) {
			DIO_u8WritePinVal(DIO_u8PIN29,DIO_u8HIGH);
		}
		else{
			DIO_u8WritePinVal(DIO_u8PIN29,DIO_u8LOW);
	}


		if (Local_Switch2 == TACTILE_u8SWITCHPRESSED) {
			DIO_u8WritePinVal(DIO_u8PIN30,DIO_u8HIGH);
		}
		else{
			DIO_u8WritePinVal(DIO_u8PIN30,DIO_u8LOW);
	}

		if (Local_Switch3 == TACTILE_u8SWITCHPRESSED) {
			DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8HIGH);
		}
		else{
			DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8LOW);
	}

	}

	return 0;
}
