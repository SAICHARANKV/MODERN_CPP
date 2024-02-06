#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
class Employee
{
private:
    int _eid;
    std::string _ename;
    float _esalary;

public:
    Employee() = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    virtual ~Employee() { std::cout << "Employee class destructor called\n"; };

    Employee(int id, std::string name, float salary);

    virtual float CalculateTax() = 0;

    int eid() const { return _eid; }

    std::string ename() const { return _ename; }
    void setEname(const std::string &ename) { _ename = ename; }

    float esalary() const { return _esalary; }
    void setEsalary(float esalary) { _esalary = esalary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_HPP
