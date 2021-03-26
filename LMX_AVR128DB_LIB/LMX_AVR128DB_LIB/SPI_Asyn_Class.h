/* 
* SPI_Asyn_Class.h
*
* Created: 4/6/2020 10:22:28 AM
* Author: GMateusDP
*/


#ifndef __SPI_ASYNC_CLASS_H__
#define __SPI_ASYNC_CLASS_H__
#include <stdio.h>
#include <string.h>
#include <atmel_start.h>
#include <spi_basic_example.h>
#include <spi_basic.h>
#include <atomic.h>
#define  SPI_SYN_BUFFER_SIZE	32

class SPI_Asyn_Class
{
//variables
public:
	volatile bool  transfer_done;
		uint8_t	*txBuffer;
		uint8_t	*rxBuffer;
protected:
private:

//functions
public:
	SPI_Asyn_Class();

	~SPI_Asyn_Class();
	void Init(void);
	int32_t Enable(void);
	void Disable(void);
	int8_t Write( const uint8_t *  p, int32_t n);
	int8_t  Read(uint8_t * p, int32_t n);
	void SetCS(bool st);
	
	
	bool	Is_Transfer_Done(void);
//	void	SetDescriptor(spi_m_sync_descriptor *);
protected:
	
private:
	SPI_Asyn_Class( const SPI_Asyn_Class &c );
	SPI_Asyn_Class& operator=( const SPI_Asyn_Class &c );

}; //SPI_Asyn_Class


#endif //__SPI_Asyn_Class_H__
