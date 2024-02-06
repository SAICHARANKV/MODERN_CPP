#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "Car.h"
using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;
using EngineContainer = std::vector<Engine>;

void CreateCarObjects(CarPointerContainer &carData, EngineContainer &engineData);
void CreateObjects(CarPointerContainer &carData, EngineContainer &engineData);
std::vector<Car> FindAbove80TorqueCars(CarPointerContainer &carData);
int FindHorsePowerByCarId(CarPointerContainer &carData, std::string carId);
std::vector<Car> FindCarByCarType(CarPointerContainer &CarData, int &cType);

#endif // FUNCTIONALITIES_H
