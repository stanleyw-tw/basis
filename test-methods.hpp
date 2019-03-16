#pragma once

/**
 * @brief Example 7: contains test cases for pointer issues
 *
 * Idea: pointer issues, virtual tables, rule of three, memory leaks,
 * segmentation faults
 */
#include "Bob.hpp"

namespace examples {

/**
 * @brief Example 1: contains test cases for the diagonal difference example
 *
 * Idea: style of code; usage of standard library; complexity of algorithm
 * (O(n) vs O(n²))
 */
void checkDiagonalDifference();

/**
 * @brief Example 2: Contains test cases for the plus-minus-count example
 *
 * Idea: simple operations (modulo, logical or), check division by zero, static
 * casting, standard library usage
 */
void checkCountPlusMinus();

/**
 * @brief Example 3: contains test cases for computing the sum of an array
 * example
 *
 *  Idea: standardized types, long types, standard library
 */
void checkSumOfArray();

/**
 * @brief Example 4: contains test cases for the internal states exporting
 * example
 *
 * Idea: c++ features (preprocessor directives, friend classes, getter/setter,
 * public/private sections)
 */
void checkSallyInternalStates();

/**
 * @brief Example 5: contains test cases for the sum of unique array values
 *
 * Idea: Data structures, types and algorithms, standardized long types
 */
void checkUniqueSumOfArray();

/**
 * @brief Example 6: contains test cases for the running median example
 *
 * Idea: algorithmic challenges (complexity of used algorithm, smart pointer
 * usage/concept)
 */
void checkRunningMedian();

}  // namespace examples