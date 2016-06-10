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
    unsigned roundNumber = params.roundNumber;
    unsigned turnNumber = params.turnNumber;
    unsigned turnScore = params.turnScore;
    unsigned p1Score = params.p1Score;
    unsigned p2Score = params.p2Score;
    unsigned probability = params.probability;

    int scoreGap = p1Score - p2Score + turnScore;

    /**** e.g. ****
    probability is .735245r345
    threshold = (1-.735...) * 10 = 3
    ***************/
    int riskThreshold  = (int)((1 - probability) * MAX_ROLL_THRESHOLD);

    double riskReductionMultiplier = (roundNumber > 9) ? 1.5 : 1;
    
    // Take more risk if we are losing
    if (scoreGap < 0)
    {
        riskThreshold *= RISK_MULTIPLIER;
    // Take less risk if we are ahead significantly
    } else if (scoreGap > p1Score * RISK_REDUCTION_LIMITER) {
        riskThreshold /= (RISK_MULTIPLIER * riskReductionMultiplier);
    }

    // Return the roll decision based on risk threshold vs how many rolls have been made
    if (turnNumber < riskThreshold)
    {
        return 1;
    }

    return 2;
}
