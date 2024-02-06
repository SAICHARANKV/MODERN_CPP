#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <memory>
#include "CarType.h"
#include "Engine.h"

class Car
{
private:
    std::string _carId;
    std::string _carBrand;
    CarType _carType;
    float _carPrice;
    Engine &_carEngine;

public:
    /*
        Necessary Enabler and Disabler Functions
    */
    Car() = default;
    Car(const Car &) = default;
    Car &operator=(const Car &) = default;
    Car(Car &&) = delete; // Move constructor
    Car &operator=(Car &&) = default;
    ~Car() = default; //{ std::cout << "Card details have deleted : " << _cardNumber << "\n"; };

    /*
        Parameterized Constructor
    */
    Car(std::string carId, std::string carBrand, CarType carType, float carPrice, Engine &carEngine);

    /*
        Getters and Setters
    */
    std::string carId() const { return _carId; }
    void setCarId(const std::string &carId) { _carId = carId; }

    std::string carBrand() const { return _carBrand; }
    void setCarBrand(const std::string &carBrand) { _carBrand = carBrand; }

    CarType carType() const { return _carType; }
    void setCarType(const CarType &carType) { _carType = carType; }

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    Engine &carEngine() const { return _carEngine; }
    void setCarEngine(const Engine &carEngine) { _carEngine = carEngine; }
};

#endif // CAR_H
