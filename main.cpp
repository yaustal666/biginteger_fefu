#include <gtest/gtest.h>

#include <iostream>

#include "Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 1000000000;

int main() {
  std::cout << "Testing: \n";
  std::cout << "Long Integer Laba Unar Operators\n|||||\n|||||\n|||||\nvvvvv\n";

  Integer a1(LLONG_MIN), b1(ULLONG_MAX);

  Integer res = a1 + b1;

  std::cout << res;
}