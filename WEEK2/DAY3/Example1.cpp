
/*
    [0000 0000] 0x100H
    [0000 0000] 0x101H
    [0000 0000] 0x102H
    [0000 1001] 0x103H
    [0000 0000] 0x104H
    [0000 0000] 0x105H
    [0000 0000] 0x106H
    [0000 1010] 0x107H
*/
#include <iostream>
#include <list>
#include <array>

/*
    Assume array is of a type character, size is 10 0x101H
      0    1    2    3    4    5    6    7    8    9
    ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
    0x101                               0x108H

    base address +(index * size of one element)

    arr[7]=0x101H +(7*1)=0x101H+7 =0X108H
*/

int main()
{
    /*
        std::array is a clsss in the maespace std
        <int,2> are template arguments
        where int is type and2 id fixed size of the array
    */

    std::array<int, 2> arr{9, 10};

    /*
        Objective:for each Loop (range-based loop /iterative for loop)
                SHOULD WORK!!!
        array iteration:
        1) Record and save the beginning of the array(pointer to base location)
            begin

        2) Record the address JUST BEFORE THE LAST ITEM. This would be the terminating
            point for the array.call this as
            end

        3) Put Begin and end(along with other things) and make a iterator Objective

        4) Now we can overload [] operator, ++operator,--(and anything else we need),
            these overloaded function will include "LOGIC" for iterator.

        5) Now for each loop for(int val:arr) is equivalent to
            for(itr=arr.begin(); itr!=arr.end();++itr)
            {
                int val=*itr;
            }
    */

    /*
    Has a error at n1 in for each loop
    this range-based 'for' statement requires a suitable "begin"
    function and none was foundC/C++(2291)
    */

    //     int n1 = 10;
    //     for (int val : n1)
    //     {
    //    }

    int total{0};

    for (int val : arr)
    {
        total = total + val;
    }
    std::cout << total / arr.size() << "\n";
}