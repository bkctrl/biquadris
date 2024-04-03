#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include <cstdlib>
#include <vector>
#include <string>

class level1: public Level {
    public:
    //level1() = default;
    Block * getBlock() override;
    //~level1() = default;
    char randomChar(); 
}; 
#endif