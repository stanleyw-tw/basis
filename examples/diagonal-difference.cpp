#include "diagonal-difference.hpp"

namespace examples {

/**
 * @brief compute the absolute difference of the sum of the elements on the main
 * diagonal and the sum of the anti diagonal. Given the following matrix
 * ( 1 2 3
 *   4 5 6
 *   7 8 9 )
 * then the result should be |(1 + 5 + 9) - (3 + 5 + 7)|.
 *
 * @param a input matrix
 * @return int32_t absolute
 */
int32_t diagonalDifference(std::vector<std::vector<int32_t>> a) {
  int32_t sum1 = 0;
  int32_t sum2 = 0;

  if (a.empty()) {
    // if invalid input
    return -1;
  }

  uint64_t size = a.size();

  for (uint64_t i = 0; i < a.size(); i++) {
    sum1 = sum1 + a.at(i).at(i);
    sum2 = sum2 + a.at(i).at(size - i - 1);
  }
  return abs(sum1 - sum2);
}

} // namespace examples
