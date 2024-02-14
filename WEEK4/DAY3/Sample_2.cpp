#include <cstring>
#include <functional>
#include <iostream>

int formula(int x, int y, int z) { return ((x + y) - z); }

int main() {
  auto strcpy_binded =
      std::bind(strcpy, std::placeholders::_2, std::placeholders::_1);
  // x=Source y=dest
  auto formula_binded = std::bind(formula, 100, 200, std::placeholders::_1);
  std::cout<<formula_binded(1,2,3,4,5,6);

}