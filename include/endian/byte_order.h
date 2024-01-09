/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This module provides functions for handling and converting byte order (endianness)
 *               in data for embedded systems. It supports functions to determine the byte order of
 *               the target system, as well as to swap byte order for different data types including
 *               16-bit, 32-bit, and 64-bit numbers. Additionally, the module includes utilities for
 *               storing and loading values in both little-endian and big-endian formats. This is
 *               crucial in embedded systems where data interoperability between different architectures
 *               requires correct interpretation of byte order for accurate data processing and communication.
 */


#pragma once

#if !defined(MODULE_ENDIAN_DISABLED)

//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>

#include "types.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif


/**
 * \brief           Define target byte endian order.
 *
 * \return          byte endian order \see endian_e
 */
endian_e byte_order_define(void);

/**
 * \brief           Swap endian byte order for `16-bit` type.
 *
 * \param[in]       num: `16-bit` number in one byte order.
 *
 * \return          `16-bit` number with swapped byte order.
 */
uint16_t byte_order_swap16(uint16_t num);

/**
 * \brief           Swap endian byte order for `32-bit` type.
 *
 * \param[in]       num: `32-bit` number in one byte order.
 *
 * \return          `32-bit` number with swapped byte order.
 */
uint32_t byte_order_swap32(uint32_t num);

/**
 * \brief           Swap endian byte order for `64-bit` type.
 *
 * \param[in]       num: `64-bit` number in one byte order.
 *
 * \return          `64-bit` number with swapped byte order.
 */
uint64_t byte_order_swap64(uint64_t num);

/**
 * \brief           Store `16-bit` value to bytes array in little-endian order.
 *
 * \param[in]       val: Value to write to output array.
 * \param[out]      array: Minimum `2-bytes` long output array to write value to.
 *
 * \return          none.
 **/
void byte_order_u16_to_array_le(uint16_t val, void *array);

/**
 * \brief           Store `32-bit` value to bytes array in little-endian order.
 *
 * \param[in]       val: Value to write to output array.
 * \param[out]      array: Minimum `4-bytes` long output array to write value to.
 *
 * \return          none.
 */
void byte_order_u32_to_array_le(uint32_t val, void *array);

/**
 * \brief           Load `16-bit` value from bytes array in little-endian order.
 *
 * \param[in]       array: Minimum `2-bytes` long input array to extract bytes from.
 *
 * \return          `16-bit` value extracted from input array.
 */
uint16_t byte_order_array_to_u16_le(const void *array);

/**
 * \brief           Load `32-bit` value from bytes array in little-endian order.
 *
 * \param[in]       array: Minimum `2-bytes` long input array to extract bytes from.
 *
 * \return          `32-bit` value extracted from input array.
 */
uint32_t byte_order_array_to_u32_le(const void *array);

/**
 * \brief           Store `16-bit` value to bytes array in big-endian order.
 *
 * \param[in]       val: Value to write to output array.
 * \param[out]      array: Minimum `2-bytes` long output array to write value to.
 *
 * \return          none.
 */
void byte_order_u16_to_array_be(uint16_t val, void *array);

/**
 * \brief           Store `32-bit` value to bytes array in big-endian order.
 *
 * \param[in]       val: Value to write to output array.
 * \param[out]      array: Minimum `4-bytes` long output array to write value to.
 *
 * \return          none.
 */
void byte_order_u32_to_array_be(uint32_t val, void *array);

/**
 * \brief           Load `16-bit` value from bytes array in big-endian order.
 *
 * \param[in]       array: Minimum `2-bytes` long input array to extract bytes from.
 *
 * \return          `16-bit` value extracted from input array.
 */
uint16_t byte_order_array_to_u16_be(const void *array);

/**
 * \brief           Load `32-bit` value from bytes array in big-endian order.
 *
 * \param[in]       array: Minimum `4-bytes` long input array to extract bytes from.
 *
 * \return          `32-bit` value extracted from input array.
 */
uint32_t byte_order_array_to_u32_be(const void *array);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif //#if !defined(MODULE_ENDIAN_DISABLED)
