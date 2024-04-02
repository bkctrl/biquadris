#ifndef LEVEL_H
#define LEVEL_H 
#include <string>
#include <iostream>
#include <memory>
#include <cstdlib>
#include "Block.h"

class Level {
    int levelNum;
    protected:
    int blockCounter; // for level 4
    std::vector<char> blockSequence; // for level 0
    size_t sequenceIndex; // for level 0
    bool isRandom;
    std::string FileName; 
    
    public: 
    Level(int levelNum, const std::string& FileName);
    int getLevelnum() const; 
    virtual void setSource(std::istream *in) = 0;
    virtual bool splitBlock(int blockCounter); // drops the star block
    virtual Block getBlock();
    ~Level() = default; 
    
};

#endif 

// Level doesnt handle user input 
// Level only encapsualte rules and behavior of each level