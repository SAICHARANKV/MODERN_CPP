#include <iostream>
#include <memory>
#include "Employee.hpp"
int main()
{
    Employee *emp = new Employee(10);
    delete emp;

    std::shared_ptr <Employee> sptr=std::make_shared<Employee>(101);
}