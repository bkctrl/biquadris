#include <fstream>
#include <cstdlib>
#include <string>

#include "level4.h"

level4::level4(): readsFile{false} {}

char level4::randomChar() {
    int r = rand() % 9;
    if (r < 1) {
        return 'I';
    } else if (r < 2) {
        return 'J';
    } else if (r < 3) {
        return 'L';
    } else if (r < 4) {
        return 'O';
    } else if (r < 6) {
        return 'S';
    } else if (r < 7) {
        return 'T';
    } else { // modulo is 8
        return 'Z';
    }
}


Block * level4::getBlock() {
    char nextBlockChar;

    if (readsFile) {
        nextBlockChar = sequence[index];

        index++;
        if (index >= sequence.size()) {
            index = 0;
        }
    } else {
        nextBlockChar = randomChar();
    }

    Block * newBlock = createBlock(nextBlockChar, 3);

    return newBlock;
}
