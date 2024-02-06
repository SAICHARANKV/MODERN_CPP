#include <iostream>
#include <functional>
typedef int (*IntegerOp)(int, int); // 2 method
int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

/*int main()
{
    // Function Pointers
    // ReturnType (* operation )(Parameters)
    // 1.  int (*op)(int, int); // int (*op)(int,int)=add;
    // 2. IntegerOp op;
    // 3. ModernCpp Style std::function<returntype of function (param1,....)>op;
    std::function<int(int, int)> op;
    int n;
    std::cout << "1 for add ---2 for multiply\n"
              << std::endl;
    std::cin >> n;
    if (n == 1)
    {
        op = add;
    }
    else if (n == 2)
    {
        op = multiply;
    }
    int x = 0, y = 0;
    std::cout << "X and Y values\n";
    std::cin >> x >> y;
    std::cout << op(x, y) << std::endl;
}*/

void display(int x, std::string s)
{
    std::cout << "Displaying id: " << x << " Name: " << s << "\n";
}

int main()
{
    std::function<void(int, std::string)> xs = display;
    xs(1, "sai");
}