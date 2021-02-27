/*
 * ADF5610_SAMD_LIB.cpp
 *
 * Created: 2/27/2021 12:55:45 PM
 * Author : GMateusDP
 */ 


#include <atmel_start.h>
#include "ADF5610Driver.h"
ADF5610_Driver adf;
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	adf.Init();
	/* Replace with your application code */
	while (1) {
		adf.SelfTest(1);
		delay_ms(1000);
		adf.Init();
	}
}
