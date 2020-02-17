/********************************************************************************
*
* @file    		template.h
* @author  		Kovalchuk Alexander
* @email  		alexander.kovalchuk@promwad.com
* @brief   		This file contains the prototypes functions and methods
*
********************************************************************************/
#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
#ifndef SYS_CLOCK
	#define SYS_CLOCK		135000000UL
#endif
//_____ D E F I N I T I O N ___________________________________________________
typedef void (*TriggerLowFP)(void);
typedef void (*TriggerHighFP)(void);
typedef uint32_t ticks_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I �  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
/**
 * @brief				Put trigger function to low.
 *
 * @param cb[in]		Callback function for putting trigger to low.
 *
 * @return 				none.
**/
void profile_trigger_low_cb(TriggerLowFP cb);

/**
 * @brief				Put trigger function to high.
 *
 * @param cb[in]		Callback function for putting trigger to high.
 *
 * @return 				none.
**/
void profile_trigger_high_cb(TriggerHighFP cb);

/**
 * @brief				Start time profile.
 *
 * @param 				none.
 *
 * @return 				none.
**/
void profile_ticks_start(void);

/**
 * @brief				Stop time profile.
 *
 * @param 				none.
 *
 * @return 				number of cpu ticks.
**/
ticks_t profile_ticks_stop(void);

/**
 * @brief				Convert number of cpu ticks into time.
 *
 * @param ticks[in]		Number of cpu ticks.
 *
 * @return 				time.
**/
float profile_ticks_to_time(ticks_t ticks);



/* C++ detection */
#ifdef __cplusplus
}
#endif
