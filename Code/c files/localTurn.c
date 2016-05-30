#include "../interfaces/localTurn.h"
#include "../interfaces/probability.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/dice.h"
#include "../interfaces/computerplayer.h"
#include <stdlib.h>
#include <stdio.h>

unsigned localTurn(unsigned player, char* playerName, char* opponentName,
                  unsigned p1Score, unsigned p2Score, unsigned turnCounter) {

  // values passed via game module
  unsigned playerGrandScore = p1Score;
  unsigned opponentGrandScore = p2Score;

  // local turn variables
  unsigned roundCounter = 1;
  unsigned firstRoll;
  unsigned roundScore;
  unsigned turnScore;
  unsigned die1;
  unsigned die2;
  char response;
  double prob;

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

    displayTurn(playerName, firstRoll, roundCounter, roundScore, die1, die2, turnScore,
                opponentName, opponentGrandScore);
    
    // input loop
    do {
      if (player == 0) {
        response = getInput();
      }
      else if (player == 1) {
        prob = displayProbability();
        response = getDecision(roundCounter, turnCounter, 
                              turnScore, p1Score, p2Score, prob);
      } else {
        return 0;
      }

      switch (response) {
        // keep playing
        case 'r':
          break;
        // forfeit the game
        case 'f':
          displayGameOver();
          return turnScore;
        // get the probability
        case 'p':
          prob = getProbability(firstRoll);
          displayProbability(prob);
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
  } while (response == 'r');

  // finish turn
  return turnScore;
}