/*
 * ADF5610_lib.cpp
 *
 * Created: 2/20/2021 12:21:41 PM
 * Author : GMateusDP
#include <atmel_start.h>*/



#ifdef ARDUINO_AVR_UNO
#include <Arduino.h>
#include "ADF5610Driver.h" 
ADF5610_Driver adf;


	
	/* Initializes MCU, drivers and middleware */
void setup(){
	Serial.begin(115200);
	Serial.setTimeout(1000);
	#ifdef NOT_SDI
	pinMode(12, INPUT); 
	#else
		pinMode(12, INPUT_PULLUP); 
#endif

	adf.Init();
}
void loop(){
	
	/* Replace with your application code */
	
		adf.SelfTest(1);
		Serial.println("is running outside");
		delay(1000);
		adf.Init();

}
#endif
