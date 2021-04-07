/*
 * LTC_SAMD21_LIB.cpp
 *
 * Created: 4/5/2021 8:40:04 PM
 * Author : giova
 */ 

#include <atmel_start.h>
#include "LTC5548HANDLER.h"
#include "CDC_Class.h"

static  uint16_t  dac_value=0;
int main(void)
{
	atmel_start_init();
		usb.Init();
		delay_ms(100);
		
		usb.print("[2J");
		usb.write(27);
		usb.println("initiating LTC Mixer");
	dac_sync_enable_channel(&DAC_0, 0);
	
	ltc.Init();
	bool dir=true;
	//ltc.lmx->Start_Woobling(CENTER_FREQUENCY+TUNE_MAX_BAND,CENTER_FREQUENCY-TUNE_MAX_BAND);

	/* Replace with your application code */
	while (1)
	{
		
		ltc.Tune_RF_Mixer();
	//	usb<<"RF Frequency: "<<ltc.lmx->current_frequency<<TAB_SPACE;
	//	ltc.zcd->Get_Tone();
	//	ltc.lmx->Keep_Woobling();
		
		//	DISABLE_INTERRUPTS();
		//ltc.lmx->Keep_Woobling();
	//	ltc.Check_Mixer();
		
		dac_value=dir?0:0x3ff;
	//	dac_sync_write(&DAC_0, 0, &dac_value, 1);
		
		dir=!dir;
	}
}
