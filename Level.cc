#include <string>
#include <iostream>
#include <fstream>
#include "level.h"
#include "block.h"

// 
// include the various block subclasses


Block * Level::createBlock(int levelNum, char charInput){
    if (charInput == 'I'){
        return new IBlock(levelNum, charInput);
    } else if (charInput == 'S'){
        return new SBlock{levelNum};
    } else if (charInput == 'J'){
        return new JBlock{levelNum};
    } else if (charInput == 'Z'){
        return new ZBlock{levelNum};
    } else if (charInput == 'L'){
        return new LBlock{levelNum};
    } else if (charInput == 'T'){
        return new TBlock{levelNum};
    } else if (charInput == 'O'){
        return new SBlock{levelNum};
    } 
    // else if (charInput == '*'){
    //     return new StarBlock{levelNum};
    // }
}
void Level::setSeed(int newSeed){
    seed = newSeed;
    srand(seed);
}
// would it be possible to make seed available for all fucntions at once

// I,S,J,Z,L,T,O,STAR

// would same logic apply for random and norandom functions? 

void Level::norandom(std::string filename) {
    readsFile = true;

    std::ifstream file{filename};
    char letter;
    while (file >> letter) {
        sequence.push_back(letter);
    }
}

void Level::random() {
    readsFile = false;
    index = 0;
    sequence.clear();
}

Level::~Level() = default; // proper handling of virtual dtor 