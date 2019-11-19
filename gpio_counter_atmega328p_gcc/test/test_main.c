#include <avr/io.h>
#include "unity.h"
#include "main.h"
#include "leds.h"

void setUp(void)
{
    PORTB = 0x00;
    DDRB  = 0x00;
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
    // Check if led is configured
    TEST_ASSERT_EQUAL(0xFF, DDRB);
    // Check if port is incremented
    TEST_ASSERT_EQUAL(0x01, PORTB);
}
