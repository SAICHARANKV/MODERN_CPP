#include "Employee.hpp"
#include "HR.hpp"
#include "Developer.hpp"
#include <vector>
#include <iostream>
int main()
{
    // ptr is of type employee
    // object is actual HR
    // Function is marked as virtual
    // COMPILER GO TO BOTH LHS AND RHS AND FINDS THE MOST DERVIED VERSION!!!
    // Compiler sees LHS side it only focuses on pointer type in calling a destructor
    Employee *ptr1 = new HR(10, "Sai", 993800.0f, 5, HrSpecializationType::RECURITMENT);
    Employee *ptr2 = new Developer(9, "Charan", 999299.0f, 3, DevDepartment::MLDEVELOPER);
    std::vector<Employee *> data{ptr1, ptr2};

    for (Employee *ptr : data)
    {
        std::cout << "Tax on employee: "
                  << ptr->ename()
                  << " is: " << ptr->CalculateTax() << "\n";
    }

    // delete ptr; // Employee *ptr calls ~HR();
    for (Employee *ptr : data)
    {
        delete ptr;
    }
}