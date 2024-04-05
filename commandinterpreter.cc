#include "commandinterpreter.h"
#include <algorithm>
#include <sstream>

CommandInterpreter::CommandInterpreter(GameEngine& engine) : gameEngine(engine) {
    registerCommands();
}

void CommandInterpreter::registerCommands() {
    commandMap["left"] = [this](int multiplier) { gameEngine.moveBlockLeft(multiplier); };
    commandMap["right"] = [this](int multiplier) { gameEngine.moveBlockRight(multiplier); };
    commandMap["down"] = [this](int multiplier) { gameEngine.moveBlockDown(multiplier); };
    commandMap["clockwise"] = [this](int multiplier) { executeRotate(true, multiplier); };
    commandMap["counterclockwise"] = [this](int multiplier) { executeRotate(false, multiplier); };
    // ... Other commands
}

void CommandInterpreter::executeCommand(const std::string& command, int multiplier) {
    // Check if the command exists
    auto iter = commandMap.find(command);
    if (iter != commandMap.end()) {
        // Execute the command with the given multiplier
        iter->second(multiplier);
    }
}

void CommandInterpreter::executeRotate(bool clockwise, int multiplier) {
    for (int i = 0; i < multiplier; ++i) {
        if (clockwise) {
            gameEngine.rotateBlockClockwise();
        } else {
            gameEngine.rotateBlockCounterClockwise();
        }
    }
}
