/**
* \file         template.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/
//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include "macros.h"

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
void test_Sigh(void)
{
	int32_t res = 0;
	int8_t a = 1;
	int16_t b = 100;
	int32_t c = 1000;

	res = SIGH_CHANGE(a);
	TEST_ASSERT_EQUAL_INT(res, -1);

	res = SIGH_CHANGE(b);
	TEST_ASSERT_EQUAL_INT(res, -100);

	res = SIGH_CHANGE(c);
	TEST_ASSERT_EQUAL_INT(res, -1000);

	res = SIGH_CHANGE(a * (-1));
	TEST_ASSERT_EQUAL_INT(res, 1);

	res = SIGH_CHANGE(b * (-1));
	TEST_ASSERT_EQUAL_INT(res, 100);

	res = SIGH_CHANGE(c * (-1));
	TEST_ASSERT_EQUAL_INT(res, 1000);
}

void test_OddEven(void)
{
	bool res = 0;
	int8_t a = 0;
	int16_t b = 0;
	int32_t c = 0;

	a = 10;
	b = 100;
	c = 1000;
	res = IS_ODD(a);
	TEST_ASSERT_TRUE(res);
	res = IS_ODD(b);
	TEST_ASSERT_TRUE(res);
	res = IS_ODD(c);
	TEST_ASSERT_TRUE(res);

	a = 11;
	b = 101;
	c = 1001;
	res = IS_ODD(a);
	TEST_ASSERT_FALSE(res);
	res = IS_ODD(b);
	TEST_ASSERT_FALSE(res);
	res = IS_ODD(c);
	TEST_ASSERT_FALSE(res);

	a = 10;
	b = 100;
	c = 1000;
	res = IS_EVEN(a);
	TEST_ASSERT_FALSE(res);
	res = IS_EVEN(b);
	TEST_ASSERT_FALSE(res);
	res = IS_EVEN(c);
	TEST_ASSERT_FALSE(res);

	a = 11;
	b = 101;
	c = 1001;
	res = IS_EVEN(a);
	TEST_ASSERT_TRUE(res);
	res = IS_EVEN(b);
	TEST_ASSERT_TRUE(res);
	res = IS_EVEN(c);
	TEST_ASSERT_TRUE(res);
}

void test_Equal(void)
{
	bool res = 0;
	int8_t a = 0;
	int8_t b = 0;
	int16_t a1 = 0;
	int16_t b1 = 0;
	int32_t a2 = 0;
	int32_t b2 = 0;

	a = 100;
	b = 100;
	res = IS_EQUAL(a, b);
	TEST_ASSERT_TRUE(res);

	a = 200;
	b = 100;
	res = IS_EQUAL(a, b);
	TEST_ASSERT_FALSE(res);

	a1 = 1000;
	b1 = 1000;
	res = IS_EQUAL(a1, b1);
	TEST_ASSERT_TRUE(res);

	a1 = 2000;
	b1 = 1000;
	res = IS_EQUAL(a1, b1);
	TEST_ASSERT_FALSE(res);

	a2 = 10000;
	b2 = 10000;
	res = IS_EQUAL(a2, b2);
	TEST_ASSERT_TRUE(res);

	a2 = 20000;
	b2 = 10000;
	res = IS_EQUAL(a2, b2);
	TEST_ASSERT_FALSE(res);
}

void test_AriphMean(void)
{
	int32_t res = 0;
	int8_t a = 10;
	int8_t b = 10;
	int16_t a1 = 100;
	int16_t b1 = 100;
	int32_t a2 = 1000;
	int32_t b2 = 1000;

	res = ARIPH_MEAN(a, b);
	TEST_ASSERT_EQUAL_INT(res, 10);

	res = ARIPH_MEAN(a1, b1);
	TEST_ASSERT_EQUAL_INT(res, 100);

	res = ARIPH_MEAN(a2, b2);
	TEST_ASSERT_EQUAL_INT(res, 1000);
}

void test_MinMax(void)
{
	int8_t res1 = 0;
	int16_t res2 = 0;
	int32_t res3 = 0;
	int8_t a = 0;
	int8_t b = 0;
	int16_t a1 = 0;
	int16_t b1 = 0;
	int32_t a2 = 0;
	int32_t b2 = 0;

	a = 100;
	b = 50;
	res1 = MIN(a, b);
	TEST_ASSERT_EQUAL_INT(res1, b);

	a = -50;
	b = 100;
	res1 = MIN(a, b);
	TEST_ASSERT_EQUAL_INT(res1, a);

	a1 = 2000;
	b1 = 1000;
	res2 = MIN(a1, b1);
	TEST_ASSERT_EQUAL_INT(res2, b1);

	a1 = -2000;
	b1 = 1000;
	res2 = MIN(a1, b1);
	TEST_ASSERT_EQUAL_INT(res2, a1);

	a2 = 20000;
	b2 = 10000;
	res3 = MIN(a2, b2);
	TEST_ASSERT_EQUAL_INT(res3, b2);

	a2 = -20000;
	b2 = 10000;
	res3 = MIN(a2, b2);
	TEST_ASSERT_EQUAL_INT(res3, a2);

	a = 100;
	b = 50;
	res1 = MAX(a, b);
	TEST_ASSERT_EQUAL_INT(res1, a);

	a = -50;
	b = 100;
	res1 = MAX(a, b);
	TEST_ASSERT_EQUAL_INT(res1, b);

	a1 = 2000;
	b1 = 1000;
	res2 = MAX(a1, b1);
	TEST_ASSERT_EQUAL_INT(res2, a1);

	a1 = -2000;
	b1 = 1000;
	res2 = MAX(a1, b1);
	TEST_ASSERT_EQUAL_INT(res2, b1);

	a2 = 20000;
	b2 = 10000;
	res3 = MAX(a2, b2);
	TEST_ASSERT_EQUAL_INT(res3, a2);

	a2 = -20000;
	b2 = 10000;
	res3 = MAX(a2, b2);
	TEST_ASSERT_EQUAL_INT(res3, b2);
}

void test_Bits(void)
{
	TEST_IGNORE();
}