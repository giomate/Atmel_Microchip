/*
 * LTC5548HANDLER.h
 *
 *  Created on: Feb 21, 2021
 *      Author: giova
 */

#ifndef LTC5548HANDLER_H_
#define LTC5548HANDLER_H_
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "lmx2694Handler.h"
#include "ADF5610Driver.h"
#include "ZCD_Handler.h"
#include "MIXER_TUNNER_HELPER.h"




class LTC5548_HANDLER: private MIXER_TUNNER_HELPER
 {
public:
		lmx2694_Handler  *lmx;
		ADF5610_Driver  *adf;
		ZCD_Handler *zcd;
		float tune_rf_frequency,tune_LO_frequency;
private:

	bool  enable;
	uint8_t pio_register,max_index;
	uint16_t adc_value;
	uint32_t last_frequency_b=0;
	uint32_t last_frequency_c=0;
	uint32_t current_frequency_f=0;
	uint32_t current_frequency_r=0;
	uint32_t tone;
	float next_RF_frequency, current_LO_frequency,next_LO_frequency;
	uint8_t error_counter;
	float upper_limit, lower_limit,step,step_resonance;
	bool direction;
	
public:
	LTC5548_HANDLER();
	~LTC5548_HANDLER();
	bool Init();
	bool Set_Mixer(bool st);
	void Read_Frequency_Values(void);
	uint8_t Read_Index(void);
	bool Set_Enable(bool st);
	bool Check_Mixer(void);
	float Tune_RF_Mixer();
	float Tune_LO_Mixer();
	float Start_Searching(float uplimit, float downlimit);
	float Keep_Searching();
	float Start_Searching_Resonance(float uplimit, float downlimit);
	float Keep_Searching_Resonance();
	

private:

	bool Stop_Mixer(void);
		bool Start_Mixer(void);
		bool Start_LO(void);
		bool Start_RF(void);
		bool Set_RF(float f);
		bool Set_LO(float f);

};
extern LTC5548_HANDLER ltc;

#endif /* LTC5548HANDLER_H_ */
