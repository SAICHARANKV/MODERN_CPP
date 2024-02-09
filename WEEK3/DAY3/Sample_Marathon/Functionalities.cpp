#include "Functionalities.h"
#include <vector>

void MakeLambda(FnContainer &fns)
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

    fns.emplace_back(f1);
    fns.emplace_back(f2);
    fns.emplace_back(f3);
};

void Operation(FnContainer &fns, DataContainer &data)
{
    for (FnType fn : fns)
    {
        fn(data);
    }
}
