/**
 * @file    test_convert_hex_char.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for convert HEX number to char and 
 *          vice versa functions from @conversion.c file
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
 * @brief Unit test for convert valid hex number to char function.
 */
void test_ConvertHexNumToChar_Valid(void)
{
	char expected[] = {'0','1','2','3','4','5','6','7','8','9',\
						 'A','B','C','D','E','F'};

	char actual[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};

	for(size_t i = 0; i < sizeof(actual); i++)
	{
		char num = convert_hex_num_to_char(actual[i]);
		TEST_ASSERT_EQUAL_INT(num, expected[i]);
	}
}

/**
 * @brief Unit test for convert invalid hex number to char function.
 */
void test_ConvertHexNumToChar_Invalid(void)
{
	char num = convert_hex_num_to_char(0x10);
	TEST_ASSERT_EQUAL_INT(num, ' ');

	num = convert_hex_num_to_char(0xFF);
	TEST_ASSERT_EQUAL_INT(num, ' ');
}

/**
 * @brief Unit test for convert valid hex char to number function.
 */
void test_ConvertHexCharToNum_Valid(void)
{
	char actual[] = {'0','1','2','3','4','5','6',\
						 '7','8','9',\
						 'A','B','C','D','E','F',\
						 'a','b','c','d','e','f',};

	char expected[] = {0x00,0x01,0x02,0x03,0x04,0x05,\
						0x06,0x07,0x08,0x09,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};

	for(size_t i = 0; i < sizeof(actual); i++)
	{
		uint8_t num = convert_hex_char_to_num(actual[i]);
		TEST_ASSERT_EQUAL_INT(num, expected[i]);
	}
}

/**
 * @brief Unit test for convert invalid hex char to number function.
 */
void test_ConvertHexCharToNum_Invalid(void)
{
	uint8_t num = convert_hex_char_to_num('-');
	TEST_ASSERT_EQUAL_INT(num, 0xFF);

	num = convert_hex_char_to_num('U');
	TEST_ASSERT_EQUAL_INT(num, 0xFF);
}
