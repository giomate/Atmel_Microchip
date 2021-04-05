/* 
* SPI_Syn_Class.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Syn_Class.h"

SPI_Syn_Class	*ptrSPISync;



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

		spi_m_sync_get_io_descriptor(&SPI_LMX, &io);

	Enable();
	ready=true;
	
}



uint8_t SPI_Syn_Class::Enable(){
	
	spi_m_sync_enable(&SPI_LMX);
	return 0;
}

uint8_t  SPI_Syn_Class::Write(const uint8_t * p, uint8_t n){
	ready=false;
	io_write(io, p, (uint16_t)n);

	return n;
}
uint8_t  SPI_Syn_Class::Read(uint8_t * p, uint8_t n){
	ready=false;
		io_read(io, p, (uint16_t)n);

	
	return n;
}
void SPI_Syn_Class::Disable(void){
	//SPI_LMX_disable();
	spi_m_sync_disable(&SPI_LMX);
	
}
void SPI_Syn_Class::SetCS(bool st){
	gpio_set_pin_level(CS_LMX,st);
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

