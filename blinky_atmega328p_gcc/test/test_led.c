#include <avr/io.h>
#include "unity.h"
#include "led.h"
#include "gpio.h"
#include "board.h"

void setUp(void)
{
    LED_PORT = 0x00;
    LED_DDR  = 0x00;
}

void tearDown(void)
{
}

void test_led_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    led_configure();
    /* Verify test results */
    TEST_ASSERT_BIT_HIGH(LED_PIN, LED_DDR);
}

void test_led_should_be_set(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    led_set();
    /* Verify test results */
    TEST_ASSERT_BIT_HIGH(LED_PIN, LED_PORT);
}

void test_led_should_be_cleared(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    led_set();
    led_clear();
    /* Verify test results */
    TEST_ASSERT_BIT_LOW(LED_PIN, LED_PORT);
}
