#include "../interfaces/localTurn.h"
#include "../interfaces/probability.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/dice.h"
#include "../interfaces/computerplayer.h"
#include <stdlib.h>
#include <stdio.h>

int localTurn(_Bool humanFactor, char* p1Name, char* p2Name,
              unsigned p1Score, unsigned p2Score, unsigned turnCounter) {

  // local turn variables
  _Bool activePlayer = turnCounter % 2
  unsigned rollCounter = 1;
  unsigned firstRoll;
  unsigned roundScore;
  unsigned turnScore;
  unsigned die1;
  unsigned die2;
  unsigned response;
  double probability;

  while (true) {
    // roll and calcualte
    die1 = rollDie();
    die2 = rollDie();
    if (rollCounter == 1) {
      firstRoll = die1 + die2;
    }
    roundScore = die1 + die2;
    turnScore += roundScore;

    // if you lose by rolling
    if (roundScore == firstRoll) {
      turnScore = 0;
      return turnScore;
    }

    // display/input loop
    while (true) {
      // if player is AI, just assign values
      if (humanFactor == 0) {
        probability = getProbability();
        response = getDecision(rollCounter, turnCounter, 
                              turnScore, p1Score, p2Score, probability);
        break;
      } 
      // if player is human, display roll screen
      else if (humanFactor == 1) {
        response = displayTurn(p1Name, p1Score, firstRoll, rollCounter, roundScore,
                              die1, die2, turnScore, p2Name, p2Score, activePlayer);
      } else {
        // return error code if bad input
        return -2;
      }

      switch (response) {
        // forfeit the game
        case 0:
          return -1;
        // keep playing
        case 1:
          break;
        // stop your turn
        case 2:
          return turnScore;
        // get the probability
        case 3:
          probability = getProbability(firstRoll);
          displayProbability(probability);
          break;
        // get help/commands
        case 4:
          displayInGameHelpMenu();
          break;
        // undesired input, ask again
        default:
          printf("How did you manage to get here?");
          return -2;
      }
    }

    // increment and continue if applicable
    rollCounter++;
  }
}