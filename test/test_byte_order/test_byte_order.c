/**
 * @file    test_byte_order.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests functions for work with different
 *          byte endian types from @byte_order.c file
 *
 */

//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "byte_order.h"
#include "types.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_byte_order_swap16(void)
{
    uint16_t current = byte_order_swap16(0xFACE);
    TEST_ASSERT_EQUAL_UINT16(current, 0xCEFA);

    current = byte_order_swap16(0xCEFA);
    TEST_ASSERT_EQUAL_UINT16(current, 0xFACE);
}

void test_byte_order_swap32(void)
{
    uint32_t current = byte_order_swap32(0xFACEFACE);
    TEST_ASSERT_EQUAL_UINT16(current, 0xCEFACEFA);

    current = byte_order_swap32(0xCEFACEFA);
    TEST_ASSERT_EQUAL_UINT16(current, 0xFACEFACE);
}

void test_byte_order_swap64(void)
{
    uint64_t current = byte_order_swap64(0xFACEFACEFACEFACE);
    TEST_ASSERT_EQUAL_UINT16(current, 0xCEFACEFACEFACEFA);

    current = byte_order_swap64(0xCEFACEFACEFACEFA);
    TEST_ASSERT_EQUAL_UINT16(current, 0xFACEFACEFACEFACE);
}

void test_byte_order_u16_to_array_le(void)
{
    uint16_t current = 0xFACE;
    uint8_t array[2] = {};

    byte_order_u16_to_array_le(current, array);

    TEST_ASSERT_EQUAL_UINT8(array[0], 0xCE);
    TEST_ASSERT_EQUAL_UINT8(array[1], 0xFA);
}

void test_byte_order_u32_to_array_le(void)
{
    uint32_t current = 0xFACEFACE;
    uint8_t array[4] = {};

    byte_order_u32_to_array_le(current, array);

    TEST_ASSERT_EQUAL_UINT8(array[0], 0xCE);
    TEST_ASSERT_EQUAL_UINT8(array[1], 0xFA);
    TEST_ASSERT_EQUAL_UINT8(array[2], 0xCE);
    TEST_ASSERT_EQUAL_UINT8(array[3], 0xFA);
}

void test_byte_order_array_to_u16_le(void)
{
    uint8_t array[2] = {0xCE, 0xFA};
    uint16_t current = byte_order_array_to_u16_le(array);

    TEST_ASSERT_EQUAL_UINT16(current, 0xFACE);
}

void test_byte_order_array_to_u32_le(void)
{
    uint8_t array[4] = {0xCE, 0xFA, 0xCE, 0xFA};
    uint32_t current = byte_order_array_to_u32_le(array);

    TEST_ASSERT_EQUAL_UINT32(current, 0xFACEFACE);
}

void test_byte_order_u16_to_array_be(void)
{
    uint16_t current = 0xFACE;
    uint8_t array[2] = {};

    byte_order_u16_to_array_be(current, array);

    TEST_ASSERT_EQUAL_UINT8(array[0], 0xFA);
    TEST_ASSERT_EQUAL_UINT8(array[1], 0xCE);
}

void test_byte_order_u32_to_array_be(void)
{
    uint32_t current = 0xFACEFACE;
    uint8_t array[4] = {};

    byte_order_u32_to_array_be(current, array);

    TEST_ASSERT_EQUAL_UINT8(array[0], 0xFA);
    TEST_ASSERT_EQUAL_UINT8(array[1], 0xCE);
    TEST_ASSERT_EQUAL_UINT8(array[2], 0xFA);
    TEST_ASSERT_EQUAL_UINT8(array[3], 0xCE);
}

void test_byte_order_array_to_u16_be(void)
{
    uint8_t array[2] = {0xFA, 0xCE};
    uint16_t current = byte_order_array_to_u16_be(array);

    TEST_ASSERT_EQUAL_UINT16(current, 0xFACE);
}

void test_byte_order_array_to_u32_be(void)
{
    uint8_t array[4] = {0xFA, 0xCE, 0xFA, 0xCE};
    uint32_t current = byte_order_array_to_u32_be(array);

    TEST_ASSERT_EQUAL_UINT16(current, 0xFACEFACE);
}

/* Special guard for case when unit tests were run not by PlatformIO but by Ceedling for example */
#ifdef PIO_UNIT_TESTING
int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_byte_order_swap16);
  RUN_TEST(test_byte_order_swap32);
  RUN_TEST(test_byte_order_swap64);
  RUN_TEST(test_byte_order_u16_to_array_le);
  RUN_TEST(test_byte_order_u32_to_array_le);
  RUN_TEST(test_byte_order_array_to_u16_le);
  RUN_TEST(test_byte_order_array_to_u32_le);
  RUN_TEST(test_byte_order_u16_to_array_be);
  RUN_TEST(test_byte_order_u32_to_array_be);
  RUN_TEST(test_byte_order_array_to_u16_be);
  RUN_TEST(test_byte_order_array_to_u32_be);
  return UNITY_END();
}


/**
  * For native dev-platform or for some embedded frameworks
  */
int main(void) {
  return runTests();
}
#endif
