#ifndef __GRAPHICDISPLAY_H_
#define __GRAPHICDISPLAY_H_

#include <iostream>
#include <vector>
#include "window.h"
#include "observer.h"
class Cell;

class GraphicsDisplay : public Observer {
    Xwindow xw; 
    const int gridSize; 

public:
    GraphicsDisplay(int n); 
    // either a notify or an update function: 
    // void notify(Cell &c) override; 

    ~GraphicsDisplay();
};

#endif 