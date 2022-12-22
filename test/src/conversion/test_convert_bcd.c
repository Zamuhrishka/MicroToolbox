/**
 * @file    test_convert_bcd.c
 * @author  Aleksander Kovalchuk (roux@yandex.ru)
 * @brief   This file contains unit tests for convert BCD functions
 *          from @conversion.c file
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
 * @brief Unit test for encode number to BCD.
 */
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

/**
 * @brief Unit test for decode BCD.
 */
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

