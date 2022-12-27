/**
* \file         align.h
* \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
* \brief        This file contains the prototypes functions and macros which 
*               used for data align.   
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//TODO: Need to make compiler independet align attribute
// #include "environment/compiler.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
/**
 * \brief Macros which forces a variable to always be aligned
 * 
 * \param[in] 	A: alignment value in bytes.
 */
#define ALIGN(A)       (__attribute__ ((aligned (A))))

/**
 * \brief Wrap the given structure into a padded, aligned structure and instantiate a static copy of it.
 * 
 * \param[in] 	T: the type of structure to be wrapped.
 * \param[in] 	N: instantiation name of wrapped structure.
 * \param[in] 	A: alignment value in bytes.
 * 
 * \example:
 *     typedef struct
 *     {
 *         DeviceContext_t * pDevContext;
 *     } BssContextData_t;
 *     
 *     CACHE_LINE_ALIGN__STATIC(BssContextData_t, bssData, 32);
 *
 * The data can then be access as per this example:
 *
 *     return bssData.d.pDevContext;
 */
#define CACHE_LINE_ALIGN__STATIC(T, N, A) \
        __attribute__ ((aligned (A))) typedef struct { T d; uint8_t p[(A) - (sizeof(T) % (A))]; } T##Full_t; static T##Full_t N


/**
 * \brief The following two macros support a non-static structure which can be defined in a header file
 * and instantiated in a separate .c file.
 *
 * \param[in] 	T: the type of structure to be wrapped.
 * \param[in] 	N: instantiation name of wrapped structure.
 * \param[in] 	A: alignment value in bytes.
 * 
 * The TYPE macro defines the padded structure type and externs it so that it can be accessed
 * from any file including the header.
 * The INST macro instantiates the type.  It must be given the same parameters as the TYPE macro.
 */
#define CACHE_LINE_ALIGN__TYPE(T, N, A) \
        __attribute__ ((aligned ((A)))) typedef struct { T d; uint8_t p[(A) - (sizeof(T) % (A))]; } T##Full_t; extern T##Full_t N

#define CACHE_LINE_ALIGN__INST(T, N) T##Full_t N

/**
 * \brief Forces alignment of elements within a user defined type (ADT).
 * You can use this macro to separate uncached and cached areas.
 * 
 * \param[in] 	A: alignment value in bytes.
 *
 * \example:
 * typedef struct
 * {
 *      uint8_t data1;
 *      CACHE_ALIGN_STRUCT(32);
 *      uint8_t data2;
 *      CACHE_ALIGN_STRUCT(32);
 *      uint8_t data3;
 * } SomeData_t; 
 *
 */
#define STRCONCAT(x, y)             x ## y
#define STRCONCATHELPER(x, y)       STRCONCAT(x, y)
#define CACHE_ALIGN_STRUCT(A) \
        struct { uint8_t pad[0]; } STRCONCATHELPER(align, __LINE__) __attribute__ ((aligned ((A))))

//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/** \brief          Check if addr is alignment by align bytes.
 *  \param[in]      addr: checked addr
 *  \param[in]      align: alignment value in bytes 
 *  \return         true - if addr is align.
*/
static __inline__ bool is_align(uintptr_t addr, size_t align)
{
    return (((uintptr_t)(addr)) % (align) == 0);
}

/** \brief          Align addr by lower bytes number
 *  \param[in]      addr: given addr
 *  \param[in]      align: alignment value in bytes 
 *  \return         aligned addr.
*/
static __inline__ uintptr_t align_down(uintptr_t addr, size_t align)
{
    return ((uintptr_t)((addr) & ~((align) - 1)));
}

/** \brief          Align addr by higher bytes number
 *  \param[in]      addr: given addr
 *  \param[in]      align: alignment value in bytes 
 *  \return         aligned addr.
*/
static __inline__ uintptr_t align_up(uintptr_t addr, size_t align)
{
    return ((addr & (align - 1)) ? (align_down(addr, align) + align) : addr);
}

/* C++ detection */
#ifdef __cplusplus
}
#endif
