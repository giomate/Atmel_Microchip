/* 
* SPI_Syn_Class.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Syn_Class.h"

SPI_Syn_Class	*ptrSPISync;
static	uint8_t	txStaticBuffer[SPI_SYN_BUFFER_SIZE];
static	uint8_t	rxStaticBuffer[SPI_SYN_BUFFER_SIZE];


// default constructor
SPI_Syn_Class::SPI_Syn_Class()
{
		ptrSPISync=this;
//	SPI=SPI_1;
} //SPI_Syn_Class



// default destructor
SPI_Syn_Class::~SPI_Syn_Class()
{
} //~SPI_Syn_Class

void SPI_Syn_Class::Init(){

	
	Enable();
	ready=true;
	
}



uint8_t SPI_Syn_Class::Enable(){
	SPI_LMX_enable();
	return 0;
}

uint8_t  SPI_Syn_Class::Write(const uint8_t * p, uint8_t n){
	ready=false;
	SPI_LMX_write_block((void *)p, n);

	return n;
}
uint8_t  SPI_Syn_Class::Read(uint8_t * p, uint8_t n){
	ready=false;
	SPI_LMX_read_block((void *)p, n);

	
	return n;
}
void SPI_Syn_Class::Disable(void){
	SPI_LMX_disable();
	//spi_m_sync_disable(SPI);
	
}
void SPI_Syn_Class::SetCS(bool st){
	CS_LMX_set_level(st);
}


/*
void SPI_Asyn_Class::classInterruptHandler(void) {
	SPICallbackHandler(setSPIReady());
}
*/
bool SPI_Syn_Class::IsSPIReady(void){
	return true;
	
}

//SPI_Asyn_Class::ptrSPIClass->SPICallbackHandler();

