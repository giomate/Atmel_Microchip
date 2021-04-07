/*
 * ZCD_SAMD21_LIB.cpp
 *
 * Created: 4/4/2021 9:37:23 PM
 * Author : giova
 */ 


#include <atmel_start.h>
#include "driver_init.h"
#include "utils.h"
#include "ZCD_Handler.h"
#include "CDC_Class.h"
static ZCD_Handler zcd;


static  uint16_t  dac_value=0;
int main(void)
{
	uint32_t local_tone;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
		usb.Init();
		delay_ms(100);
		usb.println("initiating ZCD Sensor");
	dac_sync_enable_channel(&DAC_0, 0);
	zcd.Init();
	bool dir=true;
	// 	TIMER_0_task1.interval = 10000;
	// 	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	// 	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	//
	//
	// 	timer_add_task(&TIMER_0, &TIMER_0_task1);
	//
	// 	timer_start(&TIMER_0);
	/* Replace with your application code */
	while (1) {

			dac_value=dir?0:0x3ff;
			dac_sync_write(&DAC_0, 0, &dac_value, 1);
		
			dir=!dir;
			local_tone=zcd.Get_Tone();
	
		
		
		
	}
}