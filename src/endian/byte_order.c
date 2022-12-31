/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        This file contains the prototypes functions which use for
 *               work with different byte endian types.
 */

//_____ I N C L U D E S _______________________________________________________
#include "byte_order.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * Define target byte endian order.
 *
 * Public function defined in byte_order.h
 */
endian_e byte_order_define(void)
{
    uint16_t marker = 0xFACE;
    uint8_t* pMarker = (uint8_t*)&marker;

    return (pMarker[0] == 0xFA && pMarker[1] == 0xCE) ? BIG_ENDIAN_ORDER : LITTLE_ENDIAN_ORDER;
}

/**
 * Swap endian byte order for `16-bit` type.
 *
 * Public function defined in byte_order.h
 */
uint16_t byte_order_swap16(uint16_t num)
{
    return ((uint16_t)((num >> 8) | ((num << 8) & 0xff00)));
}

/**
 * Swap endian byte order for `32-bit` type.
 *
 * Public function defined in byte_order.h
 */
uint32_t byte_order_swap32(uint32_t num)
{
    return ((uint32_t)((num >> 24) | ((num >> 8) & 0xff00) | ((num << 8) & 0xff0000) | ((num << 24) & 0xff000000)));
}

/**
 * Swap endian byte order for `64-bit` type.
 *
 * Public function defined in byte_order.h
 */
uint64_t byte_order_swap64(uint64_t num)
{
    return ((uint64_t)((num >> 56) | ((num >> 40) & 0xff00) | ((num >> 24) & 0xff0000) | ((num >> 8) & 0xff000000) |
                       ((num << 8) & ((uint64_t)0xff << 32)) | ((num << 24) & ((uint64_t)0xff << 40)) |
                       ((num << 40) & ((uint64_t)0xff << 48)) | ((num << 56))));
}

/**
 * Store `16-bit` value to bytes array in little-endian order.
 *
 * Public function defined in byte_order.h
 */
void byte_order_u16_to_array_le(uint16_t val, void* array)
{
    uint8_t* p = array;

    p[0] = (uint8_t)((val >> 0) & 0xFF);
    p[1] = (uint8_t)((val >> 8) & 0xFF);
}

/**
 * Store `32-bit` value to bytes array in little-endian order.
 *
 * Public function defined in byte_order.h
 */
void byte_order_u32_to_array_le(uint32_t val, void* array)
{
    uint8_t* p = array;

    p[0] = (uint8_t)((val >> 0) & 0xFF);
    p[1] = (uint8_t)((val >> 8) & 0xFF);
    p[2] = (uint8_t)((val >> 16) & 0xFF);
    p[3] = (uint8_t)((val >> 24) & 0xFF);
}

/**
 * Load `16-bit` value from bytes array in little-endian order.
 *
 * Public function defined in byte_order.h
 */
uint16_t byte_order_array_to_u16_le(const void* array)
{
    const uint8_t* p = array;
    return p[1] << 8 | p[0];
}

/**
 * Load `32-bit` value from bytes array in little-endian order.
 *
 * Public function defined in byte_order.h
 */
uint32_t byte_order_array_to_u32_le(const void* array)
{
    const uint8_t* p = array;
    return p[3] << 24 | p[2] << 16 | p[1] << 8 | p[0];
}

/**
 * Store `16-bit` value to bytes array in big-endian order.
 *
 * Public function defined in byte_order.h
 */
void byte_order_u16_to_array_be(uint16_t val, void* array)
{
    uint8_t* p = array;

    p[0] = (uint8_t)((val >> 8) & 0xFF);
    p[1] = (uint8_t)((val >> 0) & 0xFF);
}

/**
 * Store `32-bit` value to bytes array in big-endian order.
 *
 * Public function defined in byte_order.h
 */
void byte_order_u32_to_array_be(uint32_t val, void* array)
{
    uint8_t* p = array;

    p[0] = (uint8_t)((val >> 24) & 0xFF);
    p[1] = (uint8_t)((val >> 16) & 0xFF);
    p[2] = (uint8_t)((val >> 8) & 0xFF);
    p[3] = (uint8_t)((val >> 0) & 0xFF);
}

/**
 * Load `16-bit` value from bytes array in big-endian order.
 *
 * Public function defined in byte_order.h
 */
uint16_t byte_order_array_to_u16_be(const void* array)
{
    const uint8_t* p = array;
    return p[0] << 8 | p[1];
}

/**
 * Load `32-bit` value from bytes array in big-endian order.
 *
 * Public function defined in byte_order.h
 */
uint32_t byte_order_array_to_u32_be(const void* array)
{
    const uint8_t* p = array;
    return p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3];
}
