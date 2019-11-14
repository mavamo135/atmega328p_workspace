#include <avr/io.h>
#include "unity.h"
#include "main.h"
#include "mock_led.h"
#include "mock_timer.h"

void setUp(void)
{
    PORTB  = 0x00;
    DDRB   = 0x00;
    TCCR0A = 0x00;
    OCR0A  = 0x00;
    TIMSK0 = 0x00;
    TCCR0B = 0x00;
}

void tearDown(void)
{
}

void test_main_should_configure_registers(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    led_configure_Expect();
    timer_configure_Expect();
    /* Call function under test */
    AppMain();
    /* Verify test results */

}

void test_main_isr_should_toggle_led(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    led_toggle_Expect();
    /* Call function under test */
    ISR();
    /* Verify test results */

}

