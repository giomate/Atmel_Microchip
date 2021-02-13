/*
 * lmx2694Handler.cpp
 *
 *  Created on: Feb 7, 2021
 *      Author: giova
 */

#include "lmx2694Handler.h"

#include "string.h"
static SPI_Syn_Class staticSPI(&SPI_0);
static uint16_t local_read_registers[0x73];
static uint16_t local_write_registers[0x73];


lmx2694_Handler::lmx2694_Handler() {
	// TODO Auto-generated constructor stub
	write_registers=local_read_registers;
	read_registers=local_write_registers;
}

lmx2694_Handler::~lmx2694_Handler() {
	// TODO Auto-generated destructor stub
}
bool lmx2694_Handler::Init(){
	spi=&staticSPI;
	spi->Init();
	spi->SetCS(true);
	Power_Down();
	Program_Reset();
	Initiate_Registers();
	delay_ms(10);
	Toggle_FCAL_EN();
	return ((Read_Single_Register(0x6e)>>9)&0x02);



}

bool lmx2694_Handler::Power_Down(){
	spi->SetCS(false);
	Get_Three_Bytes((uint32_t)PROGRAM_POWERDOWN);
	int_result=spi->Write(write_bytes,3);
	bool_result=int_result>0;
	spi->SetCS(true);
	return bool_result;
}
bool lmx2694_Handler::Write_FCAL_EN(bool st){

	if(st){
		register_value=Read_Single_Register(0)|(0x01<<FCAL_EN);
	}else{
		register_value=Read_Single_Register(0)&(~((uint16_t)(0x01<<FCAL_EN)));
	}
	int_result=Write_Single_Register(0,register_value);

	return int_result;
}
bool lmx2694_Handler::Toggle_FCAL_EN(){
	Write_FCAL_EN(false);
	delay_us(100);
	bool_result=Write_FCAL_EN(true);

	return bool_result;
}
bool lmx2694_Handler::Program_Reset(){
	spi->SetCS(false);
	Get_Three_Bytes((uint32_t)PROGRAM_RESET_1);
	int_result=spi->Write(write_bytes,3);
	//bool_result=int_result>0;
	spi->SetCS(true);
	delay_us(100);
	spi->SetCS(false);
	Get_Three_Bytes((uint32_t)PROGRAM_RESET_0);
	int_result=spi->Write(write_bytes,3);
	bool_result=int_result>0;
	spi->SetCS(true);
	return bool_result;
}
void lmx2694_Handler::Get_Three_Bytes(uint32_t data){
	for(int i=0; i<3;i++){
		write_bytes[2-i]=(uint8_t)((data>>(8*i))&0xff);
	}

}
void lmx2694_Handler::Make_Three_Bytes(uint8_t index, uint16_t data){
	for(int i=0; i<2;i++){
		write_bytes[2-i]=(uint8_t)((data>>(8*i))&0xff);
	}
	write_bytes[0]=index;
}
void lmx2694_Handler::Initiate_Registers(){
	for(int i=NUMBER_REGISTERS; i>0;i--){
		Write_Single_Register(i-1,default_registers[i-NUMBER_REGISTERS]);

	}
}
int lmx2694_Handler::Write_Single_Register(uint8_t index,uint16_t data){
	spi->SetCS(false);
	Make_Three_Bytes(index,data);
	int_result=spi->Write(write_bytes,3);
	spi->SetCS(true);
	return int_result;
}
uint16_t lmx2694_Handler::Read_Single_Register(uint8_t index){
	Write_Single_Register(0,(uint16_t)MUXOUT_READBACK);
	register_value=0;
	uint16_t  last_value=0xff;
	while((register_value==0)|(last_value!=register_value)|(register_value==0xffff)){
		spi->SetCS(false);
			private_index=index|0x80;
			memset(read_bytes,0,3);
			int_result=spi->Write(&private_index,1);
			int_result=spi->Read(read_bytes,2);
		//	Make_Three_Bytes(private_index,0);
			
		//	int_result=spi->TransferData(write_bytes,3,read_bytes,3);
			last_value=register_value;
			register_value=read_bytes[1]*256+read_bytes[2];
			spi->SetCS(true);
	}


	Write_Single_Register(0,(uint16_t)(MUXOUT_READBACK|0x04));
	return register_value;
}
bool lmx2694_Handler::Self_Test(){
	return false;
}
