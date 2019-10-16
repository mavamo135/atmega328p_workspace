#include "unity.h"
#include "gpio.h"


void setUp(void)
{
    PORTB = 0x00;
}

void tearDown(void)
{
}

void test_gpio_mask_is_applied(void)
{
    gpio_set_mask(&DDRB, 0x7F);
    TEST_ASSERT_EQUAL(0x7F, DDRB);
}

void test_gpio_bit_is_set(void)
{
    gpio_set_bit(&PORTB, PORTB7);
    TEST_ASSERT_EQUAL(0x80, PORTB);
}

void test_gpio_bit_is_cleared(void)
{
    PORTB = 0x80;

    gpio_clear_bit(&PORTB, PORTB7);
    TEST_ASSERT_EQUAL(0x00, PORTB);
}

void test_gpio_bit_is_toggled(void)
{
    gpio_toggle_bit(&PORTB, PORTB7);
    TEST_ASSERT_EQUAL(0x80, PORTB);
}

void test_gpio_bit_can_be_read(void)
{
    PORTB = 0x80;

    uint8_t retval = gpio_read_bit(&PORTB, PORTB7);
    TEST_ASSERT_EQUAL(1, retval);
}
