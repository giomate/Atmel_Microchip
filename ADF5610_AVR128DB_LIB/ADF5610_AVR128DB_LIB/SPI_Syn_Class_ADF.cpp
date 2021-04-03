/* 
* SPI_Syn_Class_ADF.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Syn_Class_ADF.h"

SPI_Syn_Class_ADF	*ptrSPISync_adf;
static	uint8_t	txStaticBuffer[SPI_SYN_BUFFER_SIZE];
static	uint8_t	rxStaticBuffer[SPI_SYN_BUFFER_SIZE];


// default constructor
SPI_Syn_Class_ADF::SPI_Syn_Class_ADF()
{
		ptrSPISync_adf=this;
//	SPI=SPI_1;
} //SPI_Syn_Class_ADF



// default destructor
SPI_Syn_Class_ADF::~SPI_Syn_Class_ADF()
{
} //~SPI_Syn_Class_ADF

void SPI_Syn_Class_ADF::Init(){

	
	Enable();
	ready=true;
	
}



uint8_t SPI_Syn_Class_ADF::Enable(){
	SPI_ADF_enable();
	return 0;
}

uint8_t  SPI_Syn_Class_ADF::Write(const uint8_t * p, uint8_t n){
	ready=false;

	SPI_ADF_write_block((void *)p, n);

	return n;
}
uint8_t  SPI_Syn_Class_ADF::Read(uint8_t * p, uint8_t n){
	ready=false;
	SPI_ADF_read_block((void *)p, n);

	
	return n;
}
void SPI_Syn_Class_ADF::Disable(void){
	SPI_ADF_disable();
	//spi_m_sync_disable(SPI);
	
}
void SPI_Syn_Class_ADF::SetCS(bool st){
	CS_ADF_set_level(st);
}


/*
void SPI_Asyn_Class::classInterruptHandler(void) {
	SPICallbackHandler(setSPIReady());
}
*/
bool SPI_Syn_Class_ADF::IsSPIReady(void){
	return true;
	
}

//SPI_Asyn_Class::ptrSPIClass->SPICallbackHandler();

