#ifndef LEVEL_H
#define LEVEL_H 
#include <string>
#include <iostream>
#include <memory>
#include <cstdlib>


class Level {
    //int levelNum; // maybe not needed not too sure
    protected:
    int blockCounter; // for level 4
    std::vector<char> blockSequence; // for level 0
    size_t sequenceIndex; // for level 0
    bool isRandom;
    std::string FileName; 
    
    public: 
    // maybe default ctor not needed: Level(int levelNum, const std::string& FileName);
    Block * createBlock (char, int); // creates block based on the specifc type and input it to the corresponding level
    void setSeed(int);

    // int getLevelnum() const; 
    //virtual void setSource(std::istream *in) = 0;
    virtual bool splitBlock(int blockCounter); // drops the star block
    virtual Block * getBlock() = 0;
    virtual ~Level() = default; 
    
};

#endif 

// Level doesnt handle user input 
// Level only encapsualte rules and behavior of each level