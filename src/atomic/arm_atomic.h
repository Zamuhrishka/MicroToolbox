/********************************************************************************
*
* @file    		arm_atomic.h
* @author  		Kovalchuk Alexander aka Zamuhrishka
* @email  		roux@yandex.ru
* @version 		0.1
* @created 		02.11.2017
* @brief   		This file contains the functions and macros for atomic operations
*
********************************************************************************/
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
//_____ C O N F I G S  ________________________________________________________________________
//_____ I N C L U D E S _______________________________________________________________________
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"
//_____ � O N F I G S__________________________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________________________
#define MASK_TO_BIT31(A)        				(A==0x80000000)? 31 : 0
#define MASK_TO_BIT30(A)        				(A==0x40000000)? 30 : MASK_TO_BIT31(A)
#define MASK_TO_BIT29(A)        				(A==0x20000000)? 29 : MASK_TO_BIT30(A)
#define MASK_TO_BIT28(A)        				(A==0x10000000)? 28 : MASK_TO_BIT29(A)
#define MASK_TO_BIT27(A)        				(A==0x08000000)? 27 : MASK_TO_BIT28(A)
#define MASK_TO_BIT26(A)        				(A==0x04000000)? 26 : MASK_TO_BIT27(A)
#define MASK_TO_BIT25(A)        				(A==0x02000000)? 25 : MASK_TO_BIT26(A)
#define MASK_TO_BIT24(A)        				(A==0x01000000)? 24 : MASK_TO_BIT25(A)
#define MASK_TO_BIT23(A)        				(A==0x00800000)? 23 : MASK_TO_BIT24(A)
#define MASK_TO_BIT22(A)        				(A==0x00400000)? 22 : MASK_TO_BIT23(A)
#define MASK_TO_BIT21(A)        				(A==0x00200000)? 21 : MASK_TO_BIT22(A)
#define MASK_TO_BIT20(A)        				(A==0x00100000)? 20 : MASK_TO_BIT21(A)
#define MASK_TO_BIT19(A)        				(A==0x00080000)? 19 : MASK_TO_BIT20(A)
#define MASK_TO_BIT18(A)        				(A==0x00040000)? 18 : MASK_TO_BIT19(A)
#define MASK_TO_BIT17(A)        				(A==0x00020000)? 17 : MASK_TO_BIT18(A)
#define MASK_TO_BIT16(A)        				(A==0x00010000)? 16 : MASK_TO_BIT17(A)
#define MASK_TO_BIT15(A)        				(A==0x00008000)? 15 : MASK_TO_BIT16(A)
#define MASK_TO_BIT14(A)        				(A==0x00004000)? 14 : MASK_TO_BIT15(A)
#define MASK_TO_BIT13(A)       	 				(A==0x00002000)? 13 : MASK_TO_BIT14(A)
#define MASK_TO_BIT12(A)        				(A==0x00001000)? 12 : MASK_TO_BIT13(A)
#define MASK_TO_BIT11(A)        				(A==0x00000800)? 11 : MASK_TO_BIT12(A)
#define MASK_TO_BIT10(A)        				(A==0x00000400)? 10 : MASK_TO_BIT11(A)
#define MASK_TO_BIT09(A)        				(A==0x00000200)? 9  : MASK_TO_BIT10(A)
#define MASK_TO_BIT08(A)        				(A==0x00000100)? 8  : MASK_TO_BIT09(A)
#define MASK_TO_BIT07(A)        				(A==0x00000080)? 7  : MASK_TO_BIT08(A)
#define MASK_TO_BIT06(A)        				(A==0x00000040)? 6  : MASK_TO_BIT07(A)
#define MASK_TO_BIT05(A)        				(A==0x00000020)? 5  : MASK_TO_BIT06(A)
#define MASK_TO_BIT04(A)        				(A==0x00000010)? 4  : MASK_TO_BIT05(A)
#define MASK_TO_BIT03(A)        				(A==0x00000008)? 3  : MASK_TO_BIT04(A)
#define MASK_TO_BIT02(A)        				(A==0x00000004)? 2  : MASK_TO_BIT03(A)
#define MASK_TO_BIT01(A)        				(A==0x00000002)? 1  : MASK_TO_BIT02(A)
#define MASK_TO_BIT(A)          				(A==0x00000001)? 0  : MASK_TO_BIT01(A)

//_____ M A C R O S ___________________________________________________________________________
inline static int _irqDis(void)
{
    __ASM volatile ("cpsid i" : : : "memory");
    return 1;
}

inline static int _irqEn(void)
{
    __ASM volatile ("cpsie i" : : : "memory");
    return 0;
}

#define ATOMIC_BLOCK_FORCEON \
    for(int flag = _irqDis();\
        flag;\
        flag = _irqEn())



inline static int _iDisGetPrimask(void)
{
    int result;
    __ASM volatile ("MRS %0, primask" : "=r" (result) );
    __ASM volatile ("cpsid i" : : : "memory");
    return result;
}

inline static int _iSetPrimask(int priMask)
{
    __ASM volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
    return 0;
}

#define ATOMIC_BLOCK_RESTORATE \
     for(int mask = _iDisGetPrimask(), flag = 1;\
         flag;\
         flag = _iSetPrimask(mask))




//! This macros set bit in register using bit-banding mechanism
//!
//! @param reg[in] - Register address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicSetBitReg(reg, bit)				((*(volatile uint32_t*)(PERIPH_BB_BASE+32*((uint32_t)(&(reg))-PERIPH_BASE) + \
													4*((uint32_t)(MASK_TO_BIT(((1<<(bit)))))))) = 1)

//! This macros clear bit in register using bit-banding mechanism
//!
//! @param reg[in] - Register address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicClrBitReg(reg, bit)				((*(volatile uint32_t*)(PERIPH_BB_BASE+32*((uint32_t)(&(reg))-PERIPH_BASE) + \
													4*((uint32_t)(MASK_TO_BIT(((1<<(bit)))))))) = 0)

//! This macros invert bit in register using bit-banding mechanism
//!
//! @param reg[in] - Register address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicInvBitReg(reg, bit)				((*(volatile uint32_t*)(PERIPH_BB_BASE+32*((uint32_t)(&(reg))-PERIPH_BASE) + \
													4*((uint32_t)(MASK_TO_BIT(((1<<(bit)))))))) ^= 1)

//! This macros set bit in ram using bit-banding mechanism
//!
//! @param ram[in] - RAM address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicSetBitMem(ram, bit)				((*(volatile uint32_t*)(SRAM_BB_BASE+32*((uint32_t)((void*)(ram))-SRAM_BASE) + \
													4*((uint32_t)(1<<(bit))))) = 1)

//! This macros clear bit in ram using bit-banding mechanism
//!
//! @param ram[in] - RAM address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicClrBitMem(ram, bit)				((*(volatile uint32_t*)(SRAM_BB_BASE+32*((uint32_t)((void*)(ram))-SRAM_BASE) + \
													4*((uint32_t)(1<<(bit))))) = 0)

//! This macros invert bit in ram using bit-banding mechanism
//!
//! @param ram[in] - RAM address
//! @param bit[in] - Number of bit
//!
//! @return none.
//!
#define AtomicInvBitMem(ram, bit)				((*(volatile uint32_t*)(SRAM_BB_BASE+32*((uint32_t)((void*)(ram))-SRAM_BASE) + \
													4*((uint32_t)(1<<(bit))))) ^= 1)


//! This macros creates a block of code that is guaranteed
//! to be executed atomically.
//!
//! @param saved state
//!
//! @return none
//!
#define CRITICAL_BLOCK(x) 							do 	\
													{ \
														__disable_irq(); \
														{ \
															x \
														} \
														__enable_irq(); \
													}while(0);

//! This macros begin critical code block
//!
//! @param none
//!
//! @return none.
//!
#define CriticalBlockBegin()						(__disable_irq())

//! This macros end critical code block
//!
//! @param none
//!
//! @return none.
//!
#define CriticalBlockEnd()							(__enable_irq())
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________________________
//_____ I N L I N E   F U N C T I O N S _______________________________________________________
/**
* @brief 	The classic atomic Compare And Swap (CAS) operation.
*
* @detail	If current value in memory address ptr equal expected value (byte) then
* 			save new value in memory if not equal then return false and
* 			do not save anything
*
* @param  	addr[in] - memory address.
* @param  	expectedValue[in] - expected value.
* @param  	newValue[in] - new value.
*
* @return 	true/false.
*/
static inline bool CompareAndSwapByte(uint8_t* addr, uint8_t expectedValue, uint8_t newValue)
{
	uint8_t currentValue = __LDREXB(addr);

	if(currentValue != expectedValue) {
		return false;
	}
	__STREXB(newValue, addr);
	return true;
}

/**
* @brief 	The classic atomic Compare And Swap (CAS) operation.
*
* @detail	If current value in memory address ptr equal expected value (half) then
* 			save new value in memory if not equal then return false and
* 			do not save anything
*
* @param  	addr[in] - memory address.
* @param  	expectedValue[in] - expected value.
* @param  	newValue[in] - new value.
*
* @return 	true/false.
*/
static inline bool CompareAndSwapHalf(uint16_t* addr, uint16_t expectedValue, uint16_t newValue)
{
	uint16_t oldValue = __LDREXH(addr);

	if(oldValue == expectedValue) {
		return false;
	}
	__STREXH(newValue, addr);
	return true;
}

/**
* @brief 	The classic atomic Compare And Swap (CAS) operation.
*
* @detail	If current value in memory address ptr equal expected value (word) then
* 			save new value in memory if not equal then return false and
* 			do not save anything
*
* @param  	addr[in] - memory address.
* @param  	expectedValue[in] - expected value.
* @param  	newValue[in] - new value.
*
* @return 	true/false.
*/
static inline bool CompareAndSwapWord(uint32_t* addr, uint32_t expectedValue, uint32_t newValue)
{
	uint32_t oldValue = __LDREXW(addr);

	if(oldValue == expectedValue) {
		return false;
	}
	__STREXW(newValue, addr);
	return true;
}

/**
* @brief 	The classic atomic Fetch And Add operation.
*
* @detail	This function atomic add some value to the memory variable
*
* @param  	addr[in] - memory address.
* @param  	value[in] - value.
*
* @return 	none.
*/
static inline void FetchAndAddByte(uint8_t* addr, uint8_t value)
{
	uint8_t oldValue;
	do
	{
		oldValue = *addr;
	}while(CompareAndSwapByte(addr, oldValue, (oldValue + value)));
}

/**
* @brief 	The classic atomic Fetch And Add operation.
*
* @detail	This function atomic add some value to the memory variable
*
* @param  	addr[in] - memory address.
* @param  	value[in] - value.
*
* @return 	none.
*/
static inline void FetchAndAddHalf(uint16_t* addr, uint16_t value)
{
	uint16_t oldValue;
	do
	{
		oldValue = *addr;
	}while(CompareAndSwapHalf(addr, oldValue, (oldValue + value)));
}

/**
* @brief 	The classic atomic Fetch And Add operation.
*
* @detail	This function atomic add some value to the memory variable
*
* @param  	addr[in] - memory address.
* @param  	value[in] - value.
*
* @return 	none.
*/
static inline void FetchAndAddWord(uint32_t* addr, uint32_t value)
{
	uint32_t oldValue;
	do
	{
		oldValue = *addr;
	}while(CompareAndSwapWord(addr, oldValue, (oldValue + value)));
}

/**
* @brief 	Atomic operation Read-Modification-Write of byte from/to memory addr.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - new value.
*
* @return 	none.
*/
static inline void AtomicWriteByte(volatile uint8_t *addr, uint8_t value)
{
	do {
		uint8_t oldValue = __LDREXB(addr);
	}while(__STREXB(value, addr));
}


/**
* @brief 	Atomic operation Read-Modification-Write of half word from/to memory addr.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - new value.
*
* @return 	none.
*/
static inline void AtomicWriteHalf(volatile uint16_t *addr, uint16_t value)
{
	do {
		uint16_t oldValue = __LDREXH(addr);
	}while(__STREXH(value, addr));
}

/**
* @brief 	Atomic operation Read-Modification-Write of half byte from/to memory addr.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - new value.
*
* @return 	none.
*/
static inline void AtomicWriteWord(volatile uint32_t *addr, uint32_t value)
{
	do {
		uint32_t oldValue = __LDREXW(addr);
	}while(__STREXW(value, addr));
}

/**
* @brief 	Atomic operation increment of byte.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicIncByte(volatile uint8_t *addr)
{
	uint8_t byte = 0;
	do {
		byte = __LDREXB(addr) + 1ul;
	}while(__STREXB(byte, addr));
}

/**
* @brief 	Atomic operation increment of half word.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicIncHalf(volatile uint16_t *addr)
{
	uint16_t half = 0;
	do {
		half = __LDREXH(addr) + 1ul;
	}while(__STREXH(half, addr));
}

/**
* @brief 	Atomic operation increment of word.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicIncWord(volatile uint32_t *addr)
{
	uint32_t word = 0;
	do {
		word = __LDREXW(addr) + 1ul;
	}while(__STREXW(word, addr));
}

/**
* @brief 	Atomic operation decrement of byte.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicDecByte(volatile uint8_t *addr)
{
	uint8_t byte = 0;
	do {
		byte = __LDREXB(addr) - 1ul;
	}while(__STREXB(byte, addr));
}

/**
* @brief 	Atomic operation decrement of half word.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicDecHalf(volatile uint16_t *addr)
{
	uint16_t half = 0;
	do {
		half = __LDREXH(addr) - 1ul;
	}while(__STREXH(half, addr));
}

/**
* @brief 	Atomic operation decrement of word.
*
* @param  	addr[in] - memory address.
*
* @return 	none.
*/
static inline void AtomicDecWord(volatile uint32_t *addr)
{
	uint32_t word = 0;
	do {
		word = __LDREXW(addr) - 1ul;
	}while(__STREXW(word, addr));
}

/**
* @brief 	Atomic compare two bytes operation.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - the value with which we compare.
*
* @return 	none.
*/
static inline bool AtomicCompareByte(volatile uint8_t *addr, uint8_t value)
{
	bool result = (__LDREXB(addr) == value) ? true : false;
	__CLREX();
	return result;
}

/**
* @brief 	Atomic compare two half word operation.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - the value with which we compare.
*
* @return 	none.
*/
static inline bool AtomicCompareHalf(volatile uint16_t *addr, uint16_t value)
{
	bool result = (__LDREXH(addr) == value) ? true : false;
	__CLREX();
	return result;
}

/**
* @brief 	Atomic compare two word operation.
*
* @param  	addr[in] - memory address.
* @param  	value[in] - the value with which we compare.
*
* @return 	none.
*/
static inline bool AtomicCompareWord(volatile uint32_t *addr, uint32_t value)
{
	bool result = (__LDREXW(addr) == value) ? true : false;
	__CLREX();
	return result;
}

/**
* @brief 	Atomic read byte.
*
* @param  	addr[in] - memory address.
*
* @return 	read byte.
*/
static inline uint8_t AtomicReadByte(volatile uint8_t *addr)
{
	uint8_t result = __LDREXB(addr);
	__CLREX();
	return result;
}

/**
* @brief 	Atomic read half word.
*
* @param  	addr[in] - memory address.
*
* @return 	read half word.
*/
static inline uint16_t AtomicReadHalf(volatile uint16_t *addr)
{
	uint16_t result = __LDREXH(addr);
	__CLREX();
	return result;
}

/**
* @brief 	Atomic read word.
*
* @param  	addr[in] - memory address.
*
* @return 	read word.
*/
static inline uint32_t AtomicReadWord(volatile uint32_t *addr)
{
	uint32_t result = __LDREXW(addr);
	__CLREX();
	return result;
}

//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________________________
#ifdef __cplusplus
}
#endif
