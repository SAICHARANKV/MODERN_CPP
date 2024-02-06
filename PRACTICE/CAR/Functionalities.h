#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Car.h"
#include "Engine.h"

using CarPointer = std::shared_ptr<Car>;
using Container_Car = std::vector<CarPointer>;
using EngineVector = std::vector<Engine>;

void CreateEngineObjects(EngineVector &engineData);
void CreateCarObjects(Container_Car &data, EngineVector &engineData);std::ostream &operator<<(std::ostream &os, const CarPointer &ptr);
void SearchHorsePowerEngine(Container_Car &data , std::string carId);
void DisplayOver80(Container_Car &data);
// void DisplayCarType(Container &data);
// void AverageHosePower(Container &data);
// void LeastPrice(Container &data);
// void Pricesum(Container &data);

#endif // FUNCTIONALITIES_H
