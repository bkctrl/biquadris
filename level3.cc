#include "level3.h"
#include <string>
#include <fstream> 

level3::level3(): readsFile{false} {}

char level3::randomChar() {
    int r = rand() % 9;
    if (r < 1) {
        return 'T';
    } else if (r < 2) {
        return 'O';
    } else if (r < 3) {
        return 'L';
    } else if (r < 4) {
        return 'J';
    } else if (r < 6) {
        return 'S';
    } else if (r < 7) {
        return 'I';
    } else {  
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
