#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

void gpio_set_mask(volatile uint8_t* port, uint8_t mask);
void gpio_clear_mask(volatile uint8_t* port, uint8_t mask);
void gpio_mask(volatile uint8_t* port, uint8_t clear_mask, uint8_t set_mask);
void gpio_set_bit(volatile uint8_t* port, uint8_t bit);
void gpio_clear_bit(volatile uint8_t* port, uint8_t bit);
void gpio_toggle_bit(volatile uint8_t* port, uint8_t bit);
uint8_t gpio_read_bit(volatile uint8_t* port, uint8_t bit);

#endif /* _GPIO_H */