#include <cstdint>
#include <memory>
#include <vector>

#include "running-median.hpp"

namespace examples {

/**
 * @brief compute the median of the input vector a as follows:
 *      (i) take the first element -> compute the median
 *      (ii) take the first two elements -> compute the median
 *      (...)
 *      (n) take all elements -> compute the median
 * The result vector should contain all the n medians.
 *
 * @param arr
 * @return std::vector<double>
 */
void runningMedian(const std::vector<int32_t> &a,
                   std::shared_ptr<std::vector<double>> ans) {
  /*
   * Write your code here.
   */
}

}  // namespace examples
