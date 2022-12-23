/**
 * @file test_macro_align.c
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

#include "macros/align.h"
//_____ C O N F I G S  ________________________________________________________

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________

//_____ V A R I A B L E S _____________________________________________________

//_____ P R I V A T E  F U N C T I O N S_______________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________
void test_IS_ADDR_ALIGN(void)
{
	const void *ptr1 = (const void *)(0x2000);
	const void *ptr2 = (const void *)(0x2001);

	TEST_ASSERT_TRUE(IS_ADDR_ALIGN(ptr1, 4));
	TEST_ASSERT_FALSE(IS_ADDR_ALIGN(ptr2, 4));

    TEST_ASSERT_FALSE(IS_ADDR_ALIGN(ptr1, 3));
	TEST_ASSERT_TRUE(IS_ADDR_ALIGN(ptr2, 3));

	TEST_ASSERT_TRUE(IS_ADDR_ALIGN(ptr1, 2));
	TEST_ASSERT_FALSE(IS_ADDR_ALIGN(ptr2, 2));

    TEST_ASSERT_TRUE(IS_ADDR_ALIGN(ptr1, 1));
	TEST_ASSERT_TRUE(IS_ADDR_ALIGN(ptr2, 1));
}
