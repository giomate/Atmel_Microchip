/*
 * Test_Interrupts.cpp
 *
 * Created: 4/3/2021 10:26:43 AM
 * Author : GMateusDP
 */ 


#define  ATMEL_START
#include "stdio.h"
#include "string.h"
#include <atmel_start.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "atomic.h"
#include <driver_init.h>
#include <compiler.h>
#include "usart_basic.h"

//#include "adc_application.h"
//#include "dac_application.h"
//#include "usart_application.h"
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
ISR(RTC_PIT_vect)
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
	printf("hello \n\r");
    while (1) 
    {
		asm("nop");
		_delay_ms(1000);
		asm("nop");
    }
}

