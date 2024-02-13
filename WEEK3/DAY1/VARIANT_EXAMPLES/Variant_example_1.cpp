#include <iostream>
#include <variant>
#include <string>
#include <array>

int main()
{
    std::variant<int, float, std::string> v1;
    v1 = 10;
    // visit(function,item/variable)
    std::visit([](auto &&val)
               { std::cout << val << "\n"; },
               v1); // apply lambda function on v1  [10 | x]
    v1 = 10.21f;    //[x | 10.21f]
    std::visit([](auto &&val)
               { std::cout << val << "\n"; },
               v1);
    v1 = "0202";
    std::visit([](auto &&val)
               { std::cout << val << "\n"; },
               v1);

    std::array<std::variant<int, float>, 3> data{12,2.34f,33};

    for (std::variant<int, float> &v : data)
    {
        std::visit([](auto &&val)
                   { std::cout << val << "\n"; },
                   v);
    }
}