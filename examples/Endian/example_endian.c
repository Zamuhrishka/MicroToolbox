#include <stdint.h>
#include <byte_order.h>

int main() {
  /* Determine the byte order of the target system. */
  endian_e system_endian = byte_order_define(); //system_endian will be either BIG_ENDIAN or LITTLE_ENDIAN

  /* Swap the byte order of 16-bit, 32-bit, and 64-bit numbers, respectively. */
  uint16_t num16 = 0x1234;
  uint32_t num32 = 0x12345678;
  uint64_t num64 = 0x123456789ABCDEF0;

  uint16_t swapped16 = byte_order_swap16(num16); // 0x3412
  uint32_t swapped32 = byte_order_swap32(num32); // 0x78563412
  uint64_t swapped64 = byte_order_swap64(num64); // 0xF0DEBC9A78563412

  /* Store 16-bit and 32-bit values into a byte array in little-endian order. */
  uint16_t val16 = 0x1234;
  uint8_t array16[2];
  byte_order_u16_to_array_le(val16, array16); // array16 = {0x34, 0x12}

  uint32_t val32 = 0x12345678;
  uint8_t array32[4];
  byte_order_u32_to_array_le(val32, array32); // array32 = {0x78, 0x56, 0x34, 0x12}

  /* Load 16-bit and 32-bit values from a byte array in little-endian order. */
  uint16_t loaded16 = byte_order_array_to_u16_le(array16); // loaded16 = 0x1234
  uint32_t loaded32 = byte_order_array_to_u32_le(array32); // loaded32 = 0x12345678

  /* Store 16-bit and 32-bit values into a byte array in big-endian order. */
  byte_order_u16_to_array_be(val16, array16); // array16 = {0x12, 0x34}
  byte_order_u32_to_array_be(val32, array32); // array32 = {0x12, 0x34, 0x56, 0x78}

  /* Load 16-bit and 32-bit values from a byte array in big-endian order. */
  loaded16 = byte_order_array_to_u16_be(array16); // loaded16 = 0x1234
  loaded32 = byte_order_array_to_u32_be(array32); // loaded32 = 0x12345678

  return 0;
}
