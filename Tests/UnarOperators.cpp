#include <gtest/gtest.h>

#include <iostream>

#include "Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 1000000000;

TEST(AbobaTest, UnarOperators_1) {
  Integer test_Integer_unar_plus1(123), test_Integer_unar_plus2(-345);
  test_Integer_unar_plus1 = +test_Integer_unar_plus1;
  test_Integer_unar_plus2 = +test_Integer_unar_plus2;

  EXPECT_EQ(test_Integer_unar_plus1.getString(), "123");
  EXPECT_EQ(test_Integer_unar_plus2.getString(), "-345");
}

TEST(AbobaTest, UnarOperators_2) {
  Integer test_Integer_unar_minus1(875424141313),
      test_Integer_unar_minus2(-675674651635);
  test_Integer_unar_minus1 = -test_Integer_unar_minus1;
  test_Integer_unar_minus2 = -test_Integer_unar_minus2;

  EXPECT_EQ(test_Integer_unar_minus1.getString(), "-875424141313");
  EXPECT_EQ(test_Integer_unar_minus2.getString(), "675674651635");
}

TEST(AbobaTest, UnarOperators_3) {
  Integer test_Integer_unar_pp_l(999999999), test_Integer_unar_pp_r(12763);

  EXPECT_EQ((++test_Integer_unar_pp_l).getString(), "1000000000");
  EXPECT_EQ((test_Integer_unar_pp_r++).getString(), "12763");
  EXPECT_EQ(test_Integer_unar_pp_r.getString(), "12764");
}

TEST(AbobaTest, UnarOperators_4) {
  Integer test_Integer_unar_mm_l(1000000000), test_Integer_unar_mm_r(12763);

  EXPECT_EQ((--test_Integer_unar_mm_l).getString(), "999999999");
  EXPECT_EQ((test_Integer_unar_mm_r--).getString(), "12763");
  EXPECT_EQ(test_Integer_unar_mm_r.getString(), "12762");
}

int main() {
  testing::InitGoogleTest();
  std::cout << "Testing: \n";
  std::cout << "Long Integer Laba Unar Operators\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}