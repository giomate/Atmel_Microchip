/* 
* SPI_Async_Handler.cpp
*
* Created: 3/26/2021 2:48:19 PM
* Author: GMateusDP
*/


#include "SPI_Async_Handler.h"
SPI_Async_Handler	*ptrSPIAsync;

static void LMX_SPI_Transfer_Done()
{
	ptrSPIAsync->transfer_done=true;
}










// default constructor
SPI_Async_Handler::SPI_Async_Handler()
{
		ptrSPIAsync=this;
		transfer_done=false;
//	SPI=SPI_1;
} //SPI_Async_Handler



// default destructor
SPI_Async_Handler::~SPI_Async_Handler()
{
} //~SPI_Async_Handler

void SPI_Async_Handler::Init(){


	Enable();
	// Register callback function releasing SS when transfer is complete
//	SPI_LMX_register_callback(LMX_SPI_Transfer_Done);
	transfer_done=true;

	
}


int8_t SPI_Async_Handler::Enable(){
	SPI_LMX_enable();
	return 0;
}

int8_t  SPI_Async_Handler::Write(const uint8_t * p, uint8_t n){
	if (transfer_done)
	{
		transfer_done=false;
		SPI_LMX_write_block((void *)p, n);
	//			while (SPI_LMX_status_busy())
	//			; // Wait for the transfer to complete
				return n;

	} 
	else
	{
		return 0;
	}
	




	// If we get here, everything was OK
	
	
}
int8_t  SPI_Async_Handler::Read(uint8_t * p,uint8_t n){
	if (transfer_done)
	{
			transfer_done=false;
			SPI_LMX_read_block((void*)p, n);
		//	while (SPI_LMX_status_busy())
		//	; // Wait for the transfer to complete
			return n;
	} 
	else
	{
		return 0;
	}

	
}
void SPI_Async_Handler::Disable(void){
	//SPI_0_disable();
	
}
void SPI_Async_Handler::SetCS(bool st){
	CS_LMX_set_level(st);
	
}


/*
void SPI_Async_Handler::classInterruptHandler(void) {
	SPICallbackHandler(setSPIReady());
}
*/
bool SPI_Async_Handler::Is_Transfer_Done(void){

	return transfer_done;
	
}