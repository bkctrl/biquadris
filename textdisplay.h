#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include <string>

class TextDisplay : public Observer {
    Grid & grid;
public:
    TextDisplay(Grid &theGrid); //MIL
    // some sort of update function to update the texts 
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    // various functions that display the component
    void displayboard(); // displays the grid 
    ~TextDisplay() override;
    
    
};

#endif