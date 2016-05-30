#include <stdio.h>
#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"

enum typedef
    {
        UNASSIGNED,
        PLAY_LOCAL,
        PLAY_NETWORK,
        SHOW_RULES,
        HIGH_SCORES,
        EXIT_GAME
    } MainMenuInput;

enum typedef
    {
        PREVIOUS_MENU,
        SINGLE_PLAYER,
        MULTIPLAYER
    } LocalPlayInput;
// Initiate a new game of Chance-It
// Pre: randomInit() has been called once
// Post: N/A
// Clean-Up: N/A
// Param: player is a pointer to an unsigned variable
// Return: the winning score of the game
unsigned gameInit()
{
    // Main Menu Game Loop
    while (true)
    {
        // Request IO to display main menu
        MainMenuInput result = (MainMenuInput)displayMainMenu();
        switch (result)
        {
            case PLAY_LOCAL:
                playLocal();
                break;
            case PLAY_NETWORK:
                playNetwork();
                break;
            case SHOW_RULES:
                displayRules();
                break;
            case HIGH_SCORES:
                displayHighScore();
                break;
            case EXIT_GAME:
                sys.exit(0);
            default:
                printf("Sanity check failed - game:gameInit:displayMainMenu:switch\n");
                sys.exit(1);
        }

        

        // While turns < 20, run turns
            // If F, break

        // Display win/lose page
            // If ??? continue
            // If ??? break
    }
    // Thanks for playing bye.

}

static void playLocal()
{
    
    // Play Mode Select
    LocalPlayInput result = (LocalPlayInput)displayLocalSelectOpponent();
    if (result == PREVIOUS_MENU)
    {
        return;
    }
    
    
        // Request IO to display play mode select
            // If M, save state Multi-player
            // If S, save state Multi-player
            // Get player names
}

static void playNetwork()
{
    printf("Network Play has not been implemented.\n");
}