/**
 * \file         delay.c
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        Time delay functions for STM32 microcontrollers.
 */

#if !defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include "delay.h"

#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
#if !defined(SYS_CLOCK)
    #error "Constant SYS_CLOCK undefined. Please define system bus clock in Hz.\
            Example: #define SYS_CLOCK 8000000"
#endif
//_____ D E F I N I T I O N S _________________________________________________
// DWT Control register
#define DWT_CONTROL_REG (*((volatile uint32_t *)0xE0001000))

// CYCCNTENA bit in DWT_CONTROL register
#define DWT_CYCCNTENA_BIT (1UL << 0)

// DWT Cycle Counter register
#define DWT_CYCCNT_REG (*((volatile uint32_t *)0xE0001004))

// DEMCR: Debug Exception and Monitor Control Register
#define DWT_DEMCR_REG (*((volatile uint32_t *)0xE000EDFC))

// Trace enable bit in DEMCR register
#define DWT_TRCENA_BIT (1 << 24)
//_____ M A C R O S ___________________________________________________________
/**
 * \brief           Enable trace and debug block DEMCR
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_InitCycleCounter() (DWT_DEMCR_REG |= DWT_TRCENA_BIT)

/**
 * \brief           Reset cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_ResetCycleCounter() (DWT_CYCCNT_REG = 0)

/**
 * \brief           Enable cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_EnableCycleCounter() (DWT_CONTROL_REG |= DWT_CYCCNTENA_BIT)

/**
 * \brief           Disable cycle counter
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_DisableCycleCounter() (DWT_CONTROL_REG &= ~DWT_CYCCNTENA_BIT)

/**
 * \brief           Read cycle counter register
 * \param[in]       none
 * \return          none
 * \hideinitializer
 */
#define DWT_GetCycleCounter() (DWT_CYCCNT_REG)
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
    uint32_t us_count_tick = us * (SYS_CLOCK / 1000000UL);

    DWT_InitCycleCounter();    // enable DWT hardware
    DWT_ResetCycleCounter();   // reset cycle counter
    DWT_EnableCycleCounter();  // start counting

    while (DWT_GetCycleCounter() < us_count_tick) {};

    DWT_DisableCycleCounter();
}

/**
 * This function used to create ms time delay.
 *
 * Public function defined in delay.h
 */
void delay_ms(uint32_t ms)
{
    uint32_t ms_count_tick = ms * (SYS_CLOCK / 1000UL);

    DWT_InitCycleCounter();    // enable DWT hardware
    DWT_ResetCycleCounter();   // reset cycle counter
    DWT_EnableCycleCounter();  // start counting

    while (DWT_GetCycleCounter() < ms_count_tick) {};

    DWT_DisableCycleCounter();
}

#endif //#if !defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_DISABLED)
