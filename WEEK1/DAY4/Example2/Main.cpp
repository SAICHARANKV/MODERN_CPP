#include <iostream>
#include "Functionalities.h"

int main()
{
    DataContainer data;
    BikeContianer Bikedata;
    CreateObjects(data,Bikedata);
    try
    {
        std::cout << "Total Tax was : " << CalculateTotalRegistrationTax(data,Bikedata) << "\n";
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << "\n";
    }

    //std::dynamic_pointer_cast<Car>(data[0])->vehicleId();
}