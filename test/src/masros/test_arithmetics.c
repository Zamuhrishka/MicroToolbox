/**
 * @file    test_arithmetics.c
 * @author  Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief   This file contains unit tests for arithmetics operations from
 *          macros/arithmetics.h file
 */

//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "macros/arithmetics.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
void test_min_positive(void)
{
    int res = MIN(100, 50);
    TEST_ASSERT_EQUAL_INT(50, res);


    TEST_ASSERT_EQUAL_INT(50, MIN(100, 50));
    TEST_ASSERT_EQUAL_INT(1000, MIN(2000, 1000));
    TEST_ASSERT_EQUAL_INT(10000, MIN(20000, 10000));

    TEST_ASSERT_EQUAL_INT(50, MIN(50, 100));
    TEST_ASSERT_EQUAL_INT(1000, MIN(1000, 2000));
    TEST_ASSERT_EQUAL_INT(10000, MIN(10000, 20000));
}

void test_min_negative(void)
{
    TEST_ASSERT_EQUAL_INT(-100, MIN(-50, -100));
    TEST_ASSERT_EQUAL_INT(-2000, MIN(-2000, -1000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN(-20000, -10000));

    TEST_ASSERT_EQUAL_INT(-100, MIN(-100, -50));
    TEST_ASSERT_EQUAL_INT(-2000, MIN(-1000, -2000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN(-10000, -20000));
}

void test_min_mixed(void)
{
    TEST_ASSERT_EQUAL_INT(-100, MIN(50, -100));
    TEST_ASSERT_EQUAL_INT(-2000, MIN(-2000, 1000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN(-20000, 10000));
}

void test_min_equal(void)
{
    TEST_ASSERT_EQUAL_INT(50, MIN(50, 50));
    TEST_ASSERT_EQUAL_INT(-2000, MIN(-2000, -2000));
}


void test_min_bl_positive(void)
{
    TEST_ASSERT_EQUAL_INT(50, MIN_BRANCHLESS(100, 50));
    TEST_ASSERT_EQUAL_INT(1000, MIN_BRANCHLESS(2000, 1000));
    TEST_ASSERT_EQUAL_INT(10000, MIN_BRANCHLESS(20000, 10000));

    TEST_ASSERT_EQUAL_INT(50, MIN_BRANCHLESS(50, 100));
    TEST_ASSERT_EQUAL_INT(1000, MIN_BRANCHLESS(1000, 2000));
    TEST_ASSERT_EQUAL_INT(10000, MIN_BRANCHLESS(10000, 20000));
}

void test_min_bl_negative(void)
{
    TEST_ASSERT_EQUAL_INT(-100, MIN_BRANCHLESS(-50, -100));
    TEST_ASSERT_EQUAL_INT(-2000, MIN_BRANCHLESS(-2000, -1000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN_BRANCHLESS(-20000, -10000));

    TEST_ASSERT_EQUAL_INT(-100, MIN_BRANCHLESS(-100, -50));
    TEST_ASSERT_EQUAL_INT(-2000, MIN_BRANCHLESS(-1000, -2000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN_BRANCHLESS(-10000, -20000));
}

void test_min_bl_mixed(void)
{
    TEST_ASSERT_EQUAL_INT(-100, MIN_BRANCHLESS(50, -100));
    TEST_ASSERT_EQUAL_INT(-2000, MIN_BRANCHLESS(-2000, 1000));
    TEST_ASSERT_EQUAL_INT(-20000, MIN_BRANCHLESS(-20000, 10000));
}

void test_min_bl_equal(void)
{
    TEST_ASSERT_EQUAL_INT(50, MIN_BRANCHLESS(50, 50));
    TEST_ASSERT_EQUAL_INT(-2000, MIN_BRANCHLESS(-2000, -2000));
}






void test_max_positive(void)
{
    TEST_ASSERT_EQUAL_INT(100, MAX(100, 50));
    TEST_ASSERT_EQUAL_INT(2000, MAX(2000, 1000));
    TEST_ASSERT_EQUAL_INT(20000, MAX(20000, 10000));

    TEST_ASSERT_EQUAL_INT(100, MAX(50, 100));
    TEST_ASSERT_EQUAL_INT(2000, MAX(1000, 2000));
    TEST_ASSERT_EQUAL_INT(20000, MAX(10000, 20000));
}

void test_max_negative(void)
{
    TEST_ASSERT_EQUAL_INT(-50, MAX(-50, -100));
    TEST_ASSERT_EQUAL_INT(-1000, MAX(-2000, -1000));
    TEST_ASSERT_EQUAL_INT(-10000, MAX(-20000, -10000));

    TEST_ASSERT_EQUAL_INT(-50, MAX(-100, -50));
    TEST_ASSERT_EQUAL_INT(-1000, MAX(-1000, -2000));
    TEST_ASSERT_EQUAL_INT(-10000, MAX(-10000, -20000));
}

void test_max_mixed(void)
{
    TEST_ASSERT_EQUAL_INT(50, MAX(50, -100));
    TEST_ASSERT_EQUAL_INT(1000, MAX(-2000, 1000));
    TEST_ASSERT_EQUAL_INT(10000, MAX(-20000, 10000));
}

void test_max_equal(void)
{
    TEST_ASSERT_EQUAL_INT(50, MAX(50, 50));
    TEST_ASSERT_EQUAL_INT(-2000, MAX(-2000, -2000));
}


void test_max_bl_positive(void)
{
    TEST_ASSERT_EQUAL_INT(100, MAX_BRANCHLESS(100, 50));
    TEST_ASSERT_EQUAL_INT(2000, MAX_BRANCHLESS(2000, 1000));
    TEST_ASSERT_EQUAL_INT(20000, MAX_BRANCHLESS(20000, 10000));

    TEST_ASSERT_EQUAL_INT(100, MAX_BRANCHLESS(50, 100));
    TEST_ASSERT_EQUAL_INT(2000, MAX_BRANCHLESS(1000, 2000));
    TEST_ASSERT_EQUAL_INT(20000, MAX_BRANCHLESS(10000, 20000));
}

void test_max_bl_negative(void)
{
    TEST_ASSERT_EQUAL_INT(-50, MAX_BRANCHLESS(-50, -100));
    TEST_ASSERT_EQUAL_INT(-1000, MAX_BRANCHLESS(-2000, -1000));
    TEST_ASSERT_EQUAL_INT(-10000, MAX_BRANCHLESS(-20000, -10000));

    TEST_ASSERT_EQUAL_INT(-50, MAX_BRANCHLESS(-100, -50));
    TEST_ASSERT_EQUAL_INT(-1000, MAX_BRANCHLESS(-1000, -2000));
    TEST_ASSERT_EQUAL_INT(-10000, MAX_BRANCHLESS(-10000, -20000));
}

void test_max_bl_mixed(void)
{
    TEST_ASSERT_EQUAL_INT(50, MAX_BRANCHLESS(50, -100));
    TEST_ASSERT_EQUAL_INT(1000, MAX_BRANCHLESS(-2000, 1000));
    TEST_ASSERT_EQUAL_INT(10000, MAX_BRANCHLESS(-20000, 10000));
}

void test_max_bl_equal(void)
{
    TEST_ASSERT_EQUAL_INT(50, MAX_BRANCHLESS(50, 50));
    TEST_ASSERT_EQUAL_INT(-2000, MAX_BRANCHLESS(-2000, -2000));
}

void test_equal_positive(void)
{
    TEST_ASSERT_TRUE(IS_EQUAL(0, 0));
    TEST_ASSERT_TRUE(IS_EQUAL(100, 100));
    TEST_ASSERT_TRUE(IS_EQUAL(10000, 10000));
}

void test_equal_negative(void)
{
    TEST_ASSERT_TRUE(IS_EQUAL(-100, -100));
    TEST_ASSERT_TRUE(IS_EQUAL(-10000, -10000));
}

void test_equal_mixed(void)
{
    TEST_ASSERT_FALSE(IS_EQUAL(100, 200));
    TEST_ASSERT_FALSE(IS_EQUAL(1000, -1000));
    TEST_ASSERT_FALSE(IS_EQUAL(2000, 1000));
    TEST_ASSERT_FALSE(IS_EQUAL(20000, 10000));
}

void test_even(void)
{
    TEST_ASSERT_FALSE(IS_EVEN(10));
    TEST_ASSERT_FALSE(IS_EVEN(100));
    TEST_ASSERT_FALSE(IS_EVEN(1000));

    TEST_ASSERT_TRUE(IS_EVEN(11));
    TEST_ASSERT_TRUE(IS_EVEN(101));
    TEST_ASSERT_TRUE(IS_EVEN(1001));
}

void test_odd(void)
{
    TEST_ASSERT_TRUE(IS_ODD(10));
    TEST_ASSERT_TRUE(IS_ODD(100));
    TEST_ASSERT_TRUE(IS_ODD(1000));

    TEST_ASSERT_FALSE(IS_ODD(11));
    TEST_ASSERT_FALSE(IS_ODD(101));
    TEST_ASSERT_FALSE(IS_ODD(1001));
}

void test_invert_sigh(void)
{
    TEST_ASSERT_EQUAL_INT8(-1, INVERT_SIGH(1));
    TEST_ASSERT_EQUAL_INT8(1, INVERT_SIGH(-1));

    TEST_ASSERT_EQUAL_INT8(-100, INVERT_SIGH(100));
    TEST_ASSERT_EQUAL_INT8(100, INVERT_SIGH(-100));
}

void test_is_sigh_equal(void)
{
    TEST_ASSERT_TRUE(IS_SIGH_EQUAL(1, 1));
    TEST_ASSERT_FALSE(IS_SIGH_EQUAL(1, -1));

    TEST_ASSERT_TRUE(IS_SIGH_EQUAL(100, 100));
    TEST_ASSERT_FALSE(IS_SIGH_EQUAL(100, -100));
}

void test_arithmetical_mean(void)
{
    TEST_ASSERT_EQUAL_INT(ARITHMETICAL_MEAN(10, 10), 10);
    TEST_ASSERT_EQUAL_INT(ARITHMETICAL_MEAN(100, 100), 100);
    TEST_ASSERT_EQUAL_INT(ARITHMETICAL_MEAN(1000, 1000), 1000);
    TEST_ASSERT_EQUAL_INT(ARITHMETICAL_MEAN(100, 60), 80);
}

void test_swap(void)
{
    uint32_t a = 100;
    uint32_t b = 10;

    SWAP(a, b);
    TEST_ASSERT_EQUAL_INT(a, 10);
    TEST_ASSERT_EQUAL_INT(b, 100);

    int32_t x = -100;
    int32_t y = -10;

    SWAP(x, y);
    TEST_ASSERT_EQUAL_INT(x, -10);
    TEST_ASSERT_EQUAL_INT(y, -100);
}

void test_is_power_2_valid(void)
{
    uint32_t power2 = 0x01;

    for (size_t i = 0; i < 31; i++)
    {
        power2 <<= 1;
        TEST_ASSERT_TRUE(IS_POWER_2(power2));
    }
}

void test_is_power_2_invalid(void)
{
    uint32_t not_power2 = 0x03;

    for (size_t i = 0; i < 30; i++)
    {
        not_power2 <<= 1;
        TEST_ASSERT_FALSE(IS_POWER_2(not_power2));
    }
}

void test_round_up(void)
{
    TEST_ASSERT_EQUAL_INT(117, ROUND_UP(115, 3));
    TEST_ASSERT_EQUAL_INT(116, ROUND_UP(115, 2));
    TEST_ASSERT_EQUAL_INT(120, ROUND_UP(118, 10));
}


void test_round_up_pow_2(void)
{
    TEST_ASSERT_EQUAL_INT(0, ROUND_UP_POW_2(0));
    TEST_ASSERT_EQUAL_INT(1, ROUND_UP_POW_2(1));
    TEST_ASSERT_EQUAL_INT(2, ROUND_UP_POW_2(2));

    TEST_ASSERT_EQUAL_INT(4, ROUND_UP_POW_2(3));
    TEST_ASSERT_EQUAL_INT(4, ROUND_UP_POW_2(4));

    TEST_ASSERT_EQUAL_INT(8, ROUND_UP_POW_2(5));
    TEST_ASSERT_EQUAL_INT(8, ROUND_UP_POW_2(6));
    TEST_ASSERT_EQUAL_INT(8, ROUND_UP_POW_2(7));
    TEST_ASSERT_EQUAL_INT(8, ROUND_UP_POW_2(8));

    TEST_ASSERT_EQUAL_INT(16, ROUND_UP_POW_2(10));

    TEST_ASSERT_EQUAL_INT(32, ROUND_UP_POW_2(25));

    TEST_ASSERT_EQUAL_INT(64, ROUND_UP_POW_2(46));

    TEST_ASSERT_EQUAL_INT(128, ROUND_UP_POW_2(100));

    TEST_ASSERT_EQUAL_INT(256, ROUND_UP_POW_2(156));

    TEST_ASSERT_EQUAL_INT(512, ROUND_UP_POW_2(346));
}
