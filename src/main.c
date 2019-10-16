#ifndef F_CPU
#define F_CPU 8000000
#endif
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"

int main(void)
{
    gpio_set_mask(&DDRB, 0x7F);
    gpio_set_bit(&PORTB, PORTB7);

    while (1)
    {
        if ( gpio_read_bit(&PINB, PINB7) == 1 )
        {
            gpio_clear_bit(&PORTC, PORTC0);
            gpio_set_mask(&PORTB, 0x7F);
            _delay_ms(2000);
            gpio_clear_mask(&PORTB, 0x7F);
            _delay_ms(2000);
        }
        else
        {
            gpio_set_bit(&PORTC, PORTC0);
            gpio_set_mask(&PORTB, 0x7F);
            _delay_ms(500);
            gpio_clear_mask(&PORTB, 0x7F);
            _delay_ms(500);
        }
    }
}
