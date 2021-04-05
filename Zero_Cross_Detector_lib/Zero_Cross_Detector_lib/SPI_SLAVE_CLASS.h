/* 
* SPI_SLAVE_CLASS.h
*
* Created: 4/4/2021 6:48:06 PM
* Author: GMateusDP
*/


#ifndef __SPI_SLAVE_CLASS_H__
#define __SPI_SLAVE_CLASS_H__
#include <spi_basic.h>

class SPI_SLAVE_CLASS
{
//variables
public:
	volatile bool transfer_done,acknowledge;
	spi_transfer_status_t  status;
	uint8_t *              data;
	uint8_t                size_message;
	spi_transfer_type_t    type;
	
	
protected:
private:
	uint8_t  *read_buffer;
	uint8_t  *write_buffer;
	uint8_t rdata;
	
//functions
public:
	SPI_SLAVE_CLASS();
	~SPI_SLAVE_CLASS();
	void Write_Data(uint8_t *block, uint8_t sz);
	void Read_Data();
	bool Init();
	void Check_Command();
protected:
private:
	SPI_SLAVE_CLASS( const SPI_SLAVE_CLASS &c );
	SPI_SLAVE_CLASS& operator=( const SPI_SLAVE_CLASS &c );
	void SPI_ZCD_init();
	void SPI_ZCD_enable();
	void SPI_ZCD_disable();

}; //SPI_SLAVE_CLASS

static SPI_SLAVE_CLASS post;

#endif //__SPI_SLAVE_CLASS_H__
