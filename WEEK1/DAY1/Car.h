#ifndef CAR_H
#define CAR_H

#include <string>
#include "CarType.h" // User defined path and code

class Car
{
private:
    std::string _id;
    float _price;
    VehicleType _type;

public:
    Car() = delete;            // Deleted(Destroys/Disables) Default constructor
    Car(const Car &) = delete; // Deleted copy constructor
    ~Car() = default;          // Defaluted constructor
    Car &operator=(const Car &) = delete;
    Car &operator=(const Car &&) = delete; // new concept! (move assignment)
    Car(Car &&) = delete;                  // new concept (move constructor)

    explicit Car(std::string id = " ", float price = 0.0f, VehicleType type);
    explicit Car(std::string id, VehicleType type= VehicleType::SUV);
    explicit Car(std::string id); // to prevent implict conversion.

    void display();

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    VehicleType type() const { return _type; }

    std::string id() const { return _id; }
};
// float findaverage(std::vector<Car>);
// ~Car() {} // Its gets invoked just before deletion of actual object

#endif // CAR_H
