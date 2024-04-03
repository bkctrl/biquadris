#include <cstdlib>
#include <iostream>
#include "level2.h"

char level2::randomChar() {
    int c = rand() % 7;
    if (c == 0) {
        return 'J';
    } else if (c == 1) {
        return 'L';
    } else if (c == 2) {
        return 'O';
    } else if (c == 3) {
        return 'I';
    } else if (c == 4) {
        return 'S';
    } else if (c == 5) {
        return 'T';
    } else { // if (c == 6) {
        return 'Z';
    }
}

Block * level2::getBlock() {
    Block * level2Block = createBlock(randomChar(), 2);

    return level2Block;
}