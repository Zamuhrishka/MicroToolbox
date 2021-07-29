// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/**********************************************************************************************
* @file    		test_convert.c
* @author  		Kovalchuk Alexander aka mz4
* @email 		roux@yandex.ru
* @brief		Functions for testing dfifo library.
***********************************************************************************************/
//_____ I N C L U D E S _______________________________________________________________________
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cmockery.h"
#include "crc.h"
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________________________
//_____ S T A T I Ñ  F U N C T I O N   D E F I N I T I O N   __________________________________
static void Test_Crc8(void **state)
{
	uint8_t data[256] = {};
	uint8_t crc = 0;
	uint8_t crcTable = 0;
	uint8_t crc_expected = 0x14;

	for(size_t i = 0; i < sizeof(data); i++) {
		data[i] = i;
	}

	crc = crc8(data, sizeof(data));
	crcTable = crc8_table(data, sizeof(data));

	assert_int_equal(crc, crcTable);
	assert_int_equal(crc, crc_expected);
}

static void Test_Crc16(void **state)
{
	uint8_t data[256] = {};
	uint16_t crc = 0;
	uint16_t crcTable = 0;
	uint16_t crc_expected = 0x3fbd;

	for(size_t i = 0; i < sizeof(data); i++) {
		data[i] = i;
	}

	crc = crc16(data, sizeof(data));
	crcTable = crc16_table(data, sizeof(data));

	assert_int_equal(crc, crcTable);
	assert_int_equal(crc, crc_expected);
}

static void Test_Crc32(void **state)
{
	uint8_t data[256] = {};
	uint32_t crc = 0;
	uint32_t crcTable = 0;
	uint32_t crc_expected = 0x29058C73;

	for(size_t i = 0; i < sizeof(data); i++) {
		data[i] = i;
	}

	crc = crc32(data, sizeof(data));
	crcTable = crc32_table(data, sizeof(data));

	assert_int_equal(crc, crcTable);
	assert_int_equal(crc, crc_expected);
}
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________________________
void Test_Crc(void)
{
	  const UnitTest tests[] =
	  {
		  unit_test(Test_Crc8),
		  unit_test(Test_Crc16),
		  unit_test(Test_Crc32),
	  };

	  run_tests(tests);
}
