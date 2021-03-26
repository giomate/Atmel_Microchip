/**
 * \file
 *
 * \brief Driver initialization.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/*
 * Code generated by START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

void EVENT_SYSTEM_0_initialization(void)
{

	EVENT_SYSTEM_0_init();
}

/* configure pins and initialize registers */
void ZCD_0_initialization(void)
{

	// Disable digital input buffer
	PD1_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PD1_set_pull_mode(PORT_PULL_OFF);

	ZCD_0_init();
}

/* configure pins and initialize registers */
void ZCD_1_initialization(void)
{

	// Disable digital input buffer
	PE3_set_isc(PORT_ISC_INPUT_DISABLE_gc);
	// Disable pull-up resistor
	PE3_set_pull_mode(PORT_PULL_OFF);

	ZCD_1_init();
}

/* configure the pins and initialize the registers */
void SPI_0_initialization(void)
{

	// Set pin direction to input
	PA5_set_dir(PORT_DIR_IN);

	PA5_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_OFF);

	// Set pin direction to output

	PA4_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	PA4_set_dir(PORT_DIR_OUT);

	// Set pin direction to output

	PA6_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	PA6_set_dir(PORT_DIR_OUT);

	SPI_0_init();
}

/* configure the pins and initialize the registers */
void SPI_1_initialization(void)
{

	// Set pin direction to input
	PC1_set_dir(PORT_DIR_IN);

	PC1_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_OFF);

	// Set pin direction to output

	PC0_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	PC0_set_dir(PORT_DIR_OUT);

	// Set pin direction to output

	PC2_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	PC2_set_dir(PORT_DIR_OUT);

	SPI_1_init();
}

void TIMER_1_initialization(void)
{

	TIMER_1_init();
}

void TIMER_0_initialization(void)
{

	TIMER_0_init();
}

/**
 * \brief System initialization
 */
void system_init()
{
	mcu_init();

	/* PORT setting on PA7 */

	// Set pin direction to output

	CS_ADF_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	CS_ADF_set_dir(PORT_DIR_OUT);

	/* PORT setting on PC3 */

	// Set pin direction to output

	CS_LMX_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    true);

	CS_LMX_set_dir(PORT_DIR_OUT);

	CLKCTRL_init();

	EVENT_SYSTEM_0_initialization();

	SLPCTRL_init();

	CPUINT_init();

	ZCD_0_initialization();

	ZCD_1_initialization();

	SPI_0_initialization();

	SPI_1_initialization();

	TIMER_1_initialization();

	TIMER_0_initialization();

	BOD_init();
}