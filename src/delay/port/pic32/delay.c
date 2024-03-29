/**
 * \file         delay.c
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        Time delay functions for PIC32 microcontrollers. This module implements precise
 *               delay functions using the PIC32's core timer. It includes `delay_us` for microsecond
 *               delays and `delay_ms` for millisecond delays. These functions calculate delay duration
 *               based on the peripheral clock frequency (PCLK_HZ) and provide accurate timing control
 *               essential for various applications in embedded systems. It's important to define
 *               PCLK_HZ correctly for accurate timing. The implementation ensures that the core timer
 *               count is properly managed and restored after each delay, enabling consistent performance.
 *
 * \warning      Work of these functions needs to be checked and validated for specific hardware
 *               configurations.
 */


#if !defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include "delay.h"

#include <stdbool.h>
#include <stdint.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
#if !defined(PCLK_HZ)
    #error "Constant PCLK_HZ undefined. Please define peripherals bus clock in Hz\
            Example: #define PCLK_HZ 8000000"
#endif

#define COUNT_PER_USEC ((PCLK_HZ / 1000000) / 2)
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
    while (ReadCoreTimer() < targetCount) {};
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
    while (ReadCoreTimer() < targetCount) {};
    // Restore count back.
    WriteCoreTimer(bakupCount + targetCount);
}

#endif //#if !defined(PIO_UNIT_TESTING) && !defined(MODULE_DELAY_DISABLED)
