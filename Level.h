#ifndef LEVEL_H
#define LEVEL_H 
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

class Block;

class Level {
    //int levelNum; // maybe not needed not too sure
    protected:
    int readsFile;
    int seed;
    int index;
    int blockCounter; // for level 4
    std::vector<char> sequence; // for level 0
    size_t sequenceIndex; // for level 0
    bool isRandom;
    std::string FileName;
    
    public: 
    // maybe default ctor not needed: Level(int levelNum, const std::string& FileName);
    Block * createBlock (char, int); // creates block based on the specifc type and input it to the corresponding level
    void setSeed(int);

    // int getLevelnum() const; 
    // virtual void setSource(std::istream *in) = 0;
    virtual bool splitBlock(int blockCounter); // drops the star block
    void norandom(std::string);
    void random();
    virtual Block * getBlock() = 0;
    virtual ~Level();
    
};

#endif 

// Level doesnt handle user input 
// Level only encapsualte rules and behavior of each level