#include <iostream>
#include <string>
#include "grid.h"
#include "textdisplay.h"
// #include "commandinterpreter.h"

int main(const int argc, const char* argv[]) {
  // initialize grid and command interpreter
  Grid grid;
  // CommandInterpreter cmdInterpreter(&grid); 
  // command-line interface
//   for (int i = 1; i < argc; ++i) {
//     if (string(argv[i]) == "-text") {
//       //  runs the program in text-only mode
//     } else if (string(argv[i]) == "-seed") {
//       //  sets the random number generator’s seed to 
//     } else if (string(argv[i]) == "-scriptfile1") {
//       // Uses argv[i+1] instead of sequence1.txt as a source of blocks
//       //  for level 0, for player 1
//     } else if (string(argv[i]) == "-scriptfile2") {
//       // Uses argv[i+1] instead of sequence2.txt as a source of blocks
//       //  for level 0, for player 1
//     } else if (string(argv[i]) == "-startlevel") {
//       // Starts the game in level argv[i+1]
//     }
//   }
  // display the grid
    std::cout << grid;
  
  // get user input from cin
  /*string user_input;
  while (getline(cin, user_input)) {
    cmdInterpreter.interpretCommand(user_input); // a method that processes user input
    grid.display();
  }*/
}


/*
heavy for level3/4 example (need to apply this code more than once)
if (playerOne->getLevel() >= 3){
  playerOne->getCurBlock()->down();
  }
*/
// 
 /*if (cmd == "left") {
                if (playerOneTurn){
                    playerOne->getCurBlock()->left();
                    if (playerOne->getLevel() >= 3){
                        playerOne->getCurBlock()->down(); // this does the purpose of heavy 
                    } */

// special actions:
// ApplyForce()
// ApplyHeavy() 
// ApplyBlind()
// each would return the respective 


// there would be a def for bool Force
/* bool Grid::setForce(bool toggleForce){
      Force = toggleForce;
}*/
// same logic applies to blind 

