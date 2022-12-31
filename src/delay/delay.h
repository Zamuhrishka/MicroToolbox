/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        Time delay functions.
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief 	    This function used to create `us` time delay.
 *
 * \warning      blocking function!
 *
 * \param[in]    us: value of time delay in `us`.
 *
 * \return 	    none.
 */
void delay_us(uint32_t us);

/**
 * \brief 	    This function used to create `ms` time delay.
 *
 * \warning      blocking function!
 *
 * \param[in]    ms: value of time delay in `ms`.
 *
 * \return 	    none.
 */
void delay_ms(uint32_t ms);
