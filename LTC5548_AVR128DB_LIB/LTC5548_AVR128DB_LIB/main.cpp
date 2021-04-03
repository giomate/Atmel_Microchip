/*
 * LTC5548_AVR128DB_LIB.cpp
 *
 * Created: 3/29/2021 7:31:18 AM
 * Author : GMateusDP
 */ 

#include <atmel_start.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "LTC5548HANDLER.h"

static LTC5548_HANDLER	ltc;

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
	ltc.Init();
    /* Replace with your application code */
    while (1) 
    {
		ltc.Read_Frequency_Values();
		//ltc.lmx->Keep_Woobling();
	//	ltc.Check_Mixer();
		
    }
}

