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
    Employee(Employee &&) = default;
    // {
    //     std::cout << "Move Constructor Called\n";
    // }
    Employee &operator=(Employee &&)
    {
        std::cout << "Move Assignment called\n";
        return *this;
    }
    ~Employee() = default;

    int eid() const { return _eid; }
    void setEid(int eid) { _eid = eid; }

    std::string ename() const { return _ename; }
    void setEname(const std::string &ename) { _ename = ename; }
};

Employee Magic(int id, std::string name)
{
    std::cout << "Middle Man Function!!!\n";
    Employee emp(id, name); // rvalue temporary stack
    return emp;
    // internally move Constructor u did r value e1
}
int main()
{
    /*
        We Reserve a total of 36 or 52 bytes of memory in main
        This Memory is now being identified by the name e1
        [This makes e1 an lvalue]
    */
    Employee e1 = Magic(1, "Sai");
    /*
        We are constructing a new object with identifier name
        e2
        RIGHT NOW, e2 uses the memory location that was
        PREVIOUSLY ATTACHED TO IDENTIFIER e1
    */
    Employee e2 = std::move(e1);
    std::cout << "E2 id: " << e2.eid() << ".\n";
    std::cout << "E2 name: " << e2.ename() << ".\n";

    std::cout << e1.ename() << "\n"; // illegal

    // Employee obj E2 is being intialized by converting lvalue of e1 to r value of e1
    e2 = std::move(Employee(111, "Cs"));

    // E2 is being assigned by an rvalue of Employee();
    e1 = Employee(111, "Sunny");
}

/* Disable OPTIMIZATON
    STEP 1: you go to magic.Return address is known
    STEP 2: Make a new local variable emp in the stack of magic
    STEP 3: Return emp(this is an rvalue)
    Hence
    Employee e1=Magic(101,"Sai");
    Construct a new object e1 in the scope of main with an rvalue of type employee
*/