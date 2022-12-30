/**
* \file
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        Macros for arithmetics operation.   
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
 * \brief           This macros take the min between `a` and `b`.
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          the min between `a` and `b`.
 */
#define MIN(a, b)            		 (((a) < (b)) ? (a) : (b))

/**
 * \brief           This macros take the min between `a` and `b` without branch
 * 
 * \warning         This optimization works well on some machines, but on modern 
 *                  machines using -O3 the branchless version is usually slower than the 
 *                  branching version. Modern compilers can perform this optimization better 
 *                  than you can! 
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          the min between `a` and `b`.
 */
#define MIN_BRANCHLESS(a, b)   		  ((b) ^ (((a) ^ (b)) & -((a) < (b))))

/**
 * \brief           This macros take the max between `a` and `b`.
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          the max between `a` and `b`.
 */
#define MAX(a, b)            		  (((a) > (b)) ? (a) : (b))

/**
 * \brief           This macros take the max between `a` and `b` without branch
 * 
 * \warning         This optimization works well on some machines, but on modern 
 *                  machines using -O3 the branchless version is usually slower than the 
 *                  branching version. Modern compilers can perform this optimization better 
 *                  than you can! 
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          the max between `a` and `b`.
 */
#define MAX_BRANCHLESS(a, b)          ((b) & (((a)-(b)) >> 31) | (a) & (~((a)-(b)) >> 31))

/**
 * \brief           This macros test two values for equal.
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          true if equal.
 */
#define IS_EQUAL(a, b)				  (((a) ^ (b)) == 0)

/**
 * \brief           This macros test number for even.
 * 
 * \param[in]       num: number
 * 
 * \return          true if number is even.
 */
#define IS_EVEN(num)				  (((num) & 1) == 1)

/**
 * \brief           This macros test number for odd.
 * 
 * \param[in]       num: number
 * 
 * \return          true if number is odd.
 */
#define IS_ODD(num)					  (!(((num) & 1) == 1))

/**
 * \brief           This macros change the number sigh.
 * 
 * \param[in]       num: number
 * 
 * \return          number with changed sigh.
 */
#define INVERT_SIGH(a)				  ((~(a)) + 1)

/**
 * \brief           Detect if two integers have opposite signs.
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          number with changed sigh.
 */
#define IS_SIGH_EQUAL(a, b) 		   (((a) ^ (b)) >= 0)

/**
 * \brief           Takes arithmetical mean between `a` and `b`.
 * 
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          arithmetical mean.
 */
#define ARITHMETICAL_MEAN(a, b)			(((a) + (b)) >> 1u)

/**
 * \brief           Swap `a` and `b`.
 * \param[in]       a: first value
 * \param[in]       b: second value
 * 
 * \return          none
 */
#define SWAP(a, b) 			           ((a) = (a) ^ (b) ^ ((b) = (a)))

/**
 * \brief           This macros test number for power of 2.
 * 
 * \param[in]       num: number
 * 
 * \return          true if number is power of 2.
 * 
 */
#define IS_POWER_2(num) 			   (num && !(num & (num - 1)))

/**
 * \brief           This macro will round a value up to the next 'base'.
 * \code
 *                  ROUND_UP(115, 3) = 117
 *                  115/3 = 38.3(3)
 *                  117/3 = 39
 * \endcode
 *
 * \param[in]       x: base
 * \param[in]       b: divider
 * \return          nearest number (from x) which would be divided on b.
 */
#define ROUND_UP(x, b)                ((((x) + ((b) - 1)) / (b)) * (b))

/**
 * \brief           These macros work together to progressively set each 
 *                  bit below the MSb. set in a 32-bit value. By cascading 
 *                  the macros, we can round any value up to the nearest 
 *                  power-of-2 at compile time.
 * 
 * \param[in]       x: number
 * 
 * \return          nearest to x the power-of-2 number.
 */
/*! \cond PRIVATE */
#define _OR2(x)                     ((x) | ((x) >> 1))
#define _OR4(x)                     (_OR2(x) | (_OR2(x) >> 2))
#define _OR8(x)                     (_OR4(x) | (_OR4(x) >> 4))
#define _OR16(x)                    (_OR8(x) | (_OR8(x) >> 8))
#define _OR32(x)                    (_OR16(x) | (_OR16(x) >> 16))
/*! \endcond */
#define ROUND_UP_POW_2(x)           ((_OR32((x) - 1)) + 1)

//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif