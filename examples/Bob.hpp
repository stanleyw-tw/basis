/**
 * @brief Fix the following code: change the definition of Bob and Alice such
 * that they behave as expected in checkBob-method. Fix memory
 * leaks, eventually.
 *
 * @file Bob.hpp
 * @author Fabian Franzelin, Stanley Wu
 * @date 2019-03-17
 */

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "helpers.hpp"

namespace examples {

class Bob {
public:
  Bob() {
    bobId = std::shared_ptr<std::vector<int>>(new std::vector<int>(1, 0));
  }
  explicit Bob(int pBobId) {
    bobId = std::shared_ptr<std::vector<int>>(new std::vector<int>(1, pBobId));
  }
  virtual ~Bob() {
    // delete bobId;
  }

  std::shared_ptr<std::vector<int>> getIds() { return bobId; }

protected:
  std::shared_ptr<std::vector<int>> bobId;
};

class Alice : public Bob {
public:
  explicit Alice(int pAliceId, int pBobId) {
    this->bobId =
        std::shared_ptr<std::vector<int>>(new std::vector<int>(1, pBobId));
    aliceId =
        std::shared_ptr<std::vector<int>>(new std::vector<int>(1, pAliceId));
  }
  virtual ~Alice() {
    // delete aliceId;
  }

  std::shared_ptr<std::vector<int>> getIds() { return aliceId; }

private:
  std::shared_ptr<std::vector<int>> aliceId;
};

inline void checkBob() {
  Bob *bob = new Bob(1);
  std::cout << "Bob  : ";
  printVector(bob->getIds()->begin(), bob->getIds()->end());

  Bob *alice = new Alice(2, (*bob->getIds())[0]);
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

} // namespace examples
