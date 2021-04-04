/*
 * ADF5610_AVR128DB_LIB.cpp
 *
 * Created: 3/26/2021 8:07:36 PM
 * Author : GMateusDP
 */ 


#include <atmel_start.h>
#include "util/delay.h"
#include "ADF5610Driver.h"
ADF5610_Driver adf;
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
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	RTC_enable();
	
	printf("hello\n\r");
	
	adf.Init();
	ENABLE_INTERRUPTS();
	/* Replace with your application code */
	while (1) {
		adf.SelfTest(1);
		_delay_ms(1000);
		adf.Init();
	}
}

