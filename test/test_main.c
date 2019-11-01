#include <avr/io.h>
#include "unity.h"
#include "main.h"
#include "button.h"
#include "led.h"
#include "gpio.h"
#include "board.h"

void setUp(void)
{
    LED_PORT = 0x00;
    LED_DDR = 0x00;
    SW_PORT = 0x00;
    SW_DDR = 0x00;
    SW_PINR = 0x00;
}

void tearDown(void)
{
}

void test_main_should_configure_registers(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    AppMain();
    /* Verify test results */
    // Check if button is configured
    TEST_ASSERT_BIT_LOW(SW_PIN, SW_DDR);
    TEST_ASSERT_BIT_HIGH(SW_PIN, SW_PORT);
    // Check if led is configured
    TEST_ASSERT_BIT_HIGH(LED_PIN, LED_DDR);
}

void test_main_should_set_indicator_if_button_is_not_pressed(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    AppMain();
    /* Verify test results */
    TEST_ASSERT_BIT_LOW(LED_PIN, LED_PORT);
}

void test_main_should_clear_indicator_if_button_is_pressed(void)
{
    /* Ensure known test state */
    SW_PINR = (1 << SW_PIN);
    /* Setup expected call chain */

    /* Call function under test */
    AppMain();
    /* Verify test results */
    TEST_ASSERT_BIT_HIGH(LED_PIN, LED_PORT);
}
