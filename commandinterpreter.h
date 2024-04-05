#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
#include <unordered_map>
#include <functional>
#include "gameengine.h"

class CommandInterpreter {
    GameEngine& gameEngine;
    std::unordered_map<std::string, std::function<void(int)>> commandMap;

    // Helper methods for commands
    void registerCommands();
    void executeRotate(bool clockwise, int multiplier);

public:
    CommandInterpreter(GameEngine& engine);
    void executeCommand(const std::string& command, int multiplier);
};

#endif // COMMANDINTERPRETER_H
