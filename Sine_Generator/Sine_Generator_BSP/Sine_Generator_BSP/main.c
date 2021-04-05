#include <atmel_start.h>
#include "driver_init.h"
#include "utils.h"
volatile bool dac_convert=true;
static struct timer_task TIMER_0_task1;

static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
	dac_convert=true;
}


static  uint16_t  dac_value=0;
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	dac_sync_enable_channel(&DAC_0, 0);
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
// 		for (uint16_t i = 0; i < 0x3ff; i=i+0x1ff)
// 		{
// 			dac_value=dir?i:0x3ff-i;
// 			while (dac_sync_write(&DAC_0, 0, &dac_value, 1)>0)
// 			{
// 				//delay_ms(1);
// 			}
// 			//delay_ms(1);
// 		}
// 		dir=!dir;
		if (dac_convert==true)
		{
			dac_value=dir?0:0x3ff;
			dac_sync_write(&DAC_0, 0, &dac_value, 1);
		//	delay_ms(100);
			dir=!dir;
		//	dac_convert=false;
		}
		
		
		
	}
}
