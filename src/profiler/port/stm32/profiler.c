/**
 * \file         profiler.c
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief
 *
 * \warning		Work of this functions need to be checked!
 */
//_____ I N C L U D E S _______________________________________________________
#include "profiler.h"

#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
#if !defined(SYS_CLOCK)
    #error "Constant SYS_CLOCK undefined. Please define system bus clock in Hz.\
			Example: #define SYS_CLOCK 8000000"
#endif
//_____ D E F I N I T I O N S _________________________________________________
// DWT Control register
#define DWT_CONTROL_REG (*((volatile uint32_t*)0xE0001000))

// CYCCNTENA bit in DWT_CONTROL register
#define DWT_CYCCNTENA_BIT (1UL << 0)

// DWT Cycle Counter register
#define DWT_CYCCNT_REG (*((volatile uint32_t*)0xE0001004))

// DEMCR: Debug Exception and Monitor Control Register
#define DWT_DEMCR_REG (*((volatile uint32_t*)0xE000EDFC))

// Trace enable bit in DEMCR register
#define DWT_TRCENA_BIT (1UL << 24)
//_____ M A C R O S ___________________________________________________________
// TRCENA: Enable trace and debug block DEMCR (Debug Exception and Monitor Control Register
#define DWT_InitCycleCounter() (DWT_DEMCR_REG |= DWT_TRCENA_BIT)

// Reset cycle counter
#define DWT_ResetCycleCounter() (DWT_CYCCNT_REG = 0)

// Enable cycle counter
#define DWT_EnableCycleCounter() (DWT_CONTROL_REG |= DWT_CYCCNTENA_BIT)

// Disable cycle counter
#define DWT_DisableCycleCounter() (DWT_CONTROL_REG &= ~DWT_CYCCNTENA_BIT)

// Read cycle counter register
#define DWT_GetCycleCounter() (DWT_CYCCNT_REG)
//_____ V A R I A B L E S _____________________________________________________
static ticks_t ticks = 0;
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * Start timer for time profiler.
 *
 * Public function defined in profiler.h
 */
void profiler_timer_start(void)
{
    ticks = 0;
    DWT_InitCycleCounter();   /* enable DWT hardware */
    DWT_ResetCycleCounter();  /* reset cycle counter */
    DWT_EnableCycleCounter(); /* start counting */
}

/**
 * Stop timer for time profiler.
 *
 * Public function defined in profiler.h
 */
ticks_t profiler_timer_stop(void)
{
    ticks = DWT_GetCycleCounter(); /* get cycle counter */
    DWT_DisableCycleCounter();     /* disable counting if not used any more */
    return ticks;
}

/**
 * This function convert number of cpu ticks into time..
 *
 * Public function defined in profiler.h
 */
float profiler_ticks_to_time(ticks_t ticks)
{
    float time = 0.0f;

    time = ticks / SYS_CLOCK;

    return time;
}