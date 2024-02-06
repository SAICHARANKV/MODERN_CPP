#include <string>
#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
{
    os << "_vehicle: " << rhs._vehicleId
       << " _vehiclePrice: " << rhs._vehiclePrice
       << " _vehicleType: " << static_cast<int>(rhs._vehicleType);
    return os;
}

Vehicle::Vehicle(std::string id)
    : _vehicleId(id)
{
}

Vehicle::Vehicle(std::string id, VehicleType vtype)
    : Vehicle(id)
{
    _vehicleType = vtype;
}

Vehicle::Vehicle(std::string id, float price, VehicleType vtype)
    : Vehicle(id, vtype)
{
    _vehiclePrice = price;
}

float Vehicle::CalculateRegistrationTax()
{
    return 0.0f;
}
