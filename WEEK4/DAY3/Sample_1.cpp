// Varaint accessing
#include <array>
#include <iostream>
#include <variant>

using Vtype = std::variant<int, std::string>; // std::variant<0,1>
using Container = std::array<Vtype, 5>;

void Operation(const Container &data) {
  int total = 0;
  for (const Vtype &v : data) {
    auto f1 = [](auto &&val) { std::cout << val << " -->\t"; };
    std::visit(f1, v);
    if (std::holds_alternative<int>(v)) {
      int data = std::get<0>(v);  
      total += std::get<0>(v);
      std::cout << data * data << "\n";
    } else {
      std::string temp = std::get<1>(v);
      std::cout << temp.length() << "\n";
    }
  }
  std::cout << "Sum of integers is: " << total << "\n";
}
int main() {
  Container data;
  data[0] = 10;
  data[1] = 12;
  data[2] = "C++";
  data[3] = 18;
  data[4] = "Python";
  Operation(data);
}

/*
 If all variables can follow common syntax VISIT can be used
 If variables in variant follow or have different use cases.using
    holds_alternative and get.
*/

