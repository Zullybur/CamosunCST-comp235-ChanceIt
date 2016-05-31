#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"

#define MAX_NAME_LENGTH 16
#define ROUNDS 20

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
		printf("%d\n", i);
        // Call second player's turn
        tmpResult = localTurn(!humanFactor, player1Name, player2Name, p1Score, p2Score, i++);
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

void gameInit(_Bool opponentRemote, _Bool humanFactor)
{
    // Prepare persistent arrays for player names
    char player1Name[MAX_NAME_LENGTH];
    char player2Name[MAX_NAME_LENGTH];
    // Get Player Names
    if(opponentRemote)
    {
        char player2Name[] = "Network Player";
    } else if (!humanFactor) {
        char player2Name[] = "Computer AI";
    } else {
        char player2Name[MAX_NAME_LENGTH];
    }
    displayLocalPlayGetName(player1Name, player2Name, humanFactor);

    // Run local vs network game
    if (!opponentRemote)
    {
        playLocal(humanFactor, player1Name, player2Name);
    } else {
        playNetwork();
    }
}