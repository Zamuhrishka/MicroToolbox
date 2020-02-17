// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/**********************************************************************************************
* @file    		test_convert.c
* @author  		Kovalchuk Alexander aka mz4
* @email 		roux@yandex.ru
* @brief		Functions for testing dfifo library.
***********************************************************************************************/
//_____ I N C L U D E S _______________________________________________________________________
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cmockery.h"
#include "macros.h"
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________________________
//_____ S T A T I Ñ  F U N C T I O N   D E F I N I T I O N   __________________________________
static void Test_Sigh(void **state)
{
	int32_t res = 0;
	int8_t a = 1;
	int16_t b = 100;
	int32_t c = 1000;

	res = SIGH_CHANGE(a);
	assert_int_equal(res, -1);

	res = SIGH_CHANGE(b);
	assert_int_equal(res, -100);

	res = SIGH_CHANGE(c);
	assert_int_equal(res, -1000);

	res = SIGH_CHANGE(a * (-1));
	assert_int_equal(res, 1);

	res = SIGH_CHANGE(b * (-1));
	assert_int_equal(res, 100);

	res = SIGH_CHANGE(c * (-1));
	assert_int_equal(res, 1000);
}

static void Test_OddEven(void **state)
{
	bool res = 0;
	int8_t a = 0;
	int16_t b = 0;
	int32_t c = 0;

	a = 10;
	b = 100;
	c = 1000;
	res = IS_ODD(a);
	assert_true(res);
	res = IS_ODD(b);
	assert_true(res);
	res = IS_ODD(c);
	assert_true(res);

	a = 11;
	b = 101;
	c = 1001;
	res = IS_ODD(a);
	assert_false(res);
	res = IS_ODD(b);
	assert_false(res);
	res = IS_ODD(c);
	assert_false(res);

	a = 10;
	b = 100;
	c = 1000;
	res = IS_EVEN(a);
	assert_false(res);
	res = IS_EVEN(b);
	assert_false(res);
	res = IS_EVEN(c);
	assert_false(res);

	a = 11;
	b = 101;
	c = 1001;
	res = IS_EVEN(a);
	assert_true(res);
	res = IS_EVEN(b);
	assert_true(res);
	res = IS_EVEN(c);
	assert_true(res);
}

static void Test_Equal(void **state)
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
	assert_true(res);

	a = 200;
	b = 100;
	res = IS_EQUAL(a, b);
	assert_false(res);

	a1 = 1000;
	b1 = 1000;
	res = IS_EQUAL(a1, b1);
	assert_true(res);

	a1 = 2000;
	b1 = 1000;
	res = IS_EQUAL(a1, b1);
	assert_false(res);

	a2 = 10000;
	b2 = 10000;
	res = IS_EQUAL(a2, b2);
	assert_true(res);

	a2 = 20000;
	b2 = 10000;
	res = IS_EQUAL(a2, b2);
	assert_false(res);
}

static void Test_AriphMean(void **state)
{
	int32_t res = 0;
	int8_t a = 10;
	int8_t b = 10;
	int16_t a1 = 100;
	int16_t b1 = 100;
	int32_t a2 = 1000;
	int32_t b2 = 1000;

	res = ARIPH_MEAN(a, b);
	assert_int_equal(res, 10);

	res = ARIPH_MEAN(a1, b1);
	assert_int_equal(res, 100);

	res = ARIPH_MEAN(a2, b2);
	assert_int_equal(res, 1000);
}

static void Test_MinMax(void **state)
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
	assert_int_equal(res1, b);

	a = -50;
	b = 100;
	res1 = MIN(a, b);
	assert_int_equal(res1, a);

	a1 = 2000;
	b1 = 1000;
	res2 = MIN(a1, b1);
	assert_int_equal(res2, b1);

	a1 = -2000;
	b1 = 1000;
	res2 = MIN(a1, b1);
	assert_int_equal(res2, a1);

	a2 = 20000;
	b2 = 10000;
	res3 = MIN(a2, b2);
	assert_int_equal(res3, b2);

	a2 = -20000;
	b2 = 10000;
	res3 = MIN(a2, b2);
	assert_int_equal(res3, a2);

	a = 100;
	b = 50;
	res1 = MAX(a, b);
	assert_int_equal(res1, a);

	a = -50;
	b = 100;
	res1 = MAX(a, b);
	assert_int_equal(res1, b);

	a1 = 2000;
	b1 = 1000;
	res2 = MAX(a1, b1);
	assert_int_equal(res2, a1);

	a1 = -2000;
	b1 = 1000;
	res2 = MAX(a1, b1);
	assert_int_equal(res2, b1);

	a2 = 20000;
	b2 = 10000;
	res3 = MAX(a2, b2);
	assert_int_equal(res3, a2);

	a2 = -20000;
	b2 = 10000;
	res3 = MAX(a2, b2);
	assert_int_equal(res3, b2);
}

static void Test_Bits(void **state)
{
	assert_true(false);
}
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________________________
void Test_Macros(void)
{
	  const UnitTest tests[] =
	  {
		  unit_test(Test_Sigh),
		  unit_test(Test_OddEven),
		  unit_test(Test_Equal),
		  unit_test(Test_AriphMean),
		  unit_test(Test_MinMax),
		  unit_test(Test_Bits),
	  };

	  run_tests(tests);
}
