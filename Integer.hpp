#ifndef INTEGER_LIB
#define INTEGER_LIB

#include <algorithm>
#include <cmath>
#include <compare>
#include <exception>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

template <typename T>
concept is_integer = std::is_integral_v<T>;

namespace biginteger {
class Integer final {
 public:
  //  constructors - implemented - tested
  Integer();
  Integer(const Integer&);
  Integer& operator=(const Integer&);

  // construct from integer - implemented - tested
  template <typename T>
    requires is_integer<T>
  Integer(T);

  template <typename T>
    requires is_integer<T>
  Integer& operator=(T);

  // destructor - implemented
  ~Integer();

  // unar operators - implemented - tested
  Integer operator-() const;
  Integer& operator--();
  Integer operator--(int);

  Integer operator+() const;
  Integer& operator++();
  Integer operator++(int);

  // arithmetic binary operators -
  [[nodiscard]] Integer operator-(const Integer&) const;
  Integer& operator-=(const Integer&);

  [[nodiscard]] Integer operator+(const Integer&) const;
  Integer& operator+=(const Integer&);

  [[nodiscard]] Integer operator*(const Integer&) const;
  Integer& operator*=(const Integer&);

  [[nodiscard]] Integer operator/(const Integer&) const;
  Integer& operator/=(const Integer&);

  [[nodiscard]] Integer operator%(const Integer&) const;
  Integer& operator%=(const Integer&);

  // convert to integer - implemented
  template <typename T>
    requires is_integer<T>
  [[nodiscard]] explicit operator T() const;

  // comparison operators - implemented
  [[nodiscard]] bool operator==(const Integer&) const;
  [[nodiscard]] bool operator!=(const Integer&) const;
  [[nodiscard]] bool operator<(const Integer&) const;
  [[nodiscard]] bool operator<=(const Integer&) const;
  [[nodiscard]] bool operator>(const Integer&) const;
  [[nodiscard]] bool operator>=(const Integer&) const;

  // need to define before using Integer
  static uint64_t BASE;

  // get string - implemented
  std::string getString();

  // ofstream overload - implemented
  template <typename OStream>
  friend OStream&& operator<<(OStream&&, const Integer&);

 private:
  uint64_t* data_;
  int length_;
  bool sign_;

  Integer& ChangeDataSize(int);
  friend bool isEqualZero(const Integer&);

  // to string - implemented
  static std::string Stringify(const Integer&);
};
}  // namespace biginteger
#endif  // INTEGER_LIB