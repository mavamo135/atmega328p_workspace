#include <avr/io.h>
#include "unity.h"
#include "led.h"

void setUp(void)
{
    PORTB = 0x00;
    DDRB  = 0x00;
    PORTD = 0x00;
    DDRD  = 0x00;
}

void tearDown(void){}

void test_led_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    led_configure();
    /* Verify test results */
    TEST_ASSERT_EQUAL(0xFF, DDRB);
    TEST_ASSERT_EQUAL(0x00, PORTB);
    TEST_ASSERT_EQUAL(0xFF, DDRD);
    TEST_ASSERT_EQUAL(0x00, PORTD);
}

void test_led_should_be_toggled(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    led_configure();
    led_toggle_0();
    led_toggle_1();
    /* Verify test results */
    TEST_ASSERT_BIT_HIGH(PORTB0, PORTB);
    TEST_ASSERT_BIT_HIGH(PORTB1, PORTB);
}
