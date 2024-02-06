#include <iostream>
#include <vector>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"
int main()
{
    CarPointerContainer CarData; // empty container
    EngineContainer EngineData;  // Empty vector

    std::cout << "Creating Objects!!!\n";
    CreateObjects(CarData, EngineData);

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
        std::vector<Car> result = FindAbove80TorqueCars(CarData);
        std::cout << "Cars Above 80 Torque\n";
        for (Car &ptr : result)
        {
            std::cout << ptr << "\n";
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
        std::vector<Car> c = FindCarByCarType(CarData, ctype);
        for (Car &ptr : c)
        {
            std::cout << ptr << "\n";
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