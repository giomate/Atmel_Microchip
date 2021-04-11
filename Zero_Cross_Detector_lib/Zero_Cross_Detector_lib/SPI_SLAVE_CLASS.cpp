/* 
* SPI_SLAVE_CLASS.cpp
*
* Created: 4/4/2021 6:48:06 PM
* Author: GMateusDP
*/


#include "SPI_SLAVE_CLASS.h"
#include "Zero_Cross_Counter.h"


static uint8_t write_buffer_local[16];
static uint8_t read_buffer_local[16];
static uint8_t command=0;

SPI_SLAVE_CLASS *post;

static void SPI_Transfer_Done(){
	 post->transfer_done=true;
	  post->type = SPI_READ;
}



ISR(SPI1_INT_vect)
{
	/* SPI_ZCD_desc.data points to array element
	   to write the received data to. The data to be transmitted
	   is in the next array element.
	*/

	
	uint8_t command = SPI1.DATA;
	uint8_t wdata = 0;

	SPI1.INTFLAGS = SPI_RXCIF_bm;

	if (post->type != SPI_WRITE) {
		if (command==0x01)
		{
			post->transfer_done=false;
			post->Write_Data(post->frequency_array,4);
			
			
		}
		else
		{
			post->acknowledge=false;
		}
	}else{
		if (post->type != SPI_READ)
		{
			post->data++;
			wdata = *(post->data);
			post->size_message--;
			// if more bytes to be transferred
			if (post->size_message != 0) {
				// more data to send, send a byte
				SPI1.DATA = wdata;
			}
			// if last byte has been transferred, update status
			// and optionally call callback
			else {
				post->status = SPI_DONE;
				SPI_Transfer_Done();
				
			}
		} 
		else
		{
		}
	}

	

	
		

	
}

// default constructor
SPI_SLAVE_CLASS::SPI_SLAVE_CLASS()
{
	//ptrSPI_Slave=this;
	transfer_done=false;
	read_buffer=read_buffer_local;
	write_buffer=write_buffer_local;
	type=SPI_READ;
	
} //SPI_SLAVE_CLASS

// default destructor
SPI_SLAVE_CLASS::~SPI_SLAVE_CLASS()
{
} //~SPI_SLAVE_CLASS

bool SPI_SLAVE_CLASS::Init(){
	 	//ptrSPI_Slave=this;
	SPI_ZCD_init();
	SPI_ZCD_enable();
	
}

void SPI_SLAVE_CLASS::Read_Data(){
	 rdata = SPI1.DATA;
	 command=rdata;
}

void SPI_SLAVE_CLASS::Write_Data(uint8_t *block, uint8_t sz){
	if (block!=NULL)
	{
		data  = (uint8_t *)block;
		size_message   = sz;
		type   = SPI_WRITE;
		status = SPI_BUSY;

		SPI1.DATA = *data;
	}
	
}

void SPI_SLAVE_CLASS::SPI_ZCD_init()
{

	SPI1.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	| 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	| 0 << SPI_ENABLE_bp /* Enable Module: enabled */
	| 0 << SPI_MASTER_bp /* SPI module in slave mode */
	| SPI_PRESC_DIV4_gc; /* System Clock / 4 */

	 SPI1.CTRLB = 0 << SPI_BUFEN_bp /* Buffer Mode Enable: disabled */
			 | 0 << SPI_BUFWR_bp /* Buffer Write Mode: disabled */
			 | SPI_MODE_0_gc /* SPI Mode 0 */
			 | 0 << SPI_SSD_bp; /* Slave Select Disable: disabled */

	SPI1.INTCTRL = 0 << SPI_DREIE_bp    /* Data Register Empty Interrupt Enable: enabled */
	| 1 << SPI_IE_bp     /* Interrupt Enable: enabled */
	| 0 << SPI_RXCIE_bp  /* Receive Complete Interrupt Enable: enabled */
	| 0 << SPI_SSIE_bp   /* Slave Select Trigger Interrupt Enable: disabled */
	| 0 << SPI_TXCIE_bp; /* Transfer Complete Interrupt Enable: enabled */

	status = SPI_FREE;
}
/**
 * \brief Enable SPI_ZCD
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_SLAVE_CLASS::SPI_ZCD_enable()
{
	SPI1.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_ZCD
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_SLAVE_CLASS::SPI_ZCD_disable()
{
	SPI1.CTRLA &= ~SPI_ENABLE_bm;
}
void SPI_SLAVE_CLASS::Check_Command()
{
	if (PC3_get_level())
	{
		asm("nop");
	} 
	else
	{
		command=SPI1.DATA;
		
		if ((SPI1.INTFLAGS & SPI_RXCIF_bm)){
			
			if (command>1)
			{
				Write_Data(tako->last_frequency, 4);
			}
			else
			{
			}
		}else{
			SPI_ZCD_write_block(tako->last_frequency, 4);
		}
	}
	
	
}