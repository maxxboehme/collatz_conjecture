#include "main.h"
#include "gtest/gtest.h"

#define main FooMain

TEST(MyUnitTests, test_1) {
   ASSERT_EQ(collatz_cycle(5), 6);
}
