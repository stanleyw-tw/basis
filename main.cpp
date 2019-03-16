/**
 * @brief main file
 *
 * @file main.cpp
 * @author your name
 * @date 2018-04-17
 */

#include <cstring>

#include "test-methods.hpp"

int main(int argc, char* argv[]) {
  if (argc == 1 || std::strcmp(argv[1], "1") == 0) {
    // example 1:
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 1" << std::endl;
    examples::checkDiagonalDifference();
  }
  if (argc == 1 || std::strcmp(argv[1], "2") == 0) {
    // example 2
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 2" << std::endl;
    examples::checkCountPlusMinus();
  }
  if (argc == 1 || std::strcmp(argv[1], "3") == 0) {
    // example 3
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 3" << std::endl;
    examples::checkSumOfArray();
  }
  if (argc == 1 || std::strcmp(argv[1], "4") == 0) {
    // example 3
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 4" << std::endl;
    examples::checkSallyInternalStates();
  }
  if (argc == 1 || std::strcmp(argv[1], "5") == 0) {
    // example 5
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 5" << std::endl;
    examples::checkUniqueSumOfArray();
  }
  if (argc == 1 || std::strcmp(argv[1], "6") == 0) {
    // example 6
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 6" << std::endl;
    examples::checkRunningMedian();
  }
  if (argc == 1 || std::strcmp(argv[1], "7") == 0) {
    // example 7
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "run example 7" << std::endl;
    examples::checkBob();
  }

  return 0;
}
