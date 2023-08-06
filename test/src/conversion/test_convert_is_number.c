/**
 * @file    test_convert_is_number.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for checking number functions
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
 * @brief Unit test for correct positive dec numbers
 */
void test_ConvertIsDecNumber_Positive(void)
{
    char* str[] = {"0", "1","12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "4294967295"};

    for (size_t i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        TEST_ASSERT_TRUE(convert_is_dec_number(str[i], strlen(str[i])));
    }
}

/**
 * @brief Unit test for correct negative dec numbers
 */
void test_ConvertIsDecNumber_Negative(void)
{
    char* str[] = {"-2147483647", "-123456789", "-12345678", "-1234567", "-123456", "-12345", "-1234", "-123",\
                    "-12", "-1"};

    for (size_t i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        TEST_ASSERT_TRUE(convert_is_dec_number(str[i], strlen(str[i])));
    }
}

/**
 * @brief Unit test for incorrect dec numbers
 */
void test_ConvertIsDecNumber_Invalid(void)
{
    char* str[] = {" ", "", "2147-483647", "A123456789", "v12345678", "-1234567r", "1234RT56", "gfhfthx"};

    for (size_t i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        TEST_ASSERT_FALSE(convert_is_dec_number(str[i], strlen(str[i])));
    }
}

/**
 * @brief Unit test for correct hex numbers
 */
void test_ConvertIsHexNumber_Correct(void)
{
    char* str[] = {"0", "1","2", "3", "4", "5", "6", "7", "8", "9",\
                    "A", "B", "C", "D", "E", "F",\
                    "a", "b", "c", "d", "e", "f",\
                    "10", "11","12", "13", "14", "15", "16", "17", "18", "19",\
                    "1A", "1B","1C", "1D", "1E", "1F",\
                    "1a", "1b","1c", "1d", "1e", "1f"};

    for (size_t i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        TEST_ASSERT_TRUE(convert_is_hex_number(str[i], strlen(str[i])));
    }
}

/**
 * @brief Unit test for incorrect hex numbers
 */
void test_ConvertIsHexNumber_Incorrect(void)
{
    char* str[] = {" ", "", "r", "Dty", "E7fg", "0xEE"};

    for (size_t i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        TEST_ASSERT_FALSE(convert_is_hex_number(str[i], strlen(str[i])));
    }
}
