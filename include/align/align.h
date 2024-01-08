/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        This file contains the prototypes functions and macros which
 *               used for data align.
 */

#pragma once

#if !defined(MODULE_ALIGN_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// TODO: Need to make compiler independet align attribute
#include "compiler.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
/*! \cond PRIVATE */
#define STRCONCAT(x, y)       x##y
#define STRCONCATHELPER(x, y) STRCONCAT(x, y)
/*! \endcond */

/**
 * \brief       Macros which forces a variable to always be aligned.
 *
 * \param[in]   A: alignment value in bytes.
 */
#define ALIGN(A) (__attribute__((aligned(A))))

/**
 * \brief       Wrap the given structure into a padded, aligned structure
 *              and instantiate a static copy of it.
 *
 * \param[in]   T: the type of structure to be wrapped.
 * \param[in]   N: instantiation name of wrapped structure.
 * \param[in]   A: alignment value in bytes.
 *
 * \code
 *     typedef struct
 *     {
 *         DeviceContext_t * pDevContext;
 *     } BssContextData_t;
 *
 *     CACHE_LINE_ALIGN__STATIC(BssContextData_t, bssData, 32);
 * \endcode
 *
 * The data can then be access as per this example:
 *
 * \code
 *     return bssData.d.pDevContext;
 * \endcode
 */
#define CACHE_LINE_ALIGN__STATIC(T, N, A) \
    __attribute__((aligned(A))) typedef struct \
    { \
        T d; \
        uint8_t p[(A) - (sizeof(T) % (A))]; \
    } T##Full_t; \
    static T##Full_t N

/**
 * \brief       Definition of aligned non-static structure.
 *
 * The `TYPE` macro defines the padded structure type and externs it so that it can be accessed
 * from any file including the header.
 *
 * \param[in]   T: the type of structure to be wrapped.
 * \param[in]   N: instantiation name of wrapped structure.
 * \param[in]   A: alignment value in bytes.
 *
 */
#define CACHE_LINE_ALIGN__TYPE(T, N, A) \
    __attribute__((aligned((A)))) typedef struct \
    { \
        T d; \
        uint8_t p[(A) - (sizeof(T) % (A))]; \
    } T##Full_t; \
    extern T##Full_t N

/**
 * \brief       Instantiate of aligned non-static structure.
 *
 * \warning     The INST macro instantiates the type. It must be given the same parameters as the \ref
 * CACHE_LINE_ALIGN__TYPE macro.
 *
 * \param[in]   T: the type of structure to be wrapped.
 * \param[in]   N: instantiation name of wrapped structure.
 *
 */
#define CACHE_LINE_ALIGN__INST(T, N) T##Full_t N

/**
 * \brief       Forces alignment of elements within a user defined type (ADT).
 *              You can use this macro to separate uncached and cached areas.
 *
 * \param[in]   A: alignment value in bytes.
 *
 * \code
 * typedef struct
 * {
 *      uint8_t data1;
 *      CACHE_ALIGN_STRUCT(32);
 *      uint8_t data2;
 *      CACHE_ALIGN_STRUCT(32);
 *      uint8_t data3;
 * } SomeData_t;
 * \endcode
 */
#define CACHE_ALIGN_STRUCT(A) \
    struct \
    { \
        uint8_t pad[0]; \
    } STRCONCATHELPER(align, __LINE__) __attribute__((aligned((A))))

//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/** \brief          Checking whether the addr is aligned to a given number of bytes?
 *
 *  \param[in]      addr: checked addr
 *  \param[in]      align: alignment value in bytes
 *
 *  \return         true - if addr is align.
 */
static bool __inline__ is_align(uintptr_t addr, size_t align)
{
    return (((uintptr_t)(addr)) % (align) == 0);
}

/** \brief          Align addr by lower bytes number.
 *
 *  \param[in]      addr: given addr
 *  \param[in]      align: alignment value in bytes
 *
 *  \return         aligned addr.
 */
static __inline__ uintptr_t align_down(uintptr_t addr, size_t align)
{
    return ((uintptr_t)((addr) & ~((align)-1)));
}

/** \brief          Align addr by higher bytes number.
 *
 *  \param[in]      addr: given addr
 *  \param[in]      align: alignment value in bytes
 *
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

#endif //#if !defined(MODULE_ALIGN_DISABLED)
