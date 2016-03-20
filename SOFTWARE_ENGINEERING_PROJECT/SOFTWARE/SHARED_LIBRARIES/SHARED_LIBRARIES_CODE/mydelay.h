/*
 * mydelay.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: G
 */

#ifndef MYDELAY_H_
#define MYDELAY_H_

void Delay(u32 mytime)
{
for(u32 i = mytime; i > 0; i--)
{
	for(u32 j=4000000/36000;j>0;j--)
	{
		__asm("NOP");
	}
}

}
#endif /* MYDELAY_H_ */
