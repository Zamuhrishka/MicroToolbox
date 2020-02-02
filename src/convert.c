// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/********************************************************************************
*
* @file    		convert.c
* @author  		Kovalchuk Alexander
* @email  		roux@yandex.ru
* @brief   		This file contains the prototypes functions for different types
* 				of transformations.
*
********************************************************************************/
//_____ I N C L U D E S _______________________________________________________
#include "convert.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
//! @brief Size in bits
//! @{
enum Constants
{
	U8B		=		0,
	U16B	=		1,
	U32B	=		2,
};
//! @}

//! Max decimal counts in digit
#define MAX_DECIMAL_COUNT		10
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E _______________________________________________________
//_____ I N L I N E   F U N C T I O N _________________________________________
//_____ S T A T I C  F U N C T I O N  _________________________________________
static inline bool test_char_digit(const unsigned char c)
{
	return ((c & '0') == '0') && (((c & 0x0F) >= 0) && ((c & 0x0F) <= 9));
}

static inline uint8_t count_num(uint32_t dig, uint8_t f_n_bit)
{
	uint8_t num = 0;

	if(f_n_bit == U8B)
	{
		if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	else if(f_n_bit == U16B)
	{
		if( (dig / 10000) != 0)
			num = 5;
		else if( (dig / 1000) != 0)
			num = 4;
		else if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	else if(f_n_bit == U32B)
	{
		if( (dig / 1000000000) != 0)
			num = 10;
		else if( (dig / 100000000) != 0)
			num = 9;
		else if( (dig / 10000000) != 0)
			num = 8;
		else if( (dig / 1000000) != 0)
			num = 7;
		else if( (dig / 100000) != 0)
			num = 6;
		else if( (dig / 10000) != 0)
			num = 5;
		else if( (dig / 1000) != 0)
			num = 4;
		else if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	return(num);
}

static inline uint8_t string_digit_num_count(const char* dig)
{
	uint8_t num = 0;
	bool digit = 0;

	digit = test_char_digit(dig[num]);
	while(digit && num < MAX_DECIMAL_COUNT)
	{
		num++;
		digit = test_char_digit(dig[num]);
	}

	return num;
}
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
/**
* This function used to convert hex char to digit.
*
* Public function defined in convert.h
*/
int8_t convert_hex_char_to_num(char c)
{
	if(c >= '0' && c <= '9')
		return (c - '0');

	if(c >= 'A' && c <= 'F')
		return (10 + c - 'A');

	if(c >= 'a' && c <= 'f')
		return (10 + c - 'a');

	return (-1);
}

/**
* This function used to convert digit to hex char.
*
* Public function defined in convert.h
*/
char convert_hex_num_to_char(uint8_t num)
{
	if(num >= 0 && num <= 9)
		return (num + '0');

	if(num >= 0x0A && num <= 0x0F)
		return (num - 10 + 'A');

	return (-1);
}

/**
* This function used to convert string to MAC address.
*
* Public function defined in convert.h
*/
bool convert_string_to_mac_addr(const char *str, mac_t *macAddr)
{
	int8_t numLowPart = -1;
	int8_t numHighPart = -1;
	uint8_t offsetLowPart = 1;
	uint8_t offsetHighPart = 0;

	if(str == NULL || macAddr == NULL) {
		return false;
	}

	if(str[2] != ':' || str[5] != ':' ||
	   str[8] != ':' || str[11] != ':' ||
	   str[14] != ':')
	{
		return false;
	}

	for(size_t i = 0; i < sizeof(macAddr->value); i++)
	{
		numHighPart = convert_hex_char_to_num(str[offsetHighPart]);
		numLowPart = convert_hex_char_to_num(str[offsetLowPart]);

		if(numHighPart == (-1) || numLowPart == (-1)) {
			return false;
		}

		macAddr->value[i] = (numHighPart << 4) | numLowPart;

		offsetHighPart += 3;
		offsetLowPart += 3;
	}

	return true;
}

/**
* This function used to convert MAC address to string.
*
* Public function defined in convert.h
*/
bool convert_mac_addr_to_string(const mac_t *macAddr, char *string)
{
	char numLowPart = -1;
	char numHighPart = -1;
	uint8_t offsetLowPart = 1;
	uint8_t offsetHighPart = 0;
	char _mac[] = "00:00:00:00:00:00\0";

	if(string == NULL || macAddr == NULL) {
		return false;
	}

	for(size_t i = 0; i < sizeof(macAddr->value); i++)
	{
		numHighPart = convert_hex_num_to_char((macAddr->value[i] >> 4) & 0x0F);
		numLowPart = convert_hex_num_to_char(macAddr->value[i] & 0x0F);

		if(numHighPart == (-1) || numLowPart == (-1)) {
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
* This function used to convert IP address to string.
*
* Public function defined in convert.h
*/
bool convert_ip4addr_to_string(ip4addr_t ipAddr, char *ip)
{
	uint8_t *p;

	if(ip == NULL) {
		return false;
	}

   p = (uint8_t *) &ipAddr;
   sprintf(ip, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);

   return true;
}

/**
* This function used to convert string to IP address.
*
* Public function defined in convert.h
*/
bool convert_string_to_ip4addr(ip4addr_t *ipAddr, const char *ip)
{
	int ip1, ip2, ip3, ip4;
	ip4addr_t _ip = 0;

	if(ip == NULL || ipAddr == NULL) {
		return false;
	}

	if(sscanf(ip, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4) != 4) {
		return false;
	}

	_ip |= ip4;
	_ip <<= 8;
	_ip |= ip3;
	_ip <<= 8;
	_ip |= ip2;
	_ip <<= 8;
	_ip |= ip1;

	*ipAddr = _ip;

	return true;
}

/**
* This function used to decode BCD number.
*
* Public function defined in convert.h
*/
uint32_t convert_bcd_to_num(bcd_t bcd)
{
	uint32_t dec = 0;

	for (uint32_t mult = 1 ; bcd ; bcd = bcd >> 4)
	{
		dec += (bcd & 0x0f) * mult;
		mult *= 10;
	}

	return dec;
}

/**
* This function used to code BCD number.
*
* Public function defined in convert.h
*/
bcd_t convert_num_to_bcd(uint32_t dec)
{
	bcd_t bcd = 0;
	uint32_t i = 0;

	while (dec > 0)
	{
		bcd =  bcd | ((dec - (dec / 10) * 10) << (i * 4));
		i++;
		dec /= 10;
	}

	return bcd;
}

/**
* This function used to convert string to uint8_t number.
*
* Public function defined in convert.h
*/
uint8_t convert_string_to_uint8(const char *str)
{
	uint8_t dig;
	uint8_t num = 0;

	if(str == NULL) {
		return 0;
	}

	num = string_digit_num_count(str);

	switch(num)
	{
		case 1:
			dig = (str[0] - '0');
			break;
		case 2:
			dig = (str[0] - '0') * 10 + (str[1] - '0');
			break;
		case 3:
			dig = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0');
			break;
		default:
			dig = (-1);
			break;
	}
	return(dig);
}

/**
* This function used to convert string to uint16_t number.
*
* Public function defined in convert.h
*/
uint16_t convert_string_to_uint16(const char *str)
{
	uint16_t dig;
	uint8_t num = 0;

	if(str == NULL) {
		return 0;
	}

	num = string_digit_num_count(str);

	switch(num)
	{
		case 1:
			dig = (str[0] - '0');
			break;
		case 2:
			dig = (str[0] - '0')*10 + (str[1] - '0');
			break;
		case 3:
			dig = (str[0] - '0')*100 + (str[1] - '0')*10 + (str[2] - '0');
			break;
		case 4:
			dig = (str[0] - '0')*1000 + (str[1] - '0')*100 + (str[2] - '0')*10 + (str[3] - '0');
			break;
		case 5:
			dig = (str[0] - '0')*10000 + (str[1] - '0')*1000 + (str[2] - '0')*100 + (str[3] - '0')*10 + (str[4] - '0');
			break;
		default:
			dig = (-1);
			break;
	}
	return(dig);
}

/**
* This function used to convert string to uint32_t number.
*
* Public function defined in convert.h
*/
uint32_t convert_string_to_uint32(const char *str)
{
	uint32_t dig;
	uint8_t num = 0;

	if(str == NULL) {
		return 0;
	}

	num = string_digit_num_count(str);

	switch(num)
	{
		case 1:
			dig = (str[0] - '0');
			break;
		case 2:
			dig = (str[0] - '0')*10 + (str[1] - '0');
			break;
		case 3:
			dig = (str[0] - '0')*100 + (str[1] - '0')*10 + (str[2] - '0');
			break;
		case 4:
			dig = (str[0] - '0')*1000 + (str[1] - '0')*100 + (str[2] - '0')*10 + (str[3] - '0');
			break;
		case 5:
			dig = (str[0] - '0')*10000 + (str[1] - '0')*1000 + (str[2] - '0')*100 + (str[3] - '0')*10 + (str[4] - '0');
			break;
		case 6:
			dig = (str[0] - '0')*100000 + (str[1] - '0')*10000 + (str[2] - '0')*1000 + (str[3] - '0')*100 + (str[4] - '0')*10
		        + (str[5] - '0');
			break;
		case 7:
			dig = (str[0] - '0')*1000000 + (str[1] - '0')*100000 + (str[2] - '0')*10000 + (str[3] - '0')*1000 + (str[4] - '0')*100
		        + (str[5] - '0')*10 + (str[6] - '0');
			break;
		case 8:
			dig = (str[0] - '0')*10000000 + (str[1] - '0')*1000000 + (str[2] - '0')*100000 + (str[3] - '0')*10000 + (str[4] - '0')*1000
		        + (str[5] - '0')*100 + (str[6] - '0')*10 + (str[7] - '0');
			break;
		case 9:
			dig = (str[0] - '0')*100000000 + (str[1] - '0')*10000000 + (str[2] - '0')*1000000 + (str[3] - '0')*100000 + (str[4] - '0')*10000
		        + (str[5] - '0')*1000 + (str[6] - '0')*100 + (str[7] - '0')*10 + (str[8] - '0');
			break;
		case 10:
			dig = (str[0] - '0')*1000000000 + (str[1] - '0')*100000000 + (str[2] - '0')*10000000 + (str[3] - '0')*1000000 + (str[4] - '0')*100000
		        + (str[5] - '0')*10000 + (str[6] - '0')*1000 + (str[7] - '0')*100 + (str[8] - '0')*10 + (str[9] - '0');
			break;
		default:
			dig = (-1);
			break;
	}
	return(dig);
}

/**
* This function used to convert uint8_t number to string.
*
* Public function defined in convert.h
*/
void convert_uint8_to_string(char *str, uint8_t dig)
{
	uint8_t num = 0;

	num = count_num(dig, U8B);

	switch(num)
	{
		case 1:
			str[0] = (dig % 10) + '0';
			break;
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

/**
* This function used to convert uint16_t number to string.
*
* Public function defined in convert.h
*/
void convert_uint16_to_string(char *str, uint16_t dig)
{
	uint8_t num = 0;

	num = count_num(dig, U16B);

	switch(num)
	{
		case 1:
			str[0] = (dig % 10) + '0';
			break;
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

/**
* This function used to convert uint32_t number to string.
*
* Public function defined in convert.h
*/
void convert_uint32_to_string(char *str, uint32_t dig)
{
	uint8_t num = 0;

	num = count_num(dig, U32B);

	switch(num)
	{
		case 1:
			str[0] = (dig % 10) + '0';
			break;
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


float Utils_Round(float val, float rval)
{
    val /= rval;
    if (val <0 )
    {
        val -= 0.5;
        val = ceil(val);
    }
    else
    {
        val += 0.5;
        val = floor(val);
    }
    return (val*rval);
}

