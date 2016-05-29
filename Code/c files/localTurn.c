#include "../localTurn.h"
#include "../probability.h"
#include "../inputOutput.h"
#include "../dice.h"
#include <stdlib.h>
#include <stdio.h>

unsigned localTurn() {
  // values passed via game module
  char* name;
  char* opponentName;
  unsigned opponentScore;

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
    die1 = rollDie();
    die2 = rollDie();
    if (roundCounter == 1) {
      firstRoll = die1 + die2;
    }
    roundScore = die1 + die2;
    turnScore += roundScore;

    // if you lose by rolling
    if (roundScore == firstRoll) {
      displayGameOver();
      return turnScore;
    }

    displayTurn(name, firstRoll, roundCounter, roundScore, die1, die2, turnScore,
                opponentName, opponentScore);
    
    // input loop
    do {
      response = getInput();

      switch (response) {
        // keep playing
        case 's':
          break;
        // forfeit the game
        case 'f':
          displayGameOver();
          return turnScore;
        // get the probability
        case 'p':
          getProbability(firstRoll);
          break;
        // get help/commands
        case 'h':
          displayInGameHelpMenu();
          break;
        // undesired input, ask again
        default:
          continue;
      }
    } while (response != 's');

    // increment and continue if applicable
    roundCounter++;
  } while (response == 's');

  // finish turn
  return turnScore;
}