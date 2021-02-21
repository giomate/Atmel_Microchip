/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */



//***********************************************************************************************************************************************
//*******Code to use an ADF5355 as a signal generator from 52 to 13600 MHz based on that of DD7LP Christian Petersen for the ADF4351, (See ******
//*******credits below). The code has been ported to run on a Maple Mini 32 bit STM32F103CB ARM Cortex-M3 board. This was necessary to take *****
//*******advantage of the frequency resolution capabilities of the ADF5355. The display is an I2C OLED type. Brian Flynn GM8BJF. 14 June 2019 ***
//***********************************************************************************************************************************************
//***********************************************************************************************************************************************
// ****** Modifikation der Routinen vorgesehen für ADF4351 DDS bearbeitet von DD7LP Christian Petersen www.darc-husum.de im Februar    2017 *****
// *******Wesentliche Programmteile, Funktionen und Änderungen programmiert von DJ7OO Klaus Hirschelmann http://www.kh-gps.de/ im Februar 2017 **
//  ******Programmroutinen für das Ansprechen des ADF4351 aus einer Software von OE6OCG  Richard Posch 8302 Nestelbach 8452. Austria ************
//  ******Modifikation bezüglich des Kanalrasters. Diese wurden neu programmiert von OM Peter, DF6YL                     im Juli 2017************
//  ******Danke an OM Peter für diese Arbeit:                                 Anschrift Peter Beutel Verdistr. 2 59227 Ahlen         ************
// Achtung, kommerzielle Verwertung diese Software ist nicht gestattet bedarf der schriftlichen Zustimmmmung der Autoren, bzw Programmierer *****
//***********************************************************************************************************************************************

#include <SPI.h>
//#include <RotaryEncoder.h>   //************https://github.com/mathertel/RotaryEncoder/blob/master/RotaryEncoder.h
//Beginning of Auto generated function prototypes by Atmel Studio
void SettingFreq(double setfreq);
void ConvertFreq();
void EscribirRegistros(uint8_t d);
void LeerRegistros(uint8_t d);
bool LockDetect();
void IniciarRegistros();
void Secuencia(unsigned int k);
void SecuenciaCorta(void );
void SecuenciaLeer();
void MostrarRegistros(int m);
long Flipper(uint32_t recibido);
long GCD(long a, long b);
//End of Auto generated function prototypes by Atmel Studio






double freq;  // Start-up frequency = 5000 MHz
long nextfreq;
long Freq_Old;
long refin =  50000000;      // Referenzquarz = 100.000 Mhz - Enter exact value to calibrate (divide by 10)
long ChanStep = 10000;      // Initial channel step = 100.0 Khz
uint32_t RegRead[24];      // ADF5610 Reg's
uint32_t RegWrite[24];      // ADF5610 Reg's
uint32_t RegIni[24];      // ADF5610 Reg's



byte sent = 0;
byte received[4] ={0,0,0,0};
const int SEN = 10;
const int sdi = 11;
boolean newData = false;
char receivedChars[5];   // an array to store the received data
double freqIni=1752.5;
double NewFreq=57;

void MostrarRegistros(int);

//#define Legacy

///////////////////////// Subroutine: Set Frequency ADF5355 ///////////////////////////
void SettingFreq(double setfreq)     // Freq hier lokal oben global
{
  
 // Serial.print("Frequuency required = ");
 // Serial.println(setfreq);
  freq=setfreq;



  //Initialisation sequence

  ConvertFreq();
 
  

}

void ConvertFreq(){
  
  byte VCOAdd=0;
  double fPD;
   double N_Int;
   double f_N,f_GCD;
    uint32_t F_FracN,fPDfGCD ;

  
  //double PFDFreq = refin * ((1.0 + RD2refdoubl) / (R_Counter * (1.0 + RD1_Rdiv2))); //Phase detector frequency
  double fX=50; //Phase detector frequency
   double  fDIV=freq;
   double k=floor(log((14600)/(fDIV))/log(2));
   byte kDIV=7-(byte)(k);
   double fVCO = 7300*((freq*pow(2, k))/(14600)); //VCO
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
   
   
   
    
    double N = fVCO /fPD;   // Calculate N
    
    //Serial.println(N);
    
    N_Int = floor(fVCO/fPD);   // N= 50 for 5 GHz   // Turn N into integer
    //Serial.println((uint32_t)N_Int,HEX);

    double F_Frac1x = (N - N_Int) * pow(2, 24);   // Calculate Frac1 (N remainder * 2^24)

    F_FracN = (uint32_t)F_Frac1x;  // turn Frac1 into an integer
    //Serial.println(F_FracN,HEX);

  
#endif

  

  ////////////////// Set 32 bit register values R0 to R12 ///////////////////////////
  
  
  for (int i = 0; i <= 22; i++) {
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
		 LeerRegistros((uint8_t)0x10);
		 
		 for (int j=15;j>=0;j--){
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
        RegWrite[i]=RegWrite[5];
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
        RegWrite[i] =RegRead[i] ;
        break;
    }
 
  }
}
////////////////////////// Part-Subroutine ADF5355 ////////////////////////////

void EscribirRegistros(uint8_t d) {
  uint8_t d1=0;
  uint32_t buffer = 0;
  uint32_t recibido32=buffer;
  int shifter =1;
  int m;
  uint8_t buffer8[4];
  byte received[4];
  //RegAdr = d;
  if (d>=20){
    if(d==23){
      d1=3;
    }else if (d==24){
      d1=4;
    }else{
      d1=5;
    }
  }else{
    d1=d;
  }
  
  
 // Serial.println(d1, HEX);
  
  
  
  
  #ifdef Legacy

  #else
   
	
   // Serial.println(buffer, HEX);
 //   digitalWrite(SEN, LOW);
 //   delay(1);
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
	 digitalWrite(SEN, LOW);
	  buffer =((uint32_t)d1 <<3)|(RegWrite[d]<<8);
    for (int i = 0; i < 4; i++){
       SPI.transfer((byte)(buffer >> ((3-i) * 8))&0xFF);
    }

  #endif
  
 
 
  
  #ifdef Legacy

  #else
    digitalWrite(SEN, HIGH);
    SPI.endTransaction();
  #endif
  
  delay(1);
  //Serial.print(received[4], HEX);Serial.print(received[3], HEX); Serial.print(received[2], HEX);Serial.println(received[1], HEX);
  
  //LeerRegistros(d1);
  


}


void LeerRegistros(uint8_t d) {
	
	#ifdef NOT_SDO
		RegRead[d]=RegWrite[d];
	#else
		 byte  *recibidop;
		 uint32_t recibido32=0;
		 uint32_t recibido33=0;
		 byte readbuffer =0xFF;
		 byte receivedt[4];
		 byte received[4];
		 readbuffer&=(d<<3);
		 //bitSet(readbuffer,7);
		 //Serial.println(d, HEX);
		 
		 // Serial.println(readbuffer, HEX);

		 
		 

		 #ifdef Legacy

		 #else
		 
		 SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
		 digitalWrite(SEN, LOW);
		 SPI.transfer(0x00);SPI.transfer(0x00);SPI.transfer(d);SPI.transfer(0x00);

		 digitalWrite(SEN, HIGH);
		 
		 //delay(1);
		 
		 
		 #endif

		 
		 

		 digitalWrite(SEN, LOW);
		 
		 // SPI.transfer(0x00);SPI.transfer(0x00);SPI.transfer(d);SPI.transfer(0x00);
		 SPI.transfer(&recibido32,4);
		 RegRead[d]=0;
		 RegRead[d]=((recibido32&(0x000000FF))<<24)|((recibido32&(0x0000FF00))<<8);
		 RegRead[d]|=((recibido32&(0xFF000000))>>24)|((recibido32&(0x00FF0000))>>8);
		 RegRead[d]>>=7;
		 bitClear(RegRead[d],24);
		 
		 SPI.endTransaction();
		 digitalWrite(SEN, HIGH);

		 
		 
		 

		 //Serial.println(recibido32, HEX);
		 //Serial.println(recibido33, HEX);
		 //Serial.println((uint32_t)Flipper(recibido32), HEX);

		 // }
		 
		 delay(1);
		 //MostrarRegistros((int)d);
		 
		
#endif
 


}




///////////////////////////// Sub-Subroutine ADF5355 ////////////////////////////

////////////////////////////// Sub-Subroutine ADF5355 //////////////////////////


//////////////////////////////////////////////////////////////////////////////
//                                      Setup                               //
//////////////////////////////////////////////////////////////////////////////
void setup() {

  // ******************Screen mask static text*****************
  Serial.begin(115200);
  Serial.setTimeout(1000);
#ifdef NOT_SDO
	pinMode(MISO, INPUT); 
#else
	  pinMode(12, INPUT_PULLUP);
#endif
 
  pinMode(SEN, OUTPUT);
  IniciarRegistros();
  #ifdef Legacy

  #else
    digitalWrite(SEN, HIGH);
    SPI.begin();
  #endif
  delay(1);
  
  //Secuencia(0);
  

  
  
  

}

// *********************** Subroutine: update Display  **************************


////////////////////////////////////////////////////////////////////////
//                      MAIN PROGRAM LOOP                        //
////////////////////////////////////////////////////////////////////////
void loop()
{
	
  double step=1.0/2048.0;
  double upper_limit=3601.0,lower_limit=3599.0;
  freq=3600;
  bool dir=true;
 // IniciarRegistros();
  Secuencia(0);
  int counter=0;
  
 while ((lower_limit<=freq<=upper_limit)&&(counter<100)){
  
  if(LockDetect()){
		  
		counter=0;
		
    	Serial.print("Locked at : ");
    	Serial.print(freq);
    	Serial.println(" MHz");
		if (dir)
		{
			if (freq>(upper_limit-step)){
				dir=false;
			}
			
		}
		else
		{
			if(freq<(lower_limit+step)){
				dir=true;
			}
		}
			
  
   
     freq=dir?freq+step:freq-step;
     //Serial.println(freq);
     SettingFreq(freq);
     SecuenciaCorta();
   
    
  }else{
    counter++;
    Serial.println("**************************");
    Serial.println(" ");
    Serial.print("Not Locked at:  ");
    Serial.println(freq);
    Serial.println(" MHz");
    Serial.println(" ");
    Serial.println("**************************");
    SettingFreq(freq);
    Secuencia(0);
    delay(1);
  }
 
 
 
  delay(100);
 }

}

//*************************** End of main loop  ********************************************



/////////////////////////// Subroutine: Fixfrequencyselect ////////////////////////////


bool LockDetect(){
	 bool locked=false;
  if(digitalRead(MOSI)>0){
	   locked = true;
  }else{
 #ifdef NOT_SDO
 #else
	  LeerRegistros(18);
	  delay(1);
	  
	  //if ((digitalRead(12)== HIGH))   // select lock/unlock
	  if ((bitRead(RegRead[18],1)== HIGH)&&(bitRead(RegRead[18],2)== LOW))   // select lock/unlock
	  {
		  locked = true;
		  } else {
		  locked = false;
	  }
#endif
	  
	  
}
  return locked;
}

void IniciarRegistros(){
  uint32_t RegIni[24];      // ADF5610 Reg's
  
  for (int i = 0; i <= 24; i++) {
    switch (i) {
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
        RegIni[i] = 0x2047;
        break;
      case 11:
        RegIni[i] = 0xF8061;
        break;
      case 15:
        RegIni[i] = 0x081;
        break;
      case 20:
        RegIni[i] = RegIni[5];
         break;
      case 21:
       // RegIni[i] = 0x8E08;
		     RegIni[i] = (0x01<<3)|(0x00<<7)|(0x07<<9)|(0x03<<12)|(0x01<<15);
         break;
       case 22:
        RegIni[i] = 0x390;
		// RegIni[i] =(0x02<<3)|(0x07<<7)|(0x00);
         break;
        default:
        RegIni[i] = 0x0;
        break;
    }
    RegWrite[i]=RegIni[i];
    
     //Serial.println(RegWrite[i],HEX);
  }
}

void Secuencia(unsigned int k){
  for (int i=k; i<=19;i++){
    if (i==5){
      for(int j=22;j>19;j--){
        EscribirRegistros(j);
       
      }
	   EscribirRegistros(5);
      
    }else if((i!=4)|(i!=3)){
      EscribirRegistros(i);
    }
  }
  EscribirRegistros(3);
  EscribirRegistros(4);

}
void SecuenciaCorta(void){
  EscribirRegistros(8);
   for(int j=22;j>19;j--){
        EscribirRegistros(j);
        
      }
	  EscribirRegistros(5);
	EscribirRegistros(0xc);
  EscribirRegistros(3);
  EscribirRegistros(4);
}

void SecuenciaLeer(){
  for (int i=0; i<=19;i++){
    LeerRegistros((uint8_t)i);
  }
}
void MostrarRegistros(int m){
  Serial.print("Inhalt R");
  Serial.print(m);
  Serial.print(":  0x");
  Serial.println(RegRead[m], HEX);
}

long Flipper(uint32_t recibido){
  byte b1,b2;
  bool bit1;
  uint32_t transformado=0;
  for(int i=0;i<4;i++){
    b1=((byte)(recibido >> ((3-i) * 8)))&0xFF;
   
    for(int j=0;j<8;j++){
      bit1=bitRead(b1,j);
      bitWrite(b2,7-j,bit1);
      
    }
    transformado<<=8;
    
    transformado |=(uint32_t)(b2);
    
  }
  return (long)transformado;
}

long GCD(long a, long b) { 
	if (a == 0)
	return b;
	else if (b == 0)
	return a;

	if (a < b)
	return GCD(a, b % a);
	else
	return GCD(b, a % b);
} 


//////////////////////////////////////////////////////////////////////////////////////
