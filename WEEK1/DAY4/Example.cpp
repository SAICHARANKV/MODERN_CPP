#include <iostream>

class DataModel
{
private:
    int _id{-1};
    float _value{0.0f};

public:
    DataModel() = default;
    ~DataModel() = default;
    DataModel(const DataModel &) = default;
    DataModel &operator=(const DataModel &) = default;
    DataModel &operator=(DataModel &&) = default;
    DataModel(DataModel &&) = default;

    float value() const { return _value; }
    int id() const { return _id; }

    DataModel(int id, float value) : _id(id), _value(value){};
};

void Magic(DataModel obj)
{
    std::cout << "Magic Triggered!!!\n";
}
/*
address                 Name of identifier              CONTENT
0x1000H                    d1                           0x876H

*/
int main()
{
    DataModel *d1 = new DataModel(102, 98.19f);
    Magic(*d1); // d1 is a pointer
    delete d1;
}
/*
    Heap
    ===============

    [101  | 78.21]
    0x876H

    Magic
    ==============
    obj
    [101 | 78.21]
    0x876H

    Main Call Stack
    ===============
    d1
    [0x8765H]


*/

/*
Main Call Stack - 8 bytes of memory

[102   | 98.19]
0x145H   0x14cH
-------------------------------------------------------------
Parameterized Constructor Call Stack
        
id [102];
value [98.19];
*/

/*
    Rule of Zero
    Rule of Three
    Rule of Five
*/