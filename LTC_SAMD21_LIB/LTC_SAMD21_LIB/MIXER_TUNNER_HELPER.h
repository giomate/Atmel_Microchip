/* 
* MIXER_TUNNER_HELPER.h
*
* Created: 4/6/2021 3:45:39 PM
* Author: giova
*/


#ifndef __MIXER_TUNNER_HELPER_H__
#define __MIXER_TUNNER_HELPER_H__
#include "compiler.h"

#define  BAND_WIDTH	2048
#define  BAND_WIDTH_FRACTION	1025
#define TUNE_START_BAND	2
#define TUNE_MAX_BAND	6
#define  CENTER_FREQUENCY	9000
#define  OPTIMAL_FREQUENCY  CENTER_FREQUENCY+TUNE_START_BAND
#define  RESONANCE_SEED_FREQUENCY	10535.64

class MIXER_TUNNER_HELPER
{
//variables
public:
	int32_t gradient;
protected:
private:
	float optimum,error_tune,last_error_tune,gain;
	uint32_t tone;
	float minimum_tone, optimal_frequency,optimal_resonance,step_resonance;
	uint32_t tone_array[3];
	bool direction,direction_LO;
	float minimum_gradient,error_gradient,last_gradient;

//functions
public:
	MIXER_TUNNER_HELPER();
	~MIXER_TUNNER_HELPER();
	float Calculate_Optimum(uint32_t tn);
	void Update_Optimal_Frequency(float f){optimal_frequency=f+TUNE_START_BAND;}
	void Set_Step_Resonance(float r){step_resonance=r;}
	float Calculate_Optimum_Resonance(void);
	void Set_Minimum_Tone(float f){minimum_tone=f;}
	
protected:
private:
	MIXER_TUNNER_HELPER( const MIXER_TUNNER_HELPER &c );
	MIXER_TUNNER_HELPER& operator=( const MIXER_TUNNER_HELPER &c );
	bool Calculate_Gradient(uint32_t lv);

}; //MIXER_TUNNER_HELPER

#endif //__MIXER_TUNNER_HELPER_H__
