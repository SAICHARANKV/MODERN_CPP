#include <iostream>

class Employee
{
private:
    int _eid;
    std::string _ename;

public:
    Employee(int id, std::string name) : _eid(id), _ename(name) {}
    Employee() = delete;
    Employee(const Employee &)
    {
        std::cout << "Copy Constructor called\n";
    }
    Employee &operator=(const Employee &)
    {
        std::cout << "Copy Assignment called\n";
        return *this;
    }
    Employee(Employee &&)
    {
        std::cout << "Move Constructor Called\n";
    }
    Employee &operator=(Employee &&)
    {
        std::cout << "Move Assignment called\n";
        return *this;
    }
    ~Employee() = default;
};

Employee Magic(int id, std::string name)
{
    std::cout << "Middle Man Function!!!\n";
    return Employee(id, name); // rvalue temporary stack
}
// Employee e1 = Whatever is returned from Magic
// Employee e1 is assigned with whatever is returned from Magic

/*
    Employee e1 is assigned a rvalue
    // r value need not to be copied
*/
int main()
{
    Employee e1 = Magic(1, "Sai");
}

/*
IF NO OPTIMIZATON

        Step 1: We go to magic function
        Step 2: return an r value
        Step 3: r value assigned to e1.
        which means e1 should be attached to my data.

WITH OPTIMIZATON
        Step 1: We go to magic
        I know the address in main where data needs to be returned

        Step 2: return Employee(101,"Sai") bascially means write 101,Sai
        in the location in main which you already know!!
*/
/* Program considers copy and move are irrelavant so it do not goes to others and
prints only middlemanfunction!!!
*/