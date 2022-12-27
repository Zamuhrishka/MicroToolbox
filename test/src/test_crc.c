/**
* \file         template.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains the prototypes functions which use for...
*/
//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include "crc.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
void test_Crc8(void)
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

	TEST_ASSERT_EQUAL_INT(crc, crcTable);
	TEST_ASSERT_EQUAL_INT(crc, crc_expected);
}

void test_Crc16(void)
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

	TEST_ASSERT_EQUAL_INT(crc, crcTable);
	TEST_ASSERT_EQUAL_INT(crc, crc_expected);
}

void test_Crc32(void)
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

	TEST_ASSERT_EQUAL_INT(crc, crcTable);
	TEST_ASSERT_EQUAL_INT(crc, crc_expected);
}