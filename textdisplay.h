#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"

class TextDisplay : public Observer {
public:
    TextDisplay(); //MIL
    // update OR notify function (i think its the notify function)

    ~TextDisplay() override;
    
};

#endif