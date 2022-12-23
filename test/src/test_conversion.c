/**
* \file         template.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
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


void test_ConvertStringToMacAddr(void)
{
	bool result = false;

	mac_t patternMacAddr = {0xAA, 0x13, 0x01, 0x00, 0x55, 0xFE};
	mac_t mac = {0};

	char patternMacAddrStr1[] = "AA:13:01:00:55:FE\0";
	char patternMacAddrStr2[] = "AA!13,01600:55:FE\0";
	char patternMacAddrStr3[] = "PA:13:l1:00:55:FE\0";
	char patternMacAddrStr4[] = "It`s not a MAC address\0";
	char patternMacAddrStr5[] = "AA13010055FE\0";
	char patternMacAddrStr6[] = "";

	result = convert_string_to_mac_addr(patternMacAddrStr1, &mac);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_MEMORY(patternMacAddr.value, mac.value, sizeof(patternMacAddr.value));

	result = convert_string_to_mac_addr(patternMacAddrStr2, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(patternMacAddrStr3, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(patternMacAddrStr4, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(patternMacAddrStr5, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(patternMacAddrStr6, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(NULL, &mac);
	TEST_ASSERT_FALSE(result);

	result = convert_string_to_mac_addr(patternMacAddrStr1, NULL);
	TEST_ASSERT_FALSE(result);
}

void test_ConvertMacAddrToString(void)
{
	bool result = false;

	mac_t patternMacAddr = {0xAA, 0x13, 0x01, 0x00, 0x55, 0xFE};
	char patternMacAddrStr[] = "AA:13:01:00:55:FE\0";
	char mac[] = "00:00:00:00:00:00\0";

	result = convert_mac_addr_to_string(&patternMacAddr, mac);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING(mac, patternMacAddrStr);
}
