#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include <vector>
#include "level.h"

class level3 : public Level {
    bool readsFile;
    int index;
    std::vector<char> sequence;
    bool isHeavy;
    bool isRandom;
public:
    level3();
    Block * getBlock() override;
   //  void norandom(std::string) override;
    // void random() override;
    char randomChar();
    //~level3() = default;
};

#endif //LEVEL3_H