#include "led.h"
#include "gpio.h"
#include "board.h"

void
led_configure()
{
    // Configure led pin as output
    gpio_set_bit(&LED_DDR, LED_PIN);
}

void
led_set()
{
    gpio_set_bit(&LED_PORT, LED_PIN);
}

void
led_clear()
{
    gpio_clear_bit(&LED_PORT, LED_PIN);
}
