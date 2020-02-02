/********************************************************************************
*
* @file    		convert.h
* @author  		Kovalchuk Alexander
* @email  		roux@yandex.ru
* @brief   		This file contains the prototypes functions for different types
*
********************************************************************************/
#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
//! @brief MAC address
//! @{
typedef struct
{
	uint8_t value[6];
} 	mac_t;
//! @}

//! Ip address (version 4)
typedef uint32_t ip4addr_t;

//! BCD typedef
typedef uint32_t bcd_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E _______________________________________________________
//_____ I N L I N E   F U N C T I O N _________________________________________
//_____ S T A T I C  F U N C T I O N  _________________________________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
/**
 * @brief		This function convert hex char to digit.
 *
 * @param[in] 	c hex char.
 *
 * @return 		the number that corresponds to hex char.
**/
int8_t convert_hex_char_to_num(char c);

/**
 * @brief		This function convert digit to hex char.
 *
 * @param[in] 	num digit.
 *
 * @return 		the char that corresponds to digit.
**/
char convert_hex_num_to_char(uint8_t num);

/**
 * @brief		This function convert string to MAC address.
 *
 * @param[in] 	str string that corresponds to MAC.
 * @param[out] 	macAddr MAC address.
 *
 * @return 		true/false.
**/
bool convert_string_to_mac_addr(const char *str, mac_t *mac);

/**
 * @brief		This function convert MAC address to string.
 *
 * @param[in] 	macAddr MAC address.
 * @param[out] 	string string that corresponds to MAC.
 *
 * @return 		true/false.
**/
bool convert_mac_addr_to_string(const mac_t *mac, char *string);

/**
 * @brief		This function convert IP address to string.
 *
 * @param[in] 	ipAddr IP address @Ipv4Addr_t.
 * @param[out] 	ip string that corresponds to IP.
 *
 * @return 		true/false.
**/
bool convert_ip4addr_to_string(ip4addr_t ipAddr, char *ip);

/**
 * @brief		This function convert string to IP address.
 *
 * @param[in] 	ip string that corresponds to IP.
 * @param[out] 	ipAddr IP address.
 *
 * @return 		true/false.
**/
bool convert_string_to_ip4addr(ip4addr_t *ipAddr, const char *ip);

/**
 * @brief		This function decode BCD number.
 *
 * @param[in] 	bcd BCD number.
 *
 * @return 		decoded number.
**/
uint32_t convert_bcd_to_num(uint32_t dec);

/**
 * @brief		This function code BCD number.
 *
 * @param[in] 	dec number.
 *
 * @return 		BCD number.
**/
uint32_t convert_num_to_bcd(uint32_t bcd);

/**
 * @brief		This function convert string to uint8_t number.
 *
 * @param[in] 	str string that corresponds to number.
 *
 * @return 		number.
**/
uint8_t convert_string_to_uint8(const char *str);

/**
 * @brief		This function convert string to uint16_t number.
 *
 * @param[in] 	str string that corresponds to number.
 *
 * @return 		number.
**/
uint16_t convert_string_to_uint16(const char *str);

/**
 * @brief		This function convert string to uint32_t number.
 *
 * @param[in] 	str string that corresponds to number.
 *
 * @return 		number.
**/
uint32_t convert_string_to_uint32(const char *str);

/**
 * @brief		This function convert uint8_t number to string.
 *
 * @param[out] 	str string that corresponds to number.
 * @param[in] 	dig number.
 *
 * @return 		void.
**/
void convert_uint8_to_string(char *str, uint8_t dig);

/**
 * @brief		This function convert uint16_t number to string.
 *
 * @param[out] 	str string that corresponds to number.
 * @param[in] 	dig number.
 *
 * @return 		void.
**/
void convert_uint16_to_string(char *str, uint16_t dig);

/**
 * @brief		This function convert uint32_t number to string.
 *
 * @param[out] 	str string that corresponds to number.
 * @param[in] 	dig number.
 *
 * @return 		void.
**/
void convert_uint32_to_string(char *str, uint32_t dig);

float Utils_Round(float val, float rval);
/* C++ detection */
#ifdef __cplusplus
}
#endif
