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
#include "Zero_Cross_Counter.h"

#define  BAND_WIDTH	2
#define  CENTER_FREQUENCY	3600
#define  BAND_WIDTH_FRACTION	3

class LTC5548_HANDLER {
public:
		lmx2694_Handler  *lmx;
		ADF5610_Driver  *adf;
		Zero_Cross_Counter *zcd;
private:

	bool  enable;
	uint8_t pio_register,max_index;
	uint16_t adc_value;
	uint32_t last_frequency_b=0;
	uint32_t last_frequency_c=0;
	uint32_t current_frequency_f=0;
	uint32_t current_frequency_r=0;
public:
	LTC5548_HANDLER();
	~LTC5548_HANDLER();
	bool Init();
	bool Set_Mixer(bool st);
	void Read_Frequency_Values(void);
	uint8_t Read_Index(void);
	bool Set_Enable(bool st);
	bool Check_Mixer(void);

private:

	bool Stop_Mixer(void);
		bool Start_Mixer(void);
		bool Start_LO(void);
		bool Start_RF(void);

};

#endif /* LTC5548HANDLER_H_ */
