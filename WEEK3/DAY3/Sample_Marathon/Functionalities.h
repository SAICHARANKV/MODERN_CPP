#include <iostream>
#include <vector>
#include <functional>

using FnType = std::function<int(std::vector<int>)>; // Function Wrapper
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>;

extern FnType f1;
extern FnType f2;
extern FnType f3;
void MakeLambda(FnContainer &fns);

void Operation(FnContainer &fns, DataContainer &data);