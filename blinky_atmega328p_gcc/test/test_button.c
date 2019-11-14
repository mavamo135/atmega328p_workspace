#include "unity.h"
#include "button.h"
#include "gpio.h"
#include "board.h"

void setUp(void)
{
    SW_DDR  = 0x00;
    SW_PORT = 0x00;
    SW_PINR = 0x00;
}

void tearDown(void)
{
}

void test_button_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */
    button_configure();
    /* Verify test results */
    TEST_ASSERT_BIT_LOW(SW_PIN, SW_DDR);
    TEST_ASSERT_BIT_HIGH(SW_PIN, SW_PORT);
}

void test_button_should_read_if_button_is_pressed(void)
{
    /* Ensure known test state */
    SW_PINR = (1 << SW_PIN);
    /* Setup expected call chain */

    /* Call function under test */

    /* Verify test results */
    TEST_ASSERT_EQUAL(0x01, button_is_pressed());
}

void test_button_should_read_if_button_is_released(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */

    /* Call function under test */

    /* Verify test results */
    TEST_ASSERT_EQUAL(0x00, button_is_pressed());
}
