#ifndef BIKE_H
#define BIKE_H

#include <string>
#include "BikeType.h"
#include "Vehicle.h"
class Bike : public Vehicle
{
private:
    const BikeType _BikeType;

public:
    Bike() = delete;
    ~Bike() = default;
    Bike(const Bike &) = delete;
    Bike(Bike &&) = delete;
    Bike &operator=(const Bike &) = delete;
    Bike &operator=(Bike &&) = delete;

    // During Inheritance every child class at least should call one parent constructor
    Bike(BikeType ctype, std::string id);
    Bike(BikeType ctype, std::string id, VehicleType vtype);
    Bike(BikeType ctype, std::string id, float price, VehicleType vtype);


    // override :- only to memeber functions that are over riding other functions.
    void BookServiceAppointment() override;

    float CalculateRegistrationTax() override;

    BikeType bikeType() const { return _BikeType; }
};

#endif // BIKE_H