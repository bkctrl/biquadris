#include <fstream>
#include <cstdlib>
#include <string>

#include "level4.h"

level4::level4(): readsFile{false} {}

char level4::randomChar() {
    int c = rand() % 9;
    if (c == 0) {
        return 'T';
    } else if (c == 1) {
        return 'O';
    } else if (c == 2) {
        return 'L';
    } else if (c == 3) {
        return 'J';
    } else if (c == 4 || c == 5) {
        return 'S';
    } else if (c == 6) {
        return 'I';
    } else {  // c == 7 OR c == 8
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
