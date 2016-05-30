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
void gameInit(_Bool opponentLocal, _Bool opponentHuman)
{
    // Prepare persistent arrays for player names
    char player1[MAX_NAME_LENGTH];
    char player2[MAX_NAME_LENGTH];
    // Run local vs network game
    switch (opponentLocal)
    {
        case 0:
            playNetwork();
            break;
        case 1:
            playLocal(opponentHuman, player1, player2);
            break;
        case default:
            printf("%s\n", OPPONENT_ERROR);
    }
    // While turns < 20, run turns
            // If F, break

        // Display win/lose page
            // If ??? continue
            // If ??? break
    }
    // Thanks for playing bye.

}

static void playLocal(_Bool opponentHuman, char* player1, char* player2)
{
    unsigned p1Score = 0;
    unsigned p2Score = 0;

    // Get Player Names
    void displayLocalPlayGetName(player1, player2, opponentHuman);
    // Run <ROUNDS> turns
    for (unsigned i = 0; i < ROUNDS; i++)
    {
        // Call first player's turn
        localTurn()
        // Call second player's turn
    }
    
}

static void playNetwork()
{
    printf("Network Play has not been implemented.\n");
}