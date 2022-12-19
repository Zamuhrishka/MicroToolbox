/**
* \file         types.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
/// \brief MAC address
///{
typedef struct
{
	uint8_t value[6];
} 	mac_t;
///}

/// \brief Binary string representation of uint8_t type
///{
typedef struct bin8_tag
{
	char bit[9];
} 	bin8_t;
///}

/// \brief Binary string representation of uint16_t type
///{
typedef struct	bin16_tag
{
	char bit[17];
} 	bin16_t;
///}

/// \brief Binary string representation of uint32_t type
///{
typedef struct	bin32_tag
{
	char bit[33];
} 	bin32_t;
///}

//< Ip address (version 4)
typedef uint32_t ip4addr_t;

//< BCD typedef
typedef uint32_t bcd_t;

#define nullptr ((void*)0)

#if !defined(NULL)
#define NULL ((void *)0)
#endif
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif