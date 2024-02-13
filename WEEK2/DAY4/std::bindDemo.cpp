#include <functional>
#include <iostream>
#include <cstring>
#include "VIRTUAL_CAST_DESTRUCT_EXAMPLE/Employee.hpp"
#include "VIRTUAL_CAST_DESTRUCT_EXAMPLE/HR.hpp"
#include "VIRTUAL_CAST_DESTRUCT_EXAMPLE/Employee.cpp"
#include "VIRTUAL_CAST_DESTRUCT_EXAMPLE/HR.cpp"

// Partial functional
// Partial Function g(x) is based on keeping y as a constant

int formula(int x, int y, int z)
{
    return ((x + y) - z);
}

int main()
{
    formula(10, 20, 30);

    auto fn = std::bind(formula, std::placeholders::_1, std::placeholders::_2, 30);
    std::cout << fn(10, 20) << "\n"; // 3rd parameter never passed assumed as 30 // 10

    auto fn2 = std::bind(formula, std::placeholders::_3, std::placeholders::_1, 20);
    std::cout << fn2(10, 20, 80) << "\n"; // 2nd parameter never passed assumed as 20 // 70

    auto fn3 = std::bind(formula, std::placeholders::_2, std::placeholders::_3, 10);
    std::cout << fn3(50, 20, 80) << "\n"; // 2nd parameter never passed assumed as 20 // 70

    auto bindstrcpy = std::bind(strcpy, std::placeholders::_2, std::placeholders::_1);

    // std::bind Allows u to remap the parameters to user convience.
    // It switches the parameters placing and passes accordingly.
    // auto is used as return type of fn and fn2 using bind is not fixed or compiler dependent result;

    auto l1 = [](int x, int y, int z) -> int
    {
        return ((x + y) - z);
    };

    auto binded_lambda = std::bind(l1, std::placeholders::_2, 30, std::placeholders::_1);
    std::cout << binded_lambda(30, 10) << std::endl; // 10

    HR h1(101, "Sai", 299221.0f, 10, HrSpecializationType::PMT);
    auto bind_CalculateTax = std::bind(&HR::CalculateTax, &h1);
    std::cout << bind_CalculateTax() << "\n";
}