// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This module provides a comprehensive suite of functions for data type conversions
 *               in embedded systems. It includes functions for converting between different
 *               numerical representations like hexadecimal, BCD, and binary, as well as utilities
 *               for converting network data types such as MAC and IP addresses. The module aims to
 *               facilitate data manipulation and interoperability in embedded applications where
 *               data often needs to be converted between various formats for communication, storage,
 *               and processing purposes.
 */

#if !defined(MODULE_CONVERSION_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include "conversion.h"

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
/**
@brief Enum for data types
*/
enum Constants
{
    U8B = 0,  /**< uint8_t data type */
    U16B = 1, /**< uint16_t data type */
    U32B = 2, /**< uint32_t data type */
};

/*! Max decimal counts in digit */
#define MAX_DECIMAL_COUNT 10
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
/**
 * \brief   Check if this char is a decimal number?
 *
 * \param[in] c: given char
 *
 * \return true/false
 */
static inline bool is_dec_digit(const unsigned char c)
{
    return ((c >= '0') && (c <= '9'));
}

/**
 * \brief   Check if this char is a hex number?
 *
 * \param[in] c: given char
 *
 * \return true/false
 */
static inline bool is_hex_digit(const unsigned char c)
{
    return ((is_dec_digit(c)) || ((c >= 'A') && (c <= 'F')) || ((c >= 'a') && (c <= 'f')));
}

/**
 * \brief   Calculate count of digits in number
 *
 * \param[in] dig:      given number
 * \param[in] f_n_bit:  size of number
 *
 * \return digits count
 */
static uint8_t count_num(uint32_t dig, enum Constants f_n_bit)
{
    uint8_t num = 0;

    if (f_n_bit == U8B)
    {
        if ((dig / 100) != 0)
            num = 3;
        else if ((dig / 10) != 0)
            num = 2;
        else
            num = 1;
    }

    else if (f_n_bit == U16B)
    {
        if ((dig / 10000) != 0)
            num = 5;
        else if ((dig / 1000) != 0)
            num = 4;
        else if ((dig / 100) != 0)
            num = 3;
        else if ((dig / 10) != 0)
            num = 2;
        else
            num = 1;
    }

    else if (f_n_bit == U32B)
    {
        if ((dig / 1000000000) != 0)
            num = 10;
        else if ((dig / 100000000) != 0)
            num = 9;
        else if ((dig / 10000000) != 0)
            num = 8;
        else if ((dig / 1000000) != 0)
            num = 7;
        else if ((dig / 100000) != 0)
            num = 6;
        else if ((dig / 10000) != 0)
            num = 5;
        else if ((dig / 1000) != 0)
            num = 4;
        else if ((dig / 100) != 0)
            num = 3;
        else if ((dig / 10) != 0)
            num = 2;
        else
            num = 1;
    }

    return (num);
}

/**
 * \brief   Calculate count of digits in string.
 *
 * \param[in] dig: given string number representation
 *
 * \return digits count
 */
static uint8_t string_digit_num_count(const char *dig)
{
    uint8_t num = 0;
    bool digit = 0;

    digit = is_dec_digit(dig[num]);
    while (digit && num < MAX_DECIMAL_COUNT)
    {
        num++;
        digit = is_dec_digit(dig[num]);
    }

    return num;
}
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * This function used to convert hex char to digit.
 *
 * Public function defined in convert.h
 */
uint8_t convert_hex_char_to_num(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (c - '0');
    }

    if (c >= 'A' && c <= 'F')
    {
        return (10 + c - 'A');
    }

    if (c >= 'a' && c <= 'f')
    {
        return (10 + c - 'a');
    }

    return (0xFF);
}

/**
 * This function used to convert digit to hex char.
 *
 * Public function defined in convert.h
 */
char convert_hex_num_to_char(uint8_t num)
{
    if (num >= 0 && num <= 9)
    {
        return (num + '0');
    }

    if (num >= 0x0A && num <= 0x0F)
    {
        return (num - 10 + 'A');
    }

    return (' ');
}

/**
 * This function convert string representation of MAC to \ref `mac_t` -
 * special data type for MAC store.
 *
 * Public function defined in convert.h
 */
bool convert_string_to_mac_addr(const char *str, mac_t *macAddr)
{
    int8_t numLowPart = -1;
    int8_t numHighPart = -1;
    uint8_t offsetLowPart = 1;
    uint8_t offsetHighPart = 0;

    if (str == NULL || macAddr == NULL)
    {
        return false;
    }

    if (str[2] != ':' || str[5] != ':' || str[8] != ':' || str[11] != ':' || str[14] != ':')
    {
        return false;
    }

    for (size_t i = 0; i < sizeof(macAddr->value); i++)
    {
        numHighPart = convert_hex_char_to_num(str[offsetHighPart]);
        numLowPart = convert_hex_char_to_num(str[offsetLowPart]);

        if (numHighPart == (-1) || numLowPart == (-1))
        {
            return false;
        }

        macAddr->value[i] = (numHighPart << 4) | numLowPart;

        offsetHighPart += 3;
        offsetLowPart += 3;
    }

    return true;
}

/**
 * This function convert `mac_t` structure to string.
 *
 * Public function defined in convert.h
 */
bool convert_mac_addr_to_string(const mac_t *macAddr, char *string)
{
    int8_t numLowPart = -1;
    int8_t numHighPart = -1;
    uint8_t offsetLowPart = 1;
    uint8_t offsetHighPart = 0;
    char _mac[] = "00:00:00:00:00:00\0";

    if (string == NULL || macAddr == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < sizeof(macAddr->value); i++)
    {
        numHighPart = convert_hex_num_to_char((macAddr->value[i] >> 4) & 0x0F);
        numLowPart = convert_hex_num_to_char(macAddr->value[i] & 0x0F);

        if (numHighPart == (-1) || numLowPart == (-1))
        {
            return false;
        }

        _mac[offsetLowPart] = numLowPart;
        _mac[offsetHighPart] = numHighPart;

        offsetHighPart += 3;
        offsetLowPart += 3;
    }

    strcpy(string, _mac);

    return true;
}

/**
 * This function convert `ip4addr_t` structure to string.
 *
 * Public function defined in convert.h
 */
bool convert_ip4addr_to_string(ip4addr_t ip, char *string)
{
    uint8_t *p;

    if (string == NULL)
    {
        return false;
    }

    p = (uint8_t *)&ip;
    sprintf(string, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);

    return true;
}

/**
 * This function convert IP string representation to \ref `ip4addr_t` -
 * special data type for IP store.
 *
 * Public function defined in convert.h
 */
bool convert_string_to_ip4addr(ip4addr_t *ip, const char *string)
{
    int ip1, ip2, ip3, ip4;
    ip4addr_t _ip = 0;

    if (string == NULL || ip == NULL)
    {
        return false;
    }

    if (sscanf(string, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4) != 4)
    {
        return false;
    }

    _ip |= ip4;
    _ip <<= 8;
    _ip |= ip3;
    _ip <<= 8;
    _ip |= ip2;
    _ip <<= 8;
    _ip |= ip1;

    *ip = _ip;

    return true;
}

/**
 * This function used to decode BCD number.
 *
 * Public function defined in conversion.h
 */
uint32_t convert_bcd_to_num(bcd_t bcd)
{
    uint32_t dec = 0;

    for (uint32_t mult = 1; bcd; bcd = bcd >> 4)
    {
        dec += (bcd & 0x0f) * mult;
        mult *= 10;
    }

    return dec;
}

/**
 * This function used to encode BCD number.
 *
 * Public function defined in conversion.h
 */
bcd_t convert_num_to_bcd(uint32_t dec)
{
    bcd_t bcd = 0;
    uint32_t i = 0;

    while (dec > 0)
    {
        bcd = bcd | ((dec - (dec / 10) * 10) << (i * 4));
        i++;
        dec /= 10;
    }

    return bcd;
}

/**
 * Check if this string is a decimal number?
 *
 * Public function defined in conversion.h
 */
bool convert_is_dec_number(const char *str, size_t len)
{
    if (NULL == str || len == 0)
    {
        return false;
    }

    size_t i = (str[0] == '-' ? 1 : 0);

    for (; i < len; i++)
    {
        if (!is_dec_digit(str[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * Check if this string is a hex number?
 *
 * Public function defined in conversion.h
 */
bool convert_is_hex_number(const char *str, size_t len)
{
    if (NULL == str || len == 0)
    {
        return false;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (!is_hex_digit(str[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * This function convert string to `uint8_t` number.
 *
 * Public function defined in conversion.h
 */
uint8_t convert_str_to_u8(const char *str)
{
    uint8_t dig = 0;

    if (str == NULL)
    {
        return 0;
    }

    uint8_t num = string_digit_num_count(str);

    switch (num)
    {
        case 1: dig = (str[0] - '0'); break;
        case 2: dig = (str[0] - '0') * 10 + (str[1] - '0'); break;
        case 3: dig = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0'); break;
        default: dig = 0; break;
    }

    return dig;
}

/**
 * This function convert string to `int8_t` number.
 *
 * Public function defined in conversion.h
 */
int8_t convert_str_to_i8(const char *str)
{
    int8_t dig = 1;

    if (str == NULL)
    {
        return 0;
    }

    char *pointer = &str[0];

    if (str[0] == '-')
    {
        dig = (-1);
        pointer = &str[1];
    }

    return (dig * convert_str_to_u8(pointer));
}

/**
 * This function convert string to `uint16_t` number.
 *
 * Public function defined in conversion.h
 */
uint16_t convert_str_to_u16(const char *str)
{
    uint16_t dig;
    uint8_t num = 0;

    if (str == NULL)
    {
        return 0;
    }

    num = string_digit_num_count(str);

    switch (num)
    {
        case 1: dig = (str[0] - '0'); break;
        case 2: dig = (str[0] - '0') * 10 + (str[1] - '0'); break;
        case 3: dig = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0'); break;
        case 4: dig = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0'); break;
        case 5:
            dig = (str[0] - '0') * 10000 + (str[1] - '0') * 1000 + (str[2] - '0') * 100 + (str[3] - '0') * 10 +
                  (str[4] - '0');
            break;
        default: dig = (-1); break;
    }
    return (dig);
}

/**
 * This function convert string to `int16_t` number.
 *
 * Public function defined in conversion.h
 */
int16_t convert_str_to_i16(const char *str)
{
    int16_t dig = 1;

    if (str == NULL)
    {
        return 0;
    }

    char *pointer = &str[0];

    if (str[0] == '-')
    {
        dig = (-1);
        pointer = &str[1];
    }

    return (dig * convert_str_to_u16(pointer));
}

/**
 * This function convert string to `uint32_t` number.
 *
 * Public function defined in conversion.h
 */
uint32_t convert_str_to_u32(const char *str)
{
    uint32_t dig;
    uint8_t num = 0;

    if (str == NULL)
    {
        return 0;
    }

    num = string_digit_num_count(str);

    switch (num)
    {
        case 1: dig = (str[0] - '0'); break;
        case 2: dig = (str[0] - '0') * 10 + (str[1] - '0'); break;
        case 3: dig = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0'); break;
        case 4: dig = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0'); break;
        case 5:
            dig = (str[0] - '0') * 10000 + (str[1] - '0') * 1000 + (str[2] - '0') * 100 + (str[3] - '0') * 10 +
                  (str[4] - '0');
            break;
        case 6:
            dig = (str[0] - '0') * 100000 + (str[1] - '0') * 10000 + (str[2] - '0') * 1000 + (str[3] - '0') * 100 +
                  (str[4] - '0') * 10 + (str[5] - '0');
            break;
        case 7:
            dig = (str[0] - '0') * 1000000 + (str[1] - '0') * 100000 + (str[2] - '0') * 10000 + (str[3] - '0') * 1000 +
                  (str[4] - '0') * 100 + (str[5] - '0') * 10 + (str[6] - '0');
            break;
        case 8:
            dig = (str[0] - '0') * 10000000 + (str[1] - '0') * 1000000 + (str[2] - '0') * 100000 +
                  (str[3] - '0') * 10000 + (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 +
                  (str[7] - '0');
            break;
        case 9:
            dig = (str[0] - '0') * 100000000 + (str[1] - '0') * 10000000 + (str[2] - '0') * 1000000 +
                  (str[3] - '0') * 100000 + (str[4] - '0') * 10000 + (str[5] - '0') * 1000 + (str[6] - '0') * 100 +
                  (str[7] - '0') * 10 + (str[8] - '0');
            break;
        case 10:
            dig = (str[0] - '0') * 1000000000 + (str[1] - '0') * 100000000 + (str[2] - '0') * 10000000 +
                  (str[3] - '0') * 1000000 + (str[4] - '0') * 100000 + (str[5] - '0') * 10000 + (str[6] - '0') * 1000 +
                  (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
            break;
        default: dig = (-1); break;
    }
    return (dig);
}

/**
 * This function convert string to `int32_t` number.
 *
 * Public function defined in conversion.h
 */
int32_t convert_str_to_i32(const char *str)
{
    int32_t dig = 1;

    if (str == NULL)
    {
        return 0;
    }

    char *pointer = &str[0];

    if (str[0] == '-')
    {
        dig = (-1);
        pointer = &str[1];
    }

    return (dig * convert_str_to_u32(pointer));
}

/**
 * This function convert `uint8_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_u8_to_str(char *str, uint8_t dig)
{
    if (NULL != str)
    {
        uint8_t num = count_num(dig, U8B);
        switch (num)
        {
            case 1: str[0] = (dig % 10) + '0'; break;
            case 2:
                str[0] = ((dig % 100) / 10) + '0';
                str[1] = (dig % 10) + '0';
                break;
            case 3:
                str[0] = ((dig % 1000) / 100) + '0';
                str[1] = ((dig % 100) / 10) + '0';
                str[2] = (dig % 10) + '0';
                break;
        }
    }
}

/**
 * This function convert `int8_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_i8_to_str(char *str, int8_t dig)
{
    if (NULL != str)
    {
        char *pointer = &str[0];

        if (dig < 0)
        {
            str[0] = '-';
            dig *= (-1);
            pointer = &str[1];
        }

        convert_u8_to_str(pointer, dig);
    }
}

/**
 * This function convert `uint16_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_u16_to_str(char *str, uint16_t dig)
{
    if (NULL != str)
    {
        uint8_t num = count_num(dig, U16B);
        switch (num)
        {
            case 1: str[0] = (dig % 10) + '0'; break;
            case 2:
                str[0] = ((dig % 100) / 10) + '0';
                str[1] = (dig % 10) + '0';
                break;
            case 3:
                str[0] = ((dig % 1000) / 100) + '0';
                str[1] = ((dig % 100) / 10) + '0';
                str[2] = (dig % 10) + '0';
                break;
            case 4:
                str[0] = ((dig % 10000) / 1000) + '0';
                str[1] = ((dig % 1000) / 100) + '0';
                str[2] = ((dig % 100) / 10) + '0';
                str[3] = (dig % 10) + '0';
                break;
            case 5:
                str[0] = ((dig % 100000) / 10000) + '0';
                str[1] = ((dig % 10000) / 1000) + '0';
                str[2] = ((dig % 1000) / 100) + '0';
                str[3] = ((dig % 100) / 10) + '0';
                str[4] = (dig % 10) + '0';
                break;
        }
    }
}

/**
 * This function convert `int16_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_i16_to_str(char *str, int16_t dig)
{
    if (NULL != str)
    {
        char *pointer = &str[0];

        if (dig < 0)
        {
            str[0] = '-';
            dig *= (-1);
            pointer = &str[1];
        }

        convert_u16_to_str(pointer, dig);
    }
}

/**
 * This function convert `uint32_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_u32_to_str(char *str, uint32_t dig)
{
    if (NULL != str)
    {
        uint8_t num = count_num(dig, U32B);
        switch (num)
        {
            case 1: str[0] = (dig % 10) + '0'; break;
            case 2:
                str[0] = ((dig % 100) / 10) + '0';
                str[1] = (dig % 10) + '0';
                break;
            case 3:
                str[0] = ((dig % 1000) / 100) + '0';
                str[1] = ((dig % 100) / 10) + '0';
                str[2] = (dig % 10) + '0';
                break;
            case 4:
                str[0] = ((dig % 10000) / 1000) + '0';
                str[1] = ((dig % 1000) / 100) + '0';
                str[2] = ((dig % 100) / 10) + '0';
                str[3] = (dig % 10) + '0';
                break;
            case 5:
                str[0] = ((dig % 100000) / 10000) + '0';
                str[1] = ((dig % 10000) / 1000) + '0';
                str[2] = ((dig % 1000) / 100) + '0';
                str[3] = ((dig % 100) / 10) + '0';
                str[4] = (dig % 10) + '0';
                break;
            case 6:
                str[0] = ((dig % 1000000) / 100000) + '0';
                str[1] = ((dig % 100000) / 10000) + '0';
                str[2] = ((dig % 10000) / 1000) + '0';
                str[3] = ((dig % 1000) / 100) + '0';
                str[4] = ((dig % 100) / 10) + '0';
                str[5] = (dig % 10) + '0';
                break;
            case 7:
                str[0] = ((dig % 10000000) / 1000000) + '0';
                str[1] = ((dig % 1000000) / 100000) + '0';
                str[2] = ((dig % 100000) / 10000) + '0';
                str[3] = ((dig % 10000) / 1000) + '0';
                str[4] = ((dig % 1000) / 100) + '0';
                str[5] = ((dig % 100) / 10) + '0';
                str[6] = (dig % 10) + '0';
                break;
            case 8:
                str[0] = ((dig % 100000000) / 10000000) + '0';
                str[1] = ((dig % 10000000) / 1000000) + '0';
                str[2] = ((dig % 1000000) / 100000) + '0';
                str[3] = ((dig % 100000) / 10000) + '0';
                str[4] = ((dig % 10000) / 1000) + '0';
                str[5] = ((dig % 1000) / 100) + '0';
                str[6] = ((dig % 100) / 10) + '0';
                str[7] = (dig % 10) + '0';
                break;
            case 9:
                str[0] = ((dig % 1000000000) / 100000000) + '0';
                str[1] = ((dig % 100000000) / 10000000) + '0';
                str[2] = ((dig % 10000000) / 1000000) + '0';
                str[3] = ((dig % 1000000) / 100000) + '0';
                str[4] = ((dig % 100000) / 10000) + '0';
                str[5] = ((dig % 10000) / 1000) + '0';
                str[6] = ((dig % 1000) / 100) + '0';
                str[7] = ((dig % 100) / 10) + '0';
                str[8] = (dig % 10) + '0';
                break;
            case 10:
                str[0] = ((dig % 10000000000) / 1000000000) + '0';
                str[1] = ((dig % 1000000000) / 100000000) + '0';
                str[2] = ((dig % 100000000) / 10000000) + '0';
                str[3] = ((dig % 10000000) / 1000000) + '0';
                str[4] = ((dig % 1000000) / 100000) + '0';
                str[5] = ((dig % 100000) / 10000) + '0';
                str[6] = ((dig % 10000) / 1000) + '0';
                str[7] = ((dig % 1000) / 100) + '0';
                str[8] = ((dig % 100) / 10) + '0';
                str[9] = (dig % 10) + '0';
                break;
        }
    }
}

/**
 * This function convert `int32_t` number to string.
 *
 * Public function defined in conversion.h
 */
void convert_i32_to_str(char *str, int32_t dig)
{
    if (NULL != str)
    {
        char *pointer = &str[0];

        if (dig < 0)
        {
            str[0] = '-';
            dig *= (-1);
            pointer = &str[1];
        }

        convert_u32_to_str(pointer, dig);
    }
}

/**
 * This function used to mapping a value from one range to another.
 *
 * Public function defined in conversion.h
 */
int32_t mapping(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * Convert uint8_t number into `bin8_t` type.
 *
 * Public function defined in conversion.h
 */
bin8_t convert_u8_to_bin8(uint8_t num, endian_e endian)
{
    bin8_t bin = {};
    uint8_t base = (endian == LITTLE_ENDIAN_ORDER) ? 7 : 0;
    int8_t k = (endian == LITTLE_ENDIAN_ORDER) ? 1 : -1;

    for (uint8_t i = 0; i < 8; i++)
    {
        bin.bit[base - (i * k)] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    bin.bit[8] = '\0';

    return bin;
}

/**
 * Convert uint16_t number into `bin16_t` type.
 *
 * Public function defined in conversion.h
 */
// bin16string_t convert_u16_to_bin_string(uint16_t num)
bin16_t convert_u16_to_bin16(uint16_t num, endian_e endian)
{
    bin16_t bin = {};

    uint8_t base = (endian == LITTLE_ENDIAN_ORDER) ? 15 : 0;
    int8_t k = (endian == LITTLE_ENDIAN_ORDER) ? 1 : -1;

    for (uint8_t i = 0; i < 16; i++)
    {
        bin.bit[base - (i * k)] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    bin.bit[16] = '\0';

    return bin;
}

/**
 * Convert uint32_t number into `bin32_t` type.
 *
 * Public function defined in conversion.h
 */
bin32_t convert_u32_to_bin32(uint32_t num, endian_e endian)
{
    bin32_t bin = {};
    uint8_t base = (endian == LITTLE_ENDIAN_ORDER) ? 31 : 0;
    int8_t k = (endian == LITTLE_ENDIAN_ORDER) ? 1 : -1;

    for (uint8_t i = 0; i < 32; i++)
    {
        bin.bit[base - (i * k)] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    bin.bit[32] = '\0';

    return bin;
}
#endif //#if !defined(MODULE_CONVERSION_DISABLED)
