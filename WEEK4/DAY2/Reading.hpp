#ifndef READING_HPP
#define READING_HPP

#include "ReadingType.hpp"
#include <ostream>

class Reading {
private:
  ReadingType _readingType;
  float _readingValue;

public:
  Reading() = delete;
  Reading(const Reading &) = delete;
  Reading(Reading &&) = default;
  Reading &operator=(const Reading &) = delete;
  Reading &&operator=(const Reading &&) = delete;
  Reading(ReadingType reading, float value);
  ~Reading() = default;

  friend std::ostream &operator<<(std::ostream &os, const Reading &rhs);

  bool operator<(const Reading &rhs) {
    return _readingValue < rhs._readingValue;
  }

  friend std::ostream &operator<<(std::ostream &os, const Reading &rhs) {
    os << "_readingType: " << static_cast<int>(rhs._readingType)
       << " _readingValue: " << rhs._readingValue;
    return os;
  }
};

#endif // READING_HPP
