#include <unistd.h>
#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"
#include "../interfaces/highScore.h"

#define MAX_NAME_LENGTH 17
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
        _Bool isHighScore;
        if (p1Score != p2Score) {
            // Display winner and send score to high score table based on which score is higher
            printf("The winner is: %s!\n", (p1Score>p2Score) ? player1Name : player2Name);

            isHighScore = submitScore(
                (p1Score > p2Score) ? player1Name : player2Name,
                (p1Score>p2Score) ? p1Score : p2Score
            );

        } else {
            isHighScore = submitTieScore(player1Name, p1Score, player2Name, p2Score);
            printf("The game was a tie. Ties are lame.\n");
        }

        if (isHighScore) {
            printf("\nGood job! you got a high score!\n");
        }
        
    }

    printf("\nReturning to main menu...\n");
    sleep(1.5);
    system("clear");
}

static void playNetwork(_Bool humanFactor, char* player1Name, char* player2Name)
{
    printf("Sorry - Network Play has not been implemented.\n");
    sleep(1.5);
}

static void getName(char* name, _Bool isNetwork)
{
    if (isNetwork)
    {
        name[0] = 'N'; name[1] = 'e'; name[2] = 't'; name[3] = 'w';
        name[4] = 'o'; name[5] = 'r'; name[6] = 'k'; name[7] = ' ';
        name[8] = 'P'; name[9] = 'l'; name[10] = 'a'; name[11] = 'y';
        name[12] = 'e'; name[13] = 'r'; name[14] = '\0';
    } else {
        name[0] = 'C'; name[1] = 'o'; name[2] = 'm'; name[3] = 'p';
        name[4] = 'u'; name[5] = 't'; name[6] = 'e'; name[7] = 'r';
        name[8] = ' '; name[9] = 'P'; name[10] = 'l'; name[11] = 'a';
        name[12] = 'y'; name[13] = 'e'; name[14] = 'r'; name[15] = '\0';
    }
}
void gameInit(_Bool opponentRemote, _Bool humanFactor)
{
    // Prepare persistent arrays for player names
    char player1Name[MAX_NAME_LENGTH];
    char player2Name[MAX_NAME_LENGTH];

    // Get Player Names
    if(opponentRemote)
    {
        getName(player2Name, 1);
    } else if (!humanFactor) {
        getName(player2Name, 0);
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
