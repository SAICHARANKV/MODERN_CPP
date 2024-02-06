#include <iostream>

void Moremagic(int *ptr)
{
}
void magic(int val)
{
    std::cout << val * val << "\n";
}

int main()
{
    int n1 = 10;
    const int n2 = 20;
    // int *ptr = NULL;
    int *ptr = nullptr;
    magic(10);
    magic(n1);
    magic(n2);
    // magic(ptr);

    Moremagic(0); // implict type conversion which should not be allowed.
    // 0 to NULL value
    // we cannot change this conversion but atleast provide warning
}
