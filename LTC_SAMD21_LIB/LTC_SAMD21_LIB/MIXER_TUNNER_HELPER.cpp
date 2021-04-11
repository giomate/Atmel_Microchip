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
	minimum_gradient=24000000;
	last_gradient=648648;
	optimal_frequency=CENTER_FREQUENCY+TUNE_START_BAND;
	optimal_resonance=RESONANCE_SEED_FREQUENCY;
	last_error_tune=240000;
	error_tune=24000000;
	direction=true;
	direction_LO=true;
	gradient=0;
} //MIXER_TUNNER_HELPER

// default destructor
MIXER_TUNNER_HELPER::~MIXER_TUNNER_HELPER()
{
} //~MIXER_TUNNER_HELPER

float MIXER_TUNNER_HELPER::Calculate_Optimum(uint32_t tn){
	if (tn>=170000000)
	{
		if (tn==170000000)
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
			if ((tn!=0xffffff))
			{
				if (tn<minimum_tone)
				{
					minimum_tone=float(tn);
					optimal_frequency=ltc.tune_rf_frequency;
					optimal_resonance=ltc.adf->current_frequency;
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
			
			
			//	gain=exp((error_tune)/(abs(max(last_error_tune,error_tune))*4096.0));
				gain=exp((error_tune)/(170000000.0));
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
	usb<<"RF Frequency: "<<ltc.lmx->current_frequency<<"\ttone "<<tn;
	usb<<"\tgradient "<<gradient<<"\tdirection "<<direction<<"\terror "<<error_tune<<"\tgain "<<gain<<"\toptimum "<<optimum<<NEWLINE;
	return optimum;
}

float MIXER_TUNNER_HELPER::Calculate_Optimum_Resonance(void){
	if (abs(gradient)>0)
	{
		if (abs(gradient)<648648)
		{
			if (abs(gradient)<minimum_gradient)
			{
				minimum_gradient=abs(float(gradient));
			//	optimal_resonance=ltc.adf->current_frequency;
			}
			else
			{
				
			}
			
			direction_LO=gradient>0?!direction_LO:direction_LO;
		
			
			if (direction_LO)
			{
				error_gradient=abs((float(gradient)))-minimum_gradient;
			}
			else
			{
				error_gradient=minimum_gradient-abs((float(gradient)));
			}
			
			
			gain=exp((error_gradient)/(2048.0));
			optimum=optimal_resonance*gain;
			if (optimum>(optimal_resonance+step_resonance))
			{
				optimum=optimal_frequency+step_resonance;
			}
			else
			{
				if (optimum<(optimal_frequency-step_resonance))
				{
					optimum=(optimal_frequency-step_resonance);
				}
				else
				{
				}
			}
		}
		else
		{
			if (ltc.adf->current_frequency>optimal_resonance)
			{
				optimum=optimal_resonance- float(TUNE_START_BAND);
				
			}
			else
			{
				optimum=optimal_resonance+ float(TUNE_START_BAND);
				
			}
		}
		
			

	}
	else
	{
		optimum=optimal_resonance;
		
	}
	usb<<"LO Frequency: "<<ltc.adf->current_frequency<<"\tgradient "<<gradient<<"\tdirection_LO "<<direction_LO<<"\terror "<<error_gradient<<"\tgain "<<gain<<"\toptimum "<<optimum<<NEWLINE;
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
