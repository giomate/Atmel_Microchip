/*
 * Zero_Cross_Detector_lib.cpp
 *
 * Created: 3/27/2021 10:47:22 AM
 * Author : GMateusDP
 */ 

#include <stdio.h>
#include <string.h>
#include <atmel_start.h>

#include <usart_basic.h>
#include <atomic.h>


#include <util/delay.h>

#include <usart_basic.h>

#include "Zero_Cross_Counter.h"
#include "SPI_SLAVE_CLASS.h"




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
	uint32_t last_frequency_b=0;
	uint32_t last_frequency_c=0;
		uint32_t current_frequency_b=0;
		uint32_t current_frequency_c=0;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	RTC_enable();
	
	tako.Init();
	post.Init();
	ENABLE_INTERRUPTS();
	//asm("nop");
	printf("hello\n\r");
	/* Replace with your application code */
	while (1) {
		current_frequency_c=(uint32_t)(24000000/(tako.capture_timer_fall));
		if (last_frequency_c!=current_frequency_c)
		{
			if (tako.capture_timer_fall>0)
			{
				last_frequency_c=current_frequency_c;
					tako.Set_Last_Frequency(last_frequency_c);
				printf("Counter C : %lu \n\r", current_frequency_c);
			}
			
		} 
		else
		{
			
		}
		current_frequency_b=(uint32_t)(24000000/(tako.capture_timer_rise));
		if (last_frequency_b!=current_frequency_b)
		{
			if (tako.capture_timer_rise>0)
			{
				last_frequency_b=current_frequency_b;
				tako.Set_Last_Frequency(last_frequency_b);
				printf("Counter B : %lu \n\r", current_frequency_b);
			}
			
		}
		else
		{
		}
		//post.Check_Command();
		
		
			
	}
}
