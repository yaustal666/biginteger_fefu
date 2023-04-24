#include <gtest/gtest.h>

#include <iostream>

#include "../Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 100000000;

TEST(AbobaTest, Constructors_ch_uch) {
  // CHAR_MIN = -128, UCHAR_MAX = 255, n = 110, z = 122
  char ch1 = CHAR_MIN, ch2 = 'n', ch3 = 'z';
  unsigned char uch1 = UCHAR_MAX, uch2 = 'n', uch3 = 'z';

  Integer test_Integer_ch1(ch1), test_Integer_ch2(ch2), test_Integer_ch3(ch3);

  EXPECT_EQ(test_Integer_ch1.getString(), "-128");
  EXPECT_EQ(test_Integer_ch2.getString(), "110");
  EXPECT_EQ(test_Integer_ch3.getString(), "122");

  Integer test_Integer_uch1(uch1), test_Integer_uch2(uch2),
      test_Integer_uch3(uch3);

  EXPECT_EQ(test_Integer_uch1.getString(), "255");
  EXPECT_EQ(test_Integer_uch2.getString(), "110");
  EXPECT_EQ(test_Integer_uch3.getString(), "122");
}

TEST(AbobaTest, Constructors_sh_ush) {
  // SHRT_MIN = -32768, USHRT_MAX = 65535
  short sh1 = SHRT_MIN, sh2 = 32000, sh3 = -4356;
  unsigned short ush1 = USHRT_MAX, ush2 = 2452, ush3 = 8999;

  Integer test_Integer_sh1(sh1), test_Integer_sh2(sh2), test_Integer_sh3(sh3);
  EXPECT_EQ(test_Integer_sh1.getString(), "-32768");
  EXPECT_EQ(test_Integer_sh2.getString(), "32000");
  EXPECT_EQ(test_Integer_sh3.getString(), "-4356");

  Integer test_Integer_ush1(ush1), test_Integer_ush2(ush2),
      test_Integer_ush3(ush3);
  EXPECT_EQ(test_Integer_ush1.getString(), "65535");
  EXPECT_EQ(test_Integer_ush2.getString(), "2452");
  EXPECT_EQ(test_Integer_ush3.getString(), "8999");
}

TEST(AbobaTest, Constructors_i_ui) {
  // INT_MIN = -2147483648, UINT_MAX = 4294967295
  int i1 = 0, i2 = INT_MIN, i3 = 462;
  unsigned int ui1 = 0, ui2 = UINT_MAX, ui3 = 1472399;

  Integer test_Integer_i1(i1), test_Integer_i2(i2), test_Integer_i3(i3);
  EXPECT_EQ(test_Integer_i1.getString(), "0");
  EXPECT_EQ(test_Integer_i2.getString(), "-2147483648");
  EXPECT_EQ(test_Integer_i3.getString(), "462");

  Integer test_Integer_ui1(ui1), test_Integer_ui2(ui2), test_Integer_ui3(ui3);
  EXPECT_EQ(test_Integer_ui1.getString(), "0");
  EXPECT_EQ(test_Integer_ui2.getString(), "4294967295");
  EXPECT_EQ(test_Integer_ui3.getString(), "1472399");
}

TEST(AbobaTest, Constructors_l_ul) {
  // LONG_MIN = -9223372036854775808, ULONG_MAX = 18446744073709551615
  long l1 = -34, l2 = LONG_MIN, l3 = 8765443;
  unsigned long ul1 = ULONG_MAX, ul2 = 1, ul3 = 98765432;
  Integer test_Integer_l1(l1), test_Integer_l2(l2), test_Integer_l3(l3);
  EXPECT_EQ(test_Integer_l1.getString(), "-34");
  EXPECT_EQ(test_Integer_l2.getString(), "-9223372036854775808");
  EXPECT_EQ(test_Integer_l3.getString(), "8765443");

  Integer test_Integer_ul1(ul1), test_Integer_ul2(ul2), test_Integer_ul3(ul3);
  EXPECT_EQ(test_Integer_ul1.getString(), "18446744073709551615");
  EXPECT_EQ(test_Integer_ul2.getString(), "1");
  EXPECT_EQ(test_Integer_ul3.getString(), "98765432");
}

TEST(AbobaTest, Constructors_ll_ull) {
  // LLONG_MIN = -9223372036854775808, ULLONG_MAX = 18446744073709551615
  long long ll1 = -65756646, ll2 = LLONG_MIN, ll3 = 65762735327;
  unsigned long long ull1 = 1764, ull2 = ULLONG_MAX, ull3 = 66725467254872648;

  Integer test_Integer_ll1(ll1), test_Integer_ll2(ll2), test_Integer_ll3(ll3);
  EXPECT_EQ(test_Integer_ll1.getString(), "-65756646");
  EXPECT_EQ(test_Integer_ll2.getString(), "-9223372036854775808");
  EXPECT_EQ(test_Integer_ll3.getString(), "65762735327");

  Integer test_Integer_ull1(ull1), test_Integer_ull2(ull2),
      test_Integer_ull3(ull3);
  EXPECT_EQ(test_Integer_ull1.getString(), "1764");
  EXPECT_EQ(test_Integer_ull2.getString(), "18446744073709551615");
  EXPECT_EQ(test_Integer_ull3.getString(), "66725467254872648");
}

TEST(AbobaTest, Constructors_copy1) {
  Integer test_Integer_origin1(LLONG_MIN), test_Integer_origin2(53247242);

  Integer test_Integer_copy1(test_Integer_origin1),
      test_Integer_copy2(test_Integer_origin2);

  EXPECT_EQ(test_Integer_origin1.getString(), test_Integer_copy1.getString());
  EXPECT_EQ(test_Integer_origin2.getString(), test_Integer_copy2.getString());
}

TEST(AbobaTest, Constructors_copy2) {
  Integer test_Integer_origin1(LLONG_MIN), test_Integer_origin2(53247242);

  Integer test_Integer_copy1 = test_Integer_origin1;
  Integer test_Integer_copy2(123);
  test_Integer_copy2 = test_Integer_origin2;

  EXPECT_EQ(test_Integer_origin1.getString(), test_Integer_copy1.getString());
  EXPECT_EQ(test_Integer_origin2.getString(), test_Integer_copy2.getString());
}

int main() {
  testing::InitGoogleTest();
  std::cout << "Testing: \n";
  std::cout << "Long Integer Laba Constructors\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}