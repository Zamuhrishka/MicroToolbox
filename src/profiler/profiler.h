/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
typedef uint32_t ticks_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief	Start timer for time profiler.
 *
 * \param 	none.
 *
 * \return 	none.
 **/
void profiler_timer_start(void);

/**
 * \brief	Stop timer for time profiler.
 *
 * \param 	none.
 *
 * \return 	number of cpu ticks.
 **/
ticks_t profiler_timer_stop(void);

/**
 * \brief	Convert number of cpu ticks into time.
 *
 * \param   ticks[in]	Number of cpu ticks.
 *
 * \return  time.
 **/
float profiler_ticks_to_time(ticks_t ticks);
