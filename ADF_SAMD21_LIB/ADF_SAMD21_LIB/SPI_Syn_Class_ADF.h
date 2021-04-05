/* 
* SPI_Syn_Class_ADF.h
*
* Created: 4/6/2020 10:22:28 AM
* Author: GMateusDP
*/


#ifndef __SPI_Syn_Class_ADF_ADF_H__
#define __SPI_Syn_Class_ADF_ADF_H__
#include "driver_init.h"
#include "utils.h"
#define  SPI_SYN_BUFFER_SIZE	32

class SPI_Syn_Class_ADF
{
//variables
public:
	volatile bool  ready;
		uint8_t	*txBuffer;
		uint8_t	*rxBuffer;
protected:
private:
	io_descriptor *io;
//functions
public:
	SPI_Syn_Class_ADF();

	~SPI_Syn_Class_ADF();
	void Init(void);
	uint8_t Enable(void);
	void Disable(void);
	uint8_t Write( const uint8_t *  p, uint8_t n);
	uint8_t  Read(uint8_t * p, uint8_t n);
	void SetCS(bool st);
	
	
	bool	IsSPIReady(void);
	
protected:
	
private:
	SPI_Syn_Class_ADF( const SPI_Syn_Class_ADF &c );
	SPI_Syn_Class_ADF& operator=( const SPI_Syn_Class_ADF &c );

}; //SPI_Syn_Class_ADF


#endif //__SPI_Syn_Class_ADF_H__
