/*
 * LMX_lib.cpp
 *
 * Created: 2/8/2021 11:45:40 AM
 * Author : GMateusDP
 */ 


#include "atmel_start.h"
#include "lmx2694Handler.h"

lmx2694_Handler lmx;

int main(void)
{
	atmel_start_init();
//	timer_start(&TIMER_0);
	while(!lmx.Init()){
		delay_ms(1000);
		//gpio_toggle_pin_level(LED0);
	}
//	gpio_set_pin_level(LED0,true);
    /* Replace with your application code */
    while (1) 
    {
		lmx.Self_Test();
		delay_ms(1000);
    }
}
