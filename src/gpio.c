#include "gpio.h"

void
gpio_set_mask(volatile uint8_t* port, uint8_t mask)
{
    *port |= mask;
}

void
gpio_clear_mask(volatile uint8_t* port, uint8_t mask)
{
    *port &= ~mask;
}

void
gpio_set_bit(volatile uint8_t* port, uint8_t bit)
{
    *port |= _BV(bit);
}

void
gpio_clear_bit(volatile uint8_t* port, uint8_t bit)
{
    *port &= ~_BV(bit);
}

void
gpio_toogle_bit(volatile uint8_t* port, uint8_t bit)
{
    *port ^= _BV(bit);
}

uint8_t
gpio_read_bit(volatile uint8_t* port, uint8_t bit)
{
    return (*port & _BV(bit)) >> bit;
}