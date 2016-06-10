#include "../interfaces/localTurn.h"
#include "../interfaces/probability.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/dice.h"
#include "../interfaces/computerPlayer.h"
#include <stdlib.h>
#include <stdio.h>

int localTurn(_Bool humanFactor, char* p1Name, char* p2Name,
              unsigned p1Score, unsigned p2Score, unsigned turnCounter) {
  // local turn variables
  _Bool activePlayer = turnCounter % 2;  // False if player 1, True if plyer 2
  _Bool reRoll;
  unsigned rollCounter = 1;
  unsigned firstRoll;
  unsigned roundScore;
  unsigned turnScore = 0;
  unsigned die1;
  unsigned die2;
  unsigned response;
  double probability;

  while (1) {
    // roll and calcualte
    die1 = rollDie();
    die2 = rollDie();
    if (rollCounter == 1) {
      firstRoll = die1 + die2;
    }
    roundScore = die1 + die2;
    turnScore += roundScore;

    // if you lose by rolling
    if (roundScore == firstRoll && rollCounter > 1) {
      if (!activePlayer) {
        displayFailRoll(p1Name, firstRoll, p2Name);
      } else {
        displayFailRoll(p2Name, firstRoll, p1Name);
      }
      turnScore = 0;
      return turnScore;
    }

    // display/input loop
    while (1) {
      reRoll = 0;
      // if player is AI, just assign values
      if (activePlayer && !humanFactor) {
        probability = getProbability(firstRoll);
        response = getDecision(rollCounter, turnCounter, 
                              turnScore, p1Score, p2Score, probability);
      } 
      // if player is human, display roll screen
      else {
        DisplayTurn turn;
        turn.p1Name = p1Name;
        turn.p1Score = p1Score;
        turn.firstRoll = firstRoll;
        turn.rollCounter = rollCounter;
        turn.roundScore = roundScore;
        turn.die1 = die1;
        turn.die2 = die2;
        turn.turnScore = turnScore;
        turn.p2Name = p2Name;
        turn.p2Score = p2Score;
        turn.activePlayer = activePlayer;
        turn.turnCounter = turnCounter;
        response = displayTurn(turn);
      }

      switch (response) {
        // forfeit the game
        case 0:
          return -1;
        // keep playing
        case 1:
          rollCounter++;
          reRoll = 1;
          break;
        // stop your turn
        case 2:
          if (!activePlayer) {
            displayStopTurn(p1Name, turnScore, p2Name);
          } else {
            displayStopTurn(p2Name, turnScore, p1Name);
          }
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
          printf("How did you manage to get here? (sanity check failed)\n");
          return -2;
      }
      if (reRoll) break;
    }
  }
}
