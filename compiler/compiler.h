/**
* \file    		compiler.h
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
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
#if (defined(__GCC__))
// Указывает GCC всегда подставлять функции, независимо от того включена оптимизация или нет
#define __inline__     				__inline__   __attribute__((always_inline))

/*
* Cигнализирует вам, что функция устарела и ее больше не следует использовать. 
* Если вы попытаетесь использовать устаревшую функцию, компилятор выдаст предупреждение. 
* Этот атрибут также можно применять к типам и переменным
*/
#define __deprecated           		__attribute__((deprecated))

/*
* сообщает компилятору, что эта функция используется, независимо от того найдет 
* ли GCC экземпляры вызова этой функции. Это может быть полезно в тех случаях, 
* когда функции С вызываются из ассемблера.
*/
#define __attribute_used__     		__attribute__((__used__))

/*
* Cообщает компилятору, что эта функция не имеет состояния (т.е. использует для 
* генерации возвращаемого результата только переданные ей аргументы).
*/
#define __attribute_const__     	__attribute__((__const__))

/*
* Gринуждает компилятор всегда проверять, что возвращаемое значение функции 
* проверяется в месте вызова. Этим гарантируется, что везде, откуда вызывается 
* функция результат будет проверяться, что позволяет обработать потенциальные ошибки.
*/
#define __must_check            	__attribute__((warn_unused_result))

#define likely(x)   				__builtin_expect(!!(x), 1)

#define unlikely(x) 				__builtin_expect(!!(x), 0)

#ifndef ARCH_HAS_PREFETCH
#define prefetch(x) 				__builtin_prefetch(x)
#endif
#else
#define __inline__     			
#define __deprecated           	
#define __attribute_used__     	
#define __attribute_const__     	
#define __must_check            	
#define likely(x)   				
#define unlikely(x) 				
#ifndef ARCH_HAS_PREFETCH
	#define prefetch(x) 			
#endif
#endif
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
static inline void prefetch_range(void *addr, size_t len)
{
#ifdef ARCH_HAS_PREFETCH
    char *cp;
    char *end = addr + len;
 
    for (cp = addr; cp < end; cp += PREFETCH_STRIDE)
        prefetch(cp);
#endif
}
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
