#include "../interfaces/localTurn.h"
#include "../interfaces/probability.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/dice.h"
#include "../interfaces/computerPlayer.h"
#include <stdlib.h>
#include <stdio.h>

int localTurn(LocalTurnParams localTurnParams) {
  // local turn variables
  _Bool humanFactor = localTurnParams.humanFactor;
  char* p1Name = localTurnParams.player1Name;
  char* p2Name = localTurnParams.player2Name;
  unsigned p1Score = localTurnParams.p1Score;
  unsigned p2Score = localTurnParams.p2Score;
  unsigned turnCounter = localTurnParams.turnCount;

  _Bool activePlayer = localTurnParams.turnCounter % 2;  // False if player 1, True if plyer 2
  _Bool reRoll;
  unsigned rollCounter = 1;
  unsigned firstRoll;
  unsigned roundScore;
  unsigned turnScore = 0;
  unsigned die1;
  unsigned die2;
  unsigned response;
  double probability;
  DisplayTurn turnData;
  DecisionParams decisionParams;

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

        decisionParams.rollCounter = rollCounter;
        decisionParams.turnCounter = turnCounter;
        decisionParams.turnScore = turnScore;
        decisionParams.p1Score = p1Score;
        decisionParams.p2Score = p2Score;
        decisionParams.probability = probability;

        response = getDecision(decisionParams);
      } 
      // if player is human, display roll screen
      else {
        // assign all struct values before sending to displayTurn
        turnData.p1Name = p1Name;
        turnData.p1Score = p1Score;
        turnData.firstRoll = firstRoll;
        turnData.rollCounter = rollCounter;
        turnData.roundScore = roundScore;
        turnData.die1 = die1;
        turnData.die2 = die2;
        turnData.turnScore = turnScore;
        turnData.p2Name = p2Name;
        turnData.p2Score = p2Score;
        turnData.activePlayer = activePlayer;
        turnData.turnCounter = (turnCounter/2)+1;

        response = displayTurn(turnData);
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
          // bad input, this shouldn't get exectuted
          return -2;
      }
      if (reRoll) break;
    }
  }
}
