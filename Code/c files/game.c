#include "../interfaces/inputOutput.h"
#include "../interfaces/localTurn.h"

enum typdef
{
    UNASSIGNED,
    PLAY_LOCAL,
    PLAY_NETWORK,
    SHOW_RULES,
    HIGH_SCORES,
    EXIT_GAME
} MainMenu;
// Initiate a new game of Chance-It
// Pre: randomInit() has been called once
// Post: N/A
// Clean-Up: N/A
// Param: player is a pointer to an unsigned variable
// Return: the winning score of the game
unsigned gameInit()
{

    // Main Menu Loop
    while (true)
    {
        // Request IO to display main menu
        MainMenu result = (gameType)displayMainMenu();

        switch (result)
        {
            case 
            case LOCAL:

                break;
            case NETWORK:

                break;
            default:
                printf("Sanity check failed - game:gameInit:displayMainMenu:switch");
                sys.exit(1);

        }
        // If R, request rules page, continue
        // If V, request high-score page, continue
        // If L, save state (Play Mode: local)
        // If N, save state (Play Mode: network)
        // IF E, return

        // Play Mode Select
            // Request IO to display play mode select
                // If M, save state Multi-player
                // If S, save state Multi-player
                // Get player names

        // While turns < 20, run turns
            // If F, break

        // Display win/lose page
            // If ??? continue
            // If ??? break
    }
    // Thanks for playing bye.

}