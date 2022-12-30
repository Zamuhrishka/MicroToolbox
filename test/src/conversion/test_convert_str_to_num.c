/**
* \file         test_convert_str_to_num.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains unit tests for convert string to number functions, 
*               from @conversion.c file
*/

//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "conversion.h"
#include "types.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * @brief Unit test for checking convert string to uint8_t number function.
 */
void test_ConvertStrToU8(void)
{
	uint8_t expected[] = {0, 1, 12, 123, 255};
	uint8_t current = 0;
	char* str[] = {"0", "1", "12", "123", "255"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(uint8_t); i++)
	{
		current = convert_str_to_u8(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}

/**
 * @brief Unit test for checking convert string to int8_t number function.
 */
void test_ConvertStrToI8(void)
{
	int8_t expected[] = {-127, -89, -6, 0, 3, 42, 127};
	int8_t current = 0;
	char* str[] = {"-127", "-89", "-6", "0", "3", "42", "127"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(uint8_t); i++)
	{
		current = convert_str_to_i8(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}

/**
 * @brief Unit test for checking convert string to uint16_t number function.
 */
void test_ConvertStrToU16(void)
{
	uint16_t expected[] = {0, 1, 12, 123, 1234, 65535};
	uint16_t current = 0;
	char* str[] = {"0", "1", "12", "123", "1234", "65535"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(uint16_t); i++)
	{
		current = convert_str_to_u16(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}

/**
 * @brief Unit test for checking convert string to int16_t number function.
 */
void test_ConvertStrToI16(void)
{
	uint16_t expected[] = {-32767, -1234, -123, -12, -1, 0, 1, 12, 123, 1234, 32767};
	uint16_t current = 0;
	char* str[] = {"-32767", "-1234", "-123", "-12", "-1", "0", "1", "12", "123", "1234", "32767"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(int16_t); i++)
	{
		current = convert_str_to_i16(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}

/**
 * @brief Unit test for checking convert string to uint32_t number function.
 */
void test_ConvertStrToU32(void)
{
	uint32_t expected[] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 4294967295};
	uint32_t current = 0;
	char* str[] = {"0", "1","12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "4294967295"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(uint32_t); i++)
	{
		current = convert_str_to_u32(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}

/**
 * @brief Unit test for checking convert string to int32_t number function.
 */
void test_ConvertStrToI32(void)
{
	int32_t expected[] = {-2147483647, -123456789, -12345678, -1234567, -123456, -12345, -1234, -123, -12,\
                        -1, 0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 2147483647};
	int32_t current = 0;
	char* str[] = {"-2147483647", "-123456789", "-12345678", "-1234567", "-123456", "-12345", "-1234", "-123",\
                	"-12", "-1", "0", "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678",\
                    "123456789", "2147483647"};

	for (size_t i = 0; i < sizeof(expected)/sizeof(int32_t); i++)
	{
		current = convert_str_to_i32(str[i]);
		TEST_ASSERT_EQUAL_INT(current, expected[i]);
	}
}
