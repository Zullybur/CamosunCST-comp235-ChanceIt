#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"

#define OPPONENT_ERROR "The selected opponent type was invalid."
#define MAX_NAME_LENGTH 16
#define ROUNDS 20

// Initiate a new game of Chance-It
// Pre: randomInit() has been called once
// Post: N/A
// Clean-Up: N/A
// Param: player is a pointer to an unsigned variable
// Return: the winning score of the game
void gameInit(_Bool opponentLocal, _Bool humanFactor)
{
    // Prepare persistent arrays for player names
    char player1Name[MAX_NAME_LENGTH];
    // Get Player Names

    if(!opponentLocal)
    {
        char player2Name[] = "Network Player";
        player1Name = displayLocalPlayGetName(player1Name, player2Name, humanFactor);
    } else if (!humanFactor) {
        char player2Name[] = "Computer AI";
        player1Name = displayLocalPlayGetName(player1Name, player2Name, humanFactor);
    } else {
        char player2Name[MAX_NAME_LENGTH] = displayLocalPlayGetName(player1Name, player2Name, humanFactor);
    }
    // Run local vs network game
    switch (opponentLocal)
    {
        case 0:
            playNetwork();
            break;
        case 1:
            playLocal(humanFactor, player1, player2);
            break;
        case default:
            printf("%s\n", OPPONENT_ERROR);
    }
}

static void playLocal(_Bool humanFactor, char* player1Name, char* player2Name)
{
    unsigned p1Score = 0;
    unsigned p2Score = 0;
    int tmpResult;

    // Run <ROUNDS> turns for each player
    for (unsigned i = 0; i < ROUNDS * 2; )
    {
        // Call first player's turn
        tmpResult = localTurn(humanFactor, player1Name, player2Name, p1Score, p2Score, i++);
        if (tmpResult >= 0)
        {
            p1Score += tmpResult;
        } else {
            printf("Player 1 Forfeits TODO: Game over screen\n");
            break;
        }

        // Call second player's turn
        tmpResult = localTurn(humanFactor, player1Name, player2Name, p1Score, p2Score, i++);
        if (tmpResult >= 0)
        {
            p2Score += tmpResult;
        } else {
            printf("Player 2 Forfeits TODO: Game over screen\n");
            break;
        }
    }
    printf("TODO: Game over screen\n");
}

static void playNetwork()
{
    printf("Network Play has not been implemented.\n");
}