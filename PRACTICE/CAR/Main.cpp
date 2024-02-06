#include <iostream>
#include <vector>
#include "Functionalities.h"

int main()
{
    Container_Car data; // Empty Container
    EngineVector engineData;
    std::cout << "Creating Objects !!!!"
              << "\n";
    // Creating Engine Objects
    CreateEngineObjects(engineData);
    // Creating Car Objects
    CreateCarObjects(data, engineData);
    std::cout << "Displaying Objects !!!!"
              << "\n";
    DisplayObjects(data);
    SearchHorsePowerEngine(data, "2");
    SearchHorsePowerEngine(data, "12");
    std::cout << "\n***DisplayOver80***" << std::endl;
    DisplayOver80(data);
}