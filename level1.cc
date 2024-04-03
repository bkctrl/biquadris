#include <cstdlib>
#include <iostream>
#include "level1.h"

char level1::randomChar() {
    int c = rand() % 12;
    if (c < 2) { // 0, 1
        return 'J';
    } else if (c < 4) { // 2, 3
        return 'L';
    } else if (c < 6) { // 4, 5
        return 'O';
    } else if (c < 8) { // 6, 7
        return 'I';
    } else if (c == 8) { // 8
        return 'S';
    } else if (c < 11) { // 9, 10
        return 'T';
    } else { // 11 cuz 12 mod 12 == 0
        return 'Z';
    }
}

Block * level1::getBlock() {
    Block * level1Block = createBlock(randomChar(), 1);
    return level1Block;
}


// The block selector will randomly choose a block with probabilities skewed 
// such that S and Z blocks are selected with probability 1/12 each, and the other
//  blocks are selected with probability 1/6 each.