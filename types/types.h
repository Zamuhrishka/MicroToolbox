/**
* \file    		types.h
* \author  		Kovalchuk Alexander (roux@yandex.ru)
* \brief   		This file contains the prototypes functions which use for...
*/

/*
 * Copyright (c) year Alexander KOVALCHUK
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of library_name.
 *
 * Author:          Alexander KOVALCHUK <roux@yandex.ru>
 */

#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
//_____ C O N F I G S  ________________________________________________________
#ifndef XCHAL_DCACHE_LINESIZE
#define XCHAL_DCACHE_LINESIZE 32
#endif
//_____ D E F I N I T I O N ___________________________________________________
/*
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
#define DCACHE_LINE_ALIGN__STATIC(T, N) __attribute__ ((aligned (XCHAL_DCACHE_LINESIZE))) typedef struct { T d; uint8_t p[XCHAL_DCACHE_LINESIZE - (sizeof(T) % XCHAL_DCACHE_LINESIZE)]; } T##Full_t; static T##Full_t N

/*
 * The following two macros support a non-static structure which can be defined in a header file
 * and instantiated in a seperate c file.  It should be used in the same way as the above macro.
 *
 * The TYPE macro defines the padded structure type and externs it so that it can be accessed
 * from any file including the header.
 * The INST macro instantiates the type.  It must be given the same parameters as the TYPE macro.
 */
#define DCACHE_LINE_ALIGN__TYPE(T, N) __attribute__ ((aligned (XCHAL_DCACHE_LINESIZE))) typedef struct { T d; uint8_t p[XCHAL_DCACHE_LINESIZE - (sizeof(T) % XCHAL_DCACHE_LINESIZE)]; } T##Full_t; extern T##Full_t N
#define DCACHE_LINE_ALIGN__INST(T, N) T##Full_t N

/**
 * Define a macro which forces a structure to always be aligned.  It does not pad the structure.
 */
#define DCACHE_ALIGN __attribute__ ((aligned (XCHAL_DCACHE_LINESIZE)))

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
 * } SomeData_t; // sizeof(...) == 3*XCHAL_DCACHE_LINESIZE Bytes
 *
 * You can use this macro to separate uncached and cached areas of a HAL context.
 */
#define DCACHE_ALIGN_STRUCT     struct { uint8_t pad[0]; } STRCONCATHELPER(align, __LINE__) __attribute__ ((aligned (XCHAL_DCACHE_LINESIZE)))
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
