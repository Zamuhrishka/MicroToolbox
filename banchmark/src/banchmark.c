/********************************************************************************
*
* @file    		template.h
* @author  		Kovalchuk Alexander
* @email  		alexander.kovalchuk@promwad.com
* @brief   		This file contains the prototypes functions and methods
*
********************************************************************************/
//_____ I N C L U D E S _______________________________________________________
#include "banchmark.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//_____ D E F I N I T I O N ___________________________________________________
//DWT Control register
#define DWT_CONTROL_REG             	(*((volatile uint32_t*)0xE0001000))

//CYCCNTENA bit in DWT_CONTROL register
#define DWT_CYCCNTENA_BIT       		(1UL<<0)

//DWT Cycle Counter register
#define DWT_CYCCNT_REG              	(*((volatile uint32_t*)0xE0001004))

//DEMCR: Debug Exception and Monitor Control Register
#define DWT_DEMCR_REG                 	(*((volatile uint32_t*)0xE000EDFC))

//Trace enable bit in DEMCR register
#define DWT_TRCENA_BIT              	(1UL<<24)
//_____ M A C R O S ___________________________________________________________
// TRCENA: Enable trace and debug block DEMCR (Debug Exception and Monitor Control Register
#define DWT_InitCycleCounter()   		(DWT_DEMCR_REG |= DWT_TRCENA_BIT)

// Reset cycle counter
#define DWT_ResetCycleCounter()   		(DWT_CYCCNT_REG = 0)

// Enable cycle counter
#define DWT_EnableCycleCounter()  		(DWT_CONTROL_REG |= DWT_CYCCNTENA_BIT)

// Disable cycle counter
#define DWT_DisableCycleCounter()   	(DWT_CONTROL_REG &= ~DWT_CYCCNTENA_BIT)

// Read cycle counter register
#define DWT_GetCycleCounter()   		(DWT_CYCCNT_REG)

//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
static ticks_t ticks = 0;
static TriggerLowFP trigger_low = NULL;
static TriggerHighFP trigger_high = NULL;
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I С  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________
/**
 * @brief				Put trigger function to low.
 *
 * @param cb[in]		Callback function for putting trigger to low.
 *
 * @return 				none.
**/
void profile_trigger_low_cb(TriggerLowFP cb)
{
	if(cb != NULL) {
		trigger_low = cb;
	}
}

/**
 * @brief				Put trigger function to high.
 *
 * @param cb[in]		Callback function for putting trigger to high.
 *
 * @return 				none.
**/
void profile_trigger_high_cb(TriggerHighFP cb)
{
	if(cb != NULL) {
		trigger_high = cb;
	}
}

/**
 * @brief				Start time profile.
 *
 * @param 				none.
 *
 * @return 				none.
**/
void profile_ticks_start(void)
{
	ticks = 0;
	DWT_InitCycleCounter(); 									/* enable DWT hardware */
	DWT_ResetCycleCounter(); 									/* reset cycle counter */
	DWT_EnableCycleCounter(); 									/* start counting */
}

/**
 * @brief				Stop time profile.
 *
 * @param 				none.
 *
 * @return 				number of cpu ticks.
**/
ticks_t profile_ticks_stop(void)
{
	ticks = DWT_GetCycleCounter(); 								/* get cycle counter */
	DWT_DisableCycleCounter(); 									/* disable counting if not used any more */
	return ticks;
}

/**
 * @brief				Convert number of cpu ticks into time.
 *
 * @param ticks[in]		Number of cpu ticks.
 *
 * @return 				time.
**/
float profile_ticks_to_time(ticks_t ticks)
{
	float time = 0.0f;

	if(SYS_CLOCK != 0)
	{
		time = ticks/SYS_CLOCK;
	}

	return time;
}
