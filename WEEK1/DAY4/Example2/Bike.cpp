#include "Bike.h"
#include <iostream>

void Bike::BookServiceAppointment()
{
    std::cout << "Appointment Booked for " << vehicleId() << std::endl;
}

/* For Commute and Hybrid tax is 10% and for other categories tax is 15% */
float Bike::CalculateRegistrationTax()
{
    if (_BikeType == BikeType::COMMUTE || _BikeType == BikeType::HYBRID)
    {
        return 0.1f * vehiclePrice();
    }

    return 0.15f * vehiclePrice();
}

Bike::Bike(BikeType btype, std::string id)
    : Vehicle(id), _BikeType(btype)
{
}

Bike::Bike(BikeType btype, std::string id, VehicleType vtype)
    : Vehicle(id, vtype), _BikeType(btype)
{
}

Bike::Bike(BikeType btype, std::string id, float price, VehicleType vtype)
    : Vehicle(id, price, vtype), _BikeType(btype)
{
}
