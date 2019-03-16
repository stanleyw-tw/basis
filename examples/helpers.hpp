/*
 * helpers.hpp
 *
 *  Created on: Apr 13, 2018
 *      Author: franzef
 */

#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

namespace examples {

template <typename T>
void insertionSort(std::vector<T>* container, T value) {
  /*
   * Write your code here.
   */
}

template <class Iter>
void printVector(Iter first, Iter last) {
  using value_type = typename std::iterator_traits<Iter>::value_type;
  std::copy(first, last, std::ostream_iterator<value_type>(std::cout, ", "));
  std::cout << std::endl;
}

template <class Iter>
bool compareVectors(Iter ifirst, Iter ilast, Iter jfirst, Iter jlast,
                    double tol = 1e-14) {
  bool success = true;

  auto i = ifirst, j = jfirst;
  while (success && i != ilast && j != jlast) {
    success &= std::abs(*i - *j) < tol;
    i = std::next(i);
    j = std::next(j);
  }

  return success && i == ilast && j == jlast;
}

}  // namespace examples
