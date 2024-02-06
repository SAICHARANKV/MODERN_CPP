#include <iostream>
#include <memory>
#include <optional>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"
void CreateCarObjects(CarPointerContainer &carData, EngineContainer &engineData)
{
    engineData.emplace_back(Engine("E101", EngineType::ICT, 400, 111));
    engineData.emplace_back(Engine("E102", EngineType::ICT, 100, 79));
    engineData.emplace_back(Engine("E103", EngineType::HYBRID, 412, 123));

    carData.emplace_back(std::make_shared<Car>("Car101", "Hyundai", CarType::SPORTS, 102930.0f, engineData[0]));
    carData.emplace_back(std::make_shared<Car>("Car102", "Skoda", CarType::SUV, 292912.0f, engineData[1]));
    carData.emplace_back(std::make_shared<Car>("Car103", "BMW", CarType::SEDAN, 299221.0f, engineData[2]));
}

// void CreateObjects(CarPointerContainer &CarData, EngineContainer &EngineData)
// {
//     std::string engineId{""};
//     int engineType{0};
//     int horsepower{0};
//     int torque{0};
//     std::string carId{""};
//     std::string carBrand{""};
//     // CarType carType{CarType::SEDAN}
//     int carType{0};
//     float carPrice{0.0f};

//     for (int i = 0; i < 2; i++)
//     {
//         std::cin >> engineId;
//         std::cin >> engineType;
//         std::cin >> horsepower;
//         std::cin >> torque;
//         EngineData.emplace_back(engineId, static_cast<EngineType>(engineType), horsepower, torque);
//     }
//     auto itr = EngineData.begin();
//     for (int i = 0; i < 2; i++)
//     {
//         std::cin >> carId;
//         std::cin >> carBrand;
//         std::cin >> carType;
//         std::cin >> carPrice;
//         CarData.emplace_back(std::make_shared<Car>(carId, carBrand, static_cast<CarType>(carType), carPrice, *itr++));
//     }
// }

/*
    case 1: find a match and return
    case 2: data is empty
    case 3: no matching ID
*/
int FindHorsePowerByCarId(CarPointerContainer &carData, std::string carId)
{
    if (carData.empty())
    {
        throw EmptyContainerException("No Data !!! Empty container !!!\n ");
    }

    for (CarPointer &ptr : carData)
    {
        if (ptr->carId() == carId)
        {
            return ptr->carEngine().get().engineHorsePower();
        }
    }

    throw IdNotFoundException("Id Does Not Exist!");
}

std::optional<std::vector<Car>> FindAbove80TorqueCars(CarPointerContainer &carData)
{
    std::vector<Car> p;
    if (carData.empty())
    {
        throw EmptyContainerException("Empty Container!!!\n");
    }

    for (CarPointer &ptr : carData)
    {
        if (ptr->carEngine().get().engineTorque() > 80)
        {
            p.emplace_back(*ptr);
        }
    }
    if (p.empty())
    {
        return std::nullopt;
    }
    return p;
}

std::optional<std::vector<Car>> FindCarByCarType(CarPointerContainer &CarData, int &cType)
{
    std::vector<Car> p;
    if (CarData.empty())
    {
        throw EmptyContainerException("Empty Container!!!\n");
    }
    for (CarPointer &car : CarData)
    {
        if (car->carType() == static_cast<CarType>(cType))
        {
            p.emplace_back(*car);
        }
    }
    if (p.empty())
    {
        return std::nullopt;
    }
    return p;
}
