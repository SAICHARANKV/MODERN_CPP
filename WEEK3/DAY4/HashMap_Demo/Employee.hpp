#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
class Employee
{
private:
    int _id;
    std::string _name;
    std::string _location;

public:
    Employee() = delete;
    ~Employee() = default;
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee(Employee &&) = default;
    Employee &operator=(Employee &&) = delete;

    Employee(int id, std::string name, std::string location)
        : _id(id), _name(name), _location(location) {}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
    {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _location: " << rhs._location;
        return os;
    }
};

#endif // EMPLOYEE_HPP
