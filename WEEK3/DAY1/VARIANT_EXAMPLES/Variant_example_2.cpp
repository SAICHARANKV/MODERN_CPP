#include <iostream>
#include <variant>
#include <vector>
#include <string>

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

int main()
{
    std::vector<std::variant<Employee, BusinessOwner>> data(2);
    data[0] = Employee();
    data[1] = BusinessOwner();

    for (auto &val : data)
    {
        std::visit([](auto &&value)
                   { value.Display(); },val);
    }
}