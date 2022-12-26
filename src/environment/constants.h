/**
* \file         constants.h
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        Common constants  
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//< Constant for pressed button state
#ifndef PRESS
	#define			PRESS                           0
#endif

//< Constant for released button state
#ifndef RELEASE
	#define			RELEASE                         1
#endif

//< Constant for pass state
#ifndef PASS
	#define			PASS			                1
#endif

//< Constant for fault state
#ifndef FAULT
	#define			FAULT                           0
#endif

//< Constant for off state
#ifndef OFF
	#define			OFF     		                0
#endif

//< Constant for on state
#ifndef ON
	#define			ON      		                1
#endif

//< Constant for enable state
#ifndef ENABLE
	#define			ENABLE   		                1
#endif

//< Constant for disable state
#ifndef DISABLE
	#define			DISABLE  		                0
#endif

//< Constant for set state
#ifndef SET
	#define			SET     	                	1
#endif

//< Constant for clear state
#ifndef CLEAR
	#define			CLEAR     	                	0
#endif

//< Constant for low state
#ifndef LOW
	#define			LOW								0
#endif

//< Constant for high state
#ifndef HIGH
	#define			HIGH							1
#endif

//< Constants for capacity of data
#define 			KBYTE							1024
#define 			MBYTE							(KBYTE * KBYTE)

//< Invalid values for different data types
#define 			INVALID8						((uint8_t)-1)
#define 			INVALID16						((uint16_t)-1)
#define 			INVALID32						((uint32_t)-1)
#define 			INVALID64						((uint64_t)-1)

//< Constants for bits position
#define 			BIT0  							0x01
#define 			BIT1  							0x02
#define 			BIT2  							0x04
#define 			BIT3  							0x08
#define 			BIT4  							0x10
#define 			BIT5  							0x20
#define 			BIT6  							0x40
#define 			BIT7  							0x80
#define 			BIT8  							0x0100
#define 			BIT9  							0x0200
#define 			BIT10 							0x0400
#define 			BIT11 							0x0800
#define 			BIT12 							0x1000
#define 			BIT13 							0x2000
#define 			BIT14 							0x4000
#define 			BIT15 							0x8000
#define 			BIT16 							0x00010000
#define 			BIT17 							0x00020000
#define 			BIT18 							0x00040000
#define 			BIT19 							0x00080000
#define 			BIT20 							0x00100000
#define 			BIT21 							0x00200000
#define 			BIT22 							0x00400000
#define 			BIT23 							0x00800000
#define 			BIT24 							0x01000000
#define 			BIT25 							0x02000000
#define 			BIT26 							0x04000000
#define 			BIT27 							0x08000000
#define 			BIT28 							0x10000000
#define 			BIT29 							0x20000000
#define 			BIT30 							0x40000000
#define 			BIT31 							0x80000000
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif