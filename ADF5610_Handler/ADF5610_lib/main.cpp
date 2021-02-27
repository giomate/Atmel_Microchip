/*
 * main.cpp
 *
 * Created: 2/27/2021 11:43:12 AM
 *  Author: GMateusDP
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
				delay(1000);
				adf.Init();
	}
}