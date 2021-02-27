/* 
* SPI_Syn_Class.cpp
*
* Created: 4/6/2020 10:22:27 AM
* Author: GMateusDP
*/


#include "SPI_Syn_Class.h"


#ifdef ARDUINO_AVR_UNO
#include <SPI.h>
#else
	#include "driver_init.h"
#endif

SPI_Syn_Class	*ptrSPISync;
static	uint8_t	txStaticBuffer[SPI_SYN_BUFFER_SIZE];
static	uint8_t	rxStaticBuffer[SPI_SYN_BUFFER_SIZE];

// default constructor
SPI_Syn_Class::SPI_Syn_Class()
{
		ptrSPISync=this;
			SEN=7;
//	SPI=SPI_1;
} //SPI_Syn_Class
	#ifdef ARDUINO_AVR_UNO
	#else
	
SPI_Syn_Class::SPI_Syn_Class(spi_m_sync_descriptor * spiDesc)
{
	SPI=spiDesc;
	ptrSPISync=this;
} //SPI_Syn_Class
#endif
// default destructor
SPI_Syn_Class::~SPI_Syn_Class()
{
} //~SPI_Syn_Class

bool SPI_Syn_Class::Init(){
	#ifdef ARDUINO_AVR_UNO
	SEN=10;
	pinMode(12, INPUT_PULLUP); 
	pinMode(SEN, OUTPUT);
	digitalWrite(SEN, HIGH);
		SPI.begin();
			ready=true;
	

	#else
	spi_m_sync_get_io_descriptor(SPI, &spio);

	spi_m_sync_enable(SPI);
	#endif
		txBuffer=txStaticBuffer;
		rxBuffer=txStaticBuffer;
	ready=(SPI!=NULL);
	return ready;

	
}
#ifdef ARDUINO_AVR_UNO
#else
void SPI_Syn_Class::SetDescriptor(spi_m_sync_descriptor *spiDesc){
	ptrSPISync=this;
	SPI=spiDesc;
}

#endif


int32_t SPI_Syn_Class::Enable(){
#ifdef ARDUINO_AVR_UNO
	SPI.beginTransaction(SPISettings());
#else	
	spi_m_sync_get_io_descriptor(SPI, &spio);
	spi_m_sync_enable(SPI);
#endif
	ready=true;
	return 0;
}

int32_t  SPI_Syn_Class::Write(const uint8_t * p, int32_t n){
	int32_t w;
	wFlag=true;
#ifdef ARDUINO_AVR_UNO
	SPI.transfer((void*)p, n);
#else
	w=io_write(spio,p,n);
	wFlag=(bool)w;
#endif
	 return w;
	
}
int32_t  SPI_Syn_Class::Read(uint8_t * p, int32_t n){
	int32_t r;
	rFlag=true;
#ifdef ARDUINO_AVR_UNO
	SPI.transfer((void*)p, n);
#else
	r=io_read(spio,p,n);
	rFlag=(bool)r;
#endif
	return  r;
}
void SPI_Syn_Class::Disable(void){
#ifdef ARDUINO_AVR_UNO
	SPI.endTransaction();
#else
	spi_m_sync_disable(SPI);
#endif
	
	
}
void SPI_Syn_Class::SetCS(bool st){
	#ifdef ARDUINO_AVR_UNO
	if (st)
	{
		digitalWrite(SEN, 0x1);
		// delay(1);
		//SPI.endTransaction();
	} 
	else
	{
		SPI.beginTransaction(SPISettings(600000, MSBFIRST, SPI_MODE0));
		//delay(1);
		digitalWrite(SEN, 0x0);
		
	}
	 delay(1);

	#else
	gpio_set_pin_level(CS_ADF5610,st);
	#endif
}


/*
void SPI_Asyn_Class::classInterruptHandler(void) {
	SPICallbackHandler(setSPIReady());
}
*/
bool SPI_Syn_Class::IsSPIReady(void){
	ready=~(rFlag||wFlag);
	//spi_m_async_register_callback(&SPI0, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)(&SPI_Asyn_Class::complete_cb_SPI_0));
	if (ready)
	{
		
		return true;
	} 
	else
	{
		return false;
	}
	return ready;
	
}

//SPI_Asyn_Class::ptrSPIClass->SPICallbackHandler();

