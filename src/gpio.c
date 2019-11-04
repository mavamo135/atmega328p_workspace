#include <avr/sfr_defs.h>
#include "gpio.h"

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_set_mask(volatile uint8_t* port, uint8_t mask)
{
    *port |= mask;
}

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_clear_mask(volatile uint8_t* port, uint8_t mask)
{
    *port &= ~mask;
}

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_mask(volatile uint8_t* port, uint8_t clear_mask, uint8_t set_mask)
{
    *port = (*port & clear_mask) | set_mask;
}

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_set_bit(volatile uint8_t* port, uint8_t bit)
{
    *port |= _BV(bit);
}

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_clear_bit(volatile uint8_t* port, uint8_t bit)
{
    *port &= ~_BV(bit);
}

//TODO Check if the port address passed is within the range of GPIO ports
void
gpio_toggle_bit(volatile uint8_t* port, uint8_t bit)
{
    *port ^= _BV(bit);
}

//TODO Check if the port address passed is within the range of GPIO ports
uint8_t
gpio_read_bit(volatile uint8_t* port, uint8_t bit)
{
    return (*port & _BV(bit)) >> bit;
}