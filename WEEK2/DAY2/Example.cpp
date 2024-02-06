#include <iostream>
#include <list>
int main()
{
    // ref becomes alternate name for n1
    // sec_ref is an alternate for n1
    int n1 = 10;
    int &ref = n1; // no memory for ref or sec_ref
    int &sec_ref = ref;

    // int &arr[1]{ref}; // References can't go in array as
    // std::list<int&> data;
    // data.push_back(ref); //  References can't go in list
    // as no memory will be they r pointing to/alias .
}