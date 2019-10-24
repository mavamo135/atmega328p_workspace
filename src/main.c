#include "gpio.h"

#ifdef TEST
    #include "stub_io.h"
    #include "stub_delay.h"
#else
    #include <avr/io.h>
    #include <util/delay.h>
#endif

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
