#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_configure_pwm(void)
{
    /* Set non-inverting mode, clear OC0A on Compare Match, set OC0A at BOTTOM */
    TCCR0A  = _BV(COM0A1);
    /* Set non-inverting mode, clear OC0B on Compare Match, set OC0B at BOTTOM */
    TCCR0A |= _BV(COM0B1);
    /* Set fast PWM mode */
    TCCR0A |= _BV(WGM02) | _BV(WGM01) | _BV(WGM00);
    /* Set PWM for 50% duty cycle */
    OCR0A   = 60;
    /* Set PWM for 75% duty cycle */
    OCR0B   = 191;
    /* Configure TIMER0 to use CLK/1024 prescaler */
    TCCR0B  = _BV(CS02) | _BV(CS00);
}

void timer_configure_interrupt(void)
{
    /* Enable the compare B match interrupt */
    /* Enable the TIMER0 overflow interrupt */
    TIMSK0 = _BV(OCIE0B) | _BV(TOIE0);
    /* Enable interrupts */
    sei();
}
