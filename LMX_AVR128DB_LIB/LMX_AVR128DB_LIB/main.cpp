/*
 * LMX_AVR128DB_LIB.cpp
 *
 * Created: 26/03/2021 07:36:42
 * Author : giova
 */ 

#include <stdio.h>
#include <string.h>
#include <atmel_start.h>
#include <usart_basic.h>

#include <atomic.h>
#include <util/delay.h>  
#include <clock_config.h>
#include "lmx2694Handler.h"
 static lmx2694_Handler lmx;

void RTC_enable(void)
{
	// Wait for RTC CTRLA to be unsynchronized
	while (RTC.STATUS & RTC_CTRLABUSY_bm) {
	}

	// Enable RTC
	RTC.CTRLA |= RTC_RTCEN_bm;
}

ISR(RTC_CNT_vect)
{
	/* Toggle LED0 */
	LED0_toggle_level();

	/* Overflow interrupt flag has to be cleared manually */
	RTC.INTFLAGS = RTC_OVF_bm;
}

int main(void)
{
		atmel_start_init();
		RTC_enable();
	ENABLE_INTERRUPTS();
	printf("hello\n\r");
    /* Replace with your application code */
    while (1) 
    {
		while(!lmx.Init()){
			
			_delay_ms(100);
		//	_delay_loop_2(100);

		LED0_toggle_level();
			
		}
		LED0_set_level(true);
		//gpio_set_pin_level(LED0,true);
		/* Replace with your application code */
		while (1)
		{
			lmx.Self_Test();
			_delay_ms(1000);
		//	_delay_loop_2(1000);
			LED0_toggle_level();
		}
		LED0_set_level(true);
    }
}

