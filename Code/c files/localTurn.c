#include "localTurn.h";
#include "probability.h";
#include "inputOutput.h";
#include <stdlib.h>
#include <stdio.h>

// values passed via game module
char* name
char* opponentName
unsigned opponentScore

// local turn variables
unsigned roundCounter = 1;
unsigned firstRoll;
unsigned roundScore;
unsigned turnScore;
unsigned die1;
unsigned die2;
char response;

do {
  // roll and calcualte
  die1 = roll();
  die2 = roll();
  if (roundCoutner == 1) {
    firstRoll = die1 + die2;
  }
  roundScore = die1 + die2;
  turnScore += roundScore;

  // if you lose by rolling
  if (roundScore == firstRoll) {
    displayGameOver();
    return turnScore;
  }

  displayTurn(name, firstRoll, roundCoutner, roundScore, die1, die2, turnScore,
              opponentName, opponentScore);
  
  // input loop
  do {
    response = getChar();

    switch (response) {
      // keep playing
      case "s":
        break;
      // forfeit the game
      case "f":
        displayGameOver();
        return turnScore;
      // get the probability
      case "p":
        getProbability();
        break;
      // get help/commands
      case "h":
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

// finish turn
return turnScore;