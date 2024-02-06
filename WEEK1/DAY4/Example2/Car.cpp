#include "Car.h"
#include <iostream>

Car::Car(CarType ctype, std::string id)
    : Vehicle(id), _carType(ctype) {}

Car::Car(CarType ctype, std::string id, VehicleType vtype)
    : Vehicle(id, vtype), _carType(ctype) {}

Car::Car(CarType ctype, std::string id, float price, VehicleType vtype)
    : Vehicle(id, price, vtype), _carType(ctype) {}

void Car::BookServiceAppointment()
{
    std::cout << "Appointment Booked for " << vehicleId() << std::endl;
}

/* For Sedan and SUV tax is 10% and for other categories tax is 15% */
float Car::CalculateRegistrationTax()
{
    if (_carType == CarType::SEDAN || _carType == CarType::SUV)
    {
        return 0.1f * vehiclePrice();
    }

    return 0.15f * vehiclePrice();
}