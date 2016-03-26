#include"../../../SHARED_LIBRARIES/SHARED_LIBRARIES_CODE/types.h"
#include"TIMER_interface.h"  
#include"TIMER_config.h" 
#include"TIMER_private.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void TIMER_voidInit( void (*x)(void))
    {

    callback=x;
    // set up timer with no prescaler and CTC mode
    TCCR1B |= (1 << WGM12) | (1 << CS10);

    // initialize counter
    TCNT1 = 0;

    // initialize compare value
    OCR1A = 4000;

    // enable compare interrupt
    TIMSK |= (1 << OCIE1A);

    // enable global interrupts
    sei();

    return;
    }

ISR (TIMER1_COMPA_vect)
    {
    callback();
    }
