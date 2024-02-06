#include "Car.h"

Car::Car(std::string id, std::string brand, CarType carType, float price, RefType carengine)
    : _carId(id), _carBrand(brand), _carType(carType), _carPrice(price), _carEngine(carengine)
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "carId: " << rhs._carId << "\n"
       << "carBrand: " << rhs._carBrand << "\n"
       << "carType: " << static_cast<int>(rhs._carType) << "\n"
       << "carPrice: " << rhs._carPrice << "\n"
       << "carEngine: " << rhs._carEngine.get() << "\n"; // as it as wrapper class get is used
    return os;
}
