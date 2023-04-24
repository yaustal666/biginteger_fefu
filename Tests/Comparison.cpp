#include <gtest/gtest.h>

#include <iostream>

#include "../Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 1000000000;

TEST(AbobaTest, Comparison_1) {
  Integer test_Integer_compare1(1), test_Integer_compare2(1);

  bool eq = test_Integer_compare1 == test_Integer_compare2;
  bool more = test_Integer_compare1 > test_Integer_compare2;
  bool less = test_Integer_compare1 < test_Integer_compare2;
  bool no_eq = test_Integer_compare1 != test_Integer_compare2;
  bool more_eq = test_Integer_compare1 >= test_Integer_compare2;
  bool less_eq = test_Integer_compare1 <= test_Integer_compare2;

  EXPECT_EQ(eq, true);
  EXPECT_EQ(more, false);
  EXPECT_EQ(less, false);
  EXPECT_EQ(no_eq, false);
  EXPECT_EQ(more_eq, true);
  EXPECT_EQ(less_eq, true);
}

TEST(AbobaTest, Comparison_2) {
  Integer test_Integer_compare1(-123), test_Integer_compare2(-123);

  bool eq = test_Integer_compare1 == test_Integer_compare2;
  bool more = test_Integer_compare1 > test_Integer_compare2;
  bool less = test_Integer_compare1 < test_Integer_compare2;
  bool no_eq = test_Integer_compare1 != test_Integer_compare2;
  bool more_eq = test_Integer_compare1 >= test_Integer_compare2;
  bool less_eq = test_Integer_compare1 <= test_Integer_compare2;

  EXPECT_EQ(eq, true);
  EXPECT_EQ(more, false);
  EXPECT_EQ(less, false);
  EXPECT_EQ(no_eq, false);
  EXPECT_EQ(more_eq, true);
  EXPECT_EQ(less_eq, true);
}

TEST(AbobaTest, Comparison_3) {
  Integer test_Integer_compare1(-500099999999),
      test_Integer_compare2(-699999999999999);

  bool eq = test_Integer_compare1 == test_Integer_compare2;
  bool more = test_Integer_compare1 > test_Integer_compare2;
  bool less = test_Integer_compare1 < test_Integer_compare2;
  bool no_eq = test_Integer_compare1 != test_Integer_compare2;
  bool more_eq = test_Integer_compare1 >= test_Integer_compare2;
  bool less_eq = test_Integer_compare1 <= test_Integer_compare2;

  EXPECT_EQ(eq, false);
  EXPECT_EQ(more, true);
  EXPECT_EQ(less, false);
  EXPECT_EQ(no_eq, true);
  EXPECT_EQ(more_eq, true);
  EXPECT_EQ(less_eq, false);
}

TEST(AbobaTest, Comparison_4) {
  Integer test_Integer_compare1(-12311243242342241), test_Integer_compare2(1);

  bool eq = test_Integer_compare1 == test_Integer_compare2;
  bool more = test_Integer_compare1 > test_Integer_compare2;
  bool less = test_Integer_compare1 < test_Integer_compare2;
  bool no_eq = test_Integer_compare1 != test_Integer_compare2;
  bool more_eq = test_Integer_compare1 >= test_Integer_compare2;
  bool less_eq = test_Integer_compare1 <= test_Integer_compare2;

  EXPECT_EQ(eq, false);
  EXPECT_EQ(more, false);
  EXPECT_EQ(less, true);
  EXPECT_EQ(no_eq, true);
  EXPECT_EQ(more_eq, false);
  EXPECT_EQ(less_eq, true);
}

TEST(AbobaTest, Comparison_5) {
  Integer test_Integer_compare1(80065765173656721),
      test_Integer_compare2(-3212233134);

  bool eq = test_Integer_compare1 == test_Integer_compare2;
  bool more = test_Integer_compare1 > test_Integer_compare2;
  bool less = test_Integer_compare1 < test_Integer_compare2;
  bool no_eq = test_Integer_compare1 != test_Integer_compare2;
  bool more_eq = test_Integer_compare1 >= test_Integer_compare2;
  bool less_eq = test_Integer_compare1 <= test_Integer_compare2;

  EXPECT_EQ(eq, false);
  EXPECT_EQ(more, true);
  EXPECT_EQ(less, false);
  EXPECT_EQ(no_eq, true);
  EXPECT_EQ(more_eq, true);
  EXPECT_EQ(less_eq, false);
}

int main() {
  testing::InitGoogleTest();
  std::cout << "Testing: \n";
  std::cout << "Long Integer Laba Unar Operators\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}