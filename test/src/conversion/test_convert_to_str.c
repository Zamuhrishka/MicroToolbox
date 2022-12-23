/**
* \file         test_convert_to_bin.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains unit tests for convert_u8_to_str(), 
*               convert_i8_to_str(), convert_u16_to_str(), convert_i16_to_str()
*               convert_u32_to_str(), convert_i32_to_str() functions
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
 * @brief Unit test for checking convert uint8_t number to string.
 */
void test_ConvertU8ToStr(void)
{
	uint8_t number[] = {0, 1, 12, 123, 255};
	char current[16] = "";
	char* expected[] = {"0", "1", "12", "123", "255"};

	for (size_t i = 0; i < sizeof(number)/sizeof(uint8_t); i++)
	{
		convert_u8_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}

/**
 * @brief Unit test for checking convert int8_t number to string.
 */
void test_ConvertI8ToStr(void)
{
	uint8_t number[] = {-127, -12, -1, 0, 1, 12, 127};
	char current[16] = "";
	char* expected[] = {"-127", "-12", "-1", "0", "1", "12", "127"};

	for (size_t i = 0; i < sizeof(number)/sizeof(uint8_t); i++)
	{
		convert_i8_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}

/**
 * @brief Unit test for checking convert uint16_t number to string.
 */
void test_ConvertU16ToStr(void)
{
	uint16_t number[] = {0, 1, 12, 123, 1234, 65535};
	char current[16] = "";
	char* expected[] = {"0", "1", "12", "123", "1234", "65535"};

	for (size_t i = 0; i < sizeof(number)/sizeof(uint16_t); i++)
	{
		convert_u16_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}

/**
 * @brief Unit test for checking convert int16_t number to string.
 */
void test_ConvertI16ToStr(void)
{
	int16_t number[] = {-32767, -1234, -123, -12, -1, 0, 1, 12, 123, 1234, 32767};
	char current[16] = "";
	char* expected[] = {"-32767", "-1234", "-123", "-12", "-1", "0", "1", "12", "123", "1234", "32767"};

	for (size_t i = 0; i < sizeof(number)/sizeof(int16_t); i++)
	{
		convert_i16_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}

/**
 * @brief Unit test for checking convert uint32_t number to string.
 */
void test_ConvertU32ToStr(void)
{
	uint32_t number[] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 4294967295};
	char current[16] = "";
	char* expected[] = {"0", "1","12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "4294967295"};

	for (size_t i = 0; i < sizeof(number)/sizeof(uint32_t); i++)
	{
		convert_u32_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}

/**
 * @brief Unit test for checking convert int32_t number to string.
 */
void test_ConvertI32ToStr(void)
{
	int32_t number[] = {-2147483647, -123456789, -12345678, -1234567, -123456, -12345, -1234, -123, -12, -1, 0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 2147483647};
	char current[16] = "";
	char* expected[] = {"-2147483647", "-123456789", "-12345678", "-1234567", "-123456", "-12345", "-1234", "-123",	"-12", "-1", "0", "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "2147483647"};

	for (size_t i = 0; i < sizeof(number)/sizeof(int32_t); i++)
	{
		convert_i32_to_str(current, number[i]);		
		TEST_ASSERT_EQUAL_STRING(current, expected[i]);
		memset(current, '\0', sizeof(current));
	}
}
