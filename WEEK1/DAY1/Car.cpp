#include <string>
#include <iostream>
#include <vector>
#include "Car.h"

Car::Car(std::string id)
    : _id(id) // Deligated constructors or constructors deligation
{
    _price = 0.0f;
    _type = VehicleType::HATCHBACK;
}

Car::Car(std::string id, VehicleType type)
    : Car(id, type)
{
    _price = 0.0f;
}

Car::Car(std::string id, float price, VehicleType type)
    : Car(id, type)
{
    _price = price;
}

void Car::display()
{
    std::cout << "ID : " << _id << std::endl;
    std::cout << "Price : " << _price << std::endl;
    std::cout << "CarType : " << std::endl;
    switch (_type)
    {
    case VehicleType::SEDAN:
        std::cout << "SEDAN" << std::endl;
        break;
    case VehicleType::SUV:
        std::cout << "SUV" << std::endl;
        break;
    case VehicleType::HATCHBACK:
        std::cout << "HATCHBACK" << std::endl;
        break;
    default:
        std::cout << "UNKNOWN" << std::endl; // Handle unknown type
        break;
    }

    std::cout << std::endl;
}

// float findaverage(std::vector<Car> c)
// {
//     if (c.empty())
//         std::cout << "No Details Available\n";
//     float sum = 0.0f;
//     float result = 0.0f;
//     int size = c.size();
//     for (int i = 0; i < size; i++)
//     {
//         sum += c[i].price();
//     }
//     result = sum / size;
//     return result;
// }
