/**
* \file    		macros.h
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
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10
#define BIT5  0x20
#define BIT6  0x40
#define BIT7  0x80
#define BIT8  0x0100
#define BIT9  0x0200
#define BIT10 0x0400
#define BIT11 0x0800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000
#define BIT16 0x00010000
#define BIT17 0x00020000
#define BIT18 0x00040000
#define BIT19 0x00080000
#define BIT20 0x00100000
#define BIT21 0x00200000
#define BIT22 0x00400000
#define BIT23 0x00800000
#define BIT24 0x01000000
#define BIT25 0x02000000
#define BIT26 0x04000000
#define BIT27 0x08000000
#define BIT28 0x10000000
#define BIT29 0x20000000
#define BIT30 0x40000000
#define BIT31 0x80000000
#define BIT38 0x4000000000
#define BIT39 0x8000000000
#define BIT63 0x8000000000000000
//_____ M A C R O S ___________________________________________________________
/**
 * \brief           Clear bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define CLEAR_BIT(reg, bit)		(reg &= (~(1<<(bit))))

/**
 * \brief           Set bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define SET_BIT(reg, bit)		(reg |= (1<<(bit)))

/**
 * \brief           Invert bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define TOGGLE_BIT(reg, bit)	(reg ^= (1<<(bit)))

/**
 * \brief           Test bit in register for clear state
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          true - if clear
 * \hideinitializer
 */
#define TEST_BIT(reg, bit)		((reg & (1<<(bit))) == 0)

/**
 * \brief           This macros take the max between a and b.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the max between a and b.
 * \hideinitializer
 */
#define MAX(a, b)            	(((a) > (b)) ? (a) : (b))

/**
 * \brief           This macros take the min between a and b.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the min between a and b.
 * \hideinitializer
 */
#define MIN(a, b)            	(((a) < (b)) ? (a) : (b))

/**
 * \brief           This macros test two values for equal.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          true if equal.
 * \hideinitializer
 */
#define IS_EQUAL(a, b)			(((a) ^ (b)) == 0)

/**
 * \brief           This macros test number for even.
 * \param[in]       num: number
 * \return          true if number is even.
 * \hideinitializer
 */
#define IS_EVEN(num)			(((num) & 1) == 1)

/**
 * \brief           This macros test number for odd.
 * \param[in]       num: number
 * \return          true if number is odd.
 * \hideinitializer
 */
#define IS_ODD(num)				(!(((num) & 1) == 1))

/**
 * \brief           This macros change the number sigh.
 * \param[in]       num: number
 * \return          number with changed sigh.
 * \hideinitializer
 */
#define SIGH_CHANGE(a)			((~(a)) + 1u)

/**
 * \brief           This macros change the number sigh.
 * \param[in]       num: number
 * \return          number with changed sigh.
 * \hideinitializer
 */
#define ARIPH_MEAN(a, b)		(((a) + (b)) >> 1u)

/*
 * Stringigy helpers.  https://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr
 */
#define STRCONCAT(x, y) x ## y
#define STRCONCATHELPER(x, y) STRCONCAT(x, y)

/** Gets the number of elements in an array. */
#ifndef ARRAY_OF
#define ARRAY_OF(st_) (sizeof(st_)/sizeof(st_[0]))
#endif

#define is_aligned(POINTER, BYTE_COUNT) \
(((uint32_t)(const void *)(POINTER)) % (BYTE_COUNT) == 0)

/**
 * Use this macro to define a field in a register which spans multiple bits.
 * For example, if a field occupies fields lsb 16 to msb 23, then use this
 * macro as follows: #define BIT_MASK_XXX_FIELD     BITFIELD(23,16)
 * So the value of BIT_MASK_XXX_FIELD = 0x00FF0000
 */
#define BITFIELD(msb, lsb)   ((BIT32((msb) - (lsb) + 1) - 1) << (lsb))
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
/** Function to reverse the individual bits in a byte - i.e. bit 7 is moved to bit 0, bit 6 to bit 1,
 *  etc.
 *
 *  \param[in] Byte  Byte of data whose bits are to be reversed.
 *
 *  \return Input data with the individual bits reversed (mirrored).
 */
static inline uint8_t BitReverse(uint8_t Byte);
static inline uint8_t BitReverse(uint8_t Byte)
{
	Byte = (((Byte & 0xF0) >> 4) | ((Byte & 0x0F) << 4));
	Byte = (((Byte & 0xCC) >> 2) | ((Byte & 0x33) << 2));
	Byte = (((Byte & 0xAA) >> 1) | ((Byte & 0x55) << 1));

	return Byte;
}
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
