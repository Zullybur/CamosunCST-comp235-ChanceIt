typedef struct NetworkTurn {
    isHuman,
    p1Name,
    p2Name,
    isFirst,
    localScore,
    opponentScore,
    turnNum,
    firstRoll
} NetworkTurn;

// Recieves data from the network player
// Pre: N/A
// Post: N/A
// Cleanup N/A
// Return an unsigned of the turn score
unsigned networkTurn(NetworkTurn* params);