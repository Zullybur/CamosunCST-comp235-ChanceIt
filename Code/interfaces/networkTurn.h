typedef struct NetworkTurn {
    int sock,
    _Bool isHuman,
    char* p1Name,
    char* p2Name,
    _Bool isFirst,
    unsigned localScore,
    unsigned opponentScore,
    unsigned turnNum,
    unsigned die1,
    unsigned die2,
    unsigned firstRoll
} NetworkTurn;

// Recieves data from the network player
// Pre: N/A
// Post: N/A
// Cleanup N/A
// Return an unsigned of the turn score
unsigned networkTurn(NetworkTurn* params);