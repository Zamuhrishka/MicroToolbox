/**
* \file         delay.c
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains the prototypes functions which use for...
*/
//_____ I N C L U D E S _______________________________________________________
#include "delay.h"

#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
#if !defined(PCLK_MHZ)
	#error "Constant PCLK_MHZ undefined. Please define peripherals bus clock (MHz)"
#endif

#define COUNT_PER_USEC                  ((PCLK_MHZ/1000000)/2)
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function used to create us time delay.
*
* Public function defined in delay.h
*/
void delay_us(uint32_t us)
{
	uint32_t targetCount;
	uint32_t bakupCount;

	// Assert "us" not zero. This must be caught during debug phase.
	assert(us != 0);
	// backup current count of the core timer.
	bakupCount = ReadCoreTimer();
	// Core timer increments every 2 sys clock cycles.
	// Calculate the counts required to complete "us".
	targetCount = COUNT_PER_USEC * us;
	// Restart core timer.
	WriteCoreTimer(0);
	// Wait till core timer completes the count.
	while(ReadCoreTimer() < targetCount) {};
	// Restore count back.
	WriteCoreTimer(bakupCount + targetCount);
}

/**
* This function used to create ms time delay.
*
* Public function defined in delay.h
*/
void delay_ms(uint32_t ms)
{
	uint32_t targetCount;
	uint32_t bakupCount;

	// Assert "us" not zero. This must be caught during debug phase.
	assert(ms != 0);
	// backup current count of the core timer.
	bakupCount = ReadCoreTimer();
	// Core timer increments every 2 sys clock cycles.
	// Calculate the counts required to complete "us".
	targetCount = COUNT_PER_USEC * ms * 1000 {};
	// Restart core timer.
	WriteCoreTimer(0);
	// Wait till core timer completes the count.
	while(ReadCoreTimer() < targetCount);
	// Restore count back.
	WriteCoreTimer(bakupCount + targetCount);
}