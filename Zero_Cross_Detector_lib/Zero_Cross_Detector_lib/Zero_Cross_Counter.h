/* 
* Zero_Cross_Counter.h
*
* Created: 3/27/2021 11:09:09 AM
* Author: GMateusDP
*/


#ifndef __ZERO_CROSS_COUNTER_H__
#define __ZERO_CROSS_COUNTER_H__
#include "atmel_start.h"
#include "FREQUENCY_ESTIMATOR.h"

class Zero_Cross_Counter: public  FREQUENCY_ESTIMATOR
{
//variables
public:
	volatile bool leading_edge, zcd_level, falling_edge,got_value_r,got_value_f;
	volatile	 uint16_t capture_timer_fall;
	volatile	uint16_t capture_timer_rise;
	
	 uint8_t	 *last_frequency;
	volatile uint32_t	frequency_out;
	bool full_wave;
	

protected:
private:
		uint16_t capture_timer_tc_a;
			uint16_t capture_timer_tc_b;
	bool toogle_bit;
	uint16_t min_capture;
//functions
public:
	Zero_Cross_Counter();
	~Zero_Cross_Counter();
	bool Init();
	void CaptureCounterC(void);
	void CaptureCounterB_Rising(void);
	void CaptureCounterB_Falling(void);
	void Set_Last_Frequency(uint32_t lf);
	void Set_Last_Frequency(void);
	void Set_Last_Capture_Frequency(void);
protected:
private:
	Zero_Cross_Counter( const Zero_Cross_Counter &c );
	Zero_Cross_Counter& operator=( const Zero_Cross_Counter &c );
	void ZCD_RISING_Init(void);
	uint8_t TIMER_RISING_Init();
}; //Zero_Cross_Counter

extern Zero_Cross_Counter *tako;


#endif //__ZERO_CROSS_COUNTER_H__
