/* 
* ZCD_Handler.cpp
*
* Created: 4/4/2021 10:13:32 PM
* Author: giova
*/


#include "ZCD_Handler.h"
#include "stdio_start.h"

static SPI_Syn_ZCD_Class local_spi;

// default constructor
ZCD_Handler::ZCD_Handler()
{
	spi=&local_spi;
	tone=0;
} //ZCD_Handler

// default destructor
ZCD_Handler::~ZCD_Handler()
{
} //~ZCD_Handler

bool ZCD_Handler::Init(){
	spi->Init();
	return true;
}

uint32_t ZCD_Handler::Get_Tone(){
	command=0x01;
	spi->SetCS(false);
	spi->Write(&command,1);
	spi->SetCS(true);
	delay_ms(100);
	spi->SetCS(false);
	spi->Read(read_buffer,4);
	spi->SetCS(true);
	last_tone=tone;
	tone=0;
	for ( int i = 0; i < 4; i++)
	{
		tone|=(uint32_t)(read_buffer[i]<<(8*(3-i)));
	}
	if (tone>0)
	{
	
		if (tone<0xffffff)
		{
			gpio_toggle_pin_level(LED0);
			printf("tone: %lu \r\n",tone);
		} 
		else
		{
		}
		
	} 
	else
	{
		tone=last_tone;
	}
	return tone;
}