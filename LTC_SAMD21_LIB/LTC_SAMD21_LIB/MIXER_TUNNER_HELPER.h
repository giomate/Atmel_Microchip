/* 
* MIXER_TUNNER_HELPER.h
*
* Created: 4/6/2021 3:45:39 PM
* Author: giova
*/


#ifndef __MIXER_TUNNER_HELPER_H__
#define __MIXER_TUNNER_HELPER_H__
#include "compiler.h"
#define TUNE_START_BAND	1
#define TUNE_MAX_BAND	6
#define  CENTER_FREQUENCY	3600
#define  OPTIMAL_FREQUENCY  3604.31

class MIXER_TUNNER_HELPER
{
//variables
public:
protected:
private:
	float optimum,error_tune,last_error_tune,gain;
	uint32_t tone;
	float minimum_tone, optimal_frequency;
	uint32_t tone_array[3];
	bool direction;
	int32_t gradient;

//functions
public:
	MIXER_TUNNER_HELPER();
	~MIXER_TUNNER_HELPER();
	float Calculate_Optimum(uint32_t tn);
	
protected:
private:
	MIXER_TUNNER_HELPER( const MIXER_TUNNER_HELPER &c );
	MIXER_TUNNER_HELPER& operator=( const MIXER_TUNNER_HELPER &c );
	bool Calculate_Gradient(uint32_t lv);

}; //MIXER_TUNNER_HELPER

#endif //__MIXER_TUNNER_HELPER_H__
