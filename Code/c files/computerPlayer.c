#include "../interfaces/computerPlayer.h"

// Determines the computer player's decision to roll or stop.
// Pre: N/A
// Post: N/A
// Return 0 for stop, or 1 for roll again
// Cleanup N/A
unsigned getDecision(unsigned roundNumber, unsigned turnNumber, 
                     unsigned turnScore, unsigned p1Score,
                     unsigned p2Score, unsigned probability)
{
    /***** Notes *****
    -- 
    -- is turn number the number of rolls this turn
    ******************/

    // risk threshold
    //      -- score gap
    // related to the probability
    // return 0 or 1

    int scoreGap = p1Score - p2Score + turnScore;

    int riskThreshold  = (int)(abs(1 - probability) * 10);
    /**** e.g. ****
    probability is .735245r345
    threshold = 3
    ***************/
    if ((turnNumber < riskThreshold) ||
        ((scoreGap < 0) && (turnNumber < riskThreshold * 2)))
    {
        return 1;
    }

    return 0;
}