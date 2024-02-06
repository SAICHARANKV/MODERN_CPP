#include <iostream>

void Magic(int *data)
{
    std::cout << "Address of data in Magic : " << &data << "\n";
    std::cout << "Value at Address stored in data in Magic (Same as n1 in main) : " << *data << "\n";
    *data = 99;
    std::cout << "Address stored in data in Magic After Modification : " << data << "\n";
}
int main()
{
    int n1 = 100;
    std::cout << "Address of n1 in Main : " << &n1 << "\n";
    std::cout << "Value of n1 in Main Before calling Magic : " << n1 << "\n";
    Magic(&n1);
    std::cout << "Value of n1 in main after magic function is completed : " << n1 << "\n";
}

// Best performance with less memory space usage as
// references just uses same memory space of variable

//data type is needed for any variable. if no data type is present for example as NULL 
//it creates a problem.