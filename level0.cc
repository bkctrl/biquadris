#include "level0.h"
#include <fstream>

level0::level0(bool PlayerOne, std::string sequence1, std::string sequence2):  
    Playerindex{0} {
    char PlayerSequence;
    /*if (PlayerOne){
        std::string sequenceFile = sequence1;
    } else {
        std::string sequenceFile = sequence2;
    } */
    std::string sequenceFile = PlayerOne ? sequence1 : sequence2;  
    std::ifstream file{sequenceFile};
    while (file >> PlayerSequence) {
        sequence.push_back(PlayerSequence);
    }
}

Block * level0::getBlock() {
    Block * level0Block = createBlock(sequence[Playerindex], 0);
    Playerindex++; // reset index to 0 if size reached
    if (Playerindex >= sequence.size()) {
        Playerindex = 0;
    }
    return level0Block;
}


// make two players, each player stores their sequence 
// the sequence of each player is cycled through level0::getblock() 
// 

// push_back would add the contents of input file to a vector 

// emplace_back is used for adding to a list of observers 

/*
level0::level0(const string& sequence1, const string& sequence2): indexP1(0), indexP2(0) {
    loadSequence(sequence1, Player1);
    loadSequence(sequence2, Player2);
}

void level0::loadSequence(const string& filename, vector<char>& sequence) {
    ifstream file {filename};
    char letter;
    while (file >> letter) {
        sequence.push_back(letter);
    }
}

Block * level0::getBlock() {
    int index = 0;
    vector<char>& sequence 
    Block * newBlock = createBlock(sequence[index], 0);

    index++; // increase index, reset to zero if past end of vector
    if (index >= sequence.size()) {
        index = 0;
    }

    return newBlock;
}  */

/*
Block* level0::getBlock(bool isPlayerOne) {
    vector<char>& currentSequence = isPlayerOne ? Player1 : Player2;
    size_t& currentIndex = isPlayerOne ? indexP1 : indexP2;

    if (currentIndex >= currentSequence.size()) {
        currentIndex = 0; // Reset the index if at the end of the sequence
    }

    char blockType = currentSequence[currentIndex++];
    return new Block(blockType, 0); // Replace with actual block creation
} */
