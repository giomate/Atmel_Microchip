/*
 * LMX_SAMD21_LIB.cpp
 *
 * Created: 4/4/2021 12:22:20 PM
 * Author : giova
 */ 

#include <atmel_start.h>

#include "lmx2694Handler.h"
static lmx2694_Handler lmx;

int main(void)
{
	atmel_start_init();


	while(!lmx.Init()){
		
	delay_ms(100);
	

		gpio_toggle_pin_level(LED0);
		
	}
    gpio_set_pin_level(LED0,true);
		//printf("\r\nHello ATMEL World!\r\n");
    while (1) 
    {
		lmx.Self_Test();
		delay_ms(100);
		
    }
}
