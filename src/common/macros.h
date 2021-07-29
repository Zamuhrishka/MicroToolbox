/**
* \file         macros.h
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

#include "constants.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
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
#define STRCONCAT(x, y) 		((x) ## (y))
#define STRCONCATHELPER(x, y) 	STRCONCAT(x, y)

/** Gets the number of elements in an array. */
#ifndef ARRAY_OF
#define ARRAY_OF(st_) 			(sizeof(st_)/sizeof(st_[0]))
#endif

#define is_aligned(POINTER, BYTE_COUNT) \
								(((uint32_t)(const void *)(POINTER)) % (BYTE_COUNT) == 0)

/**
 * Use this macro to define a field in a register which spans multiple bits.
 * For example, if a field occupies fields lsb 16 to msb 23, then use this
 * macro as follows: #define BIT_MASK_XXX_FIELD     BITFIELD(23,16)
 * So the value of BIT_MASK_XXX_FIELD = 0x00FF0000
 */
#define BITFIELD(msb, lsb)   	((BIT32((msb) - (lsb) + 1) - 1) << (lsb))
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
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

/* C++ detection */
#ifdef __cplusplus
}
#endif