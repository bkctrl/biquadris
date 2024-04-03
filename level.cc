#include <string>
#include <iostream>
#include "level.h"

class Block;

// include the various block subclasses


Block * Level::createBlock(char charInput, int levelNum){
    if (charInput == 'I'){
        return new IBlock{levelNum};
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
    } else if (charInput == '*'){
        return new StarBlock{levelNum};
    }
}
void Level::setSeed(int newSeed){
    seed = newSeed;
    srand(seed);
}


// I,S,J,Z,L,T,O,STAR