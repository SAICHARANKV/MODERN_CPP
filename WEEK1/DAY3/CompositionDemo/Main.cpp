#include "Functionalities.h"
#include <iostream>

int main()
{
    std::cout << "Creating Objects!!!!" << std::endl;
    Container data;      /// Empty Container
    PrintDetails(data);
    CreateObjects(data); // adding data into vector using shared_ptr
    PrintDetails(data);
    return 0;
}