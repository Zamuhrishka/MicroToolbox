/**
* \file         test_map.c
* \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains unit tests for map() function
*               from @conversion.c file
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
void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

/**
 * @brief Unit test for checking map() function with positive arguments
 */
void test_MapPositive(void)
{
    int32_t input[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,\
                    1007,1008,1009,1010,1011,1012,1013,1014,\
                    1015,1016,1017,1018,1019,1020,1021,1022,1023};

    int32_t expected[] = {0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,\
                        251,251,251,251,252,252,252,252,\
                        253,253,253,253,254,254,254,254,255};

    for (size_t i = 0; i < sizeof(input)/sizeof(int32_t); i++)
    {
        int32_t output = map(input[i], 0, 1023, 0, 255);
        TEST_ASSERT_EQUAL_INT(output, expected[i]);
    }
}

/**
 * @brief Unit test for checking map() function with negative arguments
 */
void test_MapNegative(void)
{
    int32_t input[] = {0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,\
                    -1007,-1008,-1009,-1010,-1011,-1012,-1013,-1014,\
                    -1015,-1016,-1017,-1018,-1019,-1020,-1021,-1022,-1023};

    int32_t expected[] = {0,0,0,0,0,-1,-1,-1,-1,-2,-2,-2,-2,-3,-3,-3,\
                        -251,-251,-251,-251,-252,-252,-252,-252,\
                        -253,-253,-253,-253,-254,-254,-254,-254,-255};

    for (size_t i = 0; i < sizeof(input)/sizeof(int32_t); i++)
    {
        int32_t output = map(input[i], 0, 1023, 0, 255);
        TEST_ASSERT_EQUAL_INT(output, expected[i]);
    }
}

/* Special guard for case when unit tests were run not by PlatformIO but by Ceedling for example */
#ifdef PIO_UNIT_TESTING
int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_MapPositive);
  RUN_TEST(test_MapNegative);
  return UNITY_END();
}


/**
  * For native dev-platform or for some embedded frameworks
  */
int main(void) {
  return runTests();
}
#endif
