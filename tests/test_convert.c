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
#include "convert.h"
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________________________
//_____ S T A T I Ñ  F U N C T I O N   D E F I N I T I O N   __________________________________
static void Test_ConvertHexNumToChar(void **state)
{
	char patternChar[] = {'0','1','2','3','4','5','6',\
						 '7','8','9',\
						 'A','B','C','D','E','F'};

	char patternNum[] = {0x00,0x01,0x02,0x03,0x04,0x05,\
						0x06,0x07,0x08,0x09,\
						0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	char num = -1;


	for(size_t i = 0; i < sizeof(patternNum); i++)
	{
		num = convert_hex_num_to_char(patternNum[i]);
		assert_int_equal(num, patternChar[i]);
	}
}


static void Test_ConvertHexCharToNum(void **state)
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


	for(size_t i = 0; i < sizeof(patternNum); i++)
	{
		num = convert_hex_char_to_num(patternChar[i]);
		assert_int_equal(num, patternNum[i]);
	}

	num = convert_hex_char_to_num('-');
	assert_int_equal(num, -1);

	num = convert_hex_char_to_num('U');
	assert_int_equal(num, -1);
}

static void Test_ConvertStringToMacAddr(void **state)
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
	assert_true(result);
	assert_memory_equal(patternMacAddr.value, mac.value, sizeof(patternMacAddr.value));

	result = convert_string_to_mac_addr(patternMacAddrStr2, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(patternMacAddrStr3, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(patternMacAddrStr4, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(patternMacAddrStr5, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(patternMacAddrStr6, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(NULL, &mac);
	assert_false(result);

	result = convert_string_to_mac_addr(patternMacAddrStr1, NULL);
	assert_false(result);
}

static void Test_ConvertMacAddrToString(void **state)
{
	bool result = false;

	mac_t patternMacAddr = {0xAA, 0x13, 0x01, 0x00, 0x55, 0xFE};
	char patternMacAddrStr[] = "AA:13:01:00:55:FE\0";
	char mac[] = "00:00:00:00:00:00\0";

	result = convert_mac_addr_to_string(&patternMacAddr, mac);
	assert_true(result);
	assert_string_equal(mac, patternMacAddrStr);
}

static void Test_ConvertIpv4addrToString(void **state)
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
	assert_true(result);
	assert_string_equal(ip, patternIpAddrStr1);

	result = convert_ip4addr_to_string(ipAddr2, ip);
	assert_true(result);
	assert_string_equal(ip, patternIpAddrStr2);

	result = convert_ip4addr_to_string(ipAddr3, ip);
	assert_true(result);
	assert_string_equal(ip, patternIpAddrStr3);
}

static void Test_ConvertStringToIpv4addr(void **state)
{
	bool result = false;
	ip4addr_t ipAddr1 = 0xFA0A0A0A;
	ip4addr_t ip = 0;
	char patternIpAddrStr1[] = "10.10.10.250\0";

	result = convert_string_to_ip4addr(&ip, patternIpAddrStr1);
	assert_true(result);
	assert_int_equal(ip, ipAddr1);
}

static void Test_ConvertNumToBcd(void **state)
{
	uint32_t patternNum[] = {0,1,10,15,53,124};
	uint32_t patternBCD[] = {0,1,16,21,83,292};
	uint32_t bcd = 0;

	for(size_t i = 0; i < sizeof(patternNum)/sizeof(uint32_t); i++)
	{
		bcd = convert_num_to_bcd(patternNum[i]);
		assert_int_equal(bcd, patternBCD[i]);
	}
}

static void Test_ConvertBcdToNum(void **state)
{
	uint32_t patternNum[] = {0,1,10,15,53,124};
	uint32_t patternBCD[] = {0,1,16,21,83,292};
	uint32_t dec = 0;

	for(size_t i = 0; i < sizeof(patternNum)/sizeof(uint32_t); i++)
	{
		dec = convert_bcd_to_num(patternBCD[i]);
		assert_int_equal(dec, patternNum[i]);
	}
}

static void Test_ConvertStringToNum8(void **state)
{
	uint8_t testNum = 0;
	uint8_t patternNum = 0;
	char strDigit[] = "000";

	for(size_t i = 0; i < 3; i++)
	{
		for(size_t j = 0; j <= 9; j++)
		{
			for(size_t k = 0; k <= 9; k++)
			{
				testNum = convert_string_to_uint8(strDigit);
				assert_int_equal(testNum, patternNum);
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

static void Test_ConvertStringToNum16(void **state)
{
	uint16_t testNum = 0;
	uint16_t patternNum = 0;
	char strDigit[] = "00000";

	for(size_t i = 0; i < 9; i++)
	{
		for(size_t j = 0; j <= 9; j++)
		{
			for(size_t k = 0; k <= 9; k++)
			{
				for(size_t p = 0; p <= 9; p++)
				{
					for(size_t e = 0; e <= 9; e++)
					{
						testNum = convert_string_to_uint16(strDigit);
						assert_int_equal(testNum, patternNum);
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

static void Test_ConvertDigToStringUint8(void **state)
{
	char strDigit[] = "000\0";
	char digit[] = "000\0";

	for(size_t i = 0; i < 9; i++)
	{
		convert_uint8_to_string(strDigit, i);
		assert_string_equal(digit, strDigit);
		digit[0]++;
	}

	strDigit[0] = '1';
	digit[0] = '1';
	digit[1] = '0';
	digit[2] = '0';
	for(size_t i = 10; i < 19; i++)
	{
		convert_uint8_to_string(strDigit, i);
		assert_string_equal(digit, strDigit);
		digit[1]++;
	}

	strDigit[0] = '1';
	strDigit[1] = '0';
	digit[0] = '1';
	digit[1] = '0';
	digit[2] = '0';
	for(size_t i = 100; i < 109; i++)
	{
		convert_uint8_to_string(strDigit, i);
		assert_string_equal(digit, strDigit);
		digit[2]++;
	}

}

//_____ F U N C T I O N   D E F I N I T I O N   _______________________________________________
void Test_Convert(void)
{
	  const UnitTest tests[] =
	  {
		  unit_test(Test_ConvertHexCharToNum),
		  unit_test(Test_ConvertStringToMacAddr),
		  unit_test(Test_ConvertHexNumToChar),
		  unit_test(Test_ConvertMacAddrToString),
		  unit_test(Test_ConvertIpv4addrToString),
		  unit_test(Test_ConvertStringToIpv4addr),
		  unit_test(Test_ConvertNumToBcd),
		  unit_test(Test_ConvertBcdToNum),
		  unit_test(Test_ConvertStringToNum8),
		  unit_test(Test_ConvertStringToNum16),
		  unit_test(Test_ConvertDigToStringUint8),
	  };

	  run_tests(tests);
}
