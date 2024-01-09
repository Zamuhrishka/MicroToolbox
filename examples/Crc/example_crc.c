#include <stdint.h>
#include <crc.h>

int main() {

  /* Calculates the CRC-8-Dallas/Maxim checksum. This is suitable for small data packets where a simple and fast checksum is needed. */
  const uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
  uint8_t crc = crc8(data, sizeof(data));

  /* An alternative implementation of the CRC-8-Dallas/Maxim checksum calculation using a precomputed table for faster execution. */
  #if defined(CRC8_TABLE)
  uint8_t crc = crc8_table(data, sizeof(data));
  #endif

  /* Calculates the CRC-16-CCITT checksum. This is a commonly used CRC standard for medium-sized data. */
  const uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  uint16_t crc = crc16(data, sizeof(data));

  /* A table-based implementation for calculating the CRC-16-CCITT checksum, optimizing for speed. */
  #if defined(CRC16_TABLE)
  uint16_t crc = crc16_table(data, sizeof(data));
  #endif

  /* Calculates the CRC-32-IEEE 802.3 checksum. This is used for larger data sets where a higher level of integrity checking is required. */
  const uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
  uint_least32_t crc = crc32(data, sizeof(data));

  /* A table-based approach for calculating the CRC-32-IEEE 802.3 checksum, ideal for scenarios where performance is crucial. */
  #if defined(CRC32_TABLE)
  uint_least32_t crc = crc32_table(data, sizeof(data));
  #endif

  return 0;
}
