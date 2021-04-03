/**
 * \file
 *
 * \brief EVSYS related functionality implementation.
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
 * \addtogroup doc_driver_evsys
 *
 * \section doc_driver_evsys_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <evsys.h>

/**
 * \brief Initialize EVSYS interface
 *
 * \return Initialization status.
 */
int8_t EVENT_SYSTEM_0_init()
{

	EVSYS.CHANNEL0 = EVSYS_CHANNEL0_ZCD0_gc; /* Zero Cross Detect 0 out */

	EVSYS.CHANNEL1 = EVSYS_CHANNEL1_ZCD1_gc; /* Zero Cross Detect 1 out */

	// EVSYS.CHANNEL2 = EVSYS_CHANNEL2_OFF_gc; /* Off */

	// EVSYS.CHANNEL3 = EVSYS_CHANNEL3_OFF_gc; /* Off */

	// EVSYS.CHANNEL4 = EVSYS_CHANNEL4_OFF_gc; /* Off */

	// EVSYS.CHANNEL5 = EVSYS_CHANNEL5_OFF_gc; /* Off */

	// EVSYS.CHANNEL6 = EVSYS_CHANNEL6_OFF_gc; /* Off */

	// EVSYS.CHANNEL7 = EVSYS_CHANNEL7_OFF_gc; /* Off */

	// EVSYS.CHANNEL8 = EVSYS_CHANNEL8_OFF_gc; /* Off */

	// EVSYS.CHANNEL9 = EVSYS_CHANNEL9_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT0A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT1A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT2A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT3A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT4A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT5A = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT0B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT1B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT2B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT3B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT4B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERCCLLUT5B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERADC0START = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTB = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTC = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTD = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTF = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART0IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART1IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART2IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART3IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART4IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCA0CNTA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCA0CNTB = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCA1CNTA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCA1CNTB = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERTCB0CAPT = EVSYS_USER_CHANNEL0_gc; /* Connect user to event channel 0 */

	// EVSYS.USERTCB0COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB1CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB1COUNT = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERTCB2CAPT = EVSYS_USER_CHANNEL1_gc; /* Connect user to event channel 1 */

	// EVSYS.USERTCB2COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB3CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB3COUNT = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERTCD0INPUTA = EVSYS_USER_CHANNEL0_gc; /* Connect user to event channel 0 */

	EVSYS.USERTCD0INPUTB = EVSYS_USER_CHANNEL1_gc; /* Connect user to event channel 1 */

	// EVSYS.USEROPAMP0ENABLE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP0DRIVE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP0DUMP = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP0DISABLE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP1ENABLE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP1DRIVE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP1DUMP = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP1DISABLE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP2ENABLE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP2DRIVE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP2DUMP = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEROPAMP2DISABLE = EVSYS_USER_OFF_gc; /* Off */

	return 0;
}
