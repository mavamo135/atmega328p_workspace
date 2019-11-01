#include "button.h"
#include "gpio.h"
#include "board.h"

void
button_configure()
{
    // Configure pin PB7 as input
    gpio_clear_bit(&SW_DDR, SW_PIN);
    // Configure pin PB7 as pull-up
    gpio_set_bit(&SW_PORT, SW_PIN);
}

uint8_t
button_is_pressed(void)
{
    return gpio_read_bit(&SW_PINR, SW_PIN) == 1;
}