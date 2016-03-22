/*
 * DIO_prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: G
 */
/*********************************************************************/
/*************************included libraries*************************/
/********************************************************************/
#include"../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"DIO_interface.h"
#include"DIO_config.h"
#include"DIO_private.h"
/********************************************************************/
/********************************************************************/
/********************************************************************/


/*********************************************************************/
/*************************Global Arrays*******************************/
/********************************************************************/
/*comment!:Array of ports(portA,portB,portC,portD) */
static u8* const DIO_U8ArrayOfPorts[DIO_PORTSNUMBER] = { DIO_u8PORTA, DIO_u8PORTB,
DIO_u8PORTC, DIO_u8PORTD };

/*comment!:Array to set the direction(input (0) or output(1)) of each port */
u8* const DIO_U8ArrayOfdirection[DIO_PORTSNUMBER] = { DIO_u8DDRA, DIO_u8DDRB,
DIO_u8DDRC, DIO_u8DDRD };

/*comment!:Array of pins for each port */
u8* const DIO_U8ArrayOfPINS[DIO_PORTSNUMBER] = { DIO_u8PINA, DIO_u8PINB,
DIO_u8PINC, DIO_u8PIND };

/*comment!:Array of mask to set the value of each pin in each port*/
const u8 DIO_U8ArrayOfSETMASKS[DIO_PINSNUMBER] = { DIO_u8MASKSETPINO,
DIO_u8MASKSETPIN1, DIO_u8MASKSETPIN2, DIO_u8MASKSETPIN3,
DIO_u8MASKSETPIN4, DIO_u8MASKSETPIN5, DIO_u8MASKSETPIN6, DIO_u8MASKSETPIN7 };

/*comment!:Array of mask to clear the value of each pin in each port*/
const u8 DIO_U8ArrayOfCLRMASKS[DIO_PINSNUMBER] = { DIO_u8MASKCLRPINO,
DIO_u8MASKCLRPIN1, DIO_u8MASKCLRPIN2, DIO_u8MASKCLRPIN3,
DIO_u8MASKCLRPIN4, DIO_u8MASKCLRPIN5, DIO_u8MASKCLRPIN6, DIO_u8MASKCLRPIN7 };
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/


/*********************************************************************/
/*************************Functions**********************************/
/********************************************************************/


/*comment!:intialize function*/
extern void DIO_VoidInit(void) {
	/*comment!:set the direction(input(0) or output(1)) of each port with the intial values of each pin  in the DIO_configration.h*/
	*DIO_u8DDRA = DIO_u8PortADir;
	*DIO_u8DDRB = DIO_u8PortBDir;
	*DIO_u8DDRC = DIO_u8PortCDir;
	*DIO_u8DDRD = DIO_u8PortDDir;
	/*comment!:read port direction*/
	*DIO_u8PORTA &= (~DIO_u8PortADir);
	*DIO_u8PORTB &= (~DIO_u8PortBDir);
	*DIO_u8PORTC &= (~DIO_u8PortCDir);
	*DIO_u8PORTD &= (~DIO_u8PortDDir);

	*DIO_u8PORTA |= (DIO_u8PortAVal & DIO_u8PortADir);
	*DIO_u8PORTB |= (DIO_u8PortBVal & DIO_u8PortBDir);
	*DIO_u8PORTC |= (DIO_u8PortCVal & DIO_u8PortCDir);
	*DIO_u8PORTD |= (DIO_u8PortDVal & DIO_u8PortDDir);
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/


/*comment!:write pin value*/
extern u8 DIO_u8WritePinVal(u8 copy_u8ChIdx, u8 copy_u8PinVal) {
	u8 local_u8status;
	u8 local_u8portselection = copy_u8ChIdx / 8;
	u8 local_u8pinselection = copy_u8ChIdx % 8;
	if (copy_u8ChIdx <= DIO_u8PIN31) {
		local_u8status = u8ok;

		switch (copy_u8PinVal) {
		case 0:
			*DIO_U8ArrayOfPorts[local_u8portselection] &=
					DIO_U8ArrayOfCLRMASKS[local_u8pinselection];

			break;

		case 1:
			*DIO_U8ArrayOfPorts[local_u8portselection] |=
					DIO_U8ArrayOfSETMASKS[local_u8pinselection];

			break;

		}
	} else {
		local_u8status = u8error;
	}

	return local_u8status;

}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/


/*comment!:read pin value*/
extern u8 DIO_u8ReadPinVal(u8 copy_u8ChIdx, u8* copy_u8ptrToVal) {
	u8 local_u8status;
	u8 local_u8portselection = (copy_u8ChIdx / 8);
	u8 local_u8pinselection = copy_u8ChIdx % 8;
	if (copy_u8ChIdx <= DIO_u8PIN31) {
		local_u8status = u8ok;

		*copy_u8ptrToVal = getbit(*DIO_U8ArrayOfPINS[local_u8portselection],
				local_u8pinselection);

	} else {
		local_u8status = u8error;
	}

	return local_u8status;

}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:write port value*/
extern u8 DIO_u8WritePortVal(u8 copy_u8PortIdx, u8 copy_u8PortVal) {
	u8 local_u8status;

	if (copy_u8PortIdx <= DIO_PORTSNUMBER) {
		*DIO_U8ArrayOfPorts[copy_u8PortIdx] = copy_u8PortVal;
		local_u8status = u8ok;

	} else {
		local_u8status = u8error;
	}
	return local_u8status;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:read port value*/
extern u8 DIO_u8ReadPortVal(u8 copy_u8PortIdx, u8* copy_u8ptrToVal) {
	u8 local_u8status;
	if (copy_u8PortIdx <= DIO_PORTSNUMBER) {
		*copy_u8ptrToVal = *DIO_U8ArrayOfPINS[copy_u8PortIdx];
		local_u8status = u8ok;

	} else {
		local_u8status = u8error;
	}
	return local_u8status;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:read pin direction*/
extern u8 DIO_u8ReadPinDir(u8 copy_u8PinIdx, u8* copy_u8PtrToDir) {
	u8 local_u8status;
	u8 local_u8portselection = (copy_u8PinIdx / 8);
	u8 local_u8pinselection = copy_u8PinIdx % 8;
	if (copy_u8PinIdx <= DIO_u8PIN31) {
		local_u8status = u8ok;

		*copy_u8PtrToDir = getbit(
				*DIO_U8ArrayOfdirection[local_u8portselection],
				local_u8pinselection);

	} else {
		local_u8status = u8error;
	}

	return local_u8status;

}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:write pin direction*/
extern u8 DIO_u8WritePinDir(u8 copy_u8PinIdx, u8 copy_u8PinDir) {
	u8 local_u8status;
	u8 local_u8portselection = (copy_u8PinIdx / 8);
	u8 local_u8pinselection = copy_u8PinIdx % 8;
	if (copy_u8PinIdx <= DIO_u8PIN31) {

		local_u8status = u8ok;

		switch (copy_u8PinDir) {
		case 0:
			*DIO_U8ArrayOfdirection[local_u8portselection] &=
					DIO_U8ArrayOfCLRMASKS[local_u8pinselection];

			break;

		case 1:
			*DIO_U8ArrayOfdirection[local_u8portselection] |=
					DIO_U8ArrayOfSETMASKS[local_u8pinselection];

			break;

		}

	} else {
		local_u8status = u8error;
	}
	return local_u8status;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:write port direction*/
extern u8 DIO_u8WritePortDir(u8 copy_u8PortIdx, u8 copy_u8PortDir) {
	u8 local_u8status;
	if (copy_u8PortIdx <= DIO_PORTSNUMBER) {
		*DIO_U8ArrayOfdirection[copy_u8PortIdx] = copy_u8PortDir;//3ayzeen ne3meloo oxff for o/p,0 /p
		local_u8status = u8ok;

	} else {
		local_u8status = u8error;
	}
	return local_u8status;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

/*comment!:read port direction*/
extern u8 DIO_u8ReadPortDir(u8 copy_u8PortIdx, u8* copy_u8PtrToDir) {
	u8 local_u8status;
	if (copy_u8PortIdx <= DIO_PORTSNUMBER) {
		*copy_u8PtrToDir = *DIO_U8ArrayOfdirection[copy_u8PortIdx];
		local_u8status = u8ok;

	} else {
		local_u8status = u8error;
	}
	return local_u8status;

}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

