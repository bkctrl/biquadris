#ifndef LEVEL4_H
#define LEVEL4_H

#include <vector>
#include "level.h"

class level4 : public Level {
    bool readsFile;
    int index;
    std::vector<char> sequence;
    int seed;
    bool isHeavy;
    bool isRandom;
public:
    level4();
    char randomChar();
    Block * getBlock() override;
};


#endif