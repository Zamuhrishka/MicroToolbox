/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This file is expected to define various constants that might be used across the project.
 *               These constants could range from numeric values, buffer sizes, or specific flags essential for
 *               the system's operation.
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
/// Constant for pressed button state
#ifndef PRESS
    #define PRESS 0
#endif

/// Constant for released button state
#ifndef RELEASE
    #define RELEASE 1
#endif

/// Constant for pass state
#ifndef PASS
    #define PASS 1
#endif

/// Constant for fault state
#ifndef FAULT
    #define FAULT 0
#endif

/// Constant for off state
#ifndef OFF
    #define OFF 0
#endif

/// Constant for on state
#ifndef ON
    #define ON 1
#endif

/// Constant for enable state
#ifndef ENABLE
    #define ENABLE 1
#endif

/// Constant for disable state
#ifndef DISABLE
    #define DISABLE 0
#endif

/// Constant for set state
#ifndef SET
    #define SET 1
#endif

/// Constant for clear state
#ifndef CLEAR
    #define CLEAR 0
#endif

/// Constant for low state
#ifndef LOW
    #define LOW 0
#endif

/// Constant for high state
#ifndef HIGH
    #define HIGH 1
#endif

/// Max value for `uint8_t` data types
#ifndef UINT8_MAX
    #define UINT8_MAX ((uint8_t)-1)
#endif

/// Max value for `uint16_t` data types
#ifndef UINT16_MAX
    #define UINT16_MAX ((uint16_t)-1)
#endif

/// Max value for `uint32_t` data types
#ifndef UINT32_MAX
    #define UINT32_MAX ((uint32_t)-1)
#endif

/// Max value for `uint64_t` data types
#ifndef UINT64_MAX
    #define UINT64_MAX ((uint64_t)-1)
#endif

/**
 *  \brief Data capacity constants
 */
enum Capacity_tag
{
    KBYTE = 1024ul,    /**< bytes number in 1KB */
    MBYTE = 1048576ul, /**< bytes number in 1MB */
};

/**
 *  \brief Bit masks
 */
enum BitsMsk_tag
{
    BIT0_MSK = 0x01,
    BIT1_MSK = 0x02,
    BIT2_MSK = 0x04,
    BIT3_MSK = 0x08,
    BIT4_MSK = 0x10,
    BIT5_MSK = 0x20,
    BIT6_MSK = 0x40,
    BIT7_MSK = 0x80,
    BIT8_MSK = 0x0100,
    BIT9_MSK = 0x0200,
    BIT10_MSK = 0x0400,
    BIT11_MSK = 0x0800,
    BIT12_MSK = 0x1000,
    BIT13_MSK = 0x2000,
    BIT14_MSK = 0x4000,
    BIT15_MSK = 0x8000,
    BIT16_MSK = 0x00010000,
    BIT17_MSK = 0x00020000,
    BIT18_MSK = 0x00040000,
    BIT19_MSK = 0x00080000,
    BIT20_MSK = 0x00100000,
    BIT21_MSK = 0x00200000,
    BIT22_MSK = 0x00400000,
    BIT23_MSK = 0x00800000,
    BIT24_MSK = 0x01000000,
    BIT25_MSK = 0x02000000,
    BIT26_MSK = 0x04000000,
    BIT27_MSK = 0x08000000,
    BIT28_MSK = 0x10000000,
    BIT29_MSK = 0x20000000,
    BIT30_MSK = 0x40000000,
    BIT31_MSK = 0x80000000
};
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
