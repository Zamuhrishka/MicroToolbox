/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        This file contains the prototypes functions which used for
 *               conversion different data type to each other.
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>

#include "types.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief       This function convert hex char to digit.
 *
 * \param[in]   c: hex char.
 *
 * \return      the number that corresponds to hex char
 *              or `0xFF` if error.
 **/
uint8_t convert_hex_char_to_num(char c);

/**
 * \brief       This function convert hex digit to hex char.
 *
 * \param[in]   num: hex digit.
 *
 * \return      the char that corresponds to digit
 *              or ' ' if error.
 **/
char convert_hex_num_to_char(uint8_t num);

/**
 * \brief       This function convert string representation of MAC to \ref `mac_t` -
 *              special data type for MAC store.
 *
 * \code
 * bool result = convert_string_to_mac_addr("AA:13:01:00:55:FE", &mac);
 * \endcode
 *
 * \param[in]   str: string representation of MAC.
 * \param[out]  mac: pointer to `mac_t` structure.
 *
 * \return      true/false.
 *
 **/
bool convert_string_to_mac_addr(const char *str, mac_t *mac);

/**
 * \brief       This function convert `mac_t` structure to string.
 *              \see mac_t
 *
 * \code
 * bool result = convert_mac_addr_to_string(&mac, mac_string);
 * \endcode
 *
 * \param[in]   mac: pointer to `mac_t` structure.
 * \param[out]  string: pointer to the string in which MAC would be stored.
 *
 * \warning     Length of **string** must be not less then 18 bytes.
 *
 * \return      true/false.
 **/
bool convert_mac_addr_to_string(const mac_t *mac, char *string);

/**
 * \brief       This function convert `ip4addr_t` structure to string.
 *
 * \param[in]   ip: `ip4addr_t` structure which store IP address \see ip4addr_t.
 * \param[out]  string: pointer to the string in which IP would be stored.
 *
 * \warning     Length of **string** must be not less then 16 bytes.
 *
 * \return      true/false.
 **/
bool convert_ip4addr_to_string(ip4addr_t ip, char *string);

/**
 * \brief       This function convert IP string representation to \ref `ip4addr_t` -
 *              special data type for IP store.
 *
 * \param[in]   string: IP string representation.
 * \param[out]  ip: pointer to the `ip4addr_t` structure.
 *
 * \return      true/false.
 **/
bool convert_string_to_ip4addr(ip4addr_t *ip, const char *string);

/**
 * \brief       This function decode BCD number.
 *
 * \param[in]   bcd: BCD number.
 *
 * \return      decoded number.
 **/
uint32_t convert_bcd_to_num(bcd_t bcd);

/**
 * \brief       This function encode to BCD number.
 *
 * \param[in]   num: number.
 *
 * \return      BCD number.
 **/
bcd_t convert_num_to_bcd(uint32_t num);

/**
 * \brief       Check if this string is a decimal number?
 *
 * \param[in] str  string representation of decimal number.
 * \param[in] len  length of string
 *
 * \return true/false
 */
bool convert_is_dec_number(const char *str, size_t len);

/**
 * \brief       Check if this string is a hex number?
 *
 * \param[in] str  string representation of hex number.
 * \param[in] len  length of string
 *
 * \return true/false
 */
bool convert_is_hex_number(const char *str, size_t len);

/**
 * \brief       This function convert string to `uint8_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `uint8_t` number.
 **/
uint8_t convert_str_to_u8(const char *str);

/**
 * \brief       This function convert string to `int8_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `int8_t` number.
 **/
int8_t convert_str_to_i8(const char *str);

/**
 * \brief       This function convert string to `uint16_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `uint16_t` number.
 **/
uint16_t convert_str_to_u16(const char *str);

/**
 * \brief       This function convert string to `int16_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `int16_t` number.
 **/
int16_t convert_str_to_i16(const char *str);

/**
 * \brief       This function convert string to `uint32_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `uint32_t` number.
 **/
uint32_t convert_str_to_u32(const char *str);

/**
 * \brief       This function convert string to `int32_t` number.
 *
 * \param[in]   str: string representation of number.
 *
 * \return      `int32_t` number.
 **/
int32_t convert_str_to_i32(const char *str);

/**
 * \brief       This function convert `uint8_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning     length must be equal or greater then 4 chars.
 *
 * \param[in]   dig: `uint8_t number.
 *
 * \return      none.
 **/
void convert_u8_to_str(char *str, uint8_t dig);

/**
 * \brief       This function convert `int8_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning     length must be equal or greater then 5 chars.
 *
 * \param[in]   dig: `int8_t number.
 *
 * \return      none.
 **/
void convert_i8_to_str(char *str, int8_t dig);

/**
 * \brief       This function convert `uint16_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning length must be equal or greater then 6 chars.
 *
 * \param[in]   dig: `uint16_t` number.
 *
 * \return      none.
 **/
void convert_u16_to_str(char *str, uint16_t dig);

/**
 * \brief       This function convert `int16_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning length must be equal or greater then 7 chars.
 *
 * \param[in]   dig: `int16_t` number.
 *
 * \return      none.
 **/
void convert_i16_to_str(char *str, int16_t dig);

/**
 * \brief       This function convert `uint32_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning length must be equal or greater then 11 chars.
 *
 * \param[in]   dig: `uint32_t` number.
 *
 * \return      none.
 **/
void convert_u32_to_str(char *str, uint32_t dig);

/**
 * \brief       This function convert `int32_t` number to string.
 *
 * \param[out]  str: pointer to string in which the string representation
 *                   of number would be stored.
 *
 * \warning length must be equal or greater then 12 chars.
 *
 * \param[in]   dig: `int32_t` number.
 *
 * \return      none.
 **/
void convert_i32_to_str(char *str, int32_t dig);

/**
 * \brief       This function used to map a value from one range to another.
 *
 * \param[out]  x: variable which need to transform.
 * \param[in]   in_min: min value of input range.
 * \param[in]   in_max: max value of input range.
 * \param[in]   out_min: min value of output range.
 * \param[in]   out_max: max value of output range.
 *
 * \return      transformed variable.
 **/
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

/**
 * @brief Convert `uint8_t` number into \ref `bin8_t` type.
 *
 * @param[in] num: number
 * @param[in] endian: current endian order \ref `endian_e`
 * @return `bin8_t`
 */
bin8_t convert_u8_to_bin8(uint8_t num, endian_e endian);

/**
 * @brief Convert `uint16_t` number into \ref `bin16_t` type.
 *
 * @param[in] num: number
 * @param[in] endian: current endian order \ref `endian_e`
 * @return `bin16_t`
 */
bin16_t convert_u16_to_bin16(uint16_t num, endian_e endian);

/**
 * @brief Convert `uint32_t` number into \ref `bin32_t` type.
 *
 * @param[in] num: number
 * @param[in] endian: current endian order \see `EndianOrder_tag`
 * @return `bin32_t`
 */
bin32_t convert_u32_to_bin32(uint32_t num, endian_e endian);
