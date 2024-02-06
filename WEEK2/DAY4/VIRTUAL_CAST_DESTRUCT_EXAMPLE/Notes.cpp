#include <memory>
#include "Employee.hpp"
#include"HR.hpp"
#include"Developer.hpp"
int main()
{
    std::shared_ptr<Employee> ptr = std::make_shared<HR>(
        101, "Sai", 229923.0f,
        10, HrSpecializationType::PMT);

    //Hr has a getter called hrTeamSize()
    std::shared_ptr<HR> fullPtr=std::dynamic_pointer_cast<HR>(ptr);
    fullPtr->hrSpecialization();
}