/* 
* Zero_Cross_Counter.h
*
* Created: 3/27/2021 11:09:09 AM
* Author: GMateusDP
*/


#ifndef __ZERO_CROSS_COUNTER_H__
#define __ZERO_CROSS_COUNTER_H__
#include "atmel_start.h"

class Zero_Cross_Counter
{
//variables
public:
	volatile bool leading_edge, zcd_level, falling_edge;
	volatile uint16_t capture_timer_fall;
	volatile 	uint16_t capture_timer_rise;
	

protected:
private:
		uint16_t capture_timer_tc_a;
				uint16_t capture_timer_tc_b;
	bool toogle_bit;
//functions
public:
	Zero_Cross_Counter();
	~Zero_Cross_Counter();
	bool Init();
	void CaptureCounterC(void);
	void CaptureCounterB_Rising(void);
	void CaptureCounterB_Falling(void);
protected:
private:
	Zero_Cross_Counter( const Zero_Cross_Counter &c );
	Zero_Cross_Counter& operator=( const Zero_Cross_Counter &c );

}; //Zero_Cross_Counter

#endif //__ZERO_CROSS_COUNTER_H__
