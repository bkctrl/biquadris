#include "level3.h"
#include <string>
#include <fstream> 

level3::level3(): readsFile{false} {}

char level3::randomChar() {
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

Block * level3::getBlock() {
    char charNext;
    if (readsFile) {
        charNext = sequence[index];
        index++;
        if (index >= sequence.size()) {
            index = 0;
        }
    } else {
        charNext = randomChar();
    }
    /* 
    char charNext = readsFile ? sequence[index] : randomChar();
    if (readsFile) {
    if (++index >= sequence.size()) {
        index = 0;
    }
    }
    */
    Block * level3Block = createBlock(charNext, 3);
    return level3Block;
}
