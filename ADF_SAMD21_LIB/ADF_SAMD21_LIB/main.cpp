/*
 * ADF_SAMD21_LIB.cpp
 *
 * Created: 4/4/2021 3:12:27 PM
 * Author : giova
 */ 



#include <atmel_start.h>

#include "ADF5610Driver.h"
ADF5610_Driver adf;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	printf("hello\n\r");
	adf.Init();
	/* Replace with your application code */
	while (1) {
		adf.SelfTest(1);
		delay_ms(1000);
		adf.Init();
	}
}
