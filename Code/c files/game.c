#include <unistd.h>
#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"

#define MAX_NAME_LENGTH 16
#define ROUNDS 20

static void playLocal(_Bool humanFactor, char* player1Name, char* player2Name)
{
    _Bool forfeit = 0;
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
            printf("%s Forfeits!\n", player1Name);
            forfeit = 1;
            break;
        }
        // Call second player's turn
        tmpResult = localTurn(humanFactor, player1Name, player2Name, p1Score, p2Score, i++);
        if (tmpResult >= 0)
        {
            p2Score += tmpResult;
        } else {
            printf("%s Forfeits!\n", player2Name);
            forfeit = 1;
            break;
        }
    }
    if (!forfeit) {
        printf("%s's final score: %u\n", player1Name, p1Score);
        printf("%s's final score: %u\n", player2Name, p2Score);
        printf("The winner is: %s!\n", (p1Score>p2Score) ? player1Name : player2Name);
    }
    printf("\nReturning to main menu...\n");
    sleep(3);
}

static void playNetwork()
{
    printf("Network Play has not been implemented.\n");
}

void gameInit(_Bool opponentRemote, _Bool humanFactor)
{
    // Prepare persistent arrays for player names
    char player1Name[MAX_NAME_LENGTH];
    char* player2Name;
    // Get Player Names
    if(opponentRemote)
    {
        player2Name = "Network Player";
    } else if (!humanFactor) {
        player2Name = "Computer AI";
    } else {
        player2Name[MAX_NAME_LENGTH];
    }
    printf("GAME: Player 2 name is %s\n", player2Name);
    sleep(2);
    displayLocalPlayGetName(player1Name, player2Name, humanFactor);

    // Run local vs network game
    if (!opponentRemote)
    {
        playLocal(humanFactor, player1Name, player2Name);
    } else {
        playNetwork();
    }
}