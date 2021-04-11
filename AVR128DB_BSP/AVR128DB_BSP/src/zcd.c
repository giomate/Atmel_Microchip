/**
 * \file
 *
 * \brief ZCD related functionality implementation.
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

/**
 * \addtogroup doc_driver_zcd
 *
 * \section doc_driver_zcd_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <zcd.h>

/**
 * \brief Initialize zcd interface
 *
 * \return Initialization status.
 */
int8_t ZCD_RISING_init()
{

	ZCD0.CTRLA = 1 << ZCD_ENABLE_bp     /* Setting: enabled */
	             | 1 << ZCD_OUTEN_bp    /* Setting: enabled */
	             | 0 << ZCD_RUNSTDBY_bp /* Setting: disabled */
	             | 0 << ZCD_INVERT_bp;  /* Setting: disabled */

	 ZCD0.INTCTRL = ZCD_INTMODE_NONE_gc; /* No interrupt */
	// ZCD0.INTCTRL =  ZCD_INTMODE_RISING_gc; /* No interrupt */
	return 0;
}

/**
 * \brief Initialize zcd interface
 *
 * \return Initialization status.
 */
int8_t ZCD_FALLING_init()
{

	ZCD1.CTRLA = 1 << ZCD_ENABLE_bp     /* Setting: enabled */
	             | 1 << ZCD_OUTEN_bp    /* Setting: enabled */
	             | 0 << ZCD_RUNSTDBY_bp /* Setting: disabled */
	             | 1 << ZCD_INVERT_bp;  /* Setting: enabled */

	 ZCD1.INTCTRL = ZCD_INTMODE_NONE_gc; /* No interrupt */
//	 ZCD1.INTCTRL = ZCD_INTMODE_FALLING_gc; /* No interrupt */
	return 0;
}
