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

// while we are not going to (f)orefit
if (response != "f") {
  // initial roll
  die1 = roll();
  die2 = roll();
  firstRoll = die1 + die2;
  roundScore = firstRoll;

  displayTurn(name, firstRoll, roundCoutner, roundScore, die1, die2, turnScore,
              opponentName, opponentScore);
  
  response = getChar();
  roundCoutner++;

  // consecutive rolls while we're not (s)topping
  while (response != "s") {
    die1 = roll();
    die2 = roll();
    roundScore = die1 + die2;
    turnScore += roundScore;
    
    displayTurn(name, firstRoll, roundCoutner, roundScore, die1, die2, turnScore,
                opponentName, opponentScore);
    
    response = getChar();
    roundCoutner++;
  }
}

// finish turn
return turnScore;