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


/*comment!:initialize function*/
/*Description:
 * this function is used to set initial values of port value and direction */

/*Arguments:
 * the function take NO arguments */
/****************************NOTE*****************************/
/*to set those in those initial values check the DIO_config.h*/
/***********************************************************/
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
/*Description:
 * this function is used to set any pin to high=1 or to set it to low=0 */

/*Arguments:
 * the function take two arguments
 * u8 copy_u8ChIdx this is the pin that i want to write on it
 * u8 copy_u8PinVal this is the value of the pin high = 1 or low = 0 */
/*Range! copy_u8ChIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-20-21-22-23-24-25-26-27-28-29-30-31*/
/*Range! copy_u8PinVal:0-1*/
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
/*Description:
 * this function is used to read pin value*/
/*Arguments:
 * the function take two arguments
 * u8 copy_u8ChIdx this is the pin that i wante to write on it
 * u8 copy_u8portVal this is the value of the pin high = 1 or low = 0 */
/*Range! copy_u8ChIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-20-21-22-23-24-25-26-27-28-29-30-31*/
/*Range! copy_u8PortVal:0-1*/
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
/*Description:
 * this function is used to set port to high=1 or to set it to low=0 */
/*Arguments:
 * the function take two arguments
 * u8 copy_u8ChIdx this is the pin that i wante to write on it
 * u8 copy_u8portVal this is the value of the pin high = 1 or low = 0 */
/*Range! copy_u8portIdx : 0-1-2-3*/
/*Range! copy_u8PortVal:0-1*/
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
/*Description:
 * this function is used to read port value*/
/*Arguments:
 * the function take two arguments
 * u8 copy_u8PortIdx this is the port that i wante to set it's direction
 * u8* copy_u8PtrToDir this is to take any variable i wante to put in it the port direction*/
/*Range! :copy_u8PinIdx : 0-1-2-3*/
/*Range! :copy_u8PtrToDir:any variable*/

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
/*Description:
 * this function is used to read pin direction */
/*Arguments:
 * the function take two arguments
 * u8 copy_u8PinIdx this is the port that i wante to set it's direction
 * u8* copy_u8PtrToDir this is to take any variable i wante to put in it the port direction*/
/*Range! :copy_u8PinIdx : 1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-20-21-22-23-24-25-26-27-28-29-30-31*/
/*Range! :copy_u8PtrToDir:any variable*/

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
/*Description:
 * this function is used to set pin direction to input=0 or to output=1 */
/*Arguments:
 * the function take two arguments
 * u8 copy_u8PinIdx this is the pin that i wante to set it's direction
 * u8 copy_u8PinDir this is the value of the pin output = 1 or input = 0 */
/*Range! :copy_u8PinIdx : 0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-20-21-22-23-24-25-26-27-28-29-30-31-*/
/*Range! :copy_u8PinDir:0-1*/

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
/*Description:
 * this function is used to set port direction to input=0 or to output=1 */
/*Arguments:
 * the function take two arguments
 * u8 copy_u8PortIdx this is the port that i wante to set it's direction
 * u8 copy_u8PortDir this is the value of the port output = 1 or input = 0 */
/*Range! :copy_u8PortIdx : 0-1-2-3*/
/*Range! :copy_u8PortDir:0-1*/

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
/*Description:
 * this function is used to read port direction */
/*Arguments:
 * the function take two arguments
 * u8 copy_u8PortIdx this is the port that i wante to set it's direction
 * u8* copy_u8PtrToDir this is to take any variable i wante to put in it the port direction*/
/*Range! :copy_u8PortIdx : 0-1-2-3*/
/*Range! :copy_u8PtrToDir:any variable*/
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

