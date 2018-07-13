#include <gtest/gtest.h>
#include "../Client/client.hpp"
class ClientTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    
  }

  // virtual void TearDown() {}

  Client clientOne;
  Client clientTwo;
  Client clientThree
};
