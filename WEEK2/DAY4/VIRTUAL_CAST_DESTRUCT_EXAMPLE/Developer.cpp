#include "Developer.hpp"

Developer::Developer(int id, std::string name, float salary, int experience, DevDepartment developerDepartment)
    : Employee(id, name, salary), _developerExperience(experience), _developerDepartment(developerDepartment)
{
}

float Developer::CalculateTax()
{
    return 0.3f * esalary();
}
