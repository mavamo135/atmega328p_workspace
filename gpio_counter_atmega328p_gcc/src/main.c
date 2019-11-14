#include "main.h"
#include "leds.h"

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
    leds_configure();
    // TODO Write code to test the main loop a specific number of times
    LOOP
    {
        leds_increment();
        SLEEP(100);
    }
}
