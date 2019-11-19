#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_configure(void)
{
    /* Set the Timer to Clear Timer on Compare Match (CTC) Mode */
    TCCR0A = _BV(WGM01);
    /* Clear the TC0 Counter Value */
    TCNT0 = 0x00;
    /* Set the value to output compare 0 A */
    OCR0A = 0xFF;
    /* Enable the Compare A Match interrupt*/
    TIMSK0 = _BV(OCIE0A);
    /* Set prescaler to 1024 and start the timer */
    TCCR0B = _BV(CS02) | _BV(CS00);
    /* Enable interrupts */
    sei();
}
