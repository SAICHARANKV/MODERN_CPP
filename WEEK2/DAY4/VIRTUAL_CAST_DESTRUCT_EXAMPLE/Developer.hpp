#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP
#include "Employee.hpp"
#include "DeveloperDepartmentType.hpp"
#include <iostream>

class Developer : public Employee
{
private:
    int _developerExperience;
    DevDepartment _developerDepartment;
public:
    Developer() = delete;
    Developer &operator=(const Developer &) = delete;
    Developer &operator=(Developer &&) = delete;
    Developer(const Developer &) = delete;
    Developer(Developer &&) = delete;
    ~Developer() { std::cout << "Developer Destructor called\n"; }
    Developer(int id, std::string name, float salary, int experience,DevDepartment developerDepartment); // Parent first Child next
    float CalculateTax() override;
};

#endif // DEVELOPER_HPP
