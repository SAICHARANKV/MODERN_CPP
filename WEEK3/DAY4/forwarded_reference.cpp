/* Concept can be used in making own makeshared async
    bind implementations
*/

#include <iostream>
#include <vector>
#include <memory>

class DataModel
{
private:
    int _n1;
    std::string &_name;
    const std::string &_grade;
    std::vector<int> _data;

public:
    ~DataModel(){};
    DataModel(int n1, std::string &name, std::string &grade, std::vector<int> &&data)
        : _n1(n1), _name(name), _grade(grade), _data(std::move(data))
    {
        std::cout << "parameterized constructor called\n";
    };

    /* Getter and Setters */
    int n1() const { return _n1; }
    void setN1(int n1) { _n1 = n1; }

    std::string &name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    const std::string &grade() { return _grade; }

    std::vector<int> data() const { return _data; }
};

// DataModel,n1,name,grade,std::vector<int>{10,20,30}
// T=DataModel
// Args is type for all parameters
// Args=(n1,name,grade,std:vector<int>{10,20,30})
// here && means forwarded reference in Args/In Templated Function

template <typename T, typename... Args>
T Relay(Args &&...args)
{
    return T(std::forward<Args>(args)...); // DataModel(n1,name,grade,std::vector<int>{10,20,30})
}

void Display(int n1, std::string &name, const std::string &grade, std::vector<int> &&data)
{
}

void Relay(int n1, std::string &name, const std::string &grade, std::vector<int> &&data)
{

    // Display(n1, name, grade, data); // Data is an error as l value to r value
    //  Middle man consuming the data will destroy whole definition of the data
}

/*
    Main is original source of data
    Relay is the middle man (relying or forwarding function)
    constructor is the actual destination function where parameters should
    ARRIVE AS THEY ARE SENT FROM MAIN WITHOUT ANY CHANNELS!!!!
*/

int main()
{
    int n1 = 123;
    std::string name = "Sai";
    std::string grade = "A+";
    DataModel obj = Relay<DataModel>(n1, name, grade, std::vector<int>{10, 20, 30});
    // Relay(n1, name, grade, std::vector<int>{1, 2, 3, 4});
    std::cout << "id: " << obj.n1() << std::endl;
    for (int val : obj.data())
    {
        std::cout << val << "\n";
    }
}

// r value vector gets stored relay as it is first attached

/*
    Display <----> Relay <----> Main
*/

/*
HEAP

    [101 | Sai | A+]
        |
        |
        |
        0x100H
        |
        |
        |
        [[mptr]]
        shared_ptr
makeshared is doing the work of grabbing of address and keeping in mptr

Employee* e1=new Employee(101,"SAI","A++");
std::shared_ptr<Employee> ptr(e1); // Bad code deletion not happened and copy taking more memory

*/

/*
    Rule 1
        For regular, non template functions,T&& simply means Rvalue reference to T

    Rule 2:
    For a template function of type T, T&& means forwarded references
    [Note: such a template function should involve type deduction for parameters]

    E.x: Relay deduces type for incoming parameters n1,name,grade,data

*/