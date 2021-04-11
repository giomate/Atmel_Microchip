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
	direction=true;
	next_RF_frequency=3600;
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

bool LTC5548_HANDLER::Set_RF(float f){
	lmx->Set_Target_Frequency(f);
	while (!lmx->Is_Locked())
	{
		delay_ms(100);
		lmx->Set_Target_Frequency(f);
	}
	//usb<<"Oscillator Started"<<NEWLINE;
	return true;
}

bool LTC5548_HANDLER::Set_LO(float f){
	adf->Set_Target_Frequency(f);
	while (!adf->Is_Locked())
	{
		delay_ms(100);
		adf->Set_Target_Frequency(f);
	}
	//usb<<"Oscillator Started"<<NEWLINE;
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
			//usb<<"RF Frequency: "<<lmx->current_frequency<<TAB_SPACE;
			tone=zcd->Get_Tone();
			tune_rf_frequency=lmx->current_frequency;
			next_RF_frequency=Calculate_Optimum(tone);
			lmx->Set_Target_Frequency(next_RF_frequency);
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
				lmx->Set_Target_Frequency(next_RF_frequency);
			}
			error_counter++;
		}
		
	} 
	else
	{
		Check_Mixer();
	}
	return next_RF_frequency;
}
float LTC5548_HANDLER::Tune_LO_Mixer(){
	if (Check_Mixer())
	{
		if (adf->Is_Locked())
		{
			//usb<<"RF Frequency: "<<lmx->current_frequency<<TAB_SPACE;
		//	tone=zcd->Get_Tone();
			tune_LO_frequency=adf->current_frequency;
			next_LO_frequency=Calculate_Optimum_Resonance();
			adf->Set_Target_Frequency(next_LO_frequency);
			error_counter=0;
		}
		else
		{
			if (error_counter==0xff)
			{
				Set_LO(next_LO_frequency);
				
			}
			else
			{
				delay_ms(10);
				adf->Set_Target_Frequency(next_LO_frequency);
			}
			error_counter++;
		}
		
	}
	else
	{
		Check_Mixer();
	}
	return next_LO_frequency;
}

float LTC5548_HANDLER::Start_Searching( float downlimit,float uplimit){
	Set_Enable(false);
	upper_limit=uplimit; lower_limit=downlimit;
	step=(upper_limit-lower_limit)/2048.0;
	direction=true;
	next_LO_frequency=lower_limit;
	next_RF_frequency=next_LO_frequency;
	Set_LO(next_LO_frequency);
	Update_Optimal_Frequency(adf->current_frequency);
	Set_RF(next_LO_frequency);
	current_LO_frequency=adf->current_frequency;
	Set_Enable(true);
	return Keep_Searching();
}


float LTC5548_HANDLER::Keep_Searching(){
	if (Check_Mixer())
	{
		Tune_RF_Mixer();
		if ((gradient!=0)&(abs(gradient)<2048))
		{
			//Set_Enable(false);
			current_LO_frequency=adf->current_frequency;
			if (direction)
			{
				if ((current_LO_frequency+step)>upper_limit)
				{
					direction=false;
				}
				else
				{
				}
			}
			else
			{
				if ((current_LO_frequency-step)<lower_limit)
				{
					direction=true;
				}
				else
				{
				}
			}
			
			next_LO_frequency=direction?current_LO_frequency+step:current_LO_frequency-step;
			
			Set_LO(next_LO_frequency);
			Update_Optimal_Frequency(adf->current_frequency);
			Set_Minimum_Tone(170000000);
			Set_RF(next_LO_frequency);
		//	Set_Enable(true);
			
		} 
		else
		{
			//Tune_RF_Mixer();
			
		}
		
	} 
	else
	{
		Check_Mixer();
	}
}

float LTC5548_HANDLER::Start_Searching_Resonance( float downlimit,float uplimit){
	Set_Enable(false);
	upper_limit=uplimit; lower_limit=downlimit;
	step_resonance=(upper_limit-lower_limit)/1024.0;
	
	next_LO_frequency=RESONANCE_SEED_FREQUENCY;
	next_RF_frequency=RESONANCE_SEED_FREQUENCY;
	Set_LO(next_LO_frequency);
	Update_Optimal_Frequency(adf->current_frequency);
	Set_RF(next_LO_frequency);
	current_LO_frequency=adf->current_frequency;
	Set_Enable(true);
	Set_Step_Resonance(step_resonance);
	return Keep_Searching_Resonance();
}
float LTC5548_HANDLER::Keep_Searching_Resonance(){
	if (Check_Mixer())
	{
		Tune_RF_Mixer();
		if ((tone<648648))
		{
			//Set_Enable(false);
			current_LO_frequency=adf->current_frequency;
	
			
			Tune_LO_Mixer();
			Update_Optimal_Frequency(adf->current_frequency);
			Set_RF(adf->current_frequency);
			//	Set_Enable(true);
			
		}
		else
		{
			//Tune_RF_Mixer();
			
		}
		
	}
	else
	{
		Check_Mixer();
	}
}

LTC5548_HANDLER ltc;

