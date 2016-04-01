#include"../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"TIMER_interface.h"  
#include"TIMER_config.h" 
#include"TIMER_private.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*Comment!: pointer to call back function*/
void (*Timer_pfcallback)(void);

void TIMER_voidInit(void (*Copy_pfcallback)(void))
    {

    Timer_pfcallback = Copy_pfcallback;

    /*Comment!: set up timer with no prescaler and CTC mode*/

    TCCR1B |= (1 << WGM12) | (1 << CS10);

    /*Comment!: initialize counter*/
    TCNT1 = 0;

    /*Comment!: set compare value*/
    OCR1A = 4000;

    /*Comment!: enable compare interrupt*/
    TIMSK |= (1 << OCIE1A);

    /*Comment!: enable global interrupt*/
    sei();

    return;
    }

ISR (TIMER1_COMPA_vect)
    {

    /*Comment!: disable global interrupt*/
    cli();

    /*Comment!: call call back function*/
    Timer_pfcallback();

    /*Comment!: enable global interrupt*/
    sei();

    }
