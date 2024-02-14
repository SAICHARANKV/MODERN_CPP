#include <iostream>
#include <functional>

void Magic(std::reference_wrapper<int> ref)
{
    std::cout << ref.get() << "\n";
}
int main()
{
    int n1 = 10;
    Magic(std::ref(n1)); // explicit
    // helper function==std::ref takes l value and converts to reference_wrapper
}
// std::reference_wrapper<int> ref = n1;
// Reference wrapper cannot be nullptr 