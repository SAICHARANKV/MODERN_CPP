// Recurssion and trail Recurssion(need to search)
#include <iostream>
// Variadic templates
template <typename T>
T add(T n1)
{
    return n1;
}

/*
    Accept first argument of some type
    Accept at least 1 or more parameters after that where the type is Args
    (could be diff than T)
*/
/*
    Recurssion of addition
    FN(X,Y,Z,A)=X+fn(y,z,A)=X+Y+fn(z,A)=X+Y+Z+A
*/
template <typename T, typename... Args>
T add(T n1, Args... args)
{
    // from whatever sent,separate first parameter
    // recurssively call add on the remaining on
    return n1 + add(args...);
}
// template <typename T>
// T add(T x, T y)
// {
//     return x + y; // this line only works when + operator is overloaded for type T;
// }
// Compiler uses template and make new functions based on instances then deletes the template a
int main()
{
    int ans = add<int>(10, 20);
    std::cout << ans << "\n";
    int ans1 = add<int>(50);
    std::cout << ans1 << "\n";
}

/*
Fib(N)=Fib(N-1)+Fib(N-2)
                Fib(7)
                |
                Fib(6)+Fib(5)
                |       fib(4)+fib(3)
                Fib(5)+Fib(4)       fib(2)+fib(1)
                |       fib(3)+fib(2)  
                Fib(4)+Fib(3)       fib(1)+fib(0)
                |       fib(2)+fib(1)
                Fib(3)+Fib(2)
                |       fib(1)+fib(0)
                Fib(2)+Fib(1)
                |
                Fib(1)+Fib(0)


*/