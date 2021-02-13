/*
 * lmx2694_Default_Configuration.h
 *
 *  Created on: Feb 7, 2021
 *      Author: giova
 */

#ifndef LMX2694_DEFAULT_CONFIGURATION_H_
#define LMX2694_DEFAULT_CONFIGURATION_H_
#include "compiler.h"
// #include <stdlib.h>
// #include <stdint.h>
// #include <stdbool.h>

#define OUT_PWR_DOWN 0xAc1fE3

#define PROGRAM_RESET_1 0x00211e
#define PROGRAM_RESET_0 0x00211c
#define PROGRAM_POWERDOWN 0x002119
#define MUXOUT_READBACK 0x2118
#define NUMBER_REGISTERS 0x73
#define FCAL_EN	3




uint16_t const default_registers[]={
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x00F1,
		0x0000,
		0x0007,
		0x4440,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0064,
		0x0000,
		0x000C,
		0x0800,
		0x0000,
		0x003F,
		0x0001,
		0x0080,
		0xC350,
		0x0000,
		0x03E8,
		0x0000,
		0x01F4,
		0x0000,
		0x1388,
		0x0000,
		0x0322,
		0x00A8,
		0x09C4,
		0x0001,
		0x8001,
		0x0020,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0420,
		0x0080,
		0x0000,
		0x4180,
		0x0300,
		0x0300,
		0x07FC,	//R46
		0xC8C2,//R45
		0x1FE3, //R44	0x2C1FE3
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0xDA80,
		0xFD51,
		0x8404,
		0x0028,		//R36	0x240028
		0x0004,
		0x0000,
		0x1E21,
		0x0393,
		0x43EC,
		0x318C,  //  R30	0x1E318C
		0x318C,
		0x0488,
		0x0002,
		0x0DB0,
		0x0624,
		0x071A,
		0x007C,
		0x0001,
		0x0401,
		0xF848,
		0x27B7, //R20	0x14F848
		0x0064,
		0x012C,
		0x0080,
		0x064F,
		0x1E70,
		0x4000,
		0x5001,
		0x0018,
		0x10D8, //R10	0x0A10D8
		0x1604,
		0x2000,
		0x00B2,
		0x7802,
		0x03E8,
		0x0E43,
		0x0642,
		0x0500,
		0x080C,
		0x211C,
};

#endif /* LMX2694_DEFAULT_CONFIGURATION_H_ */
