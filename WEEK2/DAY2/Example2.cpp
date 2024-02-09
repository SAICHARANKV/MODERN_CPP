#include <functional>
#include <iostream>
#include <string>
#include <vector>
class Demo
{
private:
    int _id;

public:
    explicit Demo(int id) : _id(id) {}
    ~Demo() = default;

    int id() const { return _id; }
};
// int main()
// {
//     int n1 = 10;
//     Demo d1(n1);

//     // Directly variable
//     std::reference_wrapper<int> ref = n1;
//     std::cout << ref.get() << "\n"; // 10

//     // Through Demo Object
//     std::reference_wrapper<Demo> ref1 = d1;
//     std::cout << ref1.get().id() << "\n"; // 10
// }

/*
    Objective: gather all values created in main and
    "put them a container" give access to these values to a function called operation
*/

void Magic(std::vector<int *> &data)
{
    for (int *ptr : data)
    {
        std::cout << *ptr;
    }
}

void Magic(std::vector<std::reference_wrapper<int>> &data)
{
    for (int ptr : data)
    {
        std::cout << ptr;
    }
}
int main()
{
    int n1 = 10;
    int n2 = 20;

    // Option 1: store them in a container
    std::vector<int> data{n1, n2}; // Makes a copy and increases (doubles) memory.

    // Option 2: Put Pointers to data values in the container
    std::vector<int *> data2{&n1, &n2}; // Made 16 bytes of memory for storing 8 bytes of memory.

    // Option 3: Put reference_wrapper in the container -> container  with 2 reference wrappers of int variables
    std::vector<std::reference_wrapper<int>> data3{n1, n2}; // Made 16 bytes of memory for storing 8 bytes of memory.
    Magic(data3);
    /*
        In Option 2 and 3 even though memory wastage occurs and in option 2 code need to change with
        pointers in option 3 these won't change the syntax avoid usage of Pointers
        and option 3 even more flexible for more data too

        reference_wrapper cannot be made null value and it surely exist.
    */
}