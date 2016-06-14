#include "../interfaces/computerPlayer.h"

#define RISK_REDUCTION_LIMITER 1.5
#define RISK_MULTIPLIER 2
#define MAX_ROLL_THRESHOLD 10

// Determines the computer player's decision to roll or stop.
// Pre: N/A
// Post: N/A
// Return 2 for stop, or 1 for roll again
// Cleanup N/A
unsigned getDecision(DecisionParams params)
{
    unsigned avgBust[13] = {0,0,35,17,11,8,6,5,6,8,11,17,35};
    double risk = 0.0;

    // Take less risk at start of game
    if (params.roundNumber < 10) {
        risk = 0.20;
    // Take more risk if we are losing
    } else if (params.roundNumber < 15 && params.p1Score < params.p2Score) {
        risk = 0.40;
    // If it is the last round, roll until we win
    } else if (params.roundNumber == 20) {
        return (params.p1Score + params.turnScore < params.p2Score) ? 1 : 2;
    // If we are past round 15 and still losing, take lots of risks!
    } else if (params.p1Score + params.turnScore < params.p2Score) {
        risk = 0.50;
    } else {
        risk = 0.25;
    }
    // printf("AI 1 State:\n\trnd: %u \n\troll: %u \n\tturnScr: %u \n\tdiff: %u \n\trisk: %f\n",
    //     params.roundNumber, params.rollCounter, params.turnScore, params.p1Score - params.p2Score, risk);

    unsigned maxRolls = (unsigned)(risk * avgBust[params.firstRoll]);
    // printf("\tmax: %u\n", maxRolls);

    if (maxRolls > params.rollCounter){
        // printf("\tROLL AGAIN!\n\n");
        return 1;
    } else {
        // printf("\tSTOP :(\n\n");
        return 2;
    }
}
