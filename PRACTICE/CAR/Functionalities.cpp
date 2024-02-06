#include "Functionalities.h"
#include "Car.h"
#include <string>
#include <vector>

void CreateEngineObjects(EngineVector &engineData)
{
    Engine obj1("123", EngineType::ICT, 200, 300);
    engineData.push_back(obj1);
    Engine obj2("124", EngineType::HYBRID, 75, 350);
    engineData.push_back(obj2);
    Engine obj3("125", EngineType::ICT, 150, 390);
    engineData.push_back(obj3);
}

void CreateCarObjects(Container_Car &data, EngineVector &engineData)
{
    data.push_back(std::make_shared<Car>("1",
                                         "Hyundai",
                                         CarType::SUV, 150000.0f, engineData[0]));
    data.push_back(std::make_shared<Car>("2",
                                         "Skoda",
                                         CarType::HATCHBACK, 900000.0f, engineData[1]));

    data.push_back(std::make_shared<Car>("3",
                                         "Renault",
                                         CarType::SEDAN, 150000.0f, engineData[2]));
}

std::ostream &operator<<(std::ostream &os, const CarPointer &ptr)
{
    os << "_carId: " << ptr->carId() << "\n";
    os << " _carBrand: " << ptr->carBrand() << "\n";
    os << " _carPrice: " << ptr->carPrice() << "\n";
    os << " _carType: ";
    switch (ptr->carType())
    {
    case CarType::HATCHBACK:
        os << "HATCHBACK"
           << "\n";
        break;

    case CarType::SEDAN:
        os << "SEDAN"
           << "\n";
        break;
    case CarType::SPORTS:
        os << "SPORTS"
           << "\n";
        break;
    case CarType::SUV:
        os << "SUV"
           << "\n";
        break;
    }
    os << " car Engine Details \n";
    os << "_engineNumber:  " << ptr->carEngine().engineNumber() << "\n";
    os << "_engineHorsepower:  " << ptr->carEngine().engineHorsepower() << "\n";
    os << "_engineTorque:  " << ptr->carEngine().engineTorque() << "\n";
    os << "_engineType: ";
    switch (ptr->carEngine().engineType())
    {
    case EngineType::HYBRID:
        os << "HYBRID"
           << "\n";
        break;

    case EngineType::ICT:
        os << "ICT"
           << "\n";
        break;
    }
    return os;
}
void DisplayObjects(Container_Car &data)
{
    for (CarPointer &ptr : data)
    {
        std::cout << ptr;
        std::cout << "========================\n";
    }
}

void SearchHorsePowerEngine(Container_Car &data, std::string cId)
{
    int flag = 1;
    for (const auto &d : data)
    {
        if (d->carId() == cId)
        {
            std::cout << "Car Id: " << cId << " Has Horse Power of " << d->carEngine().engineHorsepower() << std::endl;
            flag = 0;
        }
    }
    if (flag == 1)
    {
        std::cout << "No Car details found\n";
    }
}

void DisplayOver80(Container_Car &data)
{
    for (const auto &details : data)
    {
        if (details->carEngine().engineTorque() > 80)
        {
            {
                std::cout << "Car Details : \n";
                std::cout << "Car Id : " << details->carId() << std::endl;
                std::cout << "Car Brand : " << details->carBrand() << std::endl;
                std::cout << "Car Price : " << details->carPrice() << std::endl;
                std::cout << "Car Type : ";
                if (details->carType() == CarType::HATCHBACK)
                    std::cout << "HATCHBACK\n";
                if (details->carType() == CarType::SEDAN)
                    std::cout << "SEDAN\n";
                if (details->carType() == CarType::SPORTS)
                    std::cout << "SPORTS\n";
                if (details->carType() == CarType::SUV)
                    std::cout << "SUV\n";
            }
        }
    }
}

// void DisplayCarType(Container &data)
// {
// }

// void AverageHosePower(Container &data)
// {
// }

// void LeastPrice(Container &data)
// {
// }

// void Pricesum(Container &data)
// {
// }
