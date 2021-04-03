#include <atmel_start.h>
//#include "util/delay.h"

int main(void)
{
	uint32_t dummy=0;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	dummy++;
	/* Replace with your application code */
	while (1) {
		if (dummy==0)
		{
			LED_0_toggle_level();
		} 
		else
		{
		}
		
		//_delay_ms(1000);
	}
}
