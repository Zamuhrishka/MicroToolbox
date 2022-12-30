/**
 * @file test_structs.c
 * @author Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief 
 * @date 2022-05-22
 */

//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "macros/misc.h"
//_____ C O N F I G S  ________________________________________________________

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________

//_____ V A R I A B L E S _____________________________________________________

//_____ P R I V A T E  F U N C T I O N S_______________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________
void test_ARRAY_SIZE(void)
{
    uint8_t array8[10] = {};
    uint16_t array16[10] = {};
    uint32_t array32[10] = {};

    TEST_ASSERT_EQUAL_UINT(10, ARRAY_SIZE(array8));
    TEST_ASSERT_EQUAL_UINT(10, ARRAY_SIZE(array16));
    TEST_ASSERT_EQUAL_UINT(10, ARRAY_SIZE(array32));
}

void test_offsetof(void)
{
    typedef struct {
        uint8_t     id;
        uint8_t     tag;
        bool        isValid;
        uint8_t     res;
    } CustomStruct_t;
    
    CustomStruct_t example = {};

    TEST_ASSERT_EQUAL_UINT(0, offsetof(CustomStruct_t, id));
    TEST_ASSERT_EQUAL_UINT(1, offsetof(CustomStruct_t, tag));
    TEST_ASSERT_EQUAL_UINT(2, offsetof(CustomStruct_t, isValid));
    TEST_ASSERT_EQUAL_UINT(3, offsetof(CustomStruct_t, res));
}

void test_container_of(void)
{
    typedef struct {
        uint8_t     id;
        uint16_t    tag;
        bool        isValid;
        uint8_t     res;
    } CustomStruct_t;    
    CustomStruct_t example = {};

    TEST_ASSERT_EQUAL_UINT((uint32_t)&example, (uint32_t)container_of(&example.id, CustomStruct_t, id));
    TEST_ASSERT_EQUAL_UINT((uint32_t)&example, (uint32_t)container_of(&example.tag, CustomStruct_t, tag));
    TEST_ASSERT_EQUAL_UINT((uint32_t)&example, (uint32_t)container_of(&example.isValid, CustomStruct_t, isValid));
    TEST_ASSERT_EQUAL_UINT((uint32_t)&example, (uint32_t)container_of(&example.res, CustomStruct_t, res));
}
