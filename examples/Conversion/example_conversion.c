#include <stdint.h>
#include <conversion.h>

int main() {

  /* Converts a hexadecimal character to its numerical value. */
  char hexChar = 'A';
  uint8_t num = convert_hex_char_to_num(hexChar); // num should be 10

  /* Converts a hexadecimal digit (numerical value) back to its character representation. */
  uint8_t num = 10;
  char hexChar = convert_hex_num_to_char(num);  // hexChar should be 'A'

  /* Converts a string representation of a MAC address to a mac_t structure. */
  mac_t mac;
  bool result = convert_string_to_mac_addr("AA:BB:CC:DD:EE:FF", &mac);

  /* Converts a mac_t structure back to a string representation. */
  char macString[18];
  bool result = convert_mac_addr_to_string(&mac, macString);

  /* Convert an IPv4 address between a ip4addr_t structure and a string representation. */
  ip4addr_t ipAddr;
  char ipString[16];
  bool result = convert_ip4addr_to_string(ipAddr, ipString);
  result = convert_string_to_ip4addr(&ipAddr, ipString);

  /* Convert between Binary-Coded Decimal (BCD) and regular integer numbers. */
  bcd_t bcd = 0x25; // Represents 25 in BCD
  uint32_t num = convert_bcd_to_num(bcd);
  bcd = convert_num_to_bcd(num);

  /* Convert a string representation of a number to various integer types. */
  const char *strNum = "123";
  uint8_t u8Num = convert_str_to_u8(strNum);
  int32_t i32Num = convert_str_to_i32(strNum);

  /* Convert various integer types back to a string. */
  char str[12];
  uint32_t num = 123;
  convert_u32_to_str(str, num);

  /* Maps a value from one range to another, useful in scenarios like sensor data conversion. */
  int32_t sensorValue = 512; // Range 0-1023
  int32_t percentage = mapping(sensorValue, 0, 1023, 0, 100);

  /* Convert integer types to their binary representations, considering endianess. */
  uint8_t num = 0x12;
  bin8_t bin = convert_u8_to_bin8(num, LITTLE_ENDIAN);

  return 0;
}
