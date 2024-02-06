#include "Employee.hpp"
std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_eid: " << rhs._eid
       << " _ename: " << rhs._ename
       << " _esalary: " << rhs._esalary;
    return os;
}
Employee::Employee(int id, std::string name, float salary)
    : _eid(id), _ename(name), _esalary(salary)
{
}
