#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"
#include "../interfaces/highScore.h"
#include "../interfaces/protocol.h"

#define MAX_NAME_LENGTH 17
#define ROUNDS 20
#define FORFEIT -1
#define NANO_TO_NORMAL 1000000000

static void playLocal(_Bool humanFactor, char* player1Name, char* player2Name)
{
    _Bool forfeit = 0;
    unsigned p1Score = 0;
    unsigned p2Score = 0;
    int tmpResult;

    // Run <ROUNDS> turns for each player
    for (unsigned i = 0; i < ROUNDS * 2; )
    {
        LocalTurnParams params;
        params.humanFactor = humanFactor;
        params.player1Name = player1Name;
        params.player2Name = player2Name;
        params.p1Score = p1Score;
        params.p2Score = p2Score;
        params.turnCount = i++;
        // Call first player's turn
        tmpResult = localTurn(params);
        if (tmpResult >= 0)
        {
            p1Score += tmpResult;
            params.p1Score = p1Score;
        // Break the loop if a player forfeits
        } else if (tmpResult == FORFEIT) {
            printf("%s Forfeits!\n", player1Name);
            forfeit = 1;
            break;
        } else if (tmpResult < FORFEIT) {
            // Sanity check failed
            printf("Game error occured in turn logic - returning to main menu.\n");
            nanosleep(1.5 * NANO_TO_NORMAL);
            return;
        }

        params.turnCount = i++;
        // Call second player's turn
        tmpResult = localTurn(params);
        if (tmpResult >= 0)
        {
            p2Score += tmpResult;
        } else {
            printf("%s Forfeits!\n", player2Name);
            forfeit = 1;
            break;
        }
    }
    // Display results if the game completed
    if (!forfeit) {
        printf("%s's final score: %u\n", player1Name, p1Score);
        printf("%s's final score: %u\n", player2Name, p2Score);
        _Bool isHighScore;
        if (p1Score != p2Score) {
            // Display winner and send score to high score table based on which score is higher
            printf("The winner is: %s!\n", (p1Score>p2Score) ? player1Name : player2Name);

            isHighScore = submitScore(
                ((p1Score>p2Score) ? p1Score : p2Score),
                ((p1Score > p2Score) ? player1Name : player2Name)
            );

        } else {
            isHighScore = submitTieScore(p1Score, player1Name, player2Name);
            printf("The game was a tie. Ties are lame.\n");
        }

        if (isHighScore) {
            printf("\nGood job! you got a high score!\n");
        }
        
    }

    // Return to main menu
    printf("\nReturning to main menu...\n");
    nanosleep(1.5 * NANO_TO_NORMAL);
    system("clear");
}

static void getComputerName(char* name)
{
    // Set the name to Eva
    name[0] = 'E'; name[1] = 'v'; name[2] = 'a'; name[3] = '\0';
}
void gameInit(_Bool opponentRemote, _Bool humanFactor)
{
    // Prepare persistent arrays for player names
    
    char player2Name[MAX_NAME_LENGTH];

    // Get Player Names
    displayLocalPlayGetName(player1Name, player2Name, humanFactor);

    // If opponent is remote, start a network game and then return to main menu
    if(opponentRemote)
    {
        char localPlayer[MAX_NAME_LENGTH];
        // Get local player name or set computer player name
        if (humanFactor) {
            displayLocalPlayGetName(localPlayer, NULL, 0);
        }
        else {
            getComputerName(localPlayer);
        }
        
        playNetwork(humanFactor, localPlayer);
        return;
    }

    // Otherwise, if player 2 is a computer player, set the name
    if (!humanFactor) {
        getName(player2Name);
    }

    // Finally, run local game if not network
    if (!opponentRemote)
    {
        playLocal(humanFactor, player1Name, player2Name);
    }
}
