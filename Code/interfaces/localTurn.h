typedef struct LocalTurnParams{
    _Bool humanFactor;
    char* player1Name;
    char* player2Name;
    unsigned p1Score;
    unsigned p2Score;
    unsigned turnCount;
} LocalTurnParams;

// Completes a single full turn and calculates the score.
// Pre: N/A
// Post: N/A
// Clean-Up: N/A
// Params: humanFactor - if there is a human or AI taking the turn
//         playerName - current players name
//         opponentName - the current opponents name
//         p1Score - the current players score
//         p2Score - the current opponents score
//         turnCounter - a count of the total turns taken place
// Returns: the final turn score, a -1 for a forfeit, a -2 for invalid input
int localTurn(LocalTurnParams localTurnParams);
