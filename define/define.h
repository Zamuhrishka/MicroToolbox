/**
* \file    		define.h
* \author  		Kovalchuk Alexander (roux@yandex.ru)
* \brief   		This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
#ifndef TRUE
	#define			TRUE                           	1							
#endif

#ifndef FALSE
	#define			FALSE                         	0                           
#endif

#ifndef NULL
	#define			NULL                         	0                           
#endif

#ifndef PRESS
	#define			PRESS                           0							
#endif

#ifndef RELEASE
	#define			RELEASE                         1                           
#endif

#ifndef PASS
	#define			PASS			                1							
#endif

#ifndef FAULT
	#define			FAULT                           0							
#endif

#ifndef OFF
	#define			OFF     		                0							
#endif

#ifndef ON
	#define			ON      		                1							
#endif

#ifndef ENABLE
	#define			ENABLE   		                1							
#endif

#ifndef DISABLE
	#define			DISABLE  		                0							
#endif

#ifndef SET
	#define			SET     	                	1							
#endif

#ifndef CLEAR
	#define			CLEAR     	                	0							
#endif

#ifndef LOW
	#define			LOW								0							
#endif

#ifndef HIGH
	#define			HIGH							1							
#endif

#define 			KBYTE							1024
#define 			MBYTE							(KBYTE * KBYTE)

#define 			INVALID8						((uint8_t) -1)
#define 			INVALID16						((uint16_t) -1)
#define 			INVALID32						((uint32_t) -1)
#define 			INVALID64						((uint64_t) -1)


//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
