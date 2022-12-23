/**
 * @file    test_convert_mac.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for convert MAC to string and 
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
 * @brief Unit test for convert sting of valid MAC to mac_t type.
 */
void test_ConvertStringToMacAddr_Valid(void)
{
	mac_t expected = {0xAA, 0x13, 0x01, 0x00, 0x55, 0xFE};	
	char actual[] = "AA:13:01:00:55:FE";
	mac_t mac = {};

	bool result = convert_string_to_mac_addr(actual, &mac);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_MEMORY(expected.value, mac.value, sizeof(expected.value));	
}

/**
 * @brief Unit test for convert sting of invalid MAC to mac_t type.
 */
void test_ConvertStringToMacAddr_Invalid(void)
{
	mac_t mac = {};
	char patternMacAddrStr2[] = "AA!13,01600:55:FE";
	char patternMacAddrStr3[] = "PA:13:l1:00:55:FE";
	char patternMacAddrStr4[] = "It`s not a MAC address";
	char patternMacAddrStr5[] = "AA13010055FE";
	char patternMacAddrStr6[] = "";

	bool result = convert_string_to_mac_addr(patternMacAddrStr2, &mac);
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
}

/**
 * @brief Unit test for convert mac_t type to sting.
 */
void test_ConvertMacAddrToString(void)
{
	mac_t patternMacAddr = {0xAA, 0x13, 0x01, 0x00, 0x55, 0xFE};
	char patternMacAddrStr[] = "AA:13:01:00:55:FE";
	char mac[] = "00:00:00:00:00:00";

	bool result = convert_mac_addr_to_string(&patternMacAddr, mac);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING(mac, patternMacAddrStr);
}
