#include "Employee.hpp"
#include <unordered_map>
#include <iostream>

#include <memory>

using EmpPointer = std::shared_ptr<Employee>;

using MapContainer = std::unordered_map<int, EmpPointer>;

using MapItem = std::pair<int, const EmpPointer>;

void Display(MapContainer &data)
{
    for (auto &[k, v] : data)
    {
        std::cout << "Key is: " << k << "\n"
                  << "Value is : "
                  << "\n"
                  << *v << "\n";
    }

    std::cout << "---------------------------------------" << std::endl;
    for (auto itr = data.begin(); itr != data.end(); ++itr)
    {
        std::cout << "Key is: " << itr->first << "\n"
                  << "Value is : "
                  << "\n"
                  << *(itr->second) << "\n";
    }
    std::cout << "---------------------------------------" << std::endl;

    for (MapItem p : data)
    {
        std::cout << "Key is: " << p.first << "\n"
                  << "Value is : "
                  << "\n"
                  << *(p.second) << "\n";
    }
}

/*
Map needs one const integer and one const l value reference of employee
*/

int main()
{
    // std::unordered_map<int, Employee> data;

    MapContainer data{
        MapItem(10, std::make_shared<Employee>(10, "Harshith", "Pune"))};

    data.emplace(
        std::make_pair<int, EmpPointer>(21, std::make_shared<Employee>(21, "Roshan", "Delhi")));

    data.emplace(
        std::make_pair<int, EmpPointer>(33, std::make_shared<Employee>(33, "Kaveri", "Chennai")));

    if (auto itr = data.find(10); itr != data.end())
    {
        std::cout << "Emp with the given ID: " << *(itr->second) << "\n";
    }
    else
    {
        std::cout << "Not found"
                  << "\n";
    }

    std::cout << "Number of Buckets: " << data.bucket_count() << "\n";
    std::cout << "Max Size: " << data.max_size() << "\n";
    std::cout << "Size of bucket 0: " << data.bucket_size(0) << "\n";
    std::cout << "In which Bucket is key 10? " << data.bucket(10) << "\n";

    Display(data);
}

/*
    Applications of hash tables/hash functions / hashing
    a)Data structure based on  hash tables
    b)cryptography
*/