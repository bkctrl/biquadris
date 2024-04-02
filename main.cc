#include <iostream>
#include <string>
#include "grid.h"
#include "ComInterpreter.h"
using namespace std;

int main(const int argc, const char* argv[]) {
  // initialize grid and command interpreter
  Grid grid;
  CommandInterpreter cmdInterpreter(&grid); 
  // command-line interface
  for (int i = 1; i < argc; ++i) {
    if (string(argv[i]) == "-text") {
      //  runs the program in text-only mode
    } else if (string(argv[i]) == "-seed") {
      //  sets the random number generator’s seed to 
    } else if (string(argv[i]) == "-scriptfile1") {
      // Uses argv[i+1] instead of sequence1.txt as a source of blocks
      //  for level 0, for player 1
    } else if (string(argv[i]) == "-scriptfile2") {
      // Uses argv[i+1] instead of sequence2.txt as a source of blocks
      //  for level 0, for player 1
    } else if (string(argv[i]) == "-startlevel") {
      // Starts the game in level argv[i+1]
    }
  }
  string user_input;
  while (cin >> user_input) {
    interpreter.interpretCommand(user_input);
    grid.display();
  }
}
