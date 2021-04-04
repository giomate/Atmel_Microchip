#include <atmel_start.h>
#include "util/delay.h"
#include "string.h"
#include "stdio.h"
#include "atomic.h"

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
	ENABLE_INTERRUPTS();
	sei();
	printf("hello \n\r");
	while (1)
	{
		asm("nop");
		_delay_ms(1000);
		asm("nop");
	}
}
