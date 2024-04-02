#include "textdisplay.h"
#include <iostream>
#include <string>


// implement the helper functions here


/*void TextDisplay::displayboard(){
    // list of the helper functions goes here
    // 
    std::cout << grid;
}*/

// std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
//     td.theDisplay;
    
// }

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  for (int i = 0; i < td.height; ++i) {
    for (int j = 0; j < td.width; ++j) {
      out << td.theDisplay[i][j];
    }
    out << std::endl; // out << '\n'
  }
  return out;
}

// have gameengine handle players and the boards for each player, within board you have: 
        // level
        // score 
        // ------ (divider)
        // game component (size 18*11)
        // -------
        // Next block: 
        // shows the block 