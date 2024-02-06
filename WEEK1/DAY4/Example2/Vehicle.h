#ifndef VEHICLE_H
#define VEHICLE_H

/*
    Common Behaviour
    Book an appointment
    Pay Registration Tax
*/
#include <string>
#include <ostream>
#include "VehicleType.h"
class Vehicle
{
private:
    const std::string _vehicleId;
    float _vehiclePrice;
    VehicleType _vehicleType;

public:
    Vehicle() = delete;
    Vehicle(const Vehicle &) = delete;
    Vehicle(Vehicle &&) = delete;
    Vehicle &operator=(const Vehicle &) = delete;
    Vehicle &operator=(const Vehicle &&) = delete;
    ~Vehicle() = default;

    // option 1 : only give ID
    explicit Vehicle(std::string id);
    // option 2: Only give ID,type
    Vehicle(std::string id, VehicleType vtype);
    // option 3: Tell me everything;
    Vehicle(std::string id, float price, VehicleType vtype);

    /*
        Getters and Setters
    */

    std::string vehicleId() const { return _vehicleId; }

    float vehiclePrice() const { return _vehiclePrice; }
    void setVehiclePrice(float vehiclePrice) { _vehiclePrice = vehiclePrice; }

    VehicleType vehicleType() const { return _vehicleType; }
    void setVehicleType(const VehicleType &vehicleType) { _vehicleType = vehicleType; }

    virtual void BookServiceAppointment() = 0;
    virtual float CalculateRegistrationTax();
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
