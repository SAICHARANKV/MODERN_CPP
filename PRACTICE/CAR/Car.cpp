#include "Car.h"

Car::Car(std::string carId, std::string carBrand, CarType carType, float carPrice, Engine& carEngine)
    : _carId(carId), _carBrand(carBrand), _carType(carType), _carPrice(carPrice), _carEngine(carEngine)
{
}

