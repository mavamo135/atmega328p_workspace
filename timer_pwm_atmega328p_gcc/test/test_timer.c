#include <avr/io.h>
#include "unity.h"
#include "timer.h"
#include "mock_interrupt.h"

void setUp(void)
{
    TCCR0A = 0x00;
    OCR0A  = 0x00;
    OCR0B  = 0x00;
    TCCR0B = 0x00;
    TIMSK0 = 0x00;
}

void tearDown(void){ }

void test_timer_should_be_configured(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    sei_Expect();
    /* Call function under test */
    timer_configure_pwm();
    timer_configure_interrupt();
    /* Verify test results */
    uint8_t mask_TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00)
                        | _BV(WGM01) | _BV(WGM02);
    TEST_ASSERT_EQUAL(mask_TCCR0A, TCCR0A);

    TEST_ASSERT_EQUAL(60, OCR0A);
    TEST_ASSERT_EQUAL(191, OCR0B);

    uint8_t mask_TCCR0B = _BV(CS00) | _BV(CS02);
    TEST_ASSERT_EQUAL(mask_TCCR0B, TCCR0B);

    uint8_t mask_TIMKS0 = _BV(TOIE0) | _BV(OCIE0B);
    TEST_ASSERT_EQUAL(mask_TIMKS0, TIMSK0);
}
