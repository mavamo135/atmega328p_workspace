#include <avr/io.h>
#include "led.h"

void led_configure(void)
{
    /* Configure PORTB as output */
    DDRB  = 0xFF;
    PORTB = 0x00;
}

void led_toggle(void)
{
    PORTB ^= _BV(PORTB0);
}
