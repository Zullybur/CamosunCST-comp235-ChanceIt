typedef struct DesicionParams {
    unsigned roundNumber;
    unsigned rollCounter;
    unsigned turnScore;
    unsigned p1Score;
    unsigned p2Score;
    unsigned firstRoll;
} DecisionParams;
// Determines the computer player's decision to roll or stop.
// Pre: N/A
// Post: N/A
// Return 2 for stop, or 1 for roll again
// Cleanup N/A
// Param roundNumber is the number of rounds completed
// Param turnNumber is the number of rolls made this round
// Param turnScore is the cumulative score of rolls from this turn
// Param p1Score is the current score of the player making the decision
// Param p2Score is the current score of the other player
// Param probability is the probabiity of rolling the same number again
unsigned getDecision(DecisionParams params);