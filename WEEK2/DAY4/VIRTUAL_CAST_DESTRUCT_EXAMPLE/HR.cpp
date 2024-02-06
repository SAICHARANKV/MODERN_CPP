#include "HR.hpp"

std::ostream &operator<<(std::ostream &os, const HR &rhs)
{
    os << static_cast<const Employee &>(rhs) // Casting employee and making hr class to employee class
       << " _hrTeamSize: " << rhs._hrTeamSize
       << " _hrSpecialization: " << static_cast<int>(rhs._hrSpecialization);
    return os;
}
HR::HR(int id, std::string name, float salary, int size, HrSpecializationType specialization)
    : Employee(id, name, salary), _hrTeamSize(size), _hrSpecialization(specialization)
{
}

float HR::CalculateTax()
{
    return 0.1f * esalary();
}
