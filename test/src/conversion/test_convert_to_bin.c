/**
* \file         test_convert_to_bin.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains unit tests for convert_u8_to_bin8(),
*               convert_u16_to_bin16(), convert_u32_to_bin32() functions
*               from @conversion.c file
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
 * @brief Unit test for checking of border states in convert_u8_to_bin8
 *        function in little endian case.
 */
void test_ConvertU8ToBin8_LE_Border(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(0x00, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000000", binary.bit);

    binary = convert_u8_to_bin8(0xFF, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111", binary.bit);
}

/**
 * @brief Unit test for checking of border states in convert_u8_to_bin8
 *        function in big endian case.
 */
void test_ConvertU8ToBin8_BE_Border(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(0x00, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000000", binary.bit);

    binary = convert_u8_to_bin8(0xFF, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u8_to_bin8
 *        function in little endian case.
 */
void test_ConvertU8ToBin8_LE(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(0x01, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000001", binary.bit);

    binary = convert_u8_to_bin8(0x55555555, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01010101", binary.bit);

    binary = convert_u8_to_bin8(0xAAAAAAAA, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10101010", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u8_to_bin8
 *        function in big endian case.
 */
void test_ConvertU8ToBin8_BE(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(0x01, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10000000", binary.bit);

    binary = convert_u8_to_bin8(0x55555555, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10101010", binary.bit);

    binary = convert_u8_to_bin8(0xAAAAAAAA, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01010101", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u8_to_bin8
 *        function work with negative arguments in little endian case.
 */
void test_ConvertU8ToBin8_LE_Negative(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(-1, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111", binary.bit);

    binary = convert_u8_to_bin8(-10, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11110110", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u8_to_bin8
 *        function work with negative arguments in big endian case.
 */
void test_ConvertU8ToBin8_BE_Negative(void)
{
    bin8_t binary = {};

    binary = convert_u8_to_bin8(-1, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111", binary.bit);

    binary = convert_u8_to_bin8(-10, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01101111", binary.bit);
}

/**
 * @brief Unit test for checking of border states in convert_u16_to_bin16
 *        function in little endian case.
 */
void test_ConvertU16ToBin16_LE_Border(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(0x0000, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0000000000000000", binary.bit);

    binary = convert_u16_to_bin16(0xFFFF, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1111111111111111", binary.bit);
}

/**
 * @brief Unit test for checking of border states in convert_u16_to_bin16
 *        function in big endian case.
 */
void test_ConvertU16ToBin16_BE_Border(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(0x0000, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0000000000000000", binary.bit);

    binary = convert_u16_to_bin16(0xFFFF, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1111111111111111", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u16_to_bin16
 *        function in little endian case.
 */
void test_ConvertU16ToBin16_LE(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(0x01, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0000000000000001", binary.bit);

    binary = convert_u16_to_bin16(0x55555555, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0101010101010101", binary.bit);

    binary = convert_u16_to_bin16(0xAAAAAAAA, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1010101010101010", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u16_to_bin16
 *        function in big endian case.
 */
void test_ConvertU16ToBin16_BE(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(0x01, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1000000000000000", binary.bit);

    binary = convert_u16_to_bin16(0x55555555, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1010101010101010", binary.bit);

    binary = convert_u16_to_bin16(0xAAAAAAAA, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0101010101010101", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u16_to_bin16
 *        function work with negative arguments in little endian case.
 */
void test_ConvertU16ToBin16_LE_Negative(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(-1, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1111111111111111", binary.bit);

    binary = convert_u16_to_bin16(-10, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1111111111110110", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u16_to_bin16
 *        function work with negative arguments in big endian case.
 */
void test_ConvertU16ToBin16_BE_Negative(void)
{
    bin16_t binary = {};

    binary = convert_u16_to_bin16(-1, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("1111111111111111", binary.bit);

    binary = convert_u16_to_bin16(-10, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("0110111111111111", binary.bit);
}

/**
 * @brief Unit test for checking of border states in convert_u32_to_bin32
 *        function in little endian case.
 */
void test_ConvertU32ToBin32_LE_Border(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(0x00000000, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000000000000000000000000000000", binary.bit);

    binary = convert_u32_to_bin32(0xFFFFFFFF, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111111111111111111111111111", binary.bit);
}

/**
 * @brief Unit test for checking of border states in convert_u32_to_bin32
 *        function in big endian case.
 */
void test_ConvertU32ToBin32_BE_Border(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(0x00000000, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000000000000000000000000000000", binary.bit);

    binary = convert_u32_to_bin32(0xFFFFFFFF, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111111111111111111111111111", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u32_to_bin32
 *        function in little endian case.
 */
void test_ConvertU32ToBin32_LE(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(0x01, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("00000000000000000000000000000001", binary.bit);

    binary = convert_u32_to_bin32(0x55555555, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01010101010101010101010101010101", binary.bit);

    binary = convert_u32_to_bin32(0xAAAAAAAA, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10101010101010101010101010101010", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u32_to_bin32
 *        function in big endian case.
 */
void test_ConvertU32ToBin32_BE(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(0x01, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10000000000000000000000000000000", binary.bit);

    binary = convert_u32_to_bin32(0x55555555, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("10101010101010101010101010101010", binary.bit);

    binary = convert_u32_to_bin32(0xAAAAAAAA, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01010101010101010101010101010101", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u32_to_bin32
 *        function work with negative arguments in little endian case.
 */
void test_ConvertU32ToBin32_LE_Negative(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(-1, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111111111111111111111111111", binary.bit);

    binary = convert_u32_to_bin32(-10, LITTLE_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111111111111111111111110110", binary.bit);
}

/**
 * @brief Unit test for checking of convert_u32_to_bin32
 *        function work with negative arguments in big endian case.
 */
void test_ConvertU32ToBin32_BE_Negative(void)
{
    bin32_t binary = {};

    binary = convert_u32_to_bin32(-1, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("11111111111111111111111111111111", binary.bit);

    binary = convert_u32_to_bin32(-10, BIG_ENDIAN_ORDER);
    TEST_ASSERT_EQUAL_STRING("01101111111111111111111111111111", binary.bit);
}
