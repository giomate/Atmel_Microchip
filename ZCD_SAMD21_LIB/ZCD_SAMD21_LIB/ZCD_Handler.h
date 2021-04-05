/* 
* ZCD_Handler.h
*
* Created: 4/4/2021 10:13:32 PM
* Author: giova
*/


#ifndef __ZCD_HANDLER_H__
#define __ZCD_HANDLER_H__
#include "SPI_Syn_ZCD_Class.h"

class ZCD_Handler
{
//variables
public:
	uint32_t tone;
protected:
private:
	SPI_Syn_ZCD_Class *spi;
	uint8_t command;
	uint8_t read_buffer[4];
	uint32_t last_tone;
//functions
public:
	ZCD_Handler();
	~ZCD_Handler();
	uint32_t Get_Tone();
	bool Init();
protected:
private:
	ZCD_Handler( const ZCD_Handler &c );
	ZCD_Handler& operator=( const ZCD_Handler &c );

}; //ZCD_Handler

#endif //__ZCD_HANDLER_H__
