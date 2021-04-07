/* 
* MIXER_TUNNER_HELPER.cpp
*
* Created: 4/6/2021 3:45:39 PM
* Author: giova
*/


#include "MIXER_TUNNER_HELPER.h"
#include "math.h"
#include "LTC5548HANDLER.h"
#include "CDC_Class.h"

// default constructor
MIXER_TUNNER_HELPER::MIXER_TUNNER_HELPER()
{
	minimum_tone=48000000.0;
	optimal_frequency=OPTIMAL_FREQUENCY;
	last_error_tune=240000;
	error_tune=24000000;
	direction=true;
} //MIXER_TUNNER_HELPER

// default destructor
MIXER_TUNNER_HELPER::~MIXER_TUNNER_HELPER()
{
} //~MIXER_TUNNER_HELPER

float MIXER_TUNNER_HELPER::Calculate_Optimum(uint32_t tn){
	if (tn>=24000000)
	{
		if (tn==24000000)
		{
			if (ltc.tune_rf_frequency>optimal_frequency)
			{
				optimum=optimal_frequency- float(1/16.0);
				
			} 
			else
			{
				optimum=optimal_frequency+ float(1/16.0);
				
			}
			
		} 
		else
		{
			
			if (ltc.tune_rf_frequency>optimal_frequency)
			{
				optimum=optimal_frequency- float(1/2.0);
				
			}
			else
			{
				optimum=optimal_frequency+ float(1/2.0);
				
			}
			
		}
		//error_tune=float(tn);
	} 
	else
	{
		if (tn>0)
		{
			if ((tn!=0xffffff)&(tn!=0x6e3600))
			{
				if (tn<minimum_tone)
				{
					minimum_tone=float(tn);
					optimal_frequency=ltc.tune_rf_frequency;
				}
				else
				{
					
				}
				direction=Calculate_Gradient(tn)?!direction:direction;
				if (error_tune!=0)
				{
					last_error_tune=error_tune;
				}
				
				if (direction)
				{
						error_tune=(float(tn))-minimum_tone;
				} 
				else
				{
						error_tune=minimum_tone-(float(tn));
				}
			
			
				gain=exp((error_tune)/(abs(max(last_error_tune,error_tune))*8192.0));
				optimum=optimal_frequency*gain;
				if (optimum>(optimal_frequency+TUNE_MAX_BAND))
				{
					optimum=optimal_frequency+TUNE_MAX_BAND;
				}
				else
				{
					if (optimum<(optimal_frequency-TUNE_MAX_BAND))
					{
						optimum=(optimal_frequency-TUNE_MAX_BAND);
					}
					else
					{
					}
				}
			} 
			else
			{
			}
			
			
		} 
		else
		{
			optimum=ltc.tune_rf_frequency;
		}
		
	}
	usb<<"gradient "<<gradient<<"\tdirection "<<direction<<"\terror "<<error_tune<<"\tgain "<<gain<<"\toptimum "<<optimum<<NEWLINE;
	return optimum;
}

bool MIXER_TUNNER_HELPER::Calculate_Gradient(uint32_t lv){
	tone_array[2]=tone_array[1];
	tone_array[1]=tone_array[0];
	tone_array[0]=lv;
	int32_t g1=tone_array[1]-tone_array[2];
	int32_t g0=tone_array[0]-tone_array[1];
	gradient=g0-g1;
	return gradient>0;
	
}
