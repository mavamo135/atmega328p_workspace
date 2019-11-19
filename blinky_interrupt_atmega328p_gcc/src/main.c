#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"
#include "led.h"
#include "timer.h"

#ifdef TEST
    #define LOOP
    #define SLEEP(x)
#else
    #include <util/delay.h>
    #define LOOP        while(1)
    #define SLEEP(x)    _delay_ms(x)
    int main(void)
    {
        return AppMain();
    }
#endif

int AppMain(void)
{
    led_configure();
    timer_configure();
    LOOP
    {

    }
}

ISR(TIMER0_COMPA_vect)
{
    led_toggle();
}