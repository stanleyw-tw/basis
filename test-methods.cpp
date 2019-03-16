#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#include "count-elements.hpp"
#include "diagonal-difference.hpp"
#include "graybox-problem.hpp"
#include "running-median.hpp"
#include "sum-of-array.hpp"
#include "unique-sum-of-array.hpp"

#include "helpers.hpp"

namespace examples {

void checkDiagonalDifference() {
  std::vector<std::vector<int32_t>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int32_t>> b{{1, 1, 2}, {1, 3, 1}, {4, 1, 1}};
  std::vector<std::vector<int32_t>> c{{3, 2, 1}, {1, 2, 3}, {2, 1, 3}};

  int32_t result = diagonalDifference(a);
  assert(result == 0);

  result = diagonalDifference(b);
  assert(result == 4);

  result = diagonalDifference(c);
  assert(result == 3);
}

void checkCountPlusMinus() {
  std::vector<int32_t> a{-3, 6, 9, -15, 0, -1, 25, 12, 100, 66};
  std::vector<double> a_result{0.7, 0.2};

  std::vector<int32_t> b;
  std::vector<double> b_result{0.0, 0.0};

  auto res = countPlusMinus(a);
  assert(
      compareVectors(res.begin(), res.end(), a_result.begin(), a_result.end()));

  res = countPlusMinus(b);
  assert(
      compareVectors(res.begin(), res.end(), b_result.begin(), b_result.end()));
}

void checkSallyInternalStates() {
  Sally sally(1, 1);
  Sniffer sniffer;
  int32_t privateID = 0, publicID = 0;
  sniffer.getSallyInternalStates(sally, &publicID, &privateID);

  assert(publicID == 1);
  assert(privateID == 1);
}

void checkSumOfArray() {
  // simple toy examples
  std::vector<int32_t> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int32_t> b{-1, -1, -2, -1, -3, -1, -4, -1, -1};
  std::vector<int32_t> c{3, 2, 1, 1, 2, 3, 2, 1, 3};

  assert(sumOfArray(a) == 45);
  assert(sumOfArray(b) == -15);
  assert(sumOfArray(c) == 18);

  // provoke overflow
  a.push_back(std::numeric_limits<int32_t>::max());
  b.push_back(std::numeric_limits<int32_t>::min());
  c.push_back(std::numeric_limits<int32_t>::min());

  assert(sumOfArray(a) == 2147483692);
  assert(sumOfArray(b) == -2147483663);
  assert(sumOfArray(c) == -2147483630);
}

void checkUniqueSumOfArray() {
  // simple toy examples
  std::vector<int32_t> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int32_t> b{-1, -1, -2, -1, -3, -1, -4, -1, -1};
  std::vector<int32_t> c{3, 2, 1, -1, 2, 3, 2, 1, 3, 4};

  assert(uniqueSumOfArray(a) == 45);
  assert(uniqueSumOfArray(b) == 0);
  assert(uniqueSumOfArray(c) == 44);

  // provoke overflow
  a.push_back(std::numeric_limits<int32_t>::max());
  b.push_back(std::numeric_limits<int32_t>::min());
  c.push_back(std::numeric_limits<int32_t>::min());

  assert(uniqueSumOfArray(a) == 2147483692);
  assert(uniqueSumOfArray(b) == -2147483648);
  assert(uniqueSumOfArray(c) == -2147483604);
}

void checkRunningMedian() {
  // simple toy examples
  std::vector<int32_t> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<double> a_result{1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
  std::vector<int32_t> b{-1, -1, -2, -1, -3, -1, -4, -1, -1};
  std::vector<double> b_result(b.size(), -1.0);
  std::vector<int32_t> c{3, 2, 1, -1, 2, 3, 2, 1, 3, 4};
  std::vector<double> c_result{3.0, 2.5, 2.0, 1.5, 2.0,
                               2.0, 2.0, 2.0, 2.0, 2.0};

  auto ans = std::make_shared<std::vector<double>>();
  runningMedian(a, ans);

  assert(compareVectors(ans->begin(), ans->end(), a_result.begin(),
                        a_result.end()));
  ans->clear();
  runningMedian(b, ans);

  assert(compareVectors(ans->begin(), ans->end(), b_result.begin(),
                        b_result.end()));
  ans->clear();
  runningMedian(c, ans);

  assert(compareVectors(ans->begin(), ans->end(), c_result.begin(),
                        c_result.end()));
}

}  // namespace examples