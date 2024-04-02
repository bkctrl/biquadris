#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include <string>

class TextDisplay : public Observer {
public:
    TextDisplay(); //MIL
    // some sort of update function to update the texts 
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    ~TextDisplay() override;
    
    
};

#endif