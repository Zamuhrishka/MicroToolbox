#include <stdint.h>
#include <sfloat.h>

int main() {
  /**
   * Rescales a fixed-point value (sfloat_t) to a different scale, rounding towards zero. This function is useful for
   * adjusting the precision of the fixed-point representation.
   */
  sfloat_t f = {.value = 12345, .scale = 100};  // Represents 123.45
  int_least32_t new_scale = 1000;
  // Rescale the fixed-point number to a new scale
  int_least32_t rescaled_value = sfloat_rescale(&f, new_scale);
  // Now, rescaled_value represents 123.45 with a scale of 1000

  /**
   * Converts a fixed-point sfloat_t number to a floating-point value. This function is used when a floating-point
   * representation is required for calculations or output.
   */
  sfloat_t f = {.value = 1500, .scale = 10};  // Represents 150.0
  // Convert the fixed-point number to float
  float float_value = sfloat_to_float(&f);
  // float_value is now 150.0f

  /**
   * Converts a floating-point number into a fixed-point sfloat_t number. This is especially useful when you need to
   * convert floating-point data received from external sources (e.g., sensors) into a more efficient fixed-point
   * representation for processing and storage in embedded systems.
   */
  float fnum = 123.45f;
  // Convert the float to fixed-point number
  sfloat_t sf = float_to_sfloat(fnum);
  // sf now holds the value 12345 with a scale of 100

  return 0;
}
