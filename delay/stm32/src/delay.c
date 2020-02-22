/**
* \file    		template.c
* \author  		Kovalchuk Alexander (roux@yandex.ru)
* \brief   		This file contains the prototypes functions which use for...
*/

/*
 * Copyright (c) year Alexander KOVALCHUK
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of library_name.
 *
 * Author:          Alexander KOVALCHUK <roux@yandex.ru>
 */
//_____ I N C L U D E S _______________________________________________________
#include "delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
#define DWT_CONTROL_REG             	(*((volatile uint32_t*)0xE0001000))		///< DWT Control register

#define DWT_CYCCNTENA_BIT       		(1UL<<0)								///< CYCCNTENA bit in DWT_CONTROL register

#define DWT_CYCCNT_REG              	(*((volatile uint32_t*)0xE0001004))		///< DWT Cycle Counter register

#define DWT_DEMCR_REG                 	(*((volatile uint32_t*)0xE000EDFC))		///< DEMCR: Debug Exception and Monitor Control Register

#define DWT_TRCENA_BIT              	(1 << 24)								///< Trace enable bit in DEMCR register
//_____ M A C R O S ___________________________________________________________
/**
 * \brief           Enable trace and debug block DEMCR
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_InitCycleCounter()   		(DWT_DEMCR_REG |= DWT_TRCENA_BIT)

/**
 * \brief           Reset cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_ResetCycleCounter()   		(DWT_CYCCNT_REG = 0)

/**
 * \brief           Enable cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_EnableCycleCounter()  		(DWT_CONTROL_REG |= DWT_CYCCNTENA_BIT)

/**
 * \brief           Disable cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_DisableCycleCounter()   	(DWT_CONTROL_REG &= ~DWT_CYCCNTENA_BIT)

/**
 * \brief           Read cycle counter register
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_GetCycleCounter()   		(DWT_CYCCNT_REG)
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________
/**
* This function used to create us time delay.
*
* Public function defined in delay.h
*/
void delay_us(uint32_t us)
{
	uint32_t us_count_tick =  us * (SYS_CLOCK/1000000);

	DWT_InitCycleCounter(); 									// enable DWT hardware
	DWT_ResetCycleCounter(); 									// reset cycle counter
	DWT_EnableCycleCounter(); 									// start counting

	while(DWT_GetCycleCounter() < us_count_tick) {};

	DWT_DisableCycleCounter();
}

/**
* This function used to create ms time delay.
*
* Public function defined in delay.h
*/
void delay_ms(uint32_t ms)
{
	uint32_t ms_count_tick =  ms * (SYS_CLOCK/1000);

	DWT_InitCycleCounter(); 									// enable DWT hardware
	DWT_ResetCycleCounter(); 									// reset cycle counter
	DWT_EnableCycleCounter(); 									// start counting

	while(DWT_GetCycleCounter() < ms_count_tick) {};

	DWT_DisableCycleCounter();
}
