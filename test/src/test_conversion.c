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
void test_ConvertHexNumToChar(void)
{
	char patternChar[] = {'0','1','2','3','4','5','6',\
						 '7','8','9',\
						 'A','B','C','D','E','F'};

	char patternNum[] = {0x00,0x01,0x02,0x03,0x04,0x05,\
						0x06,0x07,0x08,0x09,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	char num = -1;

    size_t i = 0;
	for(i = 0; i < sizeof(patternNum); i++)
	{
		num = convert_hex_num_to_char(patternNum[i]);
		TEST_ASSERT_EQUAL_INT(num, patternChar[i]);
	}
}


void test_ConvertHexCharToNum(void)
{
	char patternChar[] = {'0','1','2','3','4','5','6',\
						 '7','8','9',\
						 'A','B','C','D','E','F',\
						 'a','b','c','d','e','f',};

	char patternNum[] = {0x00,0x01,0x02,0x03,0x04,0x05,\
						0x06,0x07,0x08,0x09,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	int8_t num = -1;

    size_t i = 0;
	for(i = 0; i < sizeof(patternNum); i++)
	{
		num = convert_hex_char_to_num(patternChar[i]);
		TEST_ASSERT_EQUAL_INT(num, patternNum[i]);
	}

	num = convert_hex_char_to_num('-');
	TEST_ASSERT_EQUAL_INT(num, -1);

	num = convert_hex_char_to_num('U');
	TEST_ASSERT_EQUAL_INT(num, -1);
}

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

void test_ConvertIpv4addrToString(void)
{
	bool result = false;
	ip4addr_t ipAddr1 = 0xFA0A0A0A;
	ip4addr_t ipAddr2 = 0x00;
	ip4addr_t ipAddr3 = 0xFFFFFFFF;

	char patternIpAddrStr1[] = "10.10.10.250\0";
	char patternIpAddrStr2[] = "0.0.0.0\0";
	char patternIpAddrStr3[] = "255.255.255.255\0";
	char ip[] = "000.000.000.000\0";

	result = convert_ip4addr_to_string(ipAddr1, ip);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING(ip, patternIpAddrStr1);

	result = convert_ip4addr_to_string(ipAddr2, ip);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING(ip, patternIpAddrStr2);

	result = convert_ip4addr_to_string(ipAddr3, ip);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING(ip, patternIpAddrStr3);
}

void test_ConvertStringToIpv4addr(void)
{
	bool result = false;
	ip4addr_t ipAddr1 = 0xFA0A0A0A;
	ip4addr_t ip = 0;
	char patternIpAddrStr1[] = "10.10.10.250\0";

	result = convert_string_to_ip4addr(&ip, patternIpAddrStr1);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_INT(ip, ipAddr1);
}

void test_ConvertNumToBcd(void)
{
	uint32_t patternNum[] = {0,1,10,15,53,124};
	uint32_t patternBCD[] = {0,1,16,21,83,292};
	uint32_t bcd = 0;

    size_t i = 0;
	for(i = 0; i < sizeof(patternNum)/sizeof(uint32_t); i++)
	{
		bcd = convert_num_to_bcd(patternNum[i]);
		TEST_ASSERT_EQUAL_INT(bcd, patternBCD[i]);
	}
}

void test_ConvertBcdToNum(void)
{
	uint32_t patternNum[] = {0,1,10,15,53,124};
	uint32_t patternBCD[] = {0,1,16,21,83,292};
	uint32_t dec = 0;

    size_t i = 0;
	for(i = 0; i < sizeof(patternNum)/sizeof(uint32_t); i++)
	{
		dec = convert_bcd_to_num(patternBCD[i]);
		TEST_ASSERT_EQUAL_INT(dec, patternNum[i]);
	}
}

void test_ConvertStringToNum8(void)
{
	uint8_t testNum = 0;
	uint8_t patternNum = 0;
	char strDigit[] = "000";
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j <= 9; j++)
		{
			for(k = 0; k <= 9; k++)
			{
				testNum = convert_string_to_uint8(strDigit);
				TEST_ASSERT_EQUAL_INT(testNum, patternNum);
				patternNum++;
				strDigit[2]++;
			}
			strDigit[2] = '0';
			strDigit[1]++;
		}

		strDigit[0]++;
		strDigit[1] = '0';
	}
}

void test_ConvertStringToNum16(void)
{
	uint16_t testNum = 0;
	uint16_t patternNum = 0;
	char strDigit[] = "00000";
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t p = 0;
    size_t e = 0;
    
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j <= 9; j++)
		{
			for(k = 0; k <= 9; k++)
			{
				for(p = 0; p <= 9; p++)
				{
					for(e = 0; e <= 9; e++)
					{
						testNum = convert_string_to_uint16(strDigit);
						TEST_ASSERT_EQUAL_INT(testNum, patternNum);
						patternNum++;
						strDigit[4]++;
					}
					strDigit[4] = '0';
					strDigit[3]++;
				}
				strDigit[3] = '0';
				strDigit[2]++;
			}
			strDigit[2] = '0';
			strDigit[1]++;
		}
		strDigit[1] = '0';
		strDigit[0]++;
	}
}
