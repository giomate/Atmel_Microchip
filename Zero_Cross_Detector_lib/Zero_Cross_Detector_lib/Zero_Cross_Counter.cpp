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
ISR(TCB1_INT_vect)
{
		capture_value_falling= TCB1.CNT;
// 		if (ptr_zero_cross_handler->falling_edge==true)
// 		{
// 			ptr_zero_cross_handler->CaptureCounterB_Falling();
// 			
	ptr_zero_cross_handler->CaptureCounterB_Falling();
	TCB1.INTFLAGS = TCB_CAPT_bm;
}

ISR(TCD0_TRIG_vect)
{
		//capture_value_b= TCD0_CAPTUREA;
		capture_value_tc_a= TCD0_CAPTUREA;
		//capture_value_tc_b= TCD0_CAPTUREB;
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

bool Zero_Cross_Counter::Init(void){
	ZCD_RISING_Init();		EVSYS.USERTCB0CAPT = EVSYS_USER_CHANNEL0_gc; /* Connect user to event channel 0 */	TIMER_RISING_Init();
	return true;
}

void Zero_Cross_Counter::ZCD_RISING_Init(){
		// Disable digital input buffer
		PD1_set_isc(PORT_ISC_INPUT_DISABLE_gc);
		// Disable pull-up resistor
		PD1_set_pull_mode(PORT_PULL_OFF);
		ZCD0.CTRLA = 1 << ZCD_ENABLE_bp     /* Setting: enabled */
		| 1 << ZCD_OUTEN_bp    /* Setting: enabled */
		| 0 << ZCD_RUNSTDBY_bp /* Setting: disabled */
		| 0 << ZCD_INVERT_bp;  /* Setting: disabled */
}
uint8_t Zero_Cross_Counter::TIMER_RISING_Init()
{

	// TCB0.CCMP = 0x0; /* Compare or Capture: 0x0 */

	// TCB0.CNT = 0x0; /* Count: 0x0 */

	TCB0.CTRLB = 1 << TCB_ASYNC_bp      /* Asynchronous Enable: enabled */
	| 0 << TCB_CCMPEN_bp   /* Pin Output Enable: disabled */
	| 0 << TCB_CCMPINIT_bp /* Pin Initial State: disabled */
	| TCB_CNTMODE_FRQ_gc;  /* Input Capture Frequency measurement */

	TCB0.DBGCTRL = 1 << TCB_DBGRUN_bp; /* Debug Run: enabled */

	TCB0.EVCTRL = 1 << TCB_CAPTEI_bp    /* Event Input Enable: enabled */
	| 0 << TCB_EDGE_bp    /* Event Edge: disabled */
	| 0 << TCB_FILTER_bp; /* Input Capture Noise Cancellation Filter: disabled */

	TCB0.INTCTRL = 1 << TCB_CAPT_bp   /* Capture or Timeout: enabled */
	| 0 << TCB_OVF_bp; /* OverFlow Interrupt: disabled */

	TCB0.CTRLA = TCB_CLKSEL_DIV1_gc     /* CLK_PER */
	| 1 << TCB_ENABLE_bp   /* Enable: enabled */
	| 0 << TCB_RUNSTDBY_bp /* Run Standby: disabled */
	| 1 << TCB_SYNCUPD_bp  /* Synchronize Update: enabled */
	| 0 << TCB_CASCADE_bp; /* Cascade Two Timer/Counters: disabled */

	return 0;
}

void Zero_Cross_Counter::CaptureCounterC(void){
	if (toogle_bit)
	{
	//	TCD0.CTRLE=TCD_SCAPTUREA_bm;
	//	while ((TCD0.STATUS & TCD_ENRDY_bm) == 0)
	//	; // Wait for Enable Ready to be high.
		capture_timer_tc_a=TCD0.CAPTUREA;
		if (capture_timer_tc_a>0)
		{
			asm("nop");
		}
		
	} 
	else
	{
	//		TCD0.CTRLE=TCD_SCAPTUREB_bm;
	//		while ((TCD0.STATUS & TCD_ENRDY_bm) == 0)
	//		; // Wait for Enable Ready to be high.
		capture_timer_tc_b=TCD0.CAPTUREA;
				capture_timer_tc_b=TCD0.CAPTUREA;
				if (capture_timer_tc_b>0)
				{
					asm("nop");
				}
		
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