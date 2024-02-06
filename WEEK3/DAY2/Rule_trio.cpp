#include <iostream>

class Vehicle
{
private:
    int *_readingsArray; // it might be array too.
    int _vehicleId;
    int _readingSize;

public:
    Vehicle(int *readings, int id, int size)
        : _vehicleId(id)
    {
        _readingsArray = new int[size];
        for (int i = 0; i < size; i++)
        {
            _readingsArray[i] = readings[i];
        }
    }

    Vehicle(const Vehicle &rhs)
    {
        this->_readingSize = rhs._readingSize;
        this->_vehicleId = rhs._vehicleId;
        this->_readingsArray = rhs._readingsArray; // Shallow Copy
        // _readingsArray = new int[_readingSize];
        // for (int i = 0; i < rhs._readingSize; i++)
        // {
        //     _readingsArray[i] = rhs._readingsArray[i]; // deep copy
        // }
    }

    Vehicle &operator=(const Vehicle &rhs)
    {
        this->_readingSize = rhs._readingSize;
        this->_vehicleId = rhs._vehicleId;
        this->_readingsArray = rhs._readingsArray; // Shallow Copy
        // _readingsArray = new int[_readingSize];
        // for (int i = 0; i < rhs._readingSize; i++)
        // {
        //     _readingsArray[i] = rhs._readingsArray[i]; // deep copy
        // }
        return *this;
    }
    ~Vehicle()
    {
        delete[] _readingsArray;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Vehicle v(a, 1, 5);
}