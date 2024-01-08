/**
* \file         test_crc.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        Unit tests for crc8/16/32 functions from crc.c file
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
void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_crc8(void)
{
    uint8_t data[256] = {};
    uint8_t crc = 0;
    uint8_t crc_expected = 0x14;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc8(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT8(crc, crc_expected);
}

void test_crc8_table(void)
{
    uint8_t data[256] = {};
    uint8_t crc = 0;
    uint8_t crc_expected = 0x14;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc8_table(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT8(crc, crc_expected);
}

void test_crc16(void)
{
    uint8_t data[256] = {};
    uint16_t crc = 0;
    uint16_t crc_expected = 0x3fbd;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc16(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT16(crc, crc_expected);
}

void test_crc16_table(void)
{
    uint8_t data[256] = {};
    uint16_t crc = 0;
    uint16_t crc_expected = 0x3fbd;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc16_table(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT16(crc, crc_expected);
}

void test_crc32(void)
{
    uint8_t data[256] = {};
    uint32_t crc = 0;
    uint32_t crcTable = 0;
    uint32_t crc_expected = 0x29058C73;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc32(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT32(crc, crc_expected);
}

void test_crc32_table(void)
{
    uint8_t data[256] = {};
    uint32_t crc = 0;
    uint32_t crc_expected = 0x29058C73;

    for(size_t i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    crc = crc32_table(data, sizeof(data));

    TEST_ASSERT_EQUAL_UINT32(crc, crc_expected);
}

/* Special guard for case when unit tests were run not by PlatformIO but by Ceedling for example */
#ifdef PIO_UNIT_TESTING
int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_crc8);
  RUN_TEST(test_crc8_table);
  RUN_TEST(test_crc16);
  RUN_TEST(test_crc16_table);
  RUN_TEST(test_crc32);
  RUN_TEST(test_crc32_table);
  return UNITY_END();
}


/**
  * For native dev-platform or for some embedded frameworks
  */
int main(void) {
  return runTests();
}
#endif
