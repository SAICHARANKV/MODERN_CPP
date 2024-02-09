/*

Create a function that accepts a container of functions
and container of numbers and apply every function on the whole
container at once.



fns=[f1|f2|f3]  data=[10|20|30]
for(fn:fns)
{
    fn(data);
}

// fix the value in some function using bind
*/

#include <iostream>
#include <vector>
#include <functional>

using FnType = std::function<int(std::vector<int> &data)>; // Function Wrapper
using FnContainer = std::vector<FnType>;                   // Functions
using DataContainer = std::vector<int>;                    // Data

void Operation(FnContainer &fns, DataContainer &data)
{
    for (FnType fn : fns) // Entering into function wrapper and performing on function
    {
        std::cout << "value: " << fn(data) << "\n";
    }
}

int main()
{
    /* Find First Number*/
    auto f1 = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw std::runtime_error("Data is empty!!!");
        return data.front();
    };
    /* Find Last Number*/
    auto f2 = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw std::runtime_error("Data is empty!!!");
        return data.back();
    };
    /* Find the total*/
    auto f3 = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw std::runtime_error("Data is empty!!!");
        int total = 0.0;
        for (int val : data)
        {
            total += val;
        }
        return total;
    };
    DataContainer data{10, 20, 30, 40, 50};
    FnContainer fns{f1, f2, f3};
    Operation(fns, data);
    DataContainer dummydata{1, 2, 3};

    auto bindedOperation = std::bind(Operation, std::placeholders::_1, std::ref(dummydata));
    bindedOperation(fns);
}