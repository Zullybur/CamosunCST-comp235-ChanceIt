#include "localTurn.h";
#include "probability.h";
#include "inputOutput.h";

// values passed via game module
char* name
char* opponentName
unsigned opponentScore

// local turn variables
unsigned roundCounter = 1;
unsigned firstRoll;
unsigned turnScore;
unsigned die1;
unsigned die2;
char response;

do {
  // roll and calcualte
  die1 = roll();
  die2 = roll();
  firstRoll = die1 + die2;
  roundScore = firstRoll;

  displayTurn(name, firstRoll, roundCoutner, roundScore, die1, die2, turnScore,
              opponentName, opponentScore);
  
  // input loop
  do {
    response = getChar();
    
    switch (response) {
      // forfeit the game
      case response == "f":
        return turnScore;
      // get the probability
      case response == "p":
        getProbability();
        break;
      // get help/commands
      case response == "h":
        getHelp();
        break;
      // undesired input, ask again
      default:
        continue;
    }
  } while (response != "s")

  // increment and continue if applicable
  roundCoutner++;
} while (response == "s");
