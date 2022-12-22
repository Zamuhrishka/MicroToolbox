/**
* \file         conversion.h
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
#include <stdbool.h>

#include "types.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief		This function convert hex char to digit.
 *
 * \param[in] 	c: hex char.
 *
 * \return 		the number that corresponds to hex char.
**/
int8_t convert_hex_char_to_num(char c);

/**
 * \brief		This function convert digit to hex char.
 *
 * \param[in] 	num: digit.
 *
 * \return 		the char that corresponds to digit.
**/
char convert_hex_num_to_char(uint8_t num);

/**
 * \brief		This function convert string to MAC address.
 *
 * \param[in] 	str: string that corresponds to MAC.
 * \param[out] 	macAddr: MAC address.
 *
 * \return 		true/false.
**/
bool convert_string_to_mac_addr(const char *str, mac_t *mac);

/**
 * \brief		This function convert MAC address to string.
 *
 * \param[in] 	macAddr: MAC address.
 * \param[out] 	string: string that corresponds to MAC.
 *
 * \return 		true/false.
**/
bool convert_mac_addr_to_string(const mac_t *mac, char *string);

/**
 * \brief		This function convert IP address to string.
 *
 * \param[in] 	ipAddr: IP address \Ipv4Addr_t.
 * \param[out] 	ip: string that corresponds to IP.
 *
 * \return 		true/false.
**/
bool convert_ip4addr_to_string(ip4addr_t ipAddr, char *ip);

/**
 * \brief		This function convert string to IP address.
 *
 * \param[in] 	ip: string that corresponds to IP.
 * \param[out] 	ipAddr: IP address.
 *
 * \return 		true/false.
**/
bool convert_string_to_ip4addr(ip4addr_t *ipAddr, const char *ip);

/**
 * \brief		This function decode BCD number.
 *
 * \param[in] 	bcd: BCD number.
 *
 * \return 		decoded number.
**/
uint32_t convert_bcd_to_num(uint32_t dec);

/**
 * \brief		This function code BCD number.
 *
 * \param[in] 	dec: number.
 *
 * \return 		BCD number.
**/
uint32_t convert_num_to_bcd(uint32_t bcd);

/**
 * \brief		This function convert string to uint8_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
uint8_t convert_str_to_u8(const char *str);

/**
 * \brief		This function convert string to int8_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
int8_t convert_str_to_i8(const char *str);

/**
 * \brief		This function convert string to uint16_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
uint16_t convert_str_to_u16(const char *str);

/**
 * \brief		This function convert string to int16_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
int16_t convert_str_to_i16(const char *str);


/**
 * \brief		This function convert string to uint32_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
uint32_t convert_str_to_u32(const char *str);

/**
 * \brief		This function convert string to int32_t number.
 *
 * \param[in] 	str: pointer to string with string representation 
 *                   of number.
 *
 * \return 		number.
**/
int32_t convert_str_to_i32(const char *str);

/**
 * \brief		This function convert uint8_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 4 chars.
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_u8_to_str(char *str, uint8_t dig);

/**
 * \brief		This function convert int8_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 5 chars. 
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_i8_to_str(char *str, int8_t dig);

/**
 * \brief		This function convert uint16_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 6 chars. 
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_u16_to_str(char *str, uint16_t dig);

/**
 * \brief		This function convert int16_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 7 chars. 
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_i16_to_str(char *str, int16_t dig);

/**
 * \brief		This function convert uint32_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 11 chars. 
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_u32_to_str(char *str, uint32_t dig);

/**
 * \brief		This function convert int32_t number to string.
 *
 * \param[out] 	str: pointer to string in which the string representation 
 *                   of number would be stored. @warning length must be equal 
 *                   or greater then 12 chars. 
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_i32_to_str(char *str, int32_t dig);

/**
 * \brief		This function used to map a value from one range to another.
 *
 * \param[out] 	x: variable which need to transform.
 * \param[in] 	in_min: min value of input range.
 * \param[in] 	in_max: max value of input range.
 * \param[in] 	out_min: min value of output range.
 * \param[in] 	out_max: max value of output range.
 *
 * \return 		transformed variable.
**/
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

/**
 * @brief Convert uint8_t number into bin8_t type (see types.h).
 * 
 * @param[in] num: number
 * @param[in] endian: current endian order (see @endian_e) 
 * @return bin8_t 
 */
bin8_t convert_u8_to_bin8(uint8_t num, endian_e endian);

/**
 * @brief Convert uint16_t number into bin16_t type (see types.h).
 * 
 * @param[in] num: number
 * @param[in] endian: current endian order (see @endian_e) 
 * @return bin16_t 
 */
bin16_t convert_u16_to_bin16(uint16_t num, endian_e endian);

/**
 * @brief Convert uint32_t number into bin32_t type (see types.h).
 * 
 * @param[in] num: number 
 * @param[in] endian: current endian order (see @endian_e) 
 * @return bin32_t 
 */
bin32_t convert_u32_to_bin32(uint32_t num, endian_e endian);

/* C++ detection */
#ifdef __cplusplus
}
#endif
