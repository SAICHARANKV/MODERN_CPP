/*
unique_ptr is another subtype of a smart pointer

This Pointer acquires resource "Uniquely"

It cannot be copied or copy assigned

Which means 2 or more owners of the same resource cannot exist if resource

is managed by unique_ptr smart pointer.

*/
#include <iostream>
#include <memory>
#include <vector>
class DataModel
{
private:
    int _n1;
    std::string &_name;
    const std::string &_grade;
    std::vector<int> _data;

public:
    ~DataModel() { std::cout << "Destructor Called\n"; };
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
void Display(std::unique_ptr<DataModel> ptr)
// if reference used used output changes
{
}

int main()
{
    std::string name = "sai";
    std::string grade = "A++";

    /*
        on heap we acquired memory for one DataModel object
        Its pointer(address) is now owned by unique_ptr
        ptr is owner of memory.ptr goes out of scope,memory gets freed.
    */
    std::unique_ptr<DataModel> ptr = std::make_unique<DataModel>(
        123,
        name,
        grade,
        std::vector<int>{10, 20, 30});

    // Display(ptr);
    // parameterized constructor called (outputs )
    // Main ends
    // Destructor called

    // Data Never moved just ownership is transfered
    Display(std::move(ptr));
    std::cout << "Main ends\n";
    // parameterized constructor called
    // Destructor Called
    //   Main ends
}