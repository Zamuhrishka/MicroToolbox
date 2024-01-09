/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This module provides basic timing functions for creating precise microsecond and
 *               millisecond delays in embedded systems. It is essential for timing control in various
 *               hardware interfacing and control applications. The functions `delay_us` and `delay_ms`
 *               offer microsecond and millisecond resolution respectively, suitable for scenarios
 *               where specific timing is critical. Note that these functions are blocking, meaning
 *               they halt the execution of the program for the specified duration of time.
 */


#pragma once

#if !defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief       This function used to create `us` time delay.
 *
 * \warning      blocking function!
 *
 * \param[in]    us: value of time delay in `us`.
 *
 * \return       none.
 */
void delay_us(uint32_t us);

/**
 * \brief       This function used to create `ms` time delay.
 *
 * \warning      blocking function!
 *
 * \param[in]    ms: value of time delay in `ms`.
 *
 * \return       none.
 */
void delay_ms(uint32_t ms);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif //!defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_ENABLE)
