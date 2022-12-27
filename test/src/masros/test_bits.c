/**
 * @file    test_bits.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for bits operations from
 * 			macros/bits.h file
 */

//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "macros/bits.h"
//_____ C O N F I G S  ________________________________________________________

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________

//_____ V A R I A B L E S _____________________________________________________

//_____ P R I V A T E  F U N C T I O N S_______________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * @brief Unit test for set bit in uint8_t
 */
void test_SetBitsInU8(void)
{
	uint8_t actual = 0;

	for (size_t i = 0; i < 8; i++)
	{
		SET_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);	
	}
}

/**
 * @brief Unit test for set bit in uint16_t
 */
void test_SetBitsInU16(void)
{
	uint16_t actual = 0;

	for (size_t i = 0; i < 16; i++)
	{
		SET_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);		
	}
}

/**
 * @brief Unit test for set bit in uint32_t
 */
void test_SetBitsInU32(void)
{
	uint32_t actual = 0;

	for (size_t i = 0; i < 32; i++)
	{
		SET_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);		
	}	
}

/**
 * @brief Unit test for clear bit in uint8_t
 */
void test_ClearBitsInU8(void)
{
	uint8_t actual = 0xFF;

	for (size_t i = 0; i < 8; i++)
	{
		CLEAR_BIT(actual, i);
		TEST_ASSERT_BIT_LOW(i, actual);		
	}
}

/**
 * @brief Unit test for clear bit in uint16_t
 */
void test_ClearBitsInU16(void)
{
	uint16_t actual = 0xFFFF;

	for (size_t i = 0; i < 16; i++)
	{
		CLEAR_BIT(actual, i);
		TEST_ASSERT_BIT_LOW(i, actual);		
	}
}

/**
 * @brief Unit test for clear bit in uint32_t
 */
void test_ClearBitsInU32(void)
{
	uint32_t actual = 0xFFFFFFFF;

	for (size_t i = 0; i < 32; i++)
	{
		CLEAR_BIT(actual, i);
		TEST_ASSERT_BIT_LOW(i, actual);		
	}	
}

/**
 * @brief Unit test for toggle bit in uint8_t
 */
void test_ToggleBitsInU8(void)
{
	uint8_t actual = 0;

	for (size_t i = 0; i < 8; i++)
	{
		TOGGLE_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);	
        TOGGLE_BIT(actual, i);
        TEST_ASSERT_BIT_LOW(i, actual);
	}
}

/**
 * @brief Unit test for toggle bit in uint16_t
 */
void test_ToggleBitsInU16(void)
{
	uint16_t actual = 0;

	for (size_t i = 0; i < 16; i++)
	{
		TOGGLE_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);
        TOGGLE_BIT(actual, i);
        TEST_ASSERT_BIT_LOW(i, actual);		
	}
}

/**
 * @brief Unit test for toggle bit in uint32_t
 */
void test_ToggleBitsInU32(void)
{
	uint32_t actual = 0;

	for (size_t i = 0; i < 32; i++)
	{
		TOGGLE_BIT(actual, i);
		TEST_ASSERT_BIT_HIGH(i, actual);
        TOGGLE_BIT(actual, i);
        TEST_ASSERT_BIT_LOW(i, actual);		
	}
}

/**
 * @brief Unit test for test bit in uint32_t
 */
void test_TestBits(void)
{
	uint32_t test = 0;

	for (size_t i = 0; i < 32; i++)
	{
		SET_BIT(test, i);
		TEST_ASSERT_TRUE(TEST_BIT(test, i));	
        CLEAR_BIT(test, i);
        TEST_ASSERT_FALSE(TEST_BIT(test, i));
	}
}

/**
 * @brief Unit test for creates a mask macro
 */
void test_Bitfield(void)
{
	TEST_ASSERT_EQUAL_UINT(0x00FF0000, MAKE_BITFIELD(23,16));
	TEST_ASSERT_EQUAL_UINT(0xFFFF0000, MAKE_BITFIELD(31,16));
	TEST_ASSERT_EQUAL_UINT(0x0000000F, MAKE_BITFIELD(3,0));
}

/**
 * @brief Unit test for number of bits calculation macro
 */
void test_NumBits(void)
{
	TEST_ASSERT_EQUAL_UINT(8, NUM_BITS(uint8_t));
	TEST_ASSERT_EQUAL_UINT(16, NUM_BITS(uint16_t));
	TEST_ASSERT_EQUAL_UINT(32, NUM_BITS(uint32_t));
}

/**
 * @brief Unit test for isolate the rightmost 1-bit macro
 */
void test_LSO(void)
{
	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, LSO(0b0010011001010001));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000010, LSO(0b0010011001010010));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000100, LSO(0b0010011001010100));
	TEST_ASSERT_EQUAL_UINT(0b0000000000001000, LSO(0b0010011001011000));
	TEST_ASSERT_EQUAL_UINT(0b0000000000010000, LSO(0b0010011001010000));
	TEST_ASSERT_EQUAL_UINT(0b0000000000100000, LSO(0b0010011001100000));
	TEST_ASSERT_EQUAL_UINT(0b0000000001000000, LSO(0b0010011001000000));
	TEST_ASSERT_EQUAL_UINT(0b0000000010000000, LSO(0b0010011010000000));

	TEST_ASSERT_EQUAL_UINT(0b0000000100000000, LSO(0b0010011100000000));
	TEST_ASSERT_EQUAL_UINT(0b0000001000000000, LSO(0b0010011000000000));
	TEST_ASSERT_EQUAL_UINT(0b0000010000000000, LSO(0b1010010000000000));
	TEST_ASSERT_EQUAL_UINT(0b0000100000000000, LSO(0b0010100000000000));
	TEST_ASSERT_EQUAL_UINT(0b0001000000000000, LSO(0b1011000000000000));
	TEST_ASSERT_EQUAL_UINT(0b0010000000000000, LSO(0b1010000000000000));
	TEST_ASSERT_EQUAL_UINT(0b0100000000000000, LSO(0b0100000000000000));
	TEST_ASSERT_EQUAL_UINT(0b1000000000000000, LSO(0b1000000000000000));

	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, LSO(0b1111111111111111));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000000, LSO(0b0000000000000000));
}

/**
 * @brief Unit test for isolate the rightmost 0-bit macro
 */
void test_LCO(void)
{
	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, LCO(0b0010011001010010));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000010, LCO(0b0010011001010001));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000100, LCO(0b0010011001010011));
	TEST_ASSERT_EQUAL_UINT(0b0000000000001000, LCO(0b0010011001010111));
	TEST_ASSERT_EQUAL_UINT(0b0000000000010000, LCO(0b0010011001001111));
	TEST_ASSERT_EQUAL_UINT(0b0000000000100000, LCO(0b0010011001011111));
	TEST_ASSERT_EQUAL_UINT(0b0000000001000000, LCO(0b0010011000111111));
	TEST_ASSERT_EQUAL_UINT(0b0000000010000000, LCO(0b0010011001111111));

	TEST_ASSERT_EQUAL_UINT(0b0000000100000000, LCO(0b0010011011111111));
	TEST_ASSERT_EQUAL_UINT(0b0000001000000000, LCO(0b0010010111111111));
	TEST_ASSERT_EQUAL_UINT(0b0000010000000000, LCO(0b1010001111111111));
	TEST_ASSERT_EQUAL_UINT(0b0000100000000000, LCO(0b0010011111111111));
	TEST_ASSERT_EQUAL_UINT(0b0001000000000000, LCO(0b1010111111111111));
	TEST_ASSERT_EQUAL_UINT(0b0010000000000000, LCO(0b1001111111111111));
	TEST_ASSERT_EQUAL_UINT(0b0100000000000000, LCO(0b0011111111111111));
	TEST_ASSERT_EQUAL_UINT(0b1000000000000000, LCO(0b0111111111111111));

	TEST_ASSERT_EQUAL_UINT(0b10000000000000000, LCO(0b1111111111111111));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, LCO(0b0000000000000000));
}

/**
 * @brief Unit test for turn on the rightmost 0-bit macro
 */
void test_SLSB(void)
{
	TEST_ASSERT_EQUAL_UINT(0b0010011001010011, SLSB(0b0010011001010010));
	TEST_ASSERT_EQUAL_UINT(0b0010011001010011, SLSB(0b0010011001010001));
	TEST_ASSERT_EQUAL_UINT(0b0010011001010111, SLSB(0b0010011001010011));
	TEST_ASSERT_EQUAL_UINT(0b0010011001011111, SLSB(0b0010011001010111));
	TEST_ASSERT_EQUAL_UINT(0b0010011001111111, SLSB(0b0010011001011111));
	TEST_ASSERT_EQUAL_UINT(0b0010011011111111, SLSB(0b0010011001111111));
	TEST_ASSERT_EQUAL_UINT(0b0010011111111111, SLSB(0b0010011011111111));
	TEST_ASSERT_EQUAL_UINT(0b0010111111111111, SLSB(0b0010011111111111));
	TEST_ASSERT_EQUAL_UINT(0b0011111111111111, SLSB(0b0010111111111111));
	TEST_ASSERT_EQUAL_UINT(0b0111111111111111, SLSB(0b0011111111111111));
	TEST_ASSERT_EQUAL_UINT(0b1111111111111111, SLSB(0b0111111111111111));

	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, SLSB(0b0000000000000000));
	TEST_ASSERT_EQUAL_UINT(0b11111111111111111, SLSB(0b1111111111111111));
}

/**
 * @brief Unit test for turn off the rightmost 0-bit macro
 */
void test_CLSB(void)
{
	TEST_ASSERT_EQUAL_UINT(0b0010011001010000, CLSB(0b0010011001010001));
	TEST_ASSERT_EQUAL_UINT(0b0010011001010000, CLSB(0b0010011001010010));
	TEST_ASSERT_EQUAL_UINT(0b0010011001010000, CLSB(0b0010011001010100));
	TEST_ASSERT_EQUAL_UINT(0b0010011001010000, CLSB(0b0010011001011000));
	TEST_ASSERT_EQUAL_UINT(0b0010011001000000, CLSB(0b0010011001010000));
	TEST_ASSERT_EQUAL_UINT(0b0010011001000000, CLSB(0b0010011001100000));
	TEST_ASSERT_EQUAL_UINT(0b0010010000000000, CLSB(0b0010011000000000));
	TEST_ASSERT_EQUAL_UINT(0b0010000000000000, CLSB(0b0010010000000000));
	TEST_ASSERT_EQUAL_UINT(0b0000000000000000, CLSB(0b0010000000000000));

	TEST_ASSERT_EQUAL_UINT(0b0000000000000001, SLSB(0b0000000000000000));
	TEST_ASSERT_EQUAL_UINT(0b11111111111111111, SLSB(0b1111111111111111));
}

/**
 * @brief Unit test for function to reverse the individual bits in a uint8_t
 */
void test_bits_mirror_u8(void)
{
	TEST_ASSERT_EQUAL_UINT8(0xF0, bits_mirror_u8(0x0F));
	TEST_ASSERT_EQUAL_UINT8(0x0F, bits_mirror_u8(0xF0));
	TEST_ASSERT_EQUAL_UINT8(0xAA, bits_mirror_u8(0x55));
	TEST_ASSERT_EQUAL_UINT8(0x55, bits_mirror_u8(0xAA));
	TEST_ASSERT_EQUAL_UINT8(0x01, bits_mirror_u8(0x80));
	TEST_ASSERT_EQUAL_UINT8(0x80, bits_mirror_u8(0x01));
}

/**
 * @brief Unit test for function to reverse the individual bits in a uint16_t
 */
void test_bits_mirror_u16(void)
{
	TEST_ASSERT_EQUAL_UINT16(0xFF00, bits_mirror_u16(0x00FF));
	TEST_ASSERT_EQUAL_UINT16(0x00FF, bits_mirror_u16(0xFF00));
	TEST_ASSERT_EQUAL_UINT16(0xAAAA, bits_mirror_u16(0x5555));
	TEST_ASSERT_EQUAL_UINT16(0x5555, bits_mirror_u16(0xAAAA));
	TEST_ASSERT_EQUAL_UINT16(0x0001, bits_mirror_u16(0x8000));
	TEST_ASSERT_EQUAL_UINT16(0x8000, bits_mirror_u16(0x0001));
}

/**
 * @brief Unit test for function to reverse the individual bits in a uint32_t
 */
void test_bits_mirror_u32(void)
{
	TEST_ASSERT_EQUAL_UINT32(0xFFFF0000, bits_mirror_u32(0x0000FFFF));
	TEST_ASSERT_EQUAL_UINT32(0x0000FFFF, bits_mirror_u32(0xFFFF0000));
	TEST_ASSERT_EQUAL_UINT32(0xAAAAAAAA, bits_mirror_u32(0x55555555));
	TEST_ASSERT_EQUAL_UINT32(0x55555555, bits_mirror_u32(0xAAAAAAAA));
	TEST_ASSERT_EQUAL_UINT32(0x00000001, bits_mirror_u32(0x80000000));
	TEST_ASSERT_EQUAL_UINT32(0x80000000, bits_mirror_u32(0x00000001));
}
