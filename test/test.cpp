#include <gtest/gtest.h>
#include <cstdint>
#include "../src/code.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  
  EXPECT_EQ(Sum(1, 2), 3);
  EXPECT_EQ(Sum(1, 2, 3), 6);
}
