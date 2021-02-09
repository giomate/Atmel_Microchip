/*
 * lmx2694Handler.h
 *
 *  Created on: Feb 7, 2021
 *      Author: giova
 */

#ifndef LMX2694HANDLER_H_
#define LMX2694HANDLER_H_
#include "lmx2694_Default_Configuration.h"
#include "SPIHandler.h"

class lmx2694_Handler {
public:

	float current_frequency;
private:
	uint16 *read_registers,*write_registers;
	SPI_Handler		*spi;
	uint8_t write_bytes[3],read_bytes[3];
	bool bool_result;
	int int_result;
	uint16 register_value;
	uint8_t private_index;
public:
	lmx2694_Handler();
	virtual ~lmx2694_Handler();
	bool Init();
	bool Self_Test();

private:
	bool Power_Down();
	bool Write_FCAL_EN(bool st);
	bool Toggle_FCAL_EN();
	bool Program_Reset();
	void Get_Three_Bytes(uint32_t data);
	void Make_Three_Bytes(uint8_t index, uint16 data);
	void Initiate_Registers();
	int Write_Single_Register(uint8_t index,uint16 data);
	uint16 Read_Single_Register(uint8_t index);
};

#endif /* LMX2694HANDLER_H_ */
