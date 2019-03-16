/**
 * @brief You need to export the internal states of Sally. That includes Sall's
 * the private and public variables. How would you solve this problem when you
 * are solely allowed to add code to this file without altering existing code
 * but, of course, you are free to add new code wherever you want.
 *
 * @file graybox-problem.hpp
 * @author your name
 * @date 2018-04-17
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace examples {

class Sally {
public:
  Sally(int32_t publicID, int32_t privateID)
      : sallyPublicID(publicID), sallyPrivateID(privateID) {}
  ~Sally() {}

  int32_t sallyPublicID;

private:
  int32_t sallyPrivateID;
};

class Sniffer {
public:
  void getSallyInternalStates(const Sally &sally, int32_t *sallyPublicID,
                              int32_t *sallyPrivateID) {
    /* Write here your code that writes the internal states of Sally to the
* pointers in the parameter list. */
  }
};

} // namespace examples
