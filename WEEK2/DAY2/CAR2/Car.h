#ifndef CAR_H
#define CAR_H

#include <functional>
#include <string>
#include <ostream>
#include "CarType.h"
#include "Engine.h"

using RefType = std::reference_wrapper<Engine>;
class Car
{
private:
    const std::string _carId{""};
    const std::string _carBrand{""};
    const CarType _carType{CarType::SEDAN};
    float _carPrice{0.0f};
    RefType _carEngine;

public:
    /*
        Special Member Functions
    */
    Car() = delete;
    Car(const Car &) = default;
    Car(Car &&) = default;
    Car &operator=(const Car &) = delete;
    Car &operator=(Car &&) = delete;
    ~Car() = default;

    /*
        Parameterized Constructor
    */
    Car(std::string id, std::string brand, CarType carType, float price, RefType carengine);

    /*
        Getter and Setters
    */
    std::string carId() const { return _carId; }

    std::string carBrand() const { return _carBrand; }

    CarType carType() const { return _carType; }

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    RefType carEngine() const { return _carEngine; }
    void setCarEngine(const RefType &carEngine) { _carEngine = carEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

/*
    Without Car object their is no default Engine object
*/
#endif // CAR_H
