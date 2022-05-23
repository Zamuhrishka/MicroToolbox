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
#include <string.h>

#include "constants.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
/**
 * \brief           This macros take the min between a and b.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the min between a and b.
 * \hideinitializer
 */
#define MIN(a, b)            		        (((a) < (b)) ? (a) : (b))

/**
 * \brief           This macros take the min between a and b without branch
 * 
 * \warning This optimization works well on some machines, but on modern machines using clang -O3
 * thr branchless version is usually slower than the branching version. Modern compilers can perfom
 * this optimization better than you can! 
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the min between a and b.
 */
#define MIN_BRANCHLESS(a, b)   		        ((b) ^ (((a) ^ (b)) & -((a) < (b))))

/**
 * \brief           This macros take the max between a and b.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the max between a and b.
 * \hideinitializer
 */
#define MAX(a, b)            		        (((a) > (b)) ? (a) : (b))

/**
 * \brief           This macros take the max between a and b without branch
 * 
 * \warning This optimization works well on some machines, but on modern machines using clang -O3
 * thr branchless version is usually slower than the branching version. Modern compilers can perfom
 * this optimization better than you can! 
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          the max between a and b.
 */
#define MAX_BRANCHLESS(a, b)                ((b) & (((a)-(b)) >> 31) | (a) & (~((a)-(b)) >> 31))

/**
 * \brief           This macros test two values for equal.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * \return          true if equal.
 * \hideinitializer
 */
#define IS_EQUAL(a, b)				        (((a) ^ (b)) == 0)

/**
 * \brief           This macros test number for even.
 * \param[in]       num: number
 * \return          true if number is even.
 * \hideinitializer
 */
#define IS_EVEN(num)				        (((num) & 1) == 1)

/**
 * \brief           This macros test number for odd.
 * \param[in]       num: number
 * \return          true if number is odd.
 * \hideinitializer
 */
#define IS_ODD(num)					        (!(((num) & 1) == 1))

/**
 * \brief           This macros change the number sigh.
 * \param[in]       num: number
 * \return          number with changed sigh.
 * \hideinitializer
 */
#define INVERT_SIGH(a)				        ((~(a)) + 1u)

//Detect if two integers have opposite signs
#define IS_SIGH_EQUAL(a, b) 			    (((a) ^ (b)) >= 0)

/**
 * \brief           This macros change the number sigh.
 * \param[in]       num: number
 * \return          number with changed sigh.
 * \hideinitializer
 */
#define ARIPH_MEAN(a, b)			        (((a) + (b)) >> 1u)

#define SWAP(a, b) 			                ((a) = (a) ^ (b) ^ ((b) = (a)))

/**
 * \brief           This macros test number for power of 2.
 * \param[in]       num: number
 * \return          true if number is power of 2.
 * \hideinitializer
 */
#define IS_POWER_2(num) 			        (num && !(num & (num - 1)))

/*
 * This macro will round a value up to the next 'base'.
 * Find nearest number (from _x) which would be devided on _b
 * 
 * \example 
 * ROUND_UP(115, 3) = 117
 * 115/3 = 38.3(3)
 * 117/3 = 39
 */
#define ROUND_UP(_x, _b)                     ((((_x) + ((_b) - 1)) / (_b)) * (_b))

/*
 * These macros work together to progressively set each bit below the MSb
 * set in a 32-bit value. By cascading the macros, we can round any value
 * up to the nearest power-of-2 at compile time.
 */
#define _OR2(_x)                ((_x) | ((_x) >> 1))
#define _OR4(_x)                (_OR2(_x) | (_OR2(_x) >> 2))
#define _OR8(_x)                (_OR4(_x) | (_OR4(_x) >> 4))
#define _OR16(_x)               (_OR8(_x) | (_OR8(_x) >> 8))
#define _OR32(_x)               (_OR16(_x) | (_OR16(_x) >> 16))

#define ROUND_UP_POW_2(_x)      ((_OR32((_x) - 1)) + 1)

//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif