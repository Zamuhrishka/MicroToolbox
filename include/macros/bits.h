/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        This file contains macros for bits manipulations.
 */

#pragma once

#if !defined(MODULE_MACRO_BITS_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>

#include "compiler.h"
//_____ C O N F I G S  ________________________________________________________

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________
/**
 * \brief           Set bit
 *
 * \param[in]       var: variable in which need set bit
 * \param[in]       bit: number of bit which need to set
 *
 * \return          none
 */
#define SET_BIT(var, bit) ((var) |= (1 << (bit)))

/**
 * \brief           Clear bit
 *
 * \param[in]       var: variable in which need clear bit
 * \param[in]       bit: number of bit which need to clear
 *
 * \return          none
 */
#define CLEAR_BIT(var, bit) ((var) &= (~(1 << (bit))))

/**
 * \brief           Invert bit
 *
 * \param[in]       var: variable in which need toggle bit
 * \param[in]       bit: number of bit which need to toggle
 *
 * \return          none
 */
#define TOGGLE_BIT(var, bit) ((var) ^= (1 << (bit)))

/**
 * \brief           Test bit in variable for set state
 *
 * \param[in]       var: variable in which need test bit
 * \param[in]       bit: bit number
 *
 * \return          none
 */
#define TEST_BIT(var, bit) (((var) & (1 << (bit))) != 0)

/**
 * \brief           This macro creates a mask that will isolate the bits from
 *                  `l` (lower) to `u` (upper).  The `u` value must be the larger
 *                  value if `u` and `l` aren't equal.
 *
 * \param[in]       msb: most significant bit
 * \param[in]       lsb: least significant bit
 *
 * \return          bitfield
 */
#define MAKE_BITFIELD(u, l) ((((1ul << (u)) - 1ul) | (1ul << (u))) & ~((1ul << (l)) - 1ul))

/**
 * \brief           Define number of bits in `с` type
 *
 * \param[in]       type: с type (`char`, `int`, `uint8_t`, etc)
 *
 * \return          number of bits in `c` type
 */
#define NUM_BITS(type) (sizeof(type) * 8u)

/**
 * \brief           Isolate the rightmost 1-bit
 *
 * \warning         Undefined behavior for x=0 value
 *
 */
#define LSO(x) ((x) & (-(x)))

/**
 * \brief           Isolate the rightmost 0-bit
 *
 * \warning         Undefined behavior for x=(~x) value
 *
 */
#define LCO(x) (~(x) & ((x) + 1))

/**
 * \brief           Turn on the rightmost 0-bit
 *
 * \warning         Undefined behavior for x=(~x) value
 *
 */
#define SLSB(x) ((x) | ((x) + 1))

/**
 * \brief           Turn off the rightmost 1-bit
 *
 * \warning         Undefined behavior for x=0 value
 *
 */
#define CLSB(x) ((x) & ((x)-1))

//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/** \brief      Function to reverse the individual bits in a `uint8_t` - i.e. bit 7
 *              is moved to bit 0, bit 6 to bit 1, etc.
 *
 *  \param[in]  byte  byte of data whose bits are to be reversed.
 *
 *  \return     Input data with the individual bits reversed (mirrored).
 */
static __inline__ uint8_t bits_mirror_u8(uint8_t byte)
{
    byte = (((byte & 0xF0) >> 4) | ((byte & 0x0F) << 4));
    byte = (((byte & 0xCC) >> 2) | ((byte & 0x33) << 2));
    byte = (((byte & 0xAA) >> 1) | ((byte & 0x55) << 1));

    return byte;
}

/** \brief      Function to reverse the individual bits in a `uint16_t` - i.e. bit 15
 *              is moved to bit 0, bit 14 to bit 1, etc.
 *
 *  \param[in]  half  `uint16_t` of data whose bits are to be reversed.
 *
 *  \return     Input data with the individual bits reversed (mirrored).
 */
static __inline__ uint16_t bits_mirror_u16(uint16_t half)
{
    half = (((half & 0xFF00) >> 8) | ((half & 0x00FF) << 8));
    half = (((half & 0xF0F0) >> 4) | ((half & 0x0F0F) << 4));
    half = (((half & 0xCCCC) >> 2) | ((half & 0x3333) << 2));
    half = (((half & 0xAAAA) >> 1) | ((half & 0x5555) << 1));

    return half;
}

/** \brief      Function to reverse the individual bits in a `uint32_t` - i.e. bit 31
 *              is moved to bit 0, bit 30 to bit 1, etc.
 *
 *  \param[in]  word  `uint32_t` of data whose bits are to be reversed.
 *
 *  \return     Input data with the individual bits reversed (mirrored).
 */
static __inline__ uint32_t bits_mirror_u32(uint32_t word)
{
    word = (((word & 0xFFFF0000) >> 16) | ((word & 0x0000FFFF) << 16));
    word = (((word & 0xFF00FF00) >> 8) | ((word & 0x00FF00FF) << 8));
    word = (((word & 0xF0F0F0F0) >> 4) | ((word & 0x0F0F0F0F) << 4));
    word = (((word & 0xCCCCCCCC) >> 2) | ((word & 0x33333333) << 2));
    word = (((word & 0xAAAAAAAA) >> 1) | ((word & 0x55555555) << 1));

    return word;
}

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif //#if !defined(MODULE_MACRO_BITS_DISABLED)
