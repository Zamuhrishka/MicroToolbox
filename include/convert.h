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
} 	MacAddr_t;
//! @}

//! Ip address (version 4)
typedef uint32_t Ipv4Addr_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E _______________________________________________________
//_____ I N L I N E   F U N C T I O N _________________________________________
//_____ S T A T I C  F U N C T I O N  _________________________________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
/**
 * @brief		This function convert hex char to digit.
 *
 * @param[in] 	c - hex char.
 *
 * @return 		the number that corresponds to hex char or -1 if error.
**/
int8_t Convert_HexCharToNum(char c);

/**
 * @brief		This function convert digit to hex char.
 *
 * @param[in] 	num - digit.
 *
 * @return 		the char that corresponds to digit or -1 if error.
**/
char Convert_HexNumToChar(uint8_t num);

/**
 * @brief		This function convert string to MAC address.
 *
 * @param[in] 	str - string that corresponds to MAC.
 * @param[out] 	macAddr - MAC address.
 *
 * @return 		true/false.
**/
bool Convert_StringToMacAddr(const char *str, MacAddr_t *macAddr);

/**
 * @brief		This function convert MAC address to string.
 *
 * @param[in] 	macAddr - MAC address.
 * @param[out] 	string - string that corresponds to MAC.
 *
 * @return 		true/false.
**/
bool Convert_MacAddrToString(const MacAddr_t *macAddr, char *string);

/**
 * @brief		This function convert IP address to string.
 *
 * @param[in] 	ipAddr - IP address @Ipv4Addr_t.
 * @param[out] 	ip - string that corresponds to IP.
 *
 * @return 		true/false.
**/
bool Convert_Ipv4addrToString(Ipv4Addr_t ipAddr, char *ip);

/**
 * @brief		This function convert string to IP address.
 *
 * @param[in] 	ip - string that corresponds to IP.
 * @param[out] 	ipAddr - IP address.
 *
 * @return 		true/false.
**/
bool Convert_StringToIpv4addr(Ipv4Addr_t *ipAddr, const char *ip);

/**
 * @brief		This function code BCD number.
 *
 * @param[in] 	bcd - BCD number.
 *
 * @return 		BCD number.
**/
uint32_t Convert_NumToBcd(uint32_t dec);

/**
 * @brief		This function decode BCD number.
 *
 * @param[in] 	dec - number.
 *
 * @return 		decoded number.
**/
uint32_t Convert_BcdToNum(uint32_t bcd);

/**
 * @brief		This function convert string to uint8_t number.
 *
 * @param[in] 	str - string that corresponds to number.
 *
 * @return 		number.
**/
uint8_t Convert_StringToUint8(const char *str);

/**
 * @brief		This function convert string to uint16_t number.
 *
 * @param[in] 	str - string that corresponds to number.
 *
 * @return 		number.
**/
uint16_t Convert_StringToUint16(const char *str);

/**
 * @brief		This function convert string to uint32_t number.
 *
 * @param[in] 	str - string that corresponds to number.
 *
 * @return 		number.
**/
uint32_t Convert_StringToUint32(const char *str);

/**
 * @brief		This function convert uint8_t number to string.
 *
 * @param[out] 	str - string that corresponds to number.
 * @param[in] 	dig - number.
 *
 * @return 		void.
**/
void Convert_DigToStringUint8(char *str, uint8_t dig);

/**
 * @brief		This function convert uint16_t number to string.
 *
 * @param[out] 	str - string that corresponds to number.
 * @param[in] 	dig - number.
 *
 * @return 		void.
**/
void Convert_DigToStringUint16(char *str, uint16_t dig);

/**
 * @brief		This function convert uint32_t number to string.
 *
 * @param[out] 	str - string that corresponds to number.
 * @param[in] 	dig - number.
 *
 * @return 		void.
**/
void Convert_DigToStringUint32(char *str, uint32_t dig);

/* C++ detection */
#ifdef __cplusplus
}
#endif
