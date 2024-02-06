#include <iostream>

enum class COLOR
{
    RED,
    BLUE
}; // class word pops out all error
enum class RANK
{
    FIRST,
    SECOND
};
enum class GEAR
{
    FIRST,
    SECOND
};

void magic(int val) // 3.Declared for int type value might also get enum value as input.(Type safety)
{
    int n1 = val + 10;
}

int main()
{
    COLOR c1 = COLOR::RED;
    GEAR g1 = GEAR::FIRST;
    RANK r1 = RANK::FIRST; // 1.Conflicting with same names

    // if (g1 == r1) // 2.Wrong comparsions as enum contains of same name or value
    // {
    //     std::cout<<"OH No!...";
    // }

    // magic(r1); // Enum used as parameter without premission

    magic((int)r1); // Type casting to solve 3 rd error
}