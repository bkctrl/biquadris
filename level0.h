#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"
#include <vector>
#include <string>

class level0 : public Level {
    int Playerindex;
    std::vector<char> sequence;
    std::vector<char> Player1;
    std::vector<char> Player2;
    public:
    level0(bool,std::string,std::string);
    Block * getBlock() override; // supposed to add override but for some reason isnt recognized
    //~level0() = default;
};

#endif