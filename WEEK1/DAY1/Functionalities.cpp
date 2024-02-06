#include "Functionalities.h"
#include <iostream>
void CreateObjects(container &data)
{
    // Car *c1 = new Car("DS1021f", 499420.0f, VehicleType::SEDAN);
    // data.push_back(c1); regular method but an error .
    data.push_back(std::make_shared<Car>(
        "DS1021f",
        499420.0f,
        VehicleType::SEDAN));

    data.push_back(std::make_shared<Car>(
        "SK1330s",
        780000.0f,
        VehicleType::SUV));
}

float AveragePrice(container &data)
{
    float total = 0.0f;

    /*
    For each Pointer called "ptr" in data,
    access price getter using "ptr" and add it to "total"
    */
    for (Pointer &ptr : data)
    {
        total = total + ptr->price();
    }

    return total / data.size();
}
// data[0]-> sp1->get_internal_pointer->price()

/*
data[0].get()->price()l
data[0]->price();
*/
float FindPriceById(container &data, std::string id)
{
    for (Pointer &ptr : data)
    {
        if (ptr->id() == id)
        {
            std::cout << "ID FOUND...\tPrice : " << ptr->price() << std::endl;
            return ptr->price();
        }
    }
    throw std::runtime_error("ID NOT FOUND\n");

    return 0.0f;
}
