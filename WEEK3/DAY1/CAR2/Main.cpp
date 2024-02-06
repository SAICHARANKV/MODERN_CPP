#include <iostream>
#include <vector>
#include <optional>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"
int main()
{
    CarPointerContainer CarData; // empty container
    EngineContainer EngineData;  // Empty vector

    std::cout << "Creating Objects!!!\n";
    CreateCarObjects(CarData, EngineData);

    try
    {
        std::cout << "Finding Find Horse Power By CarId:\n";
        std::string id;
        std::cout << "Enter Car id to search : \t";
        std::cin >> id;
        std::cout << "HorsePower : " << FindHorsePowerByCarId(CarData, id) << "\n";
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what();
    }
    catch (IdNotFoundException &ex)
    {
        std::cout << ex.what();
    }
    try
    {
        std::optional<std::vector<Car>> result = FindAbove80TorqueCars(CarData);
        std::cout << "Cars Above 80 Torque\n";
        if (result.has_value())
        {
            for (Car &ptr : result.value())
            {
                std::cout << ptr << "\n";
            }
        }
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what();
    }
    catch (NoMatchingInstanceException &ex)
    {
        std::cout << ex.what();
    }
    try
    {
        std::cout << "Finding Engine Instance  By CarType:\n";
        int ctype;
        std::cout << "Enter Car Type to search : \t";
        std::cin >> ctype;
        std::cout << "\n";
        std::optional<std::vector<Car>> c = FindCarByCarType(CarData, ctype);
        if (c.has_value())
        {
            for (Car &ptr : c.value())
            {
                std::cout << ptr << "\n";
            }
        }
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what();
    }
    catch (IdNotFoundException &ex)
    {
        std::cout << ex.what();
    }
}