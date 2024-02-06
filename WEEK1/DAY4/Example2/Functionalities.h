#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

// SOR --Separation of Responsibility
// SOLID
// Rule of Zero , Rule of Three and Rule of Five

#include <memory>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

using VehiclePointer = std::shared_ptr<Vehicle>; // Smart Pointer always to be base class
using DataContainer = std::vector<VehiclePointer>;
using BikeContianer =std::vector<VehiclePointer>;

void CreateObjects(DataContainer &data,BikeContianer &Bikedata);
float CalculateTotalRegistrationTax(const DataContainer &data,const BikeContianer &Bikedata);

#endif // FUNCTIONALITIES_H
