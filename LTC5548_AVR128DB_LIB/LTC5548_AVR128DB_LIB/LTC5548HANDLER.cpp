/*
 * LTC5548HANDLER.cpp
 *
 *  Created on: Feb 21, 2021
 *      Author: giova
 */

#include "LTC5548HANDLER.h"

#include <stdio.h>
#include <unistd.h>
#include <util/delay.h>

static lmx2694_Handler local_lmx;
static ADF5610_Driver local_adf;
static Zero_Cross_Counter local_counter;

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
// 		adf->Set_Target_Frequency(CENTER_FREQUENCY);
// 		while (!adf->Is_Locked())
// 		{
// 			_delay_ms(100);
// 			adf->Set_Target_Frequency(CENTER_FREQUENCY);
// 		}
// 		if (Start_RF())
// 		{
// 			lmx->Set_Target_Frequency(CENTER_FREQUENCY+(BAND_WIDTH/BAND_WIDTH_FRACTION));
// 			while (!lmx->Is_Locked())
// 			{
// 				_delay_ms(100);
// 				lmx->Set_Target_Frequency(CENTER_FREQUENCY+(BAND_WIDTH/BAND_WIDTH_FRACTION));
// 			}
// // 			lmx->Start_Woobling(CENTER_FREQUENCY+BAND_WIDTH,CENTER_FREQUENCY-BAND_WIDTH);
// // 			while (!lmx->Keep_Woobling())
// // 			{
// // 				
// // 			}
// 			Set_Enable(true);
// 		} 
// 		else
// 		{
// 			Set_Enable(false);
// 		}
		
	}else{
		Set_Enable(false);
	}
	return enable;
}

bool LTC5548_HANDLER::Start_RF(void){
		while(!lmx->Init()){
			
			_delay_ms(100);
			//	_delay_loop_2(100);

			LED0_toggle_level();
			
		}
		return true;
}
bool LTC5548_HANDLER::Start_LO(void){
	while(!adf->Init()){
	
	//	_delay_ms(100);
		//	_delay_loop_2(100);

		LED0_toggle_level();
	
	}
	return true;
}
bool LTC5548_HANDLER::Stop_Mixer(void){
		Set_Enable(false);
		return enable;
}
bool LTC5548_HANDLER::Set_Enable(bool st){
	enable=st;
	LTC_ENABLE_set_level(enable);
	return st;
}
void LTC5548_HANDLER::Read_Frequency_Values(void){
	if (zcd->capture_timer_rise>0)
	{
		current_frequency_r=(uint32_t)(24000000/(zcd->capture_timer_rise));
	}
	
	if (last_frequency_c!=current_frequency_r)
	{
		if (zcd->capture_timer_rise>0)
		{
			last_frequency_c=current_frequency_r;
			
			printf("Frequency Rising : %lu \n\r", current_frequency_r);
		}
		
	}
	else
	{
		
	}
	if (zcd->capture_timer_fall>0)
	{
		current_frequency_f=(uint32_t)(24000000/(zcd->capture_timer_fall));
	}
	
	if (last_frequency_b!=current_frequency_f)
	{
		if (zcd->capture_timer_fall>0)
		{
			last_frequency_b=current_frequency_f;
			
			printf("Frequency Falling : %lu \n\r", current_frequency_f);
		}
		
	}
	else
	{
	}
	

}
uint8_t LTC5548_HANDLER::Read_Index(void){
	
	return max_index;
}
bool LTC5548_HANDLER::Check_Mixer(void){
	if(enable){
		if(adf->Is_Locked()){
		//	printf("adf frequency : %f \n\r", lmx->current_frequency);
		}else{
			Set_Enable(false);
			adf->Init();
			adf->Set_Target_Frequency(CENTER_FREQUENCY);
			_delay_ms(100);
		}
	}else{
		if (adf->Is_Locked())
		{
			Set_Enable(true);
		} 
		else
		{
			adf->Init();
			adf->Set_Target_Frequency(CENTER_FREQUENCY);
			_delay_ms(100);
		}
		
	}
	return enable;
}

