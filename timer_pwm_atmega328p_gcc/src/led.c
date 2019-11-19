#include <avr/io.h>
#include "led.h"

void led_configure(void)
{
    /* configure PORTB as output */
    DDRB  = 0xFF;
    PORTB = 0x00;
    /* Configure PORTD as output */
    DDRD  = 0xFF;
    PORTD = 0x00;
}

void led_toggle_0(void)
{
    PORTB ^= _BV(PORTB0);
}

void led_toggle_1(void)
{
    PORTB ^= _BV(PORTB1);
}
