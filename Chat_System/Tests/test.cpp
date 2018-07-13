/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2018  pawn <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include "../Client/client.hpp"

namespace {

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
    //*** Testing pallet***
//  protected:
//   // You can remove any or all of the following functions if its body
//   // is empty.
// 
//   FooTest() {
//     // You can do set-up work for each test here.
//   }
// 
//   virtual ~FooTest() {
//     // You can do clean-up work that doesn't throw exceptions here.
//   }
// 
//   // If the constructor and destructor are not enough for setting up
//   // and cleaning up each test, you can define the following methods:
// 
//   virtual void SetUp() {
//     // Code here will be called immediately after the constructor (right
//     // before each test).
//   }
// 
//   virtual void TearDown() {
//     // Code here will be called immediately after each test (right
//     // before the destructor).
//   }
// 
//   // Objects declared here can be used by all tests in the test case for Foo.
// };
// 
// // Tests that the Foo::Bar() method does Abc.
// TEST_F(ClientTest, MethodBarDoesAbc) {
//   Client client;
//   EXPECT_EQ(0, client.logIn());
// }
// 
// // Tests that Foo does Xyz.
// TEST_F(ClientTest, DoesXyz) {
//   // Exercises the Xyz feature of Foo.
// }
// // 
};
};  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
