/**
 * \file
 *
 * \brief Driver ISR.
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

#include <driver_init.h>
#include <compiler.h>

ISR(ZCD0_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */

	ZCD0.STATUS = ZCD_CROSSIF_bm;
}

ISR(ZCD1_ZCD_vect)
{
	/* Insert your ZCD interrupt handling code here */

	ZCD1.STATUS = ZCD_CROSSIF_bm;
}



ISR(TCB0_INT_vect)
{

	TCB0.INTFLAGS = TCB_CAPT_bm;
}

ISR(TCB2_INT_vect)
{

	TCB2.INTFLAGS = TCB_CAPT_bm;
}

ISR(TCD0_TRIG_vect)
{

	/* Insert your TCD TRIGA interrupt handling code here */

	/* Insert your TCD TRIGB interrupt handling code here */

	/* TRIGA and TRIGB interrupt flags have to be cleared manually */
	TCD0.INTFLAGS = TCD_TRIGA_bm | TCD_TRIGB_bm;
}
