#include "Integer.hpp"

namespace biginteger {

Integer::Integer() {
  sign_ = true;
  length_ = 0;
  data_ = new uint64_t[0];
}

Integer::Integer(const Integer &other) {
  sign_ = other.sign_;
  length_ = other.length_;
  data_ = new uint64_t[length_];
  for (size_t i = 0; i < length_; i++) data_[i] = other.data_[i];
}

Integer &Integer::operator=(const Integer &other) {
  delete[] data_;

  sign_ = other.sign_;
  length_ = other.length_;
  data_ = new uint64_t[length_];
  for (size_t i = 0; i < length_; i++) data_[i] = other.data_[i];

  return *this;
}

template <typename T>
  requires is_integer<T>
Integer::Integer(T number) {
  sign_ = number >= 0;
  uint64_t number_copy = 0;

  if (!sign_)
    number_copy = ULLONG_MAX + 1 - number;
  else
    number_copy = number;

  if (number_copy == 1 || number_copy == 0)
    length_ = 1;
  else if (number_copy % Integer::BASE == 0)
    length_ = std::ceil(std::log(number_copy + 1) / std::log(Integer::BASE));
  else
    length_ = std::ceil(std::log(number_copy) / std::log(Integer::BASE));

  data_ = new uint64_t[length_];
  for (size_t i = 0; i < length_; i++) data_[i] = 0;

  size_t i = 0;
  while (number_copy && i < length_) {
    data_[i] = number_copy % Integer::BASE;
    number_copy /= Integer::BASE;
    i++;
  }
}

template <typename T>
  requires is_integer<T>
Integer &Integer::operator=(T number) {
  Integer n(number);
  return *this = n;
}

Integer::~Integer() { delete[] data_; }

std::string Integer::Stringify(const Integer &other) {
  std::stringstream ss;
  std::string output;

  if (!other.sign_) ss << "-";
  ss << other.data_[other.length_ - 1];
  for (int i = other.length_ - 2; i >= 0; i--) {
    ss << std::setfill('0') << std::setw(std::log10(BASE)) << other.data_[i];
  }

  ss >> output;

  return output;
}

template <typename OStream>
OStream &&operator<<(OStream &&out, const Integer &number) {
  out << Integer::Stringify(number);
  return out;
}

bool Integer::operator==(const Integer &other) const {
  bool res = 1;
  if (sign_ != other.sign_) return 0;
  if (length_ != other.length_) return 0;

  for (int i = 0; i < length_; i++) {
    res = res && (data_[i] == other.data_[i]);
  }

  return res;
}

bool Integer::operator!=(const Integer &other) const {
  return !(*this == other);
}

bool Integer::operator>(const Integer &other) const {
  if (sign_ && !other.sign_) return 1;
  if (!sign_ && other.sign_) return 0;

  if (!sign_ && !other.sign_) {
    if (length_ < other.length_) return 1;
    if (length_ > other.length_) return 0;

    for (int i = length_ - 1; i >= 0; i--) {
      if (data_[i] > other.data_[i]) return 0;
      if (data_[i] < other.data_[i]) return 1;
    }
  } else {
    if (length_ < other.length_) return 0;
    if (length_ > other.length_) return 1;

    for (int i = length_ - 1; i >= 0; i--) {
      if (data_[i] > other.data_[i]) return 1;
      if (data_[i] < other.data_[i]) return 0;
    }
  }

  return 0;
}

bool Integer::operator>=(const Integer &other) const {
  return *this > other || *this == other;
}

std::string Integer::getString() { return Integer::Stringify(*this); }

bool Integer::operator<(const Integer &other) const { return other > *this; }

bool Integer::operator<=(const Integer &other) const {
  return other > *this || *this == other;
}

template <typename T>
  requires is_integer<T>
Integer::operator T() const {
  if (*this >= Integer(std::numeric_limits<T>::max()))
    return std::numeric_limits<T>::max();
  else if (*this <= Integer(std::numeric_limits<T>::min() + 1))
    return std::numeric_limits<T>::min();
  else
    return static_cast<T>(std::stoll(Integer::Stringify(*this)));
}

Integer &Integer::ChangeDataSize(int new_size) {
  uint64_t *data_copy = new uint64_t[length_];

  for (int i = 0; i < length_; i++) data_copy[i] = 0;

  for (int i = 0; i < length_; i++) data_copy[i] = data_[i];

  delete[] data_;
  data_ = new uint64_t[new_size];

  for (int i = 0; i < new_size; i++) data_[i] = 0;

  for (int i = 0; i < length_ && i < new_size; i++) data_[i] = data_copy[i];

  length_ = new_size;
  delete[] data_copy;
  return *this;
}

bool isEqualZero(const Integer &number) {
  if (number.length_ == 1 && number.data_[0] == 0) return true;
  return false;
}

Integer Integer::operator-(const Integer &other) const {
  if (!sign_ && other.sign_) return -(other + (-*this));
  if (sign_ && !other.sign_) return *this + (-other);

  if (other > *this) return -(other - *this);
  Integer result(*this);

  for (int i = 0; i < other.length_; ++i) {
    if (result.data_[i] < other.data_[i]) {
      result.data_[i] = (result.data_[i] - other.data_[i]) + BASE;
      result.data_[i + 1]--;
    } else
      result.data_[i] -= other.data_[i];
  }

  int count = 0;
  int i = 1;
  while (result.data_[result.length_ - i] == 0 && count < result.length_ - 1) {
    count++;
    i++;
  }
  result.ChangeDataSize(result.length_ - count);

  return result;
}

Integer Integer::operator+(const Integer &other) const {
  if (!sign_ && other.sign_) return other - (-*this);
  if (sign_ && !other.sign_) return *this - (-other);

  if (other > *this) return other + *this;

  Integer result(*this);
  result.ChangeDataSize(length_ + 1);

  for (int i = 0; i < other.length_; i++) {
    result.data_[i] += other.data_[i];
  }

  for (int i = 0; i < result.length_; i++) {
    if (result.data_[i] >= Integer::BASE) {
      result.data_[i] -= Integer::BASE;
      result.data_[i + 1]++;
    }
  }

  if (result.data_[result.length_ - 1] == 0) {
    result.ChangeDataSize(result.length_ - 1);
  }

  return result;
}

Integer Integer::operator-() const {
  Integer copy(*this);
  copy.sign_ = !copy.sign_;
  return copy;
}

Integer &Integer::operator--() { return *this -= Integer(1); }

Integer Integer::operator--(int) {
  Integer copy(*this);
  *this -= Integer(1);
  return copy;
}

Integer Integer::operator+() const { return *this; }

Integer &Integer::operator++() { return *this += Integer(1); }

Integer Integer::operator++(int) {
  Integer copy(*this);
  *this += Integer(1);
  return copy;
}

Integer &Integer::operator+=(const Integer &other) {
  return *this = *this + other;
}

Integer &Integer::operator-=(const Integer &other) {
  return *this = *this - other;
}

Integer Integer::operator*(const Integer &other) const {
  Integer result(0);

  if (isEqualZero(*this) || isEqualZero(other)) return result;

  result.sign_ = !(sign_ ^ other.sign_);
  std::string tmp = Integer::Stringify(*this) + Integer::Stringify(other);
  int check = std::ceil(tmp.size() / std::log10(BASE));

  result.ChangeDataSize(check);

  uint64_t shift = 0;

  for (int i = 0; i < other.length_; i++) {
    for (int j = 0; j < length_; j++) {
      result.data_[i + j] += other.data_[i] * data_[j];
    }
  }

  for (int i = 0; i < result.length_; i++) {
    result.data_[i] += shift;
    shift = result.data_[i] / BASE;
    result.data_[i] %= BASE;
  }

  int count = 0;
  int i = 1;
  while (result.data_[result.length_ - i] == 0 && count < result.length_ - 1) {
    count++;
    i++;
  }

  result.ChangeDataSize(result.length_ - count);

  return result;
}

Integer &Integer::operator*=(const Integer &other) {
  return *this = *this * other;
}

Integer Integer::operator/(const Integer &other) const {
  Integer result(0);
  if (*this < other || isEqualZero(*this)) return result;
  if (isEqualZero(other)) throw std::invalid_argument("Do not divide by 0");

  uint64_t startGuess = data_[length_ - 1] / other.data_[other.length_ - 1];
  Integer guess(startGuess);
  for (int i = 0; i < length_ - other.length_; i++) guess *= BASE;

  guess.sign_ = !(sign_ ^ other.sign_);

  std::cout << guess << std::endl;

  uint64_t i = 2;
  while (1) {
    result = guess * other;

    if (result <= *this && result + other > *this)
      return guess;
    else if (result < *this)
      guess += 1;
    else if (result > *this)
      guess -= 1;
  }
}

}  // namespace biginteger