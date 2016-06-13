#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"
#include "../interfaces/highScore.h"
#include "../interfaces/protocol.h"

#define MAX_NAME_LENGTH 17
#define ROUNDS 20
#define FORFEIT -1

static void playLocal(_Bool humanFactor, char* player1Name, char* player2Name)
{
    _Bool forfeit = 0;
    unsigned p1Score = 2;
    unsigned p2Score = 2;
    int tmpResult;

    //DEBUG:
    goto TESTIT;
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
            sleep(1);
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
            // Return to main menu
            printf("\nReturning to main menu...\n");
            sleep(1);
            system("clear");
            break;
        }
    }
    // Display results if the game completed
    TESTIT:if (!forfeit) {
        // printf("%s's final score: %u\n", player1Name, p1Score);
        // printf("%s's final score: %u\n", player2Name, p2Score);
        
        _Bool isHighScore;
        // TODO: Call for tie and not for tie
        isHighScore = submitScore
        (
               ((p1Score > p2Score) ? p1Score     : p2Score),
               ((p1Score > p2Score) ? player1Name : player2Name)
        );
        // 

        // Display end game screen
        endGameScreen(player1Name, p1Score, player2Name, p2Score, isHighScore);
    }
}

static void getComputerName(char* name)
{
    // Set the name to Eva
    name[0] = 'E'; name[1] = 'v'; name[2] = 'a'; name[3] = '\0';
}
void gameInit(_Bool opponentRemote, _Bool humanFactor)
{
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
    } else {
        char player1Name[MAX_NAME_LENGTH];
        char player2Name[MAX_NAME_LENGTH];
        // Otherwise, if player 2 is a computer player, set the name
        if (!humanFactor) {
            getComputerName(player2Name);
        }
        displayLocalPlayGetName(player1Name, player2Name, humanFactor);
        playLocal(humanFactor, player1Name, player2Name);
    }

    
}
