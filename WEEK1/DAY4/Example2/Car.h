#ifndef CAR_H
#define CAR_H

/*
    A car cannot be copied or moved
    Default instantiation should not be allowed
    This class inherits (extends) a vechile type.
    As such,it implements all base class abstract functions
*/
#include <string>
#include "CarType.h"
#include "Vehicle.h"
class Car : public Vehicle
{
private:
    const CarType _carType;

public:
    Car() = delete;
    ~Car() = default;
    Car(const Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(const Car &) = delete;
    Car &operator=(Car &&) = delete;

    // During Inheritance every child class at least should call one parent constructor
    Car(CarType ctype, std::string id);
    Car(CarType ctype, std::string id, VehicleType vtype);
    Car(CarType ctype, std::string id, float price, VehicleType vtype);

    CarType carType() const { return _carType; }

    // override :- only to memeber functions that are over riding other functions.
    void BookServiceAppointment() override;

    float CalculateRegistrationTax() override;
};
#endif // CAR_H
