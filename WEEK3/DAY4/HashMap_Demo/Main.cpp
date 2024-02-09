#include "Employee.hpp"
#include <unordered_map>
#include<memory>

using MapContainer = std::unordered_map<int, const Employee &>;
using MapItem = std::pair<int, const Employee &>;

void Display(MapContainer &data)
{
    for (auto &[k, v] : data) // cpp 17
    {
        std::cout << "Key is: " << k << " value is:" << v << "\n";
    }
    std::cout << "----------------------\n";
    for (auto itr = data.begin(); itr != data.end(); ++itr) // cpp 03
    {
        std::cout << "Key is: " << itr->first << " value is:" << itr->second << "\n";
    }
    std::cout << "------------------------\n";

    for (const MapItem &p : data) // cpp 11
    {
        std::cout << "Key is: " << p.first << " value is:" << p.second << "\n";
    }
    std::cout << "-------------------------\n";
}

int main()
{
    MapContainer data{
        MapItem(10, Employee(10, "Sai", "Pune"))};

    data.emplace(MapItem(21, Employee(21, "KC", "Mumbai")));
    data.emplace(MapItem(33, Employee(33, "Kaveri", "Delhi")));

    Display(data);
}