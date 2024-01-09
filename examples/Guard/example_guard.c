#include <stdint.h>
#include <guard.h>

int main() {
  /* Used for compile-time assertions. This macro can assert any condition and will produce a compile-time error if the condition is false. */
  STATIC_ASSERT(sizeof(int) == 4, The_int_has_invalid_size);  // Ensures that the size of 'int' is 4 bytes

  /*  Ensures the size of a structure is as expected. */
  typedef struct {
      uint8_t id;
      uint8_t tag;
      bool isValid;
      uint8_t res;
  } CustomStruct_t;

  GuardStructSize(CustomStruct_t, 4);  // Ensures that the size of 'CustomStruct_t' is 4 bytes

  /* Checks if the size of a structure is a multiple of a specified value. */
  GuardStructSizeMultiple(CustomStruct_t, 4);  // Ensures that the size of 'CustomStruct_t' is a multiple of 4 bytes

  /* Validates the offset of a structure member. */
  // Ensures that the members of 'CustomStruct_t' are at the expected offsets
  GuardStructOffset(CustomStruct_t, id, 0);
  GuardStructOffset(CustomStruct_t, tag, 1);
  GuardStructOffset(CustomStruct_t, isValid, 2);

  /* Ensures that the number of entries in an enumeration is within a specified maximum count. */
  typedef enum {
      MdData1,
      MdData2,
      // ...
  } MdData;

  // Assuming sizeof(MdData) gives the number of entries, ensure it's less than 0x40000 - 0x40
  GuardEnumEntries(MdData, sizeof(MdData), 0x40000 - 0x40);

  return 0;
}
