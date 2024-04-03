#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "subject.h"
#include "cell.h"
#include <string>

class TextDisplay : public Observer, public Subject {
    std::vector< std::vector<char> > theDisplay;
    const int width;
    const int height;
public:
    TextDisplay(int width, int height); //MIL
    // some sort of update function to update the texts 
    //friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    // various functions that display the component
    void notify (Cell&c) override;
    void displayboard(); // displays the grid 
    ~TextDisplay() override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif