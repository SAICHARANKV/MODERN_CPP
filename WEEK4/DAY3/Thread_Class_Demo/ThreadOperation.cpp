#include "ThreadOperation.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs) {
  os << "_cube_val: " << rhs._cube_val << " _value: " << rhs._value;
  return os;
}
void ThreadOperation::Produce_value_for_cube() {
  std::cout << "Enter Cube Value: " << "\n";
  std::cin >> _cube_val;
  _cube_val_available = true;
  cv.notify_one();
}

void ThreadOperation::Cube() {
  std::unique_lock<std::mutex> lk(mt);
  cv.wait(lk, [&]() { return _cube_val_available; });
    std::cout << "Cube: " << _cube_val * _cube_val * _cube_val << "\n";

}

void ThreadOperation::Square() {
  std::lock_guard lk(mt);
  std::cout << _value * _value << "\n";
}