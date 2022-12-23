/**
 * @file bits.h
 * @author Aleksander Kovalchuk (aliaksander.kavalchuk@gmail.com)
 * @brief 
 * @date 2022-05-20
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
/**
 * \brief           Set bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define SET_BIT(reg, bit)			            (reg |= (1<<(bit)))

/**
 * \brief           Clear bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define CLEAR_BIT(reg, bit)			            (reg &= (~(1<<(bit))))

/**
 * \brief           Invert bit in register
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          none
 * \hideinitializer
 */
#define TOGGLE_BIT(reg, bit)		            (reg ^= (1<<(bit)))

/**
 * \brief           Test bit in register for set state
 * \param[in]       reg: register address
 * \param[in]       bit: bit number
 * \return          true - if set
 * \hideinitializer
 */
#define TEST_BIT(reg, bit)			            ((reg & (1<<(bit))) != 0)

/**
 * \brief           This macro creates a mask that will isolate the bits from
 *                  l (lower) to u (upper).  The 'u' value must be the larger
 *                  value if 'u' and 'l' aren't equal.
 * \param[in]       msb: most significant bit
 * \param[in]       lsb: least significant bit
 * \return          bitfield
 * \hideinitializer
 */
#define MAKE_BITFIELD(u, l)                    ((((1ul << (u)) - 1ul) | (1ul << (u))) & ~((1ul << (l)) - 1ul))

/**
 * \brief Define number of bits in с type: char, int, uint8_t, etc
 * 
 * \param[in]  type: с type
 */
#define NUM_BITS(type)                          (sizeof(type) * 8u)

/**
 * \brief Isolate the rightmost 1-bit
 * 
 * \warning Undefined behaviar for x=0 value
 * 
 */
#define LSO(x)                                  ((x) & (-(x)))

/**
 * \brief Isolate the rightmost 0-bit
 * 
 * \warning Undefined behaviar for x=(~x) value
 *
 */
#define LCO(x) 			                        (~(x) & ((x)+1))

/**
 * @brief Turn on the rightmost 0-bit
 * 
 * \warning Undefined behaviar for x=(~x) value
 * 
 */
#define SLSB(x) 			                    ((x) | ((x)+1))

/**
 * @brief Turn off the rightmost 1-bit
 * 
 * \warning Undefined behaviar for x=0 value
 * 
 */
#define CLSB(x) 			                    ((x) & ((x)-1))

//_____ V A R I A B L E S _____________________________________________________

//_____ P U B L I C  F U N C T I O N S_________________________________________
// /** Function to reverse the individual bits in a byte - i.e. bit 7 is moved to bit 0, bit 6 to bit 1,
//  *  etc.
//  *
//  *  \param[in] Byte  Byte of data whose bits are to be reversed.
//  *
//  *  \return Input data with the individual bits reversed (mirrored).
//  */
// static inline uint8_t BitReverse(uint8_t Byte);
// static inline uint8_t BitReverse(uint8_t Byte)
// {
// 	Byte = (((Byte & 0xF0) >> 4) | ((Byte & 0x0F) << 4));
// 	Byte = (((Byte & 0xCC) >> 2) | ((Byte & 0x33) << 2));
// 	Byte = (((Byte & 0xAA) >> 1) | ((Byte & 0x55) << 1));

// 	return Byte;
// }


// //Перематывает один бит слева направо, то есть формирует последовательность 
// //0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001, 0b10000000, 
// //или 128, 64, 32, 16, 8, 4, 2, 1, 128
// static inline uint8_t BitRewinding(uint8_t x)
// {
//         return ((x >> 1) | (x << 7))
// }


// /**
//  * @brief Count the number of 1 bits in word x
//  * 
//  * @example
//  *      x               | 0010110111010000
//         x-1             | 0010110111001111
//         x & (x-1)       | 0010110111000000
//  * 
//  * @param[] num 
//  * @return size_t 
//  */
// static inline size_t Population(size_t num)
// {
//         size_t count = 0;
//         for (count=0; count!=0; ++count)
//         {
//                 count &= count - 1;
//         }
        
//         return count;
// }

/* C++ detection */
#ifdef __cplusplus
}
#endif
