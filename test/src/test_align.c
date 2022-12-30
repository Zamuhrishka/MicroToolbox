/**
 * @file    test_align.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for align functions
 *          from @align.c file
 */
//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "align.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * @brief Unit test for check number for valid byte align.
 */
void test_IsByteAlign(void)
{
	uintptr_t pointer[] = {0x2000, 0x2001, 0x2002, 0x2003, 0x2004};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_TRUE(is_align(pointer[i], sizeof(uint8_t)));
	}	
}

/**
 * @brief Unit test for check number for valid 2 bytes align.
 */
void test_IsTwoBytesAlign(void)
{
	uintptr_t pointer[] = {0x2000, 0x2002, 0x2004};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_TRUE(is_align(pointer[i], sizeof(uint16_t)));
	}	
}

/**
 * @brief Unit test for check number for valid 4 bytes align.
 */
void test_IsFourBytesAlign(void)
{
	uintptr_t pointer[] = {0x2000, 0x2004, 0x2008};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_TRUE(is_align(pointer[i], sizeof(uint32_t)));
	}	
}

/**
 * @brief Unit test for check number for valid 8 bytes align.
 */
void test_IsEightBytesAlign(void)
{
	uintptr_t pointer[] = {0x2000, 0x2008, 0x2010};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_TRUE(is_align(pointer[i], sizeof(uint64_t)));
	}
}

/**
 * @brief Unit test for check number for invalid 2 bytes align.
 */
void test_IsTwoBytesNotAlign(void)
{
	uintptr_t pointer[] = {0x2001, 0x2003, 0x2005};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_FALSE(is_align(pointer[i], sizeof(uint16_t)));
	}
}

/**
 * @brief Unit test for check number for invalid 4 bytes align.
 */
void test_IsFourBytesNotAlign(void)
{
	uintptr_t pointer[] = {0x2002, 0x2003, 0x2005};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_FALSE(is_align(pointer[i], sizeof(uint32_t)));
	}	
}

/**
 * @brief Unit test for check number for invalid 8 bytes align.
 */
void test_IsEightBytesNotAlign(void)
{
	uintptr_t pointer[] = {0x2002, 0x2003, 0x2005};
	
	for (size_t i = 0; i < sizeof(pointer)/sizeof(uintptr_t); i++)
	{
		TEST_ASSERT_FALSE(is_align(pointer[i], sizeof(uint64_t)));
	}
}

/**
 * @brief Unit test for 2 byte align down function.
 */
void test_AlignDownTwoBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002};
	uintptr_t expected[] = 	{0x2000, 0x2000, 0x2002};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_down(addr[i], sizeof(uint16_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}

/**
 * @brief Unit test for 4 byte align down function.
 */
void test_AlignDownFourBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002, 0x2003, 0x2004};
	uintptr_t expected[] = 	{0x2000, 0x2000, 0x2000, 0x2000, 0x2004};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_down(addr[i], sizeof(uint32_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}

/**
 * @brief Unit test for 8 byte align down function.
 */
void test_AlignDownEightBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2007, 0x2008};
	uintptr_t expected[] = 	{0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2008};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_down(addr[i], sizeof(uint64_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}

/**
 * @brief Unit test for 2 byte align up function.
 */
void test_AlignUpTwoBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002, 0x2003};
	uintptr_t expected[] = 	{0x2000, 0x2002, 0x2002, 0x2004};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_up(addr[i], sizeof(uint16_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}

/**
 * @brief Unit test for 4 byte align up function.
 */
void test_AlignUpFourBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005};
	uintptr_t expected[] = 	{0x2000, 0x2004, 0x2004, 0x2004, 0x2004, 0x2008};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_up(addr[i], sizeof(uint32_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}

/**
 * @brief Unit test for 8 byte align up function.
 */
void test_AlignUpEightBytes(void)
{
	uintptr_t addr[] = 		{0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2007, 0x2008, 0x2009};
	uintptr_t expected[] = 	{0x2000, 0x2008, 0x2008, 0x2008, 0x2008, 0x2008, 0x2008, 0x2008, 0x2008, 0x2010};
	
	for (size_t i = 0; i < sizeof(addr)/sizeof(uintptr_t); i++)
	{
		uintptr_t current_value = align_up(addr[i], sizeof(uint64_t));
		TEST_ASSERT_EQUAL_UINT(current_value, expected[i]);
	}	
}