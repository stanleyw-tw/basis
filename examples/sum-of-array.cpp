#include <cstdint>
#include <vector>

#include "sum-of-array.hpp"

namespace examples {

/**
 * @brief Compute the sum of a vector. Take in mind that the entries of the
 * vector are possibly very large.
 *
 * @param a input vector
 * @return int64_t sum of the entries of the input vector
 */
int64_t sumOfArray(const std::vector<int32_t> &a) {

  int64_t ans = 0;

  if (a.empty()) {
    return -1;
  }
  // calculate
  int64_t temp = 0;
  for (uint64_t i = 0; i < a.size(); i++) {
    temp = temp + a.at(i);
    // std::cout<<i<<": "<<temp<<std::endl;
  }
  // std::cout<<temp<<std::endl;
  ans = temp;
  // ans = static_cast<int32_t>(temp);
  // check overflow
  /*
  if( temp > (std::numeric_limits<int32_t>::max())){
    ans = std::numeric_limits<int32_t>::max();
  } else if (temp < (std::numeric_limits<int32_t>::min())){
    ans = std::numeric_limits<int32_t>::min();
  } else {
    ans = static_cast<int32_t>(temp);
  }
  */
  return ans;
}

} // namespace examples
