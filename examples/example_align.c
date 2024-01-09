#include <stdint.h>
#include <align.h>

int main() {

  /*
   * This macro is used to align a variable. For example, if you want to align a uint32_t variable to a
   * 16-byte boundary, you can declare it like this:
   */
  uint32_t ALIGN(16) myVar;

  /**
   * This macro creates a static instance of an aligned structure. It is useful for creating aligned data structures
   * that are frequently used. For example, you can define a structure and create a static instance of that structure
   * aligned on a 32-byte boundary:
   */
  typedef struct {
      int data;
  } MyStruct;
  CACHE_LINE_ALIGN__STATIC(MyStruct, myStructInstance, 32);

  /**
   * These macros are used together to define and create instances of aligned structures. You first define the type
   * using CACHE_LINE_ALIGN__TYPE, and then create an instance using CACHE_LINE_ALIGN__INST. For example:
   */

  // In the header file.
  CACHE_LINE_ALIGN__TYPE(MyStruct, globalMyStruct, 64);
  // In the source code file.
  CACHE_LINE_ALIGN__INST(MyStruct, globalMyStruct);

  /**
   * This macro adds alignment within a custom defined data type. This is useful for separating cacheable and
   * non-cacheable areas in a structure. For example:
   */
  typedef struct {
    char data1;
    CACHE_ALIGN_STRUCT(64);
    char data2;
  } AlignedData;

  /**
   * These functions are used to check and change the alignment of memory addresses. For example, is_align can be
   * used to check if the pointer is aligned, and align_down and align_up can be used to adjust the address to the
   * nearest alignment boundaries:
   */
  uintptr_t addr = 0x12345;
  size_t align = 1024;

  if (!is_align(addr, align)) {
      addr = align_up(addr, align);
  }

  return 0;
}
