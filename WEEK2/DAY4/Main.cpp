#include <iostream>
#include <memory>
#include "../DAY4/VIRTUAL_CAST_DESTRUCT_EXAMPLE/Employee.hpp"
int main()
{
    Employee *emp = new Employee(10);
    delete emp;

    std::shared_ptr <Employee> sptr=std::make_shared<Employee>(101);
}