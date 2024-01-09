/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This module defines a set of data types and constants for managing various
 *               forms of data in embedded systems programming. It includes endianess constants
 *               for byte order identification, custom data types for MAC addresses, binary
 *               string representations for different integer types, IP addresses, and BCD
 *               (Binary-Coded Decimal) data type. These definitions are crucial for handling
 *               data in a standardized way across different hardware platforms and network
 *               communication protocols, ensuring compatibility and efficient data processing
 *               in embedded and networked systems.
 */


#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
/// Constant for Little Endian byte order
#ifndef LITTLE_ENDIAN
    #define LITTLE_ENDIAN 4321
#endif

/// Constant for Big Endian byte order
#ifndef BIG_ENDIAN
    #define BIG_ENDIAN 1234
#endif

/**
 * @brief Constants for byte order definition
 *
 */
typedef enum EndianOrder_tag
{
    LITTLE_ENDIAN_ORDER = LITTLE_ENDIAN, /**< little endian byte order */
    BIG_ENDIAN_ORDER = BIG_ENDIAN,       /**< big endian byte order */
} endian_e;

/**
 * \brief MAC address data type
 */
typedef struct Mac_tag
{
    uint8_t value[6];
} mac_t;

/**
 * \brief Binary string representation of uint8_t type
 */
typedef struct bin8_tag
{
    char bit[9];
} bin8_t;

/**
 * \brief Binary string representation of uint16_t type
 */
typedef struct bin16_tag
{
    char bit[17];
} bin16_t;

/**
 * \brief Binary string representation of uint32_t type
 */
typedef struct bin32_tag
{
    char bit[33];
} bin32_t;

/// Ip address (version 4)
typedef uint32_t ip4addr_t;

/// BCD data type
typedef uint32_t bcd_t;

//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
