#ifndef LEVEL0_H
#define LEVEL0_H

#include "Level.h"
#include <vector>
#include <string>

class level0 : public Level {
    int indexP1; 
    int indexP2;
    std::vector<char> sequencePlayer1;
    std::vector<char> sequencePlayer2;
    public:
    level0();
    void loadSequence(const std::string& filename, std::vector<char>& sequence);
    void setSequenceFiles(const std::string& sequence1, const std::string& sequence2);
    Block * getBlock() override;
    ~level0() = default;
};

#endif