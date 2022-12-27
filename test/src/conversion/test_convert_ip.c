/**
 * @file    test_convert_ip.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for convert IP address functions
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
 * @brief Unit test for convert valid ip address struct to address string.
 */
void test_ConvertIpv4AddrToString_Valid(void)
{
    ip4addr_t current[] = {0xFA0A0A0A, 0x00, 0xFFFFFFFF};
    char* expected[] = {"10.10.10.250", "0.0.0.0", "255.255.255.255"};
    char ip[] = "000.000.000.000";

    for (size_t i = 0; i < sizeof(current)/sizeof(ip4addr_t); i++)
    {
        bool result = convert_ip4addr_to_string(current[i], ip);
        TEST_ASSERT_TRUE(result);
        TEST_ASSERT_EQUAL_STRING(ip, expected[i]);
    }
}

/**
 * @brief Unit test for convert invalid ip address string to ip address struct
 */
void test_ConvertStringToIpv4addr_Valid(void)
{
    ip4addr_t expected[] = {0xFA0A0A0A, 0x00, 0xFFFFFFFF};
    char* current[] = {"10.10.10.250", "0.0.0.0", "255.255.255.255"};
    ip4addr_t ip = 0;

    for (size_t i = 0; i < sizeof(current)/sizeof(char*); i++)
    {
        bool result = convert_string_to_ip4addr(&ip, current[i]);
        TEST_ASSERT_TRUE(result);
        TEST_ASSERT_EQUAL_INT(ip, expected[i]);
    }
}
