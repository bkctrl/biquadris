#include "level0.h"

level0::level0() : indexP1(0), indexP2(0) {}

void level0::setSequenceFiles(const std::string& sequence1, const std::string& sequence2) {
    loadSequence(sequence1, sequencePlayer1);
    loadSequence(sequence2, sequencePlayer2);
}

void level0::loadSequence(const std::string& filename, std::vector<char>& sequence) {
    /* std::ifstream fileStream(filename);
    char content;
    while (fileStream >> content) {
        sequence.push_back(content);
    } */
}

Block* level0::getBlock() {
    bool isPlayerOne;
    std::vector<char>& sequence = isPlayerOne ? sequencePlayer1 : sequencePlayer2;
    size_t& index = isPlayerOne ? indexP1 : indexP2;

    Block* newBlock = createBlock(sequence[index], 0);

    index++; 
    if (index >= sequence.size()) {
        index = 0;
    }

    return newBlock;
}


// push_back would add the contents of input file to a vector 

// emplace_back is used for adding to a list of observers 