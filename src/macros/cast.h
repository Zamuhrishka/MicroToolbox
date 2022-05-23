/**
 * @file cast.h
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

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________
/* The OVERRIDE macro allows you to override the intrinsic type of a variable
   with another type in a manner that will generate a compiler error if the
   size of the intrinsic type is less than that of the overriding type. The
   form of this thing is what I eventually came up with: I create a temporary
   byte array of the size of the intrinsic type, initialize it with as many 0s
   as there are bytes in the size of the overriding type, access the array to
   keep the compiler from warning me that I don't use 'temp', then throw it
   all away and return an lvalue that is of the overridden type. If you try
   and override with a bigger type than the intrinsic the 'temp' initialization
   will give you a compiler error. Since the sizes of things are known at
   compile time, the error-causing 'temp' array nonsense will compile to nothing
   and the only thing left will be a type-overridden access to 'i' within
   whatever context this macro as invoked. Point being that there's no code
   overhead here, just a type-safe override. */
#define CAST(i, t) (*((t *) (&(i))))
#define OVERRIDE(i, \
                 t) (*({char temp[sizeof(i)] = {[0 ... (sizeof(t) - 1)] = 0}; \
                        (temp[0]) ? &CAST(i, t) : &CAST(i, t); }))


/// Cast pointer address to uint32_t number
#define PTR2ADDR(x)                     ((uint32_t)((void*)(x)))
//_____ V A R I A B L E S _____________________________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
