/*
 * lmx2694Handler.h
 *
 *  Created on: Feb 7, 2021
 *      Author: giova
 */

#ifndef LMX2694HANDLER_H_
#define LMX2694HANDLER_H_
#include "lmx2694_Default_Configuration.h"
//#include "SPIHandler.h"
#include "SPI_Syn_Class.h"

class lmx2694_Handler {
public:

	float current_frequency;
private:
	uint16_t *read_registers,*write_registers;
	SPI_Syn_Class		*spi;
	uint8_t write_bytes[3],read_bytes[3];
	bool bool_result,is_locked;
	int int_result;
	uint16_t register_value;
	uint8_t private_index,channel_index,mash_order,channel_divider;
	uint32_t N_divider,numerator,denominator,gcd;
	float target_frequency,vco_frequency,divider,fraction,step;
	uint8_t error_counter;
	bool direction;
	
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
	void Make_Three_Bytes(uint8_t index, uint16_t data);
	void Initiate_Registers();
	int Write_Single_Register(uint8_t index,uint16_t data);
	uint16_t Read_Single_Register(uint8_t index);
	int Set_MUXOUT_READBACK(bool st);
	bool IsLocked(void);
	uint8_t Get_OUT_MUX(uint8_t ov);
	int Get_Channel_Divider_Value(bool mbr);
	uint32_t Get_N_Divider(bool mbr);
	uint32_t Get_Numerator(bool mbr);
	uint32_t Get_Denominator(bool mbr);
	float Calculate_Current_Frequency(bool mbr);
	uint32_t  GCD(uint32_t a, uint32_t b);
	float Set_Target_Frequency(float tf);
	void  Write_Division_Registers(void);
	uint8_t Choose_Channel_Divider_Index();
	int Program_PFD_DLY_SEL(float vcof);
	void Program_PFD_DLY_SEL(void);
	void Calculate_Fraction(float fr);
	int Set_MASH_ORDER(uint8_t mo);
};

#endif /* LMX2694HANDLER_H_ */
