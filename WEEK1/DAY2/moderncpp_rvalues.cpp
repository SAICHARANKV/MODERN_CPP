#include <iostream>
#include <vector>
#include <thread>

/*
    lvalues : values that are permanent in RAM
    (have a fixed location) aka also have an address

    lvalues have a name given by us(user)!!!

    Rvalues:
            temporary value (result of an expression)
            or result of displacement*

            rvalues don't have a fixed address
            (we can't go to their location in RAM
            and find the value WITH GURANTEE!!!)

    Intention:
        1) Both Accepted:
            a) Lvalues Accepted by copy, rvalues must be assigned e.g Magic(int n1);

            b) Lvalue by reference,rvalues must be assigned
                e.g: Magic(const int& n1);
        2) Only lvalue by reference:
            e.g: Magic (int& n1);

        3) Only rvalues by assignment:
                e.g: Magic(int&& n1);
*/
/*
    f1 takes one integer by value and returns an integer by value
*/
int f1(int &n1) {}
int f1(std::vector<int> &n1) {}

/*
    f2 takes a lvalue reference to an integer and returns an integer by value
*/
int f2(int &n1) {}

int magic1(int n1)
{
}

// int main()
// {
//     int n1 = 10;
//     /*
//         10 is an rvalue on line 39
//         It will be "ASSIGNED " to n1 variable in f1
//         scope which means 10 will get a fixed location in RAM
//         inside the call stack of f1
//     */
//     f1(10); // rvalue

//     /*
//         n1 is an lvalue stored in 4 bytes of memory in main.
//         These 4 bytes of data will be copied into the scope of f1
//         and a new variable "n1" local to f1 will be created this is copy
//         semantics NOT ASSIGNMENT
//     */

//     f1(n1);

//     std::vector<int> v;
//     for (int i = 0; i < 100000; i++)
//     {
//         v.push_back(i);
//     }

//     f1(v);
// }

/*
    Demo takes a rvalue reference to standard vector of integers
    and return integer by value
*/
int Demo(std::vector<int> &&data)
{
    // operations on a vector of integer passed!
}
int Demo(std::string &&data)
{
    //....
    data = "Saicharan";
}
int main()
{
    // std::vector<int> v1{10, 20, 30};
    // Demo(v1); // an rvalue reference cannot be bound to an lvalue C/C++(1768)
    std::string s1 = "Sunny";
    Demo(std::move(s1));

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << s1 << "\n"; // illegal! I can gebt any output!!
    // After moving donot try to access v1
}