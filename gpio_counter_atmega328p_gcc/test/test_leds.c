#include <avr/io.h>
#include "unity.h"
#include "leds.h"

void setUp(void)
{
    PORTB = 0x00;
    DDRB  = 0x00;
}

void tearDown(void)
{
}

void test_led_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    leds_configure();
    /* Verify test results */
    TEST_ASSERT_EQUAL(0xFF, DDRB);
    TEST_ASSERT_EQUAL(0x00, PORTB);
}

void test_led_should_be_toggled(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    leds_configure();
    leds_increment();
    /* Verify test results */
    TEST_ASSERT_EQUAL(0x01, PORTB);
}
