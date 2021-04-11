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
static Zero_Cross_Counter tako_static;
static SPI_SLAVE_CLASS post_static;



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
	uint16_t counter_printf=0;
	uint32_t last_frequency_b=0;
	uint32_t last_frequency_c=0;
		uint32_t current_frequency_b=0;
		uint32_t current_frequency_c=0;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	RTC_enable();
	tako=&tako_static;
	post=&post_static;
	tako->Init();
	post->Init();
	post->frequency_array=tako->last_frequency;
	ENABLE_INTERRUPTS();
	//asm("nop");
	printf("hello\n\r");
	/* Replace with your application code */
	while (1) {
		current_frequency_c=(uint32_t)(24000000/(tako->capture_timer_fall));
		if (last_frequency_c!=current_frequency_c)
		{
			if (tako->capture_timer_fall>0)
			{
				last_frequency_c=current_frequency_c;
					//tako.Set_Last_Frequency(last_frequency_c);
					if (tako->full_wave)
					{
						printf("Counter fall : %lu \n\r", current_frequency_c);
					}
				
			}
			
		} 
		else
		{
			
		}
		current_frequency_b=(uint32_t)(24000000/(tako->capture_timer_rise));
		if (last_frequency_b!=current_frequency_b)
		{
			if (tako->capture_timer_rise>0)
			{
				last_frequency_b=current_frequency_b;
				//tako.Set_Last_Frequency(last_frequency_b);
				if (tako->full_wave)
				{
					printf("Counter Full WaveRise : %lu \n\r", current_frequency_b);
				}else{
					
				}
				
			}
			
		}
		else
		{
		}
		tako->Set_Last_Capture_Frequency();
		if ((*tako->timer_rise>0)&(tako->got_value_r))
		{
		//	printf("Raw capture rise : %u \n\r", *tako->timer_rise);
			tako->got_value_r=false;
		}
		if ((*tako->timer_fall>0)&(tako->got_value_f))
		{
		//	printf("Raw capture fall : %u \n\r", *tako->timer_fall);
			tako->got_value_f=false;
		}
		if (counter_printf==0)
		{
			if (tako->frequency_out<24000000)
			{
				printf("Last Frequency OUT : %lu \n\r", tako->frequency_out);
			} 
			else
			{
			}
			
		} 
		else
		{
		}
		counter_printf++;
		//post.Check_Command();
		
		
			
	}
}
