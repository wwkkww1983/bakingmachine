#include "stm32f10x.h"
#include "csp_pwm.h"
#include "delay.h"
#include "sys.h"
#include "csp_timer.h"
#include "csp_gpio.h"
#include "csp_uart.h"
#include "csp_adc.h"
#include "csp_uart.h"
#include "arg_debug_pro.h"

int main(void)
{
	delay_init();

	csp_gpio_init();
	csp_pwm_init();
	csp_timer_init();
	csp_uart_init();
	csp_adc_init();

	arg_debug_pro_init();
	while (1)
	{
		csp_timer_handle();
		csp_uart_handle();
		csp_adc_handle();
		csp_pwm_handle();
		arg_debug_pro_handle();
	}
}
