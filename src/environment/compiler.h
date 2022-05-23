/**
* \file         compiler.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdlib.h>
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
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

    #define align(A)                    __attribute__((aligned (A)))

    #define section(A)                  __attribute__((__section__ (A)))

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
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
static inline void prefetch_range(void *addr, size_t len)
{
#ifdef ARCH_HAS_PREFETCH
    char *cp;
    char *end = addr + len;
 
    for (cp = addr; cp < end; cp += PREFETCH_STRIDE)
        prefetch(cp);
#endif
}

/* C++ detection */
#ifdef __cplusplus
}
#endif