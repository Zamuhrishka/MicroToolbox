/**
* \file         template.c
* \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains the prototypes functions which use for...
*/
//_____ I N C L U D E S _______________________________________________________
#include "unity.h"

#include "sfloat.h"

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

void test_Sfloat(void)
{
    sfloat_t sf = {0};
    float f = 0.0f;

    sf = float_to_sfloat(0.0f);

    TEST_ASSERT_EQUAL_UINT(sf.value, 0);
    TEST_ASSERT_EQUAL_UINT(sf.scale, 1);

    f = sfloat_to_float(&sf);

    TEST_ASSERT_EQUAL_FLOAT(0.0f, f);

    sf = float_to_sfloat(10.5);

    TEST_ASSERT_EQUAL_UINT(sf.value, 105);
    TEST_ASSERT_EQUAL_UINT(sf.scale, 10);

    f = sfloat_to_float(&sf);

    TEST_ASSERT_EQUAL_FLOAT(10.5, f);


    sf = float_to_sfloat(0.5f);

    TEST_ASSERT_EQUAL_UINT(sf.value, 5);
    TEST_ASSERT_EQUAL_UINT(sf.scale, 10);

    f = sfloat_to_float(&sf);

    TEST_ASSERT_EQUAL_FLOAT(0.5f, f);
}

/* Special guard for case when unit tests were run not by PlatformIO but by Ceedling for example */
#ifdef PIO_UNIT_TESTING
int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_Sfloat);
  return UNITY_END();
}


/**
  * For native dev-platform or for some embedded frameworks
  */
int main(void) {
  return runTests();
}
#endif
