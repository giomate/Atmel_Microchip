/*
 * LMX_AVR128DB_LIB.cpp
 *
 * Created: 26/03/2021 07:36:42
 * Author : giova
 */ 

#include <atmel_start.h>
#include "lmx2694Handler.h"
lmx2694_Handler lmx;

int main(void)
{
		atmel_start_init();
	ENABLE_INTERRUPTS();
    /* Replace with your application code */
    while (1) 
    {
		while(!lmx.Init()){
			delay_ms()
			delay_ms(1000);
			gpio_toggle_pin_level(LED0);
		}
		gpio_set_pin_level(LED0,true);
		/* Replace with your application code */
		while (1)
		{
			lmx.Self_Test();
			delay_ms(1000);
		}
    }
}

