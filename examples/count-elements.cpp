#include <cstdint>
#include <vector>

#include "count-elements.hpp"

namespace examples {

/**
 * @brief compute the relative frequency of the positive and the negative
 * elements in the input vector from which the factorization of the absolute
 * value contains a 5 or a 3. Given (-3, 6, 9, -15), then the expected result
 * would be [0.5, 0.5].
 *
 * @param arr
 * @return std::vector<double>
 */
std::vector<double> countPlusMinus(std::vector<int32_t> arr) {
  std::vector<double> res;

  if (arr.empty()) {
    // invalid input
    res.push_back(0.0);
    res.push_back(0.0);
    return res;
  }
  uint64_t size = arr.size();
  uint64_t pos_count = 0;
  uint64_t neg_count = 0;

  for (uint64_t i = 0; i < size; i++) {
    if ((arr.at(i) % 3 == 0) || (arr.at(i) % 5 == 0)) {
      if (arr.at(i) > 0) {
        pos_count++;
      } else if (arr.at(i) < 0) {
        neg_count++;
      } else {
        // element = 0 is undefined but count as positive in test case
        // TODO
        pos_count++;
      }
    }
  }
  double pos_value = static_cast<double>(pos_count) / static_cast<double>(size);
  double neg_value = static_cast<double>(neg_count) / static_cast<double>(size);
  res.push_back(pos_value);
  res.push_back(neg_value);
  return res;
}

} // namespace examples
