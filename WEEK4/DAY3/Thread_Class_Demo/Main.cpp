#include "ThreadOperation.h"
#include <array>

int main() {
  //   ThreadOperation obj1(10);
  //   std::thread th1(&ThreadOperation::Square, &obj1);
  ThreadOperation obj2(10);
  std::thread th2(&ThreadOperation::Cube, &obj2);
  std::thread th3(&ThreadOperation::Produce_value_for_cube, &obj2);
  std::array<std::thread, 3> threadarray;

  //   th1.join();
  th2.join();
  th3.join();
}