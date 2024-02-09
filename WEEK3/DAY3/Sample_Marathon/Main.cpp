#include "Functionalities.h"
#include <iostream>

int main()
{
    FnContainer fns;
    std::vector<int> data = {19, 18, 28, 293, 29};
    MakeLambda(fns);
    Operation(fns, data);
    DataContainer dummydata{1, 2, 3};
    auto bindedOperation = std::bind(Operation, std::placeholders::_1, std::ref(dummydata));
    bindedOperation(fns);
}