#include "Engine.h"

Engine::Engine(std::string engineNumber, EngineType engineType, int power, int torque)
    : _engineNumber(engineNumber), _engineType(engineType), _engineHorsePower(power), _engineTorque(torque)
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "engineNumber: " << rhs._engineNumber << "\n"
       << "engineType: " << static_cast<int>(rhs._engineType) << "\n"
       << "engineHorsePower: " << rhs._engineHorsePower << "\n"
       << "engineTorque: " << rhs._engineTorque << "\n"
       << "=====================\n";
    return os;
}
