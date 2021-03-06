/* 
* SPI_Syn_Class_ADF.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Syn_Class_ADF.h"

SPI_Syn_Class_ADF	*ptrSPISync_adf;



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

	spi_m_sync_get_io_descriptor(&SPI_ADF, &io);
	Enable();
	ready=true;
	
}



uint8_t SPI_Syn_Class_ADF::Enable(){
	spi_m_sync_enable(&SPI_ADF);
	return 0;
}

uint8_t  SPI_Syn_Class_ADF::Write(const uint8_t * p, uint8_t n){
	ready=false;

	io_write(io, p, (uint16_t)n);

	return n;
}
uint8_t  SPI_Syn_Class_ADF::Read(uint8_t * p, uint8_t n){
	ready=false;
	io_read(io, p, (uint16_t)n);

	
	return n;
}
void SPI_Syn_Class_ADF::Disable(void){
	spi_m_sync_disable(&SPI_ADF);
	//spi_m_sync_disable(SPI);
	
}
void SPI_Syn_Class_ADF::SetCS(bool st){
	gpio_set_pin_level(CS_ADF,st);
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

