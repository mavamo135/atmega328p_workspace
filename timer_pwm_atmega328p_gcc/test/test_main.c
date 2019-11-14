#include <avr/io.h>
#include "unity.h"
#include "main.h"
#include "mock_led.h"
#include "mock_timer.h"

void setUp(void) {}

void tearDown(void) {}

void test_main_should_configure_registers(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    led_configure_Expect();
    timer_configure_pwm_Expect();
    timer_configure_interrupt_Expect();
    /* Call function under test */
    AppMain();
    /* Verify test results */

}

void test_main_isr_should_toggle_led(void)
{
    /* Ensure known test state */

    /* Setup expected call chain */
    led_toggle_0_Expect();
    /* Call function under test */
    ISR();
    /* Verify test results */

}
