#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
#include <unordered_map>
#include <functional>
#include "gameengine.h"
#include "grid.h"

class CommandInterpreter {
private:
    GameEngine* gameEngine;
    Grid* grid;
    std::unordered_map<std::string, std::function<void()>> commandMap;

    void initializeCommands();

public:
    explicit CommandInterpreter(GameEngine& engine, Grid& grid);
    void interpretCommand(const std::string& input);
};

#endif //COMMANDINTERPRETER_H
