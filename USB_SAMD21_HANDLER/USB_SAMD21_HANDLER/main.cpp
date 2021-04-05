/*
 * USB_SAMD21_HANDLER.cpp
 *
 * Created: 4/5/2021 6:54:36 PM
 * Author : GMateusDP
 */ 


#include <atmel_start.h>
#include "CDC_Class.h"


void usb_test(void){
	if (usb.available())
	{
		usb<<"it should work";
		int inByte=usb.read();
		if (inByte>33)
		{
			//usb.writeData2(&inByte,1);
			usb.println(inByte);
			usb.println((float)inByte/23);
			
			usb<<"it does work"<<NEWLINE;
		}
	}
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	usb.Init();
	delay_ms(100);

	while (1) {
		usb_test();
		
	}
}