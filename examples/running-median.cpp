#include <cstdint>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "helpers.hpp"
#include "running-median.hpp"

namespace examples {

template <typename T> void print_queue(T &q) {
  while (!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << '\n';
}

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

  if (a.empty()) {
    return;
  }

  double median;
  int32_t value;
  uint64_t input_size = a.size();
  std::priority_queue<int32_t, std::vector<int32_t>, std::less<int32_t>> max;
  std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> min;

  // for each element
  for (uint64_t i = 0; i < input_size; i++) {
    value = a.at(i);
    if (i == 0) {
      min.push(value);
      median = static_cast<double>(value);
      ans->push_back(median);
    } else {
      if (value > min.top()) {
        min.push(value);
      } else {
        max.push(value);
      }
      // re-balance
      if (max.size() > min.size()) {
        min.push(max.top());
        max.pop();
      } else if (min.size() > max.size()) {
        max.push(min.top());
        min.pop();
      }
      // calculate running median
      if ((max.size() + min.size()) % 2 == 0) {
        median = static_cast<double>((max.top() + min.top())) / 2;
        ans->push_back(median);
      } else {
        double max_v = (double)max.top();
        double min_v = (double)min.top();
        median = (max.size() > min.size()) ? max_v : min_v;
        ans->push_back(median);
      }

    } // if first
  }   // for loop
  // for debug
  // print_queue(max);
  // print_queue(min);
  // printVector(ans->begin(), ans->end());
}

} // namespace examples
