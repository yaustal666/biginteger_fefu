#include <gtest/gtest.h>

#include <iostream>

#include "../Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 1000000000;

TEST(AbobaTest, BinaryPlus_1) {
  Integer test_Integer_sum1(1), test_Integer_sum2(1);
  test_Integer_sum1 = test_Integer_sum1 + test_Integer_sum2;
  EXPECT_EQ(test_Integer_sum1.getString(), "2");

  Integer test_Integer_sum3(-1), test_Integer_sum4(-1);
  test_Integer_sum3 = test_Integer_sum3 + test_Integer_sum4;
  EXPECT_EQ(test_Integer_sum3.getString(), "-2");

  Integer test_Integer_sum5(-8795431), test_Integer_sum6(9356718562);
  test_Integer_sum5 = test_Integer_sum5 + test_Integer_sum6;
  EXPECT_EQ(test_Integer_sum5.getString(), "9347923131");

  Integer test_Integer_sum7(-8795431), test_Integer_sum8(9356718562);
  test_Integer_sum7 = test_Integer_sum8 + test_Integer_sum7;
  EXPECT_EQ(test_Integer_sum7.getString(), "9347923131");
}

TEST(AbobaTest, BinaryPlus_2) {
  Integer test_Integer_sum1(ULLONG_MAX), test_Integer_sum2(ULLONG_MAX);
  test_Integer_sum1 = test_Integer_sum1 + test_Integer_sum2;
  EXPECT_EQ(test_Integer_sum1.getString(), "36893488147419103230");

  Integer test_Integer_sum3(LLONG_MIN), test_Integer_sum4(LLONG_MIN);
  test_Integer_sum3 = test_Integer_sum3 + test_Integer_sum4;
  EXPECT_EQ(test_Integer_sum3.getString(), "-18446744073709551616");

  Integer test_Integer_sum5(LLONG_MIN), test_Integer_sum6(ULLONG_MAX);
  test_Integer_sum5 = test_Integer_sum6 + test_Integer_sum5;
  EXPECT_EQ(test_Integer_sum5.getString(), "9223372036854775807");
}

TEST(AbobaTest, BinaryPlus_3) {
  Integer test_Integer_sum1(ULLONG_MAX), test_Integer_sum2(ULLONG_MAX);
  for (int i = 0; i < 10; ++i) {
    test_Integer_sum1 += test_Integer_sum2;
  }
  EXPECT_EQ(test_Integer_sum1.getString(), "202914184810805067765");

  Integer test_Integer_sum3(LLONG_MIN), test_Integer_sum4(LLONG_MIN);
  for (int i = 0; i < 10; ++i) {
    test_Integer_sum3 += test_Integer_sum4;
  }
  EXPECT_EQ(test_Integer_sum3.getString(), "-101457092405402533888");
}

TEST(AbobaTest, BinaryMinus_1) {
  Integer test_Integer_sub1(123), test_Integer_sub2(125);
  test_Integer_sub1 = test_Integer_sub1 - test_Integer_sub2;
  EXPECT_EQ(test_Integer_sub1.getString(), "-2");

  Integer test_Integer_sub3(LLONG_MAX), test_Integer_sub4(ULLONG_MAX);
  test_Integer_sub3 = test_Integer_sub3 - test_Integer_sub4;
  EXPECT_EQ(test_Integer_sub3.getString(), "-9223372036854775808");

  Integer test_Integer_sub6(125000), test_Integer_sub7(-125000);
  test_Integer_sub6 = test_Integer_sub6 - test_Integer_sub7;
  EXPECT_EQ(test_Integer_sub6.getString(), "250000");

  Integer test_Integer_sub8(-1342543535764168710),
      test_Integer_sub9(123456967745345241);
  test_Integer_sub8 = test_Integer_sub8 - test_Integer_sub9;
  EXPECT_EQ(test_Integer_sub8.getString(), "-1466000503509513951");
}

TEST(AbobaTest, BinaryMinus_2) {
  Integer test_Integer_sub1(123), test_Integer_sub2(125);
  test_Integer_sub1 -= test_Integer_sub2;
  EXPECT_EQ(test_Integer_sub1.getString(), "-2");

  Integer test_Integer_sub3(LLONG_MAX), test_Integer_sub4(ULLONG_MAX);
  test_Integer_sub3 -= test_Integer_sub4;
  EXPECT_EQ(test_Integer_sub3.getString(), "-9223372036854775808");

  Integer test_Integer_sub6(125000), test_Integer_sub7(-125000);
  test_Integer_sub6 -= test_Integer_sub7;
  EXPECT_EQ(test_Integer_sub6.getString(), "250000");

  Integer test_Integer_sub8(1342543535764168710),
      test_Integer_sub9(1342543535764168709);
  test_Integer_sub8 -= test_Integer_sub9;
  EXPECT_EQ(test_Integer_sub8.getString(), "1");
}

int main() {
  testing::InitGoogleTest();
  std::cout << "\nTesting: \n";
  std::cout
      << "Long Integer Laba Binary Operators\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}