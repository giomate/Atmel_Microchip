/*
 * ADF5610Driver.cpp
 *
 *  Created on: Dec 6, 2020
 *      Author: GMateusDP
 */

#include "ADF5610Driver.h"
#include <stdio.h>
#include "math.h"
#include "string.h"
#include "inttypes.h"
#ifdef NIOS_BUILD
#include "unistd.h"
#endif

#ifdef ARDUINO_AVR_UNO
	#include "Arduino.h"
#else
	#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
	#define bitSet(value, bit) ((value) |= (1UL << (bit)))
	#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
	#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
	#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#endif


//static SPI_Handler staticSPI;
static SPI_Syn_Class staticSPI(&SPI_0);

ADF5610_Driver::ADF5610_Driver() {
	// TODO Auto-generated constructor stub
	 current_frequency=3600;
		

		 buffer32=0;
		 dir=1;
		 spi=&staticSPI;
		 is_locked=false;
		 upper_limit=3602;
		 lower_limit=3598;
		 step=1.0/1024.0;
		 target_frequency=current_frequency+step;
		 pll_started=false;
}

ADF5610_Driver::~ADF5610_Driver() {
	// TODO Auto-generated destructor stub
}

void ADF5610_Driver::Init(void){
	spi=&staticSPI;
//	spi->Init(SPI_ADF5610_BASE,0);

	//spi->SetCS(true);
	spi->Init();

	 InitiateRegisters();
	 InitPLL();
	// CompleteConfigurationFlow(0);


}
bool  ADF5610_Driver::InitPLL(void){

	do{
		CompleteConfigurationFlow(0);
		ReadAllRegisters();
		pll_started= bitRead(RegRead[1],1)&(bitRead(RegRead[1],0)==0);
		delay_ms(100);
		
	
	}while((!IsLocked())|((!pll_started)|false));
	return pll_started;
}

void ADF5610_Driver::SetNextFrequency(void)     // Freq hier lokal oben global
{

  CalculateVCOValues();



}
void ADF5610_Driver::ShowRegisters(int index){

	switch (index){
		  case 0:
		   #ifdef ARDUINO_AVR_UNO
			Serial.print("Read R");Serial.print(index);Serial.print("0x");Serial.println(RegRead[index],HEX);
			#else
#ifdef NIOS_BUILD
			  printf("Read R%d",index);
			  printf(":  0x%08lx\n" ,RegRead[index]);
#endif
			 #endif
			  break;
		//  case 16:
		//  		  break;
		//  case 17:
		//  	  		  break;
		  case 18:
		  	  		  break;
		  case 19:
		  	  		  break;
		  default:
		     #ifdef ARDUINO_AVR_UNO
		     Serial.print("Write R");Serial.print(index);Serial.print(" 0x");Serial.print(RegWrite[index],HEX);
			  Serial.print("\tRead R");Serial.print(index);Serial.print(" 0x");Serial.println(RegRead[index],HEX);
		     #else
#ifdef NIOS_BUILD

			  printf("Write R%d",index);
			  printf(":  0x%08lx\t",RegWrite[index]);
			  printf("Read R%d",index);
			  printf(":  0x%08lx\n",RegRead[index]);
#endif
			  #endif

			  break;


	  }


}
bool ADF5610_Driver::LockDetect(void){

  ReadRegisters(18);
  bool locked=false;
  //if ((digitalRead(12)== HIGH))   // select lock/unlock
  if ((bitRead(RegRead[18],1)== true)&&(bitRead(RegRead[18],2)== false))   // select lock/unlock
  {
    locked = true;
	//Serial.println("is locked");
  } else {
    locked = false;
  }
  return locked;
}

bool ADF5610_Driver::IsLocked(void){
#ifdef NOT_SDO
	is_locked= gpio_get_pin_level(PA06);
#else


	if (gpio_get_pin_level(PA06)){
		is_locked = true;
	}else{
		ReadRegisters(18);
		if ((bitRead(RegRead[18],1)== true)&&(bitRead(RegRead[18],2)== false))   // select lock/unlock
		{
			is_locked = true;
			
		} else {
			is_locked = false;
		}
	}
	
		
	
#endif

	return is_locked;
}

void  ADF5610_Driver::WriteRegisters(uint8_t index) {
  local_index=0;
  buffer32 = 0;


  //RegAdr = d;
  if (index>19){
    if(index>22){
		if (index>23)
		{
			if (index==24)
			{
				local_index=4;
			} 
			else
			{
				 local_index=3;
			}
		} 
		else
		{
			 local_index=3;
		}
     
    }else {
		 local_index=5;
     
    }
  }else{
    local_index=index;
  }
  switch (local_index){
	 // case 0:
		//  ReadRegisters(vco_index);
		 // ShowRegisters(vco_index);
		//  break;
	  case 16:
	  		  break;
	  case 17:
	  	  		  break;
	  case 18:
	  	  		  break;
	  case 19:
	  	  		  break;
	  default:
	
		
		    spi->SetCS(false);
		
			  buffer32 =((uint32_t)local_index <<3)|(RegWrite[index]<<8);
			  // buffer32 =((uint32_t)vco_index <<25)|(RegWrite[index]<<1);
			  ConvertU32FourByteArray(to_send,buffer32);
			
				// delay(1);
		          spi->Write(to_send,4);
				   //   for (int i = 0; i < 4; i++){
					//	  dummy_byte=(uint8_t)(buffer32 >> ((3-i) * 8))&0xFF;
					  //    spi->Write(&dummy_byte);
				      //}
		
			 usleep(1);
		   spi->SetCS(true);
		 

		    //Serial.print(received[4], HEX);Serial.print(received[3], HEX); Serial.print(received[2], HEX);Serial.println(received[1], HEX);
		   if(!is_locked){
			   usleep(1);
			   ReadRegisters(local_index);
			   
				   if(RegRead[local_index]!=RegWrite[index]){
							   ShowRegisters(index);

						   }
			   
		   }



		  break;


  }
}
void ADF5610_Driver::ConvertU32FourByteArray(uint8_t *array,uint32_t  data){
	for (int i =0;i<4;i++){
		array[i]=(uint8_t)((data>>((3-i)*8)&0xff));
	}
}

void ADF5610_Driver::ReadRegisters(uint8_t index) {

#ifdef NOT_SDO
	RegRead[index]=RegWrite[index];
#else
	spi->SetCS(false);
	to_send[0]=0;
	to_send[1]=0;
	to_send[2]=index;
	to_send[3]=0;
	spi->Write(to_send,4);
//	for(int i =0; i<4;i++){
//		spi->Write(&to_send[i]);
//	}
	
	spi->SetCS(true);
	delay_ms(1);
	spi->SetCS(false);
	
	spi->Read((uint8_t*)&recibido32,4);
	RegRead[index]=0;
	RegRead[index]=0;
	

	RegRead[index]=((recibido32&(0x000000FF))<<24)|((recibido32&(0x0000FF00))<<8);
	
	RegRead[index]|=((recibido32&(0xFF000000))>>24)|((recibido32&(0x00FF0000))>>8);
	RegRead[index]>>=7;
	bitClear(RegRead[index],24);
	
	spi->SetCS(true);
#endif
	






}
void ADF5610_Driver::InitiateRegisters(void){
        // ADF5610 Reg's

  for (int i = 0; i < 23; i++) {
    switch (i) {
    case 0:
        //  RegIni[i] = 0x20;
          break;
      case 1:
        RegIni[i] = 0x2;
        break;
      case 2:
        RegIni[i] = 0x1;
        break;
      case 3:
        RegIni[i] = 0x31;
        break;
      case 4:
        RegIni[i] = 0xFD70A3;
        break;
      case 5:
        RegIni[i] = 0x000;
        break;
      case 6:
        RegIni[i] = 0x2F4A;
        break;
      case 7:
	  
        RegIni[i] = 0x214D;
        break;
      case 8:
        RegIni[i] = 0xC9BEFF;
        break;
        case 9:
        RegIni[i] = 0x3FFF;
        break;
        case 10:
       // RegIni[i] = 0x2043;
        RegIni[i] = 0x2047;
        break;
        case 11:
        RegIni[i] = 0xF8061;
        break;
        case 15:
        RegIni[i] = 0x081;
        break;
		case 16:
		RegIni[i] = 0x020;
		break;
        case 20:
        RegIni[i] = RegIni[5];
         break;
        case 21:
      // RegIni[i] = 0x8E08;
       RegIni[i] = (0x01<<3)|(0x00<<7)|(0x07<<9)|(0x03<<12)|(0x01<<15);
         break;
         case 22:
     //  RegIni[i] = 0x390;
         RegIni[i] =(0x02<<3)|(0x07<<7)|(0x00);
         break;
        default:
        RegIni[i] = 0x0;
        break;
    }
    RegWrite[i]=RegIni[i];

  }
}
void ADF5610_Driver::CompleteConfigurationFlow(unsigned int k){
  for (int i=k; i<20;i++){
    if (i==5){
      for(int j=22;j>19;j--){
        WriteRegisters(j);
       
      }
	   WriteRegisters(5);

    }else if((i!=4)|(i!=3)){
      WriteRegisters(i);
    }
  }
  WriteRegisters(3);
  WriteRegisters(4);

}
void ADF5610_Driver::ShortConfigurationFlow(void){
  WriteRegisters(8);
  WriteSubVCO();
  WriteRegisters(3);
  WriteRegisters(4);
}
void ADF5610_Driver::WriteSubVCO(void){
	WriteRegisters(22);
	//WriteRegisters(21);
	WriteRegisters(20);
	WriteRegisters(5);
}

void ADF5610_Driver::ReadAllRegisters(){
  for (int i=0; i<=19;i++){
	  
    ReadRegisters((uint8_t)i);
  }
}
long ADF5610_Driver::GCD(long a, long b) {
	if (a == 0)
	return b;
	else if (b == 0)
	return a;

	if (a < b)
	return GCD(a, b % a);
	else
	return GCD(b, a % b);
}


long ADF5610_Driver::Flipper(uint32_t recibido){
  uint8_t b1=0,b2=0;
  bool bit1;
  uint32_t transformado=0;
  for(int i=0;i<4;i++){
    b1=((uint8_t)(recibido >> ((3-i) * 8)))&0xFF;

    for(int j=0;j<8;j++){
      bit1=bitRead(b1,j);
      bitWrite(b2,7-j,bit1);

    }
    transformado<<=8;

    transformado |=(uint32_t)(b2);

  }
  return (long)transformado;
}

void ADF5610_Driver::CalculateVCOValues(void){
	  uint8_t VCOAdd=0;
	  double fPD;
	 aux_register=0;

	  //double PFDFreq = refin * ((1.0 + RD2refdoubl) / (R_Counter * (1.0 + RD1_Rdiv2))); //Phase detector frequency
	  double fX=50; //Phase detector frequency



		double  fDIV=target_frequency;
		int k=floor(log((14600)/(fDIV))/log(2));
		//  Serial.print("kdiv: "); Serial.println((byte)k,HEX);
		uint8_t kDIV=7-(uint8_t)(k);
	   // Serial.println(kDIV,BIN);


	  double fVCO = 7300*((target_frequency*pow(2, k))/(14600)); //VCO
	  //Serial.println(fVCO);
	  if (fVCO<4000){
		fPD = 1*fX; //Phase detector frequency
	  }else{
		fPD = 2*fX; //Phase detector frequency
	  }
#ifdef EXACT_FREQ
    N_Int = floor(fVCO/fPD);   // N= 50 for 5 GHz   // Turn N into integer
    f_N=N_Int*fPD;
    f_GCD=GCD(long(fVCO),long(fPD));
    fPDfGCD=(uint32_t)(fPD/f_GCD);
    F_FracN=(uint32_t)(ceil(pow(2,24)*(fVCO-f_N)/(fPD)));
    
#else

 N = fVCO /fPD;   // Calculate N

  //Serial.println(N);

  N_Int = floor(fVCO/fPD);   // N= 50 for 5 GHz   // Turn N into integer


 F_Frac1x = (N - N_Int) * pow(2, 24);   // Calculate Frac1 (N remainder * 2^24)

   F_FracN = (uint32_t)F_Frac1x;  // turn Frac1 into an integer
 
#endif

  for (int i = 0; i < 23; i++) {
    //Serial.println(i);
    switch (i) {
      case 3:
        RegWrite[i] =(uint32_t)(0x00FFFFFF&((long)N_Int));  //Fixed value (Phase control not needed)
        break;
      case 4:
        RegWrite[i] =(uint32_t)(0x00FFFFFF&(F_FracN));
        break;
      case 5:
   #ifdef NOT_SDO
		 RegWrite[i]=RegIni[i];
   #else
		 ReadRegisters((uint8_t)0x10);
   
		  for (int j=15;j>0;j--){
			   if(j>7){
				   //bitWrite(RegWrite[i], j, 0);
				   bitWrite(RegWrite[i], j, bitRead(RegRead[0x10],j-8));
				}else{
				   bitWrite(RegWrite[i], j, 0);
			   }
		   }
		   bitWrite(RegWrite[i], 13,1);
   
   #endif
        break;
      case 8:
        if (fVCO<4000){
          bitWrite(RegWrite[i], 19, 0);
        }else{
          bitWrite(RegWrite[i], 19, 1);
        }
        break;
#ifdef EXACT_FREQ
		case 0xc:
		RegWrite[i]=(uint32_t)(0x3FFF&(fPDfGCD));
		break;
#endif
      case 20:
    	  aux_register=RegWrite[5];
    	// bitClear(aux_register,7);
        RegWrite[i]=aux_register;
        break;
      case 21:
        RegWrite[i]=RegIni[i];
        break;
      case 22:
		 VCOAdd=0b00000010;
			for (int j=3;j<16;j++){
				if (j<7){
					bitWrite(RegWrite[i], j, bitRead(VCOAdd,j-3));
				}else{
					bitWrite(RegWrite[i], j, bitRead(kDIV,j-7));
				}
			}
        //Serial.println(RegWrite[i],HEX);

        break;
      default:
      //  RegWrite[i] =RegRead[i] ;
        break;
    }

  }
}
long ADF5610_Driver::CalculateGCD(long a, long b) {
   if (a == 0 || b == 0)
      return 0;
   else if (a == b)
      return a;
   else if (a > b)
      return CalculateGCD(a-b, b);
   else return CalculateGCD(a, b-a);
}

bool	ADF5610_Driver::SelfTest(uint8_t cycles){
	dir=1;
	int errorCounter=0;
	int counter=0;
	while (((lower_limit<=current_frequency)&(current_frequency<=upper_limit))&&(cycles>counter)){

		 if(IsLocked()){
			 is_locked=true;
			 errorCounter=0;
			 current_frequency=target_frequency;
			  if ((current_frequency>(upper_limit-step))&&(dir==1)){


				dir=-1;
			  }else if((current_frequency<(lower_limit+step))&&(dir==-1)){

				dir=1;

			  }
			   #ifdef ARDUINO_AVR_UNO
				 Serial.print("Locked at : ");
				 Serial.print(current_frequency);
				 Serial.println(" MHz");
				 #else
#ifdef NIOS_BUILD
			   printf("Current frequence: %lf\n",current_frequency);
#endif
			   #endif
				target_frequency=current_frequency+(dir*step);

				SetNextFrequency();
				ShortConfigurationFlow();
				usleep(1000);


		 }else{
			 errorCounter++;
			 if(is_locked){
				 is_locked=false;
				 #ifdef ARDUINO_AVR_UNO
				     Serial.println("**************************");
				     Serial.println(" ");
				     Serial.print("Not Locked at:  ");
				     Serial.println(current_frequency);
				     Serial.println(" MHz");
				     Serial.println(" ");
				     Serial.println("**************************");
					 #else
	#ifdef NIOS_BUILD				 
				  printf("**************************\n\r");
				   printf("Not Locked at:  %lf",target_frequency);
				   printf(" MHz\n");
				   printf("**************************\n");
	#endif
				   #endif
			 }
			//next_frequency=current_frequency;
		   SetNextFrequency();
		    /// Serial.print("Not Locked at:  ");
		  //   Serial.println(current_frequency);
		   CompleteConfigurationFlow(0);

			for (int var = 1; var < 24; ++var) {
			//	ShowRegisters(var);
			}

			usleep(100000);
			if(errorCounter>100){
				return false;
			}


		 }
		 delay_ms(1);
	}
	return true;
}
#ifdef ARDUINO_AVR_UNO
#else

void ADF5610_Driver::usleep(long us){
	if (us/1000>1)
	{
		delay_ms(us/1000);
	} 
	else
	{
		delay_ms(1);
	}
	
}
#endif





