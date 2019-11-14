#include "main.h"
#include "button.h"
#include "led.h"

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
    button_configure();
    led_configure();

    LOOP
    {
        if ( button_is_pressed() )
        {
            led_set();
        }
        else
        {
            led_clear();
        }
    }

    return 0;
}
