/* 
* SPI_Asyn_Class.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Asyn_Class.h"

SPI_Asyn_Class	*ptrSPISync;




static void LMX_SPI_Transfer_Done()
{
	ptrSPISync->transfer_done=true;
}

// default constructor
SPI_Asyn_Class::SPI_Asyn_Class()
{
		ptrSPISync=this;
		transfer_done=false;
//	SPI=SPI_1;
} //SPI_Asyn_Class



// default destructor
SPI_Asyn_Class::~SPI_Asyn_Class()
{
} //~SPI_Asyn_Class

void SPI_Asyn_Class::Init(){



	// Register callback function releasing SS when transfer is complete
	SPI_0_register_callback(LMX_SPI_Transfer_Done);


	
}


int8_t SPI_Asyn_Class::Enable(){

	return 0;
}

int8_t  SPI_Asyn_Class::Write(const uint8_t * p, uint8_t n){
	if (transfer_done)
	{
		transfer_done=false;
		SPI_0_exchange_block(p, n);
		return n;
	} 
	else
	{
		return 0;
	}
	




	// If we get here, everything was OK
	
	
}
int8_t  SPI_Asyn_Class::Read(uint8_t * p,uint8_t n){
	if (transfer_done)
	{
			transfer_done=false;
			SPI_0_exchange_block(p, n);
			while (SPI_0_status_busy())
			; // Wait for the transfer to complete
			return n;
	} 
	else
	{
		return 0
	}

	
}
void SPI_Asyn_Class::Disable(void){
	
	
}
void SPI_Asyn_Class::SetCS(bool st){
	CS_LMX_set_level(st)
	
}


/*
void SPI_Asyn_Class::classInterruptHandler(void) {
	SPICallbackHandler(setSPIReady());
}
*/
bool SPI_Asyn_Class::Is_Transfer_Done(void){

	return transfer_done;
	
}

//SPI_Asyn_Class::ptrSPIClass->SPICallbackHandler();

