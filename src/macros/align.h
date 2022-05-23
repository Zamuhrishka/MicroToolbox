/**
 * @file align.h
 * @author Aleksander Kovalchuk (roux@yandex.ru)
 * @brief 
 * @date 2022-05-22
 */

#pragma once

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

//_____ I N C L U D E S _______________________________________________________

//_____ C O N F I G S  ________________________________________________________
#ifndef DATA_CACHE_LINESIZE
    #define DATA_CACHE_LINESIZE     32
#endif
//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________
#define STRCONCAT(x, y)             x ## y
#define STRCONCATHELPER(x, y)       STRCONCAT(x, y)

/**
 * \brief           Check if addr is alignment by align.
 * \param[in]       addr: addr
 * \param[in]       align: alignment in bytes 
 * \return          true - if addr is align.
 * \hideinitializer
 */
#define IS_ADDR_ALIGN(addr, align) \
        (((uint32_t)(const void *)(addr)) % (align) == 0)

/**
 * Wrap the given structure into a padded, aligned structure and instantiate a static copy of it.
 * This should be used when the variables are only required to be accessed in a single file.  It
 * has two parameters, T is the type of structure to be wrapped and N is instantiation name
 *
 * Example usage:
 *
 *     typedef struct
 *     {
 *         VCCDeviceContext_t * pAllocatedContext;
 *     } VCCBssData_t;
 *     
 *     DCACHE_LINE_ALIGN__STATIC(VCCBssData_t, bssData);
 *
 * The data can then be access as per this example:
 *
 *     return bssData.d.pAllocatedContext;
 */
#define DCACHE_LINE_ALIGN__STATIC(T, N) \
    __attribute__ ((aligned (DATA_CACHE_LINESIZE))) typedef struct { T d; uint8_t p[DATA_CACHE_LINESIZE - (sizeof(T) % DATA_CACHE_LINESIZE)]; } T##Full_t; static T##Full_t N

/**
 * The following two macros support a non-static structure which can be defined in a header file
 * and instantiated in a seperate c file.  It should be used in the same way as the above macro.
 *
 * The TYPE macro defines the padded structure type and externs it so that it can be accessed
 * from any file including the header.
 * The INST macro instantiates the type.  It must be given the same parameters as the TYPE macro.
 */
#define DCACHE_LINE_ALIGN__TYPE(T, N) \
    __attribute__ ((aligned (DATA_CACHE_LINESIZE))) typedef struct { T d; uint8_t p[DATA_CACHE_LINESIZE - (sizeof(T) % DATA_CACHE_LINESIZE)]; } T##Full_t; extern T##Full_t N

#define DCACHE_LINE_ALIGN__INST(T, N) T##Full_t N

/**
 * Define a macro which forces a structure to always be aligned.  It does not pad the structure.
 */
#define DCACHE_ALIGN __attribute__ ((aligned (DATA_CACHE_LINESIZE)))

/**
 * Forces alignment of elements within a user defined type (ADT)
 *
 * Example usage:
 *
 * typedef struct
 * {
 *      uint8_t data1;
 *      DCACHE_ALIGN_STRUCT;
 *      uint8_t data2;
 *      DCACHE_ALIGN_STRUCT;
 *      uint8_t data3;
 * } SomeData_t; // sizeof(...) == 3*DATA_CACHE_LINESIZE Bytes
 *
 * You can use this macro to separate uncached and cached areas.
 */
#define DCACHE_ALIGN_STRUCT \
    struct { uint8_t pad[0]; } STRCONCATHELPER(align, __LINE__) __attribute__ ((aligned (DATA_CACHE_LINESIZE)))

//_____ V A R I A B L E S _____________________________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
