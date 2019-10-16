#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <avr/io.h>

void gpio_set_mask(volatile uint8_t* port, uint8_t mask);
void gpio_clear_mask(volatile uint8_t* port, uint8_t mask);
void gpio_set_bit(volatile uint8_t* port, uint8_t bit);
void gpio_clear_bit(volatile uint8_t* port, uint8_t bit);
void gpio_toggle_bit(volatile uint8_t* port, uint8_t bit);
uint8_t gpio_read_bit(volatile uint8_t* port, uint8_t bit);

#endif /* GPIO_H */