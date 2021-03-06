/* 
* Zero_Cross_Counter.cpp
*
* Created: 3/27/2021 11:09:09 AM
* Author: GMateusDP
*/


#include "Zero_Cross_Counter.h"
#include "SPI_SLAVE_CLASS.h"
#include <driver_init.h>
#include <compiler.h>
#include "string.h"

Zero_Cross_Counter *tako;

static uint16_t capture_static_value_rising;
static uint16_t capture_static_value_falling;
static uint16_t capture_value_tc_a;
static uint16_t capture_value_tc_b;
 static uint8_t	 local_last_frequency[4];

ISR(ZCD0_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */
	tako->leading_edge=true;
	tako->falling_edge=false;
	//tako->CaptureCounterC();

	ZCD0.STATUS = ZCD_CROSSIF_bm;
}

ISR(ZCD1_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */
	tako->falling_edge=true;
	tako->leading_edge=false;
	ZCD1.STATUS = ZCD_CROSSIF_bm;
}
ISR(TCB0_INT_vect)
{
	capture_static_value_rising= TCB0.CNT;
	
// 	if (tako->leading_edge==true)
// 	{
// 		tako->CaptureCounterB_Rising();
	if (capture_static_value_rising>0)
	{
		if (tako->falling_edge)
		{
			tako->CaptureCounterB_Rising();
			tako->full_wave=true;
		}else{
			tako->full_wave=false;
		}

	}
	tako->got_value_r=true;
	tako->leading_edge=true;
	tako->falling_edge=false;

	TCB0.INTFLAGS = TCB_CAPT_bm;
}
ISR(TCB1_INT_vect)
{
		capture_static_value_falling= TCB1.CNT;
		if (capture_static_value_falling>0)
		{
			if (tako->leading_edge)
			{
				tako->CaptureCounterB_Falling();
				tako->full_wave=true;
			}else{
				tako->full_wave=false;
			}
		}
// 		if (tako->falling_edge==true)
// 		{
// 			tako->CaptureCounterB_Falling();
// 		
		tako->got_value_f=true;
	
		tako->falling_edge=true;
		tako->leading_edge=false;
	TCB1.INTFLAGS = TCB_CAPT_bm;
}

ISR(TCD0_TRIG_vect)
{
		//capture_value_b= TCD0_CAPTUREA;
		capture_value_tc_a= TCD0_CAPTUREA;
		//capture_value_tc_b= TCD0_CAPTUREB;
		tako->CaptureCounterC();
	

	/* Insert your TCD TRIGA interrupt handling code here */

	/* Insert your TCD TRIGB interrupt handling code here */
	
	

	/* TRIGA and TRIGB interrupt flags have to be cleared manually */
	TCD0.INTFLAGS = TCD_TRIGA_bm | TCD_TRIGB_bm;
}
// default constructor
Zero_Cross_Counter::Zero_Cross_Counter()
{
	//ptr_zero_cross_handler=this;
	last_frequency=local_last_frequency;
	timer_fall=&capture_static_value_falling;
	timer_rise=&capture_static_value_rising;
	falling_edge=true;
	leading_edge=true;
	post->frequency_array=local_last_frequency;
} //Zero_Cross_Counter

// default destructor
Zero_Cross_Counter::~Zero_Cross_Counter()
{
} //~Zero_Cross_Counter

bool Zero_Cross_Counter::Init(void){

//	ZCD_RISING_Init();
	//	EVSYS.USERTCB0CAPT = EVSYS_USER_CHANNEL0_gc; /* Connect user to event channel 0 */
	//TIMER_RISING_Init();

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
	tako->capture_timer_rise= capture_static_value_rising;
}
void Zero_Cross_Counter::CaptureCounterB_Falling(void){
	tako->capture_timer_fall= capture_static_value_falling;
}

void Zero_Cross_Counter::Set_Last_Frequency(uint32_t lf){
	uint32_t local_value;
	frequency_out=lf;
	for (int i = 0; i < 4; i++)
	{
		local_value=(lf>>((3-i)*8))&0xff;
		last_frequency[i]=((uint8_t)local_value&0xff);
	}
	//memcpy((void*)last_frequency,(void*)&lf,4);
	
}
void Zero_Cross_Counter::Set_Last_Capture_Frequency(void){
	uint32_t local_value;
	tako->frequency_out=OnCapture_Frequecy_Out();
	uint32_t	dummy_frequency=frequency_out;
	for (int i = 0; i < 4; i++)
	{
		local_value=(dummy_frequency>>((3-i)*8))&0xff;
		if (i==0)
		{
			last_frequency[i]=(0xa0)|((uint8_t)local_value&0xff);
		} 
		else
		{
			last_frequency[i]=((uint8_t)local_value&0xff);
		}
		
	}
	//memcpy((void*)last_frequency,(void*)&lf,4);
	
}

