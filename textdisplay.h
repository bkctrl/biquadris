#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "cell.h"
#include "block.h"
#include <string>

class TextDisplay : public Observer {
    std::vector< std::vector<char> > theDisplay;
    const int width = 11;
    const int height = 18;
public:
    TextDisplay(); //MIL
    ~TextDisplay(); // destructor
    // some sort of update function to update the texts 
    //friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    // various functions that display the component

    // this function will be called by the cell to notify the textdisplay of the change
    void notify (Cell &c);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif