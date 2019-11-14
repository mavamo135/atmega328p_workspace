#include <avr/io.h>
#include "unity.h"
#include "timer.h"
#include "mock_interrupt.h"

void setUp(void)
{
    TCCR0A = 0x00;
    OCR0A  = 0x00;
    TIMSK0 = 0x00;
    TCCR0B = 0x00;
}

void tearDown(void)
{
}

void test_timer_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    sei_Expect();
    /* Call function under test */
    timer_configure();
    /* Verify test results */
    TEST_ASSERT_BIT_HIGH(WGM01, TCCR0A);
    TEST_ASSERT_EQUAL(0xFF, OCR0A);
    TEST_ASSERT_BIT_HIGH(OCIE0A, TIMSK0);
    TEST_ASSERT_BIT_HIGH(CS00, TCCR0B);
    TEST_ASSERT_BIT_HIGH(CS02, TCCR0B);
}
