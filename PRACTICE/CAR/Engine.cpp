#include "Engine.h"

Engine::Engine(std::string engineNumber, EngineType engineType, int engineHorsepower, int engineTorque)
    : _engineNumber(engineNumber), _engineType(engineType), _engineHorsepower(engineHorsepower), _engineTorque(engineTorque)
{
}