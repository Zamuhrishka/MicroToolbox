/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        Compiler abstraction layer
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
#if defined(__clang__)

#elif defined(__GNUC__) || defined(__GNUG__)
    /// Request GCC make function always inline
    #define __inline__ __inline__ __attribute__((always_inline))

    /// Signals that the function is deprecated and should no longer be used.
    #define __deprecated__      __attribute__((deprecated))

    /// Tells the compiler that this function is used, whether or not GCC finds
    /// instances of this function call.
    /// \note This can be useful in cases where C functions are called from assembler.
    #define __attribute_used__  __attribute__((__used__))

    /// Tells the compiler that this function is stateless.
    /// \note uses only the arguments passed to it to generate the returned result
    #define __attribute_const__ __attribute__((__const__))

    /// Tells linker that this object need to be aligned by value order
    #define __align__(value)    __attribute__((aligned((value))))

    /// Causes the compiler to always check that the return value of a function is
    /// checked at the call site.
    #define __must_check__      __attribute__((warn_unused_result))

    /// The hint to the compiler to emit instructions that will cause branch prediction
    /// to favour the "likely" side of a jump instruction.
    #define __likely__(x)       __builtin_expect(!!(x), 1)
    #define __unlikely__(x)     __builtin_expect(!!(x), 0)

    /// Tells linker to put object in desire section
    #define __section__(A)      __attribute__((__section__(A)))

#else
    /// Request GCC make function always inline
    #define __inline__
    /// Signals that the function is deprecated and should no longer be used.
    #define __deprecated__
    /// Tells the compiler that this function is used, whether or not GCC finds
    /// instances of this function call.
    /// \note This can be useful in cases where C functions are called from assembler.
    #define __attribute_used__
    /// Tells the compiler that this function is stateless.
    /// \note uses only the arguments passed to it to generate the returned result
    #define __attribute_const__
    /// Tells linker that this object need to be aligned by value order
    #define __align__(value)
    /// Causes the compiler to always check that the return value of a function is
    /// checked at the call site.
    #define __must_check__
    /// The hint to the compiler to emit instructions that will cause branch prediction
    /// to favour the "likely" side of a jump instruction.
    #define __likely__(x)
    /// The hint to the compiler to emit instructions that will cause branch prediction
    /// to favour the "likely" side of a jump instruction.
    #define __unlikely__(x)
    /// Tells linker to put object in desire section
    #define __section__(A)
#endif
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
