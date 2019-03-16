#include <cstdint>
#include <vector>

#include "unique-sum-of-array.hpp"

namespace examples {

/**
 * @brief Compute the sum of the unique elements from a vector. Find for each
 * multiple element a unique integer that has not yet been added to the sum.
 * These newly found integers have to be unique withing themselves as well and
 * if added to the original sum, the sum must be minimal.
 *
 * Example: Let the input vector be (1, 1, 2, 4). Then the sum of unique
 * elements is 1 + 2 + 4 = 7. The 1 shows up twice, hence we replace it by the
 * minimum integer that is unique with respect to (1, 2, 4). This integer is
 * obviously 3, which leads to the final result of 7 + 3 = 10.
 *
 * @param a
 * @return int32_t
 */
int32_t uniqueSumOfArray(const std::vector<int32_t>& a) {
  /*
   * Write your code here.
   */
  return 0;
}

}  // namespace examples
