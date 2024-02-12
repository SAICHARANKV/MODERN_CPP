#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <memory>
// Smart Pointers 
class Employee
{
private:
public:
    Employee() = default;
    void Display() { std::cout << "Employee ewyuuuu\n"; }
    ~Employee() { std::cout << "Employee object destroyed\n"; }
};

class BusinessOwner
{
private:
public:
    BusinessOwner() = default;
    void Display() { std::cout << "BusinessOwner ewyuuuu\n"; }
    ~BusinessOwner() { std::cout << "BusinessOwner object destroyed\n"; }
};
using Epointer = std::shared_ptr<Employee>;
using Bpointer = std::shared_ptr<BusinessOwner>;
int main()
{
    std::vector<std::variant<Epointer, Bpointer>> data(2);
    data[0] = std::make_shared<BusinessOwner>();
    data[1] = std::make_shared<Employee>();

    for (auto &&val : data)
    {
        std::visit([](auto &&val)
                   { val->Display(); },
                   val);
    }
}