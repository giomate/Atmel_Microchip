/*
 * ADF5610Driver.h
 *
 *  Created on: Dec 6, 2020
 *      Author: GMateusDP
 */

#ifndef ADF5610DRIVER_H_
#define ADF5610DRIVER_H_

//#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
//#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
//#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
//#define bitSet(value, bit) ((value) |= (1UL << (bit)))
//#include "SPIHandler.h"
#include "SPI_Syn_Class_ADF.h"
class ADF5610_Driver {
public:
	float current_frequency;  // Start-up frequency = 5000 MHz
private:
	SPI_Syn_Class_ADF		*spi_adf;
	float upper_limit,lower_limit;


	

	uint32_t RegRead[23];      // ADF5610 Reg's
	uint32_t RegWrite[23];      // ADF5610 Reg's
	uint32_t RegIni[23];      // ADF5610 Reg's
	uint32_t buffer32;
	char receivedChars[5];   // an array to store the received data
	float step,target_frequency;
	 int dir;
	 bool is_locked;
	  uint32_t aux_register;
	    uint8_t local_index;
		 uint32_t recibido32;




	   uint8_t received_bytes[4];
	   uint8_t to_send[4];
	   uint8_t dummy_byte;
	   bool pll_started;
	      double f_N,f_GCD,N_Int,N,F_Frac1x;
	      uint32_t F_FracN,fPDfGCD ;

public:
	ADF5610_Driver();
	~ADF5610_Driver();
	bool Init(void);
	void SetNextFrequency(void);
	void CalculateVCOValues(void);
	void WriteRegisters(uint8_t d);
	void ReadRegisters(uint8_t d);
	bool LockDetect(void);
	void InitiateRegisters(void);
	void CompleteConfigurationFlow(unsigned int k);
	void ShortConfigurationFlow(void );
	void ReadAllRegisters(void);
	void ShowRegisters(int m);
	long Flipper(uint32_t recibido);
	long CalculateGCD(long a, long b);
	bool SelfTest(uint8_t cycles);
	bool Is_Locked(void);
	bool	Start_Woobling(float ul, float ll);
	bool Keep_Woobling(void);
	void Set_Target_Frequency(float tf);
private:
	void ConvertU32FourByteArray(uint8_t *array,uint32_t  data);
	bool  InitPLL(void);
	void WriteSubVCO(void);
	long GCD(long a, long b) ;
#ifdef ARDUINO_AVR_UNO
	void usleep(long us);
#endif
#ifdef NIOS_BUILD
#else
	void usleep(long us);
#endif

};

#endif /* ADF5610DRIVER_H_ */
