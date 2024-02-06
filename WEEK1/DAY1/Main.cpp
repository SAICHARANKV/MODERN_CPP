#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Car.h"
#include "CarType.h"
#include "Functionalities.h"

void magic(Car &c1)
{
    std::cout << c1.price() << "\n";
}
int main()
{
    // std::vector<Car *> c;
    // Car *c1 = new Car("1", 20000, VehicleType::SEDAN);
    // c.push_back(c1);
    // Car *c2 = new Car("2", 40000, VehicleType::HATCHBACK);
    // c.push_back(c2);
    // Car *c3 = new Car("3", 50000, VehicleType::SUV);
    // c.push_back(c3);
    // findaverage(c);
    container data; // empty container

    CreateObjects(data); // by reference to CreateObjects

    AveragePrice(data);
    std::string _id;
    std::cin >> _id;
    FindPriceById(data, _id);

    // std::string s1 = "1303";
    // magic(s1); // Throws an error as explicit word is given

    return 0;
}

/*
    if there is only 1 unknown parameter in a constructor (unknown means a parameter
    which does not have a default value), such a constructor can be called by passing
    1 value for unknown parameter

*/