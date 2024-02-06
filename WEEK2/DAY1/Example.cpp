#include <iostream>
#include <vector>
#include <functional> // Includes all functional features

// void Odd(std::function<int(int)> odd1, std::vector<int> &data)
// {
//     for (int val : data)
//     {
//         if (val % 2 == 0)
//             std::cout << "NO";
//         std::cout << "YES";
//     }
// }

// void Manager(int (*fn)(int), std::vector<int> &data)
void Manager(std::function<int(int)> fn, std::vector<int> &data) // Wrapper
// unwraps square function by address and access defintiton
{
    for (int val : data)
        std::cout << fn(val);
}

int Square(int number)
{
    std::cout << "\t";
    return number * number;
}

int Cube(int number)
{
    std::cout << "\t";
    return number * number * number;
}

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};

    /* L value Lambda function with name of the object as f1
            // this lambda is of signature
            - input of 1 integer by value
            - return of 1 integer by value
    */
    auto f1 = [](int number) -> int // auto = std::function<int(int)>
    {
        std::cout << "\t";
        return number * number;
    };
    // execute f1 directly like a function without passing;
    std::cout << f1(10) << std::endl;
    // Manager(Square, data);
    // Square
    // R value lambda function
    Manager([](int number) -> int
            { std::cout<<"\t";
            return number * number; },
            data); // LAMBDA function

    std::cout << std::endl;
    // Cube
    Manager([](int number) -> int
            { std::cout<<"\t";
            return number * number*number; },
            data); // LAMBDA function

    Manager(Square, data); // uses square function address as parameter
    std::cout << std::endl;
    //   int (*ptr)(int) = Square;
}

// class lambda
// {
// private:
// public:
//     int operator()(int number)
//     {
//         return number * number;
//     }
// };

// lambda obj(1);