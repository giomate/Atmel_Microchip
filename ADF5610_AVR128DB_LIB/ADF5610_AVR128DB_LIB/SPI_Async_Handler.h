/* 
* SPI_Async_Handler.h
*
* Created: 3/26/2021 2:48:19 PM
* Author: GMateusDP
*/


#ifndef __SPI_ASYNC_HANDLER_H__
#define __SPI_ASYNC_HANDLER_H__

#include "atmel_start.h"

class SPI_Async_Handler
{
//variables
public:
	volatile bool  transfer_done;
protected:
private:

//functions
public:
	SPI_Async_Handler();
	~SPI_Async_Handler();
	void Init(void);
	int8_t Enable(void);
	void Disable(void);
	int8_t Write( const uint8_t *  p, uint8_t n);
	int8_t  Read(uint8_t * p, uint8_t n);
	void SetCS(bool st);
	bool	Is_Transfer_Done(void);
protected:
private:
	SPI_Async_Handler( const SPI_Async_Handler &c );
	SPI_Async_Handler& operator=( const SPI_Async_Handler &c );

}; //SPI_Async_Handler

#endif //__SPI_ASYNC_HANDLER_H__
