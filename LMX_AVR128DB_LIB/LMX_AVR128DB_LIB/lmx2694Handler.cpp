/*
 * lmx2694Handler.cpp
 *
 *  Created on: Feb 7, 2021
 *      Author: giova
 */

#include "lmx2694Handler.h"
#include "math.h"

#include "string.h"
static SPI_Syn_Class staticSPI(&SPI_0);
static uint16_t local_read_registers[0x73];
static uint16_t local_write_registers[0x73];
static const int channel_divider_values[]={2,4,6,8,12,16,24,32,48,64,72,96,128,192};
const uint8_t channel_divider_size=14;
const uint32_t precision=0xffffffff;

lmx2694_Handler::lmx2694_Handler() {
	// TODO Auto-generated constructor stub
	write_registers=local_read_registers;
	read_registers=local_write_registers;
	channel_divider=1;
	channel_index=0;
	step=(4400.0-400.0)/(1024*32.0);
	current_frequency=4000;
	target_frequency=current_frequency+step;
	direction=true;

	
	mash_order=1;
	
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
	//Set_MASH_ORDER(1);
#if ONLY_LOCK_SIGNAL
	delay_ms(100);
	return IsLocked();
#else
	return ((Read_Single_Register(0x6e)>>9)&0x02);
#endif




}
int lmx2694_Handler::Set_MASH_ORDER(uint8_t mo){
	mash_order=mo;
#if ONLY_LOCK_SIGNAL
	register_value=write_registers[44] ;
#else
	register_value=Read_Single_Register(44);
#endif
	
	register_value=(register_value&(0xfff8))|(uint16_t)mash_order;
	int_result=Write_Single_Register(44,register_value);
	return int_result;
}
bool lmx2694_Handler::IsLocked(void){
	
	is_locked=gpio_get_pin_level(PA06);
	if (is_locked)
	{
	} 
	else
	{
		delay_ms(10);
		is_locked=gpio_get_pin_level(PA06);
	}
	
	if (is_locked)
	{
		if (Get_OUT_MUX(2)>0)
		{
			current_frequency=Calculate_Current_Frequency(false)/1;
		} 
		else
		{
			channel_divider=Get_Channel_Divider_Value(false);
			current_frequency=Calculate_Current_Frequency(false)/channel_divider;
		}
	} 
	else
	{
#if ONLY_LOCK_SIGNAL	

#else
		is_locked=((Read_Single_Register(0x6e)>>9)&0x02);
#endif
		
	}
	return is_locked;
}
uint8_t lmx2694_Handler::Get_OUT_MUX(uint8_t ov){
	if (ov==2)
	{
		return	(uint8_t)((write_registers[46])&(0x03));
	} 
	else
	{
		return	(uint8_t)((write_registers[45]>>11)&(0x03));
	}
}
int lmx2694_Handler::Get_Channel_Divider_Value(bool mbr){
	if (mbr)
	{
		channel_index=((Read_Single_Register(75))>>6)&0x1f;
	} 
	else
	{
		channel_index=((write_registers[75])>>6)&0x1f;
	}
	return channel_divider_values[channel_index];
}

uint32_t lmx2694_Handler::Get_N_Divider(bool mbr){
	if (mbr)
	{
	} 
	else
	{
		N_divider=(uint32_t)(write_registers[34]<<16)+write_registers[36];
	}
	return N_divider;
}
uint32_t lmx2694_Handler::Get_Numerator(bool mbr){
	if (mbr)
	{
	} 
	else
	{
		numerator=(uint32_t)(write_registers[42]<<16)+write_registers[43];
	}
	return numerator;
}
uint32_t lmx2694_Handler::Get_Denominator(bool mbr){
	if (mbr)
	{
	}
	else
	{
		denominator=(uint32_t)(write_registers[38]<<16)+write_registers[39];
	}
	return denominator;
}
float lmx2694_Handler::Calculate_Current_Frequency(bool mbr){
	if (mbr)
	{
	} 
	else
	{
		vco_frequency=REFERENCE_FREQUENCY*2*(float(Get_N_Divider(false))+float(Get_Numerator(false))/float(Get_Denominator(false)));
	}
	return vco_frequency;
}
uint32_t  lmx2694_Handler::GCD(uint32_t a, uint32_t b)
{
	if (a == 0)
	return b;
	else if (b == 0)
	return a;

	if (a < b)
	return GCD(a, b % a);
	else
	return GCD(b, a % b);
}

float lmx2694_Handler::Set_Target_Frequency(float tf){
	if (tf>MAX_VCO_FREQUENCY)
	{
		target_frequency=MAX_VCO_FREQUENCY;
	} 
	else
	{
		if (tf>MIN_PLL_FREQUENCY)
		{
			target_frequency=tf;
			
			
			if (tf>MIN_VCO_FREQUENCY)
			{
				if (current_frequency>MIN_VCO_FREQUENCY)
				{
					
				} 
				else
				{
					Write_Single_Register(46,write_registers[46]|OUT_MUX_VCO);
				}
				channel_divider=1;
				
					
					
			}
			else
			{
				if (current_frequency<MIN_VCO_FREQUENCY)
				{
				} 
				else
				{
					Write_Single_Register(46,write_registers[46]&(~((uint16_t)0x03)));
				}
				register_value=write_registers[75]&(~((uint16_t)0x07c0));
				Write_Single_Register(75,register_value|(((uint16_t)Choose_Channel_Divider_Index())<<6));
				if (channel_divider>2)
				{
					Write_Single_Register(31,0x43ec);
				}else{
					Write_Single_Register(31,0x3ec);
				}
				
			}
			divider=(tf*channel_divider)/(REFERENCE_FREQUENCY*2);
			N_divider=(uint32_t)(floor(divider));
			fraction=divider-N_divider;
			Calculate_Fraction(fraction);
			Write_Division_Registers();
			
			Toggle_FCAL_EN();
			
		} 
		else
		{

		}
		
	}

}
void  lmx2694_Handler::Write_Division_Registers(void){
	Write_Single_Register(43,(uint16_t)(numerator&0xffff));
	Write_Single_Register(42,(uint16_t)(numerator>>16));
	Write_Single_Register(39,(uint16_t)(denominator&0xffff));
	Write_Single_Register(38,(uint16_t)(denominator>>16));
	Program_PFD_DLY_SEL();
	Write_Single_Register(36,(uint16_t)(N_divider&0xffff));
	Write_Single_Register(34,(uint16_t)(N_divider>>16));
	

}

uint8_t lmx2694_Handler::Choose_Channel_Divider_Index(){
	for ( int i = 0; i < channel_divider_size; i++)
	{
		if (i<3)
		{
				if (MAX_VCO_FREQUENCY/(channel_divider_values[i])>target_frequency)
				{
				}
				else
				{
					if (i>0)
					{
							channel_index=i-1;
					} 
					else
					{
						 channel_index=0;
					}
					break;
				
				}
		} 
		else
		{
				if (11500/(channel_divider_values[i])>target_frequency)
				{
				}
				else
				{
					channel_index= i-1;
					break;
				}
		}
	
	}
	channel_divider=channel_divider_values[channel_index];
	return channel_index;
}
int lmx2694_Handler::Program_PFD_DLY_SEL(float vcof){
	if (mash_order)
	{
		switch (mash_order)
		{
			case 0:
				if (vcof>12500)
				{
					Write_Single_Register(37,0x8204);
				}
				else
				{
					Write_Single_Register(37,0x8104);
				}
		
			break;
			case 1:
				if (vcof>12500)
				{
					Write_Single_Register(37,0x8304);
				}
				else
				{
					if (vcof>10000)
					{
						Write_Single_Register(37,0x8204);
					} 
					else
					{
						Write_Single_Register(37,0x8104);
					}
					
				}
				break;
			
			
			default:
			/* Your code here */
			break;
		}
	} 
	else
	{
	}
	
	return write_registers[37];
}
void lmx2694_Handler::Program_PFD_DLY_SEL(void){
	if (target_frequency>MIN_VCO_FREQUENCY)
	{
		vco_frequency=target_frequency;
	} 
	else
	{
		vco_frequency=target_frequency*Get_Channel_Divider_Value(false);
	}
	Program_PFD_DLY_SEL(vco_frequency);
}

void lmx2694_Handler::Calculate_Fraction(float fr){
	gcd=GCD(round(fr*precision),precision);
	numerator=round(fr*precision)/gcd;
	denominator=precision/gcd;
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

#if ONLY_LOCK_SIGNAL
	if(st){
		register_value=write_registers[0]|(0x01<<FCAL_EN);
	}else{
		register_value=write_registers[0]&(~((uint16_t)(0x01<<FCAL_EN)));
	}
#else
	if(st){
		register_value=Read_Single_Register(0)|(0x01<<FCAL_EN);
	}else{
		register_value=Read_Single_Register(0)&(~((uint16_t)(0x01<<FCAL_EN)));
	}
#endif


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
	for (int i = 0; i < NUMBER_REGISTERS; i++)
	{
	//	write_registers[i]=default_registers[NUMBER_REGISTERS-i-1];
		read_registers[i]=default_registers[NUMBER_REGISTERS-i-1];
	}
	for(int i=NUMBER_REGISTERS; i>0;i--){
	
		Write_Single_Register(i-1,read_registers[i-1]);

	}

}
int lmx2694_Handler::Write_Single_Register(uint8_t index,uint16_t data){
	if ((write_registers[index]==data)&is_locked)
	{
	} 
	else
	{
		spi->SetCS(false);
		Make_Three_Bytes(index,data);
		int_result=spi->Write(write_bytes,3);
		if (int_result>0)
		{
				write_registers[index]=data;
		} 
		else
		{
		}

		spi->SetCS(true);
	}
	
	return int_result;
}
uint16_t lmx2694_Handler::Read_Single_Register(uint8_t index){
	Set_MUXOUT_READBACK(false);
	register_value=0;
	uint16_t  last_value=0xff;
	while((register_value==0)|(register_value==0xffff)){
		spi->SetCS(false);
			private_index=index|0x80;
			memset(read_bytes,0,3);
			int_result=spi->Write(&private_index,1);
			int_result=spi->Read(read_bytes,2);
		//	Make_Three_Bytes(private_index,0);
			
		//	int_result=spi->TransferData(write_bytes,3,read_bytes,3);
			register_value=read_bytes[0]*256+read_bytes[1];
			spi->SetCS(true);
	}

	read_registers[index]=register_value;
	Set_MUXOUT_READBACK(true);
	return register_value;
}

int lmx2694_Handler::Set_MUXOUT_READBACK(bool st){
	if(st){
		register_value=read_registers[0]|(0x01<<READBACK_ENABLE_BIT);
		}else{
		register_value=read_registers[0]&(~((uint16_t)(0x01<<READBACK_ENABLE_BIT)));
	}
	int_result=Write_Single_Register(0,register_value);
	return int_result;
}

bool lmx2694_Handler::Self_Test(){
	error_counter=0;
	while(error_counter<0xff){
		if (IsLocked())
		{
			if (direction)
			{
					if (current_frequency+step>MAX_SENSOR_FREQUENCY)
					{
						direction=false;
					}
					else
					{
					}
			} 
			else
			{
				if (current_frequency-step<MIN_PLL_FREQUENCY)
				{
					direction=true;
				} 
				else
				{
				}
			}
		
			target_frequency=direction?current_frequency+step:current_frequency-step;
			Set_Target_Frequency(target_frequency);
			error_counter=0;
			delay_ms(10);
		} 
		else
		{
			error_counter++;
			delay_ms(100+10*error_counter);
			Set_Target_Frequency(current_frequency);
			delay_ms(100);
		}
	}
}
