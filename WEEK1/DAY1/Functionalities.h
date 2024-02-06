#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

// New concept
#include <memory>
#include "Car.h"
#include <vector>

using Pointer = std::shared_ptr<Car>;
using container = std::vector<Pointer>;

void CreateObjects(container &data);
// CreateObjects takes 1 parameter as l value of type reference to a container and returns void.
// Where container is the standard vector of pointers.
// And where pointers is the shared_ptr of Car class.

// if used &&data  changes to r value
float AveragePrice(container &data);

float FindPriceById(container &data, std::string id);
#endif // FUNCTIONALITIES_H
