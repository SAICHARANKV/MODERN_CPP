#include <algorithm>
#include <array>
#include <iostream>
#include <thread>

/*
    step 1 : check const & reference to what type?
        st::array<int,2>

    step 2 : look at the class for this type, is it
    copu constructible,move constructible or both?

    step 3 : If only copy is enable,user must lvalue
            If only move is enable, copy is not allowed ,only  r value
            If both are available, user can pass both lvalue of array or r value
   of array
*/

void Square(const std::array<int, 5> &data) {
  std::for_each(data.begin(), data.end(), [](const int &number) {
    std::cout << number * number << "\t";
  });
}

int main() {
  std::cout << "Hello\n";

  std::array<int, 5> result;
  std::array<int, 5> data{1, 2, 3, 4, 5};
  int i = 0;
  std::thread t1(Square, std::ref(data));

  /*Main Thread operation */
  std::for_each(data.begin(), data.end(),
                [&](const int &number) { result[i++] = number * number; });
  t1.join();
}