// Transfer of lvalue to r value helpful

#include <iostream>
#include <string>
#include <array>

/*
stack of GetInput
4 bytes for id
8 bytes for age
32 bytes for string
4 million bytes (40 lakh) for array
*/

demo d1;
class demo
{
private:
    int _id;
    float _age;
    std::string _name;
    std::array<int, 1000000> _arr;

public:
    demo(int id, float age, std::string name, std::array<int, 1000000> &&arr) // Taking ownership as rvalue and take data
        : _id(id), _age(age), _name(name), _arr(std::move(arr))               // Transfering to object and data is available.
    {
    }
    ~demo() {}
};
void GetInput()
{
    int id{-1};
    float age{-1.0f};
    std::string name{""};
    std::array<int, 1000000> data{1}; // Starting and ending position data on stack remaining all are one heap.

    std::cin >> id;
    std::cin >> age;
    std::cin >> name;
    // 1 million  input of array
    d1 = demo(id, age, name, std::move(data)); // Transfering ownership to class.
}

int main()
{
    GetInput();
}