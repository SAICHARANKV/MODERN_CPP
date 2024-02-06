#include <iostream>
#include "Functionalities.h"

void CreateObjects(DataContainer &data, BikeContianer &Bikedata)
{
    data.emplace_back(
        std::make_shared<Car>(CarType::SEDAN, "V101", 890000.0f, VehicleType::COMMERICAL));
    data.emplace_back(
        std::make_shared<Car>(CarType::SUV, "s101", 1390000.0f, VehicleType::PRIVATE));
    data.emplace_back(
        std::make_shared<Car>(CarType::HATCHBACK, "H101", 2390000.0f, VehicleType::COMMERICAL));
    Bikedata.emplace_back(
        std::make_shared<Bike>(BikeType::HYBRID, "B101", 900000.0f, VehicleType::PRIVATE));
    Bikedata.emplace_back(
        std::make_shared<Bike>(BikeType::COMMUTE, "B102", 900000.0f, VehicleType::COMMERICAL));
    Bikedata.emplace_back(
        std::make_shared<Bike>(BikeType::SPORTS, "B103", 900000.0f, VehicleType::PRIVATE));
}

float CalculateTotalRegistrationTax(const DataContainer &data, const BikeContianer &Bikedata)
{
    if (data.empty())
    {
        throw std::runtime_error("Empty Car data received");
    }
    if (Bikedata.empty())
    {
        throw std::runtime_error("Empty Bike data received");
    }
    float total_car = 0.0f;
    float total_bike = 0.0f;
    for (const VehiclePointer &ptr : data)
    {
        total_car = total_car + ptr->CalculateRegistrationTax();
    }
    for (const VehiclePointer &ptr : Bikedata)
    {
        total_bike = total_bike + ptr->CalculateRegistrationTax();
    }
    std::cout << "Car_tax: " << total_car << " Bike_tax: " << total_bike << std::endl;
    float total = 0.0f;
    total = total_car + total_bike;

    return total;
}
