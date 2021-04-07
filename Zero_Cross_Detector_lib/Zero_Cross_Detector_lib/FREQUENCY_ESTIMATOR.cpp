/* 
* FREQUENCY_ESTIMATOR.cpp
*
* Created: 4/6/2021 10:04:04 AM
* Author: GMateusDP
*/


#include "FREQUENCY_ESTIMATOR.h"
#include "Zero_Cross_Counter.h"

// default constructor
FREQUENCY_ESTIMATOR::FREQUENCY_ESTIMATOR()
{
	error_counter=0;
} //FREQUENCY_ESTIMATOR

// default destructor
FREQUENCY_ESTIMATOR::~FREQUENCY_ESTIMATOR()
{
} //~FREQUENCY_ESTIMATOR

uint32_t FREQUENCY_ESTIMATOR::Get_Frequency_Out(){
	if (abs(tako->capture_timer_rise-tako->capture_timer_fall)<MAX_ERROR_COUNTER)
	{
	
		average_counter=(tako->capture_timer_rise+tako->capture_timer_fall)/2;
		error_counter=0;
	} 
	else
	{
		capture_timer_falling=*timer_fall;
		capture_timer_rising=*timer_rise;
		min_capture=capture_timer_rising<capture_timer_falling?capture_timer_rising:capture_timer_falling;
		if (min_capture>0)
		{
			average_counter=min_capture;
		
			
		} 
		else
		{
			average_counter=1;
		}
		
		error_counter++;
	
		
	}
	current_frequency=(uint32_t)(24000000/(average_counter));
	return current_frequency;
}
uint32_t FREQUENCY_ESTIMATOR::OnCapture_Frequecy_Out(void){
		capture_timer_falling=*timer_fall;
		capture_timer_rising=*timer_rise;
	if ((tako->got_value_r&tako->got_value_f)&(capture_timer_rising>0)&(capture_timer_falling>0))
	{
		min_capture=capture_timer_rising<capture_timer_falling?capture_timer_rising:capture_timer_falling;
		if (min_capture>0)
		{
			average_counter=min_capture;
		} 
		else
		{
			average_counter=2;
		}
		
	}
	else
	{
		if ((tako->got_value_r)&(capture_timer_rising>0))
		{
			average_counter=capture_timer_rising;
		} 
		else
		{
			if ((tako->got_value_f)&(capture_timer_falling>0))
			{
				average_counter=capture_timer_falling;
			} 
			else
			{
				average_counter=1;
			}
		}
	}
	current_frequency=(uint32_t)(24000000/(average_counter));
	return current_frequency;	
}