#include "main.h"
#include "button.h"
#include "led.h"

#ifdef TEST
    #define FOREVER()   0
    #define SLEEP(x)
#else
    #include <util/delay.h>
    #define FOREVER()   1
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

    do
    {
        if ( button_is_pressed() )
        {
            led_set();
        }
        else
        {
            led_clear();
        }
    } while (FOREVER());

    return 0;
}
