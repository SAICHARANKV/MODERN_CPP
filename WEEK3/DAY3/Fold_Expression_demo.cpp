// CPP 17 style of code for RECURSSION
// meta programming

#include <iostream>
template <typename... T> // ... elipsis
auto Subtract(T... n1)
{
    return (... - n1);
}

/* Associtivity means right end of parameter*/
/*
    int ans = Subtract<int>(10, 20, 30);
        10-(20-30)= 10+10=20  right Associtivity(n1-...)
    int ans = Subtract<int>(30,20,10); (...-n1);
    (30-20)-10=10-10=0 left Associtivity(...-n1)
*/

int main()
{
    int ans = Subtract<int>(30, 20, 10);
    std::cout << ans << "\n";
}