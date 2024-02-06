#include <iostream>
#include <list>
#include <vector>
#include <stack>

class Demo
{
private:
    int _id{-1}; // In class default intialization
public:
    Demo() = default;
    Demo(int id) : _id{id} {};
};
int main()
{
    // std::list<std::vector<std::stack<int>>> d1; can be resolved with using keyword
    // std::list<int> l1{10, 20, 30};
    // // std::list<int>::iterator
    // for (auto itr = l1.begin(); itr != l1.end(); itr++)
    // {
    //     //.....
    // }

    // Uniform intialization
    Demo d1{};
    Demo d2{20};

    
}