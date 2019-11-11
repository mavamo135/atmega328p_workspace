#include <avr/io.h>
#include "unity.h"
#include "gpio.h"

void setUp(void)
{
    PORTB = 0x00;
    DDRB = 0x00;
}

void tearDown(void)
{
}

void test_gpio_mask_is_applied(void)
{
    /* Call function under test */
    gpio_set_mask(&DDRB, 0x7F);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x7F, DDRB);

    /* Call function under test */
    gpio_clear_mask(&DDRB, 0x7F);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x00, DDRB);

    /* Call function under test */
    gpio_set_mask(&DDRB, 0xFF);
    gpio_mask(&DDRB, 0X0F, 0x7F);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x7F, DDRB);
}

void test_gpio_bit_is_set(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    gpio_set_bit(&PORTB, PORTB7);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x80, PORTB);
}

void test_gpio_bit_is_cleared(void)
{
    /* Ensure known test state */
    PORTB = 0x80;
    /* Setup expected call chain */

    /* Call function under test */
    gpio_clear_bit(&PORTB, PORTB7);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x00, PORTB);
}

void test_gpio_bit_is_toggled(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    gpio_toggle_bit(&PORTB, PORTB7);
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x80, PORTB);
}

void test_gpio_bit_can_be_read(void)
{
    /* Ensure known test state */
    PORTB = 0x80;
    /* Setup expected call chain */

    /* Call function under test */
    uint8_t retval = gpio_read_bit(&PORTB, PORTB7);
    /* Verify test results */
    TEST_ASSERT_EQUAL(1, retval);
}

void test_gpio_write_single_bytes_of_variable(void)
{
    /* Ensure known test state */
    ADCH = 0x43;
    ADCL = 0x21;
    /* Setup expected call chain */

    /* Call function under test */
    
    /* Verify test results */
    TEST_ASSERT_EQUAL_HEX16(0x4321, ADC);
}