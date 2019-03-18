#include <algorithm>
#include <cstdint>
#include <iostream>
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
int64_t uniqueSumOfArray(const std::vector<int32_t> &a) {
  /*
   * Write your code here.
   */
  if (a.empty()) {
    // invalid input
    return -1;
  }

  std::vector<int> sortedVector = a;
  std::sort(sortedVector.begin(), sortedVector.end());
  uint64_t size = sortedVector.size();

  int64_t ans = sortedVector[0];
  for (uint64_t i = 1; i < size; i++) {
    if (sortedVector[i] == sortedVector[i - 1]) {
      uint64_t j = i;
      while ((j < size) && (sortedVector[j] <= sortedVector[j - 1])) {

        sortedVector[j] = sortedVector[j] + 1;

        j++;
      }
    }
    ans = ans + sortedVector[i];
    // std::cout<<ans<<std::endl;
  }
  return ans;
}

} // namespace examples
