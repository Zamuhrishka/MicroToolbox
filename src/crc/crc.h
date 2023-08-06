/**
 * \file
 * \author       Kovalchuk Alexander (aliaksander.kavalchuk@gmail.com)
 * \brief        This file contains functions for calculate crc8/16/32.
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief       This function calculate checksum CRC-8-Dallas/Maxim.
 *  - Used polynomial: `x^8 + x^5 + x^4 + 1` (0x31).
 *  - Init  : 0xFF
 *  - Revert: false
 *  - XorOut: 0x00
 *  - Check : 0xF7 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc8 value.
 **/
uint8_t crc8(const uint8_t *pcBlock, size_t len);

#if defined(CRC8_TABLE)
/**
 * \brief       This function calculate by table method checksum CRC-8-Dallas/Maxim.
 *  - Used polynomial: `x^8 + x^5 + x^4 + 1` (0x31).
 *  - Init  : 0xFF
 *  - Revert: false
 *  - XorOut: 0x00
 *  - Check : 0xF7 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc8 value.
 **/
uint8_t crc8_table(const uint8_t *pcBlock, size_t len);
#endif

/**
 * \brief   This function calculate checksum CRC-16-CCITT.
 *  - Used polynomial: `x^16 + x^12 + x^5 + 1` (0x1021).
 *  - Init  : 0xFFFF
 *  - Revert: false
 *  - XorOut: 0x0000
 *  - Check : 0x29B1 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc16 value.
 **/
uint16_t crc16(const uint8_t *pcBlock, size_t len);

#if defined(CRC16_TABLE)
/**
 * \brief   This function calculate by table method checksum CRC-16-CCITT.
 *  - Used polynomial: `x^16 + x^12 + x^5 + 1` (0x1021).
 *  - Init  : 0xFFFF
 *  - Revert: false
 *  - XorOut: 0x0000
 *  - Check : 0x29B1 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc16 value.
 **/
uint16_t crc16_table(const uint8_t *pcBlock, size_t len);
#endif

/**
 * \brief   This function calculate checksum CRC-32-IEEE 802.3.
 *  - Used polynomial: `x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11
 *                      + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1` (0x04C11DB7)
 *  - Init  : 0xFFFFFFFF
 *  - Revert: false
 *  - XorOut: 0xFFFFFFFF
 *  - Check : 0xCBF43926 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc32 value.
 **/
uint_least32_t crc32(const uint8_t *buf, size_t len);

#if defined(CRC32_TABLE)
/**
 * \brief   This function calculate by table method checksum CRC-32-IEEE 802.3.
 *  - Used polynomial: `x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11
 *                      + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1` (0x04C11DB7)
 *  - Init  : 0xFFFFFFFF
 *  - Revert: false
 *  - XorOut: 0xFFFFFFFF
 *  - Check : 0xCBF43926 ("123456789")
 *
 * \param[in]   pcBlock: pointer to the data buffer.
 * \param[in]   len: size of data buffer.
 *
 * \return      calculated crc32 value.
 **/
uint_least32_t crc32_table(const uint8_t *buf, size_t len);
#endif
