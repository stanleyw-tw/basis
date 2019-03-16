/**
 * @brief Fix the following code: change the definition of Bob and Alice such
 * that they behave as expected in checkBob-method. Fix memory
 * leaks, eventually.
 *
 * @file Bob.hpp
 * @author Fabian Franzelin
 * @date 2018-04-17
 */

#pragma once

#include <iostream>
#include <vector>

#include "helpers.hpp"

namespace examples {

class Bob {
 public:
  Bob() { bobId = new std::vector<int>(1, 0); }
  explicit Bob(int pBobId) { bobId = new std::vector<int>(1, pBobId); }
  virtual ~Bob() { delete bobId; }

  std::vector<int>* getIds() { return bobId; }

 protected:
  std::vector<int>* bobId;
};

class Alice : public Bob {
 public:
  explicit Alice(int pAliceId, int pBobId) {
    this->bobId = new std::vector<int>(1, pBobId);
    aliceId = new std::vector<int>(1, pAliceId);
  }
  virtual ~Alice() { delete aliceId; }

  std::vector<int>* getIds() { return aliceId; }

 private:
  std::vector<int>* aliceId;
};

inline void checkBob() {
  Bob* bob = new Bob(1);
  std::cout << "Bob  : ";
  printVector(bob->getIds()->begin(), bob->getIds()->end());

  Bob* alice = new Alice(2, (*bob->getIds())[0]);
  std::cout << "Alice: ";
  printVector(alice->getIds()->begin(), alice->getIds()->end());

  Bob bobby = *bob;
  std::cout << "Bobby: ";
  printVector(bobby.getIds()->begin(), bobby.getIds()->end());

  delete bob;

  std::cout << "Bobby: ";
  printVector(bobby.getIds()->begin(), bobby.getIds()->end());

  delete alice;
}

}  // namespace examples
