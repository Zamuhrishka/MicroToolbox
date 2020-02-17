/**
* \file    		constants.h
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

#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
#ifndef PRESS
	#define			PRESS                           0							///< Button state is press
#endif

#ifndef RELEASE
	#define			RELEASE                         1                           ///< Button state is release
#endif

#ifndef PASS
	#define			PASS			                1							///< Operation is OK
#endif

#ifndef FAULT
	#define			FAULT                           0							///< Operation is wrong
#endif

#ifndef OFF
	#define			OFF     		                0							///< Something is OFF
#endif

#ifndef ON
	#define			ON      		                1							///< Something is ON
#endif

#ifndef ENABLE
	#define			ENABLE   		                1							///< Something is ON
#endif

#ifndef DISABLE
	#define			DISABLE  		                0							///< Something is OFF
#endif

#ifndef SET
	#define			SET     	                	1							///< Bit is set
#endif

#ifndef CLEAR
	#define			CLEAR     	                	0							///< Bit is clear
#endif

#ifndef LOW
	#define			LOW								0							///< Low level of signal
#endif

#ifndef HIGH
	#define			HIGH							1							///< High level of signal
#endif
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
