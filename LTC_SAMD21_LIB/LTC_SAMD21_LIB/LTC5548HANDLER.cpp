/*
 * LTC5548HANDLER.cpp
 *
 *  Created on: Feb 21, 2021
 *      Author: giova
 */

#include "LTC5548HANDLER.h"
#include "CDC_Class.h"



static lmx2694_Handler local_lmx;
static ADF5610_Driver local_adf;
static ZCD_Handler local_counter;


LTC5548_HANDLER::LTC5548_HANDLER() {
	// TODO Auto-generated constructor stub

}

LTC5548_HANDLER::~LTC5548_HANDLER() {
	// TODO Auto-generated destructor stub
}

bool LTC5548_HANDLER::Init(void){
	Set_Enable(false);
	lmx=&local_lmx;
	adf=&local_adf;
	zcd=&local_counter;
	Start_Mixer();
	zcd->Init();
	return !enable;
}
bool LTC5548_HANDLER::Set_Mixer(bool st){
	if(st){
		Start_Mixer();
	}else{
		Stop_Mixer();
	}
	return enable;
}
bool LTC5548_HANDLER::Start_Mixer(void){
	if(Start_LO()){
		adf->Set_Target_Frequency(CENTER_FREQUENCY);
		while (!adf->Is_Locked())
		{
			delay_ms(100);
			adf->Set_Target_Frequency(CENTER_FREQUENCY);
		}
		if (Start_RF())
		{
		//	lmx->Set_Target_Frequency(float(CENTER_FREQUENCY+(float)(BAND_WIDTH/((float)BAND_WIDTH_FRACTION))));
			lmx->Set_Target_Frequency(OPTIMAL_FREQUENCY);
			while (!lmx->Is_Locked())
			{
				delay_ms(100);
				//lmx->Set_Target_Frequency(float(CENTER_FREQUENCY+(float)(BAND_WIDTH/BAND_WIDTH_FRACTION)));
				lmx->Set_Target_Frequency(OPTIMAL_FREQUENCY);
			}
			tune_rf_frequency=lmx->current_frequency;
// 			lmx->Start_Woobling(CENTER_FREQUENCY+BAND_WIDTH,CENTER_FREQUENCY-BAND_WIDTH);
// 			while (!lmx->Keep_Woobling())
// 			{
// 				
// 			}
			Set_Enable(true);
		} 
		else
		{
			Set_Enable(false);
		}
		
	}else{
		Set_Enable(false);
	}
	return enable;
}

bool LTC5548_HANDLER::Start_RF(void){
		while(!lmx->Init()){
			
			delay_ms(100);
			//	_delay_loop_2(100);

		//	LED0_toggle_level();
			gpio_toggle_pin_level(LED0);
			usb<<"Radiator NOT Started"<<NEWLINE;
			
		}
		usb<<"Radiator Started"<<NEWLINE;
		return true;
}
bool LTC5548_HANDLER::Start_LO(void){
	while(!adf->Init()){
	
		delay_ms(100);
		//	_delay_loop_2(100);

		//LED0_toggle_level();
		gpio_toggle_pin_level(LED0);
		usb<<"Oscillator NOT Started"<<NEWLINE;
	
	}
	usb<<"Oscillator Started"<<NEWLINE;
	return true;
}
bool LTC5548_HANDLER::Stop_Mixer(void){
		Set_Enable(false);
		return enable;
}
bool LTC5548_HANDLER::Set_Enable(bool st){
	enable=st;
	
	gpio_set_pin_level(LTC_ENABLE,st);
	if (enable)
	{
		usb<<"Mixer Enabled"<<NEWLINE;
	} 
	else
	{
		usb<<"Mixer Disabled"<<NEWLINE;
	}
	return st;
}
void LTC5548_HANDLER::Read_Frequency_Values(void){
	tone=zcd->Get_Tone();
	

}
uint8_t LTC5548_HANDLER::Read_Index(void){
	
	return max_index;
}
bool LTC5548_HANDLER::Check_Mixer(void){
	if(enable){
		if(adf->Is_Locked()){
			if (lmx->Is_Locked())
			{
				return enable;
			} 
			else
			{
				Set_Enable(false);
			}
		//	printf("adf frequency : %f \n\r", lmx->current_frequency);
		}else{
			Set_Enable(false);
			
			
			
		}
	}else{
		if (adf->Is_Locked())
		{
			if (lmx->Is_Locked())
			{
				Set_Enable(true);
			} 
			else
			{
				Start_RF();
			}
			
		} 
		else
		{
			Start_Mixer();
		}
		
	}
	return enable;
}

float LTC5548_HANDLER::Tune_RF_Mixer(){
	if (Check_Mixer())
	{
		if (lmx->Is_Locked())
		{
			usb<<"RF Frequency: "<<lmx->current_frequency<<TAB_SPACE;
			tone=zcd->Get_Tone();
			tune_rf_frequency=lmx->current_frequency;
			next_rf_frequency=Calculate_Optimum(tone);
			lmx->Set_Target_Frequency(next_rf_frequency);
			error_counter=0;
		} 
		else
		{
			if (error_counter==0xff)
			{
				Start_RF();
			} 
			else
			{
				delay_ms(10);
				lmx->Set_Target_Frequency(next_rf_frequency);
			}
			error_counter++;
		}
		
	} 
	else
	{
		Check_Mixer();
	}
	
}

LTC5548_HANDLER ltc;

