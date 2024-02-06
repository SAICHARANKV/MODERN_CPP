#include <iostream>
#include <tuple>
#include <array>
int main()
{
    // In same line we can destructure multiple items to multiple variables
    // It will work on items that have a particular size
    // It works array, tuple, pair.
    auto [age, experience] = std::array<int, 2>{27, 12};
    std::cout << "Experience: " << experience << "\n";
    std::cout << "Age: " << age << "\n";

    auto [a, b] = std::pair<int, std::string>{101, "SAICHARAN"};
    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";

    auto [c, d, e] = std::tuple<int, std::string, float>{1, "SUNNY", 99.9f};
    std::cout << "C: " << c << "\n";
    std::cout << "D: " << d << "\n";
    std::cout << "E: " << e << "\n";
}