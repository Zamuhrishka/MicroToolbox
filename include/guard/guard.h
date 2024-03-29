/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        This module contains a collection of macros designed for compile-time assertions
 *               and structural validations in C. It includes macros for static assertions, guarding
 *               the size of structures, ensuring structure sizes are multiples of a specified value,
 *               and verifying the offset of structure members. These tools are crucial for ensuring
 *               data structure consistency and memory layout expectations, especially in embedded
 *               systems programming where such guarantees are critical for reliable operation.
 *               Additionally, it provides a macro for validating the number of entries in an enumeration
 *               relative to a maximum count, further enhancing data integrity checks.
 */


#pragma once

#if !defined(MODULE_MACRO_GUARD_DISABLED)
//_____ I N C L U D E S _______________________________________________________
#include "misc.h"
//_____ C O N F I G S  ________________________________________________________

//_____ D E F I N I T I O N S _________________________________________________

//_____ M A C R O S ___________________________________________________________
/**
 * \brief       Static assert
 *
 * \param[in]   COND: bool expresion
 * \param[in]   MSG: fail message
 *
 * \warning The `MSG` need to be text without quotes and spaces!
 *
 * \example
 * \code
 * STATIC_ASSERT(sizeof(int)==4, The_int_has_invalid_size);
 * \endcode
 */
#define STATIC_ASSERT(COND, MSG) typedef char static_assertion##MSG[(COND) ? 1 : -1]

/**
 * \brief   Check size of struct on compile time
 *
 * \param[in]   st: struct type
 * \param[in]   sz: expected size of struct
 *
 * \code
 * typedef struct {
 *         uint8_t     id;
 *         uint8_t     tag;
 *         bool        isValid;
 *         uint8_t     res;
 * } CustomStruct_t;
 * GuardStructSize(CustomStruct_t, 4);
 * \endcode
 */
#define GuardStructSize(st, sz) typedef uint8_t GuardStructSize##st##_header[(sizeof(st) == (sz)) ? 1 : -1]

/**
 * \brief   Check that size of struct is divide on `sz`
 *
 * \param[in]   st: struct type
 * \param[in]   sz: value on which the size of struct must divided
 *
 * \code
 * typedef struct {
 *  uint8_t     id;
 *  uint8_t     tag;
 *  bool        isValid;
 *  uint8_t     res;
 * } CustomStruct_t;
 * GuardStructSize(CustomStruct_t, 4);
 * GuardStructSizeMultiple(CustomStruct_t, 4);
 * \endcode
 */
#define GuardStructSizeMultiple(st, sz) \
    typedef uint8_t GuardStructSizeMultiple##st##_header[((sizeof(st) % (sz)) == 0) ? 1 : -1]

/**
 * \brief   Check that offset of struct member equal `os`
 *
 * \param[in]   st: struct type
 * \param[in]   mb: name of struct member
 * \param[in]   os: expected offset
 *
 * \code
 * typedef struct {
 *  uint8_t     id;
 *  uint8_t     tag;
 *  bool        isValid;
 *  uint8_t     res;
 * } CustomStruct_t;
 * GuardStructSize(CustomStruct_t, 4);
 * GuardStructOffset(CustomStruct_t, id,        0);
 * GuardStructOffset(CustomStruct_t, tag,       1);
 * GuardStructOffset(CustomStruct_t, isValid,   2);
 * \endcode
 */
#define GuardStructOffset(st, mb, os) \
    typedef uint8_t GuardStructOffset##st##mb_header[(offsetof(st, mb) == os) ? 1 : -1]

/**
 * \brief
 *
 * \code
 *   GuardEnumEntries(MdData, sizeof(MdData), 0x40000 - 0x40);
 * \endcode
 *
 * The following is to ensure that we have at least `0x40` byte padding at the end
 */
#define GuardEnumEntries(st, cnt, max_cnt) typedef uint8_t GuardEnumEntries##st##_header[((cnt) <= (max_cnt)) ? 1 : -1]
//_____ V A R I A B L E S _____________________________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________
#endif //#if !defined(MODULE_MACRO_GUARD_DISABLED)
