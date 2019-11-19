#include <avr/io.h>
#include "leds.h"

void leds_configure(void)
{
    /* Configure PORTB as output */
    DDRB  = 0xFF;
    PORTB = 0x00;
}

void leds_increment(void)
{
    PORTB++;
}
