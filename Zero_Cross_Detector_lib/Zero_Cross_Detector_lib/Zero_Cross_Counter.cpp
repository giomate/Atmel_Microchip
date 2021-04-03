/* 
* Zero_Cross_Counter.cpp
*
* Created: 3/27/2021 11:09:09 AM
* Author: GMateusDP
*/


#include "Zero_Cross_Counter.h"
#include <driver_init.h>
#include <compiler.h>
Zero_Cross_Counter *ptr_zero_cross_handler;
static uint16_t capture_value_rising;
static uint16_t capture_value_falling;
static uint16_t capture_value_tc_a;
static uint16_t capture_value_tc_b;

ISR(ZCD0_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */
	ptr_zero_cross_handler->leading_edge=true;
	ptr_zero_cross_handler->falling_edge=false;
	//ptr_zero_cross_handler->CaptureCounterC();

	ZCD0.STATUS = ZCD_CROSSIF_bm;
}

ISR(ZCD1_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */
	ptr_zero_cross_handler->falling_edge=true;
	ptr_zero_cross_handler->leading_edge=false;
	ZCD1.STATUS = ZCD_CROSSIF_bm;
}
ISR(TCB0_INT_vect)
{
	capture_value_rising= TCB0.CNT;
// 	if (ptr_zero_cross_handler->leading_edge==true)
// 	{
// 		ptr_zero_cross_handler->CaptureCounterB_Rising();
	ptr_zero_cross_handler->CaptureCounterB_Rising();

	TCB0.INTFLAGS = TCB_CAPT_bm;
}
ISR(TCB2_INT_vect)
{
		capture_value_falling= TCB2.CNT;
// 		if (ptr_zero_cross_handler->falling_edge==true)
// 		{
// 			ptr_zero_cross_handler->CaptureCounterB_Falling();
// 			
	ptr_zero_cross_handler->CaptureCounterB_Falling();
	TCB2.INTFLAGS = TCB_CAPT_bm;
}

ISR(TCD0_TRIG_vect)
{
		//capture_value_b= TCD0_CAPTUREA;
		capture_value_tc_a= TCD0_CAPTUREA;
		capture_value_tc_b= TCD0_CAPTUREB;
		ptr_zero_cross_handler->CaptureCounterC();
	

	/* Insert your TCD TRIGA interrupt handling code here */

	/* Insert your TCD TRIGB interrupt handling code here */
	
	

	/* TRIGA and TRIGB interrupt flags have to be cleared manually */
	TCD0.INTFLAGS = TCD_TRIGA_bm | TCD_TRIGB_bm;
}
// default constructor
Zero_Cross_Counter::Zero_Cross_Counter()
{
	ptr_zero_cross_handler=this;
} //Zero_Cross_Counter

// default destructor
Zero_Cross_Counter::~Zero_Cross_Counter()
{
} //~Zero_Cross_Counter

void Zero_Cross_Counter::CaptureCounterC(void){
	if (toogle_bit)
	{
	//	TCD0.CTRLE=TCD_SCAPTUREA_bm;
	//	while ((TCD0.STATUS & TCD_ENRDY_bm) == 0)
	//	; // Wait for Enable Ready to be high.
		capture_timer_tc_a=TCD0.CAPTUREA;
		
	} 
	else
	{
	//		TCD0.CTRLE=TCD_SCAPTUREB_bm;
	//		while ((TCD0.STATUS & TCD_ENRDY_bm) == 0)
	//		; // Wait for Enable Ready to be high.
		capture_timer_tc_b=TCD0.CAPTUREB;
		
	}
	TCD0.CTRLE=TCD_RESTART_bm;
	toogle_bit=!toogle_bit;
	leading_edge=false;
}
void Zero_Cross_Counter::CaptureCounterB_Rising(void){
	capture_timer_rise= capture_value_rising;
}
void Zero_Cross_Counter::CaptureCounterB_Falling(void){
	capture_timer_fall= capture_value_falling;
}