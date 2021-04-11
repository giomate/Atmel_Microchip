/* 
* FREQUENCY_ESTIMATOR.h
*
* Created: 4/6/2021 10:04:05 AM
* Author: GMateusDP
*/


#ifndef __FREQUENCY_ESTIMATOR_H__
#define __FREQUENCY_ESTIMATOR_H__
#include <compiler.h>
#define MAX_ERROR_COUNTER	32

class FREQUENCY_ESTIMATOR
{
//variables
public:
	 uint16_t *timer_fall;
	 uint16_t *timer_rise;
protected:
private:
	 uint16_t capture_timer_falling;
	uint16_t capture_timer_rising,min_capture;
	uint32_t average_counter;
	uint32_t current_frequency;
	uint8_t error_counter;
//functions
public:
	FREQUENCY_ESTIMATOR();
	~FREQUENCY_ESTIMATOR();
	uint32_t Get_Frequency_Out();
	uint32_t OnCapture_Frequecy_Out(void);
protected:
private:
	FREQUENCY_ESTIMATOR( const FREQUENCY_ESTIMATOR &c );
	FREQUENCY_ESTIMATOR& operator=( const FREQUENCY_ESTIMATOR &c );

}; //FREQUENCY_ESTIMATOR

#endif //__FREQUENCY_ESTIMATOR_H__
