/**
* \file         profiler.h
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
typedef uint32_t ticks_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * @brief	Start time profiler.
 *
 * @param 	none.
 *
 * @return 	none.
**/
void profiler_start(void);

/**
 * @brief	Stop time profiler.
 *
 * @param 	none.
 *
 * @return 	number of cpu ticks.
**/
ticks_t profiler_stop(void);

/**
 * @brief	Convert number of cpu ticks into time.
 *
 * @param ticks[in]	Number of cpu ticks.
 *
 * @return time.
**/
float profiler_ticks_to_time(ticks_t ticks);

/* C++ detection */
#ifdef __cplusplus
}
#endif