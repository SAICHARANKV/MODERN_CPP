#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string _engineNumber;
    EngineType _engineType;
    int _engineHorsepower;
    int _engineTorque;

public:
    Engine() = default;
    Engine(const Engine &) = default;
    Engine &operator=(const Engine &) = default;
    Engine(Engine &&) = delete; // Move constructor
    Engine &operator=(Engine &&) = default;
    ~Engine() = default; //{ std::cout << "Card details have deleted : " << _cardNumber << "\n"; };
    Engine(std::string engineNumber, EngineType engineType, int engineHorsepower, int engineTorque);

    std::string engineNumber() const { return _engineNumber; }
    void setEngineNumber(const std::string &engineNumber) { _engineNumber = engineNumber; }

    EngineType engineType() const { return _engineType; }
    void setEngineType(const EngineType &engineType) { _engineType = engineType; }

    int engineHorsepower() const { return _engineHorsepower; }
    void setEngineHorsepower(int engineHorsepower) { _engineHorsepower = engineHorsepower; }

    int engineTorque() const { return _engineTorque; }
    void setEngineTorque(int engineTorque) { _engineTorque = engineTorque; }
};

#endif // ENGINE_H
