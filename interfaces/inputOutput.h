#include<stdio.h>

/*Pre-condition: N/A
 *Post-condition: The screen was updated to display new information
 *Clean up: N/A
 *Param name, userSelection 
 *returns N/A
 */
void dispGamePlay(char *name, int userSelection); 

/*Pre-condition: A highscore file exists
 *Post-condition: The highscore was displayed on the screen
 *Clean up: N/A
 *Param N/A
 *returns N/A
 */
void dispHighScore();

/*Pre-condition: N/A
 *Post-condition: The main menu was displayed on the screen
 *Clean up: N/A
 *Param N/A
 *returns N/A
 */
void dispMainMenu();

/*Pre-condition: N/A
 *Post-condition: The help menu was displayed on the screen
 *Clean up: N/A
 *Param N/A
 *returns N/A
 */
void dispHelpMenu();

/*Pre-condition: N/A
 *Post-condition: The Network Play Mode was displayed on screen
 *Clean up: N/A
 *Param name player's name for screen display
 *Param name player's score 
 *returns N/A
 */
void dispNetworkPlayMode(char *name, unsigned score)

/*Pre-condition: N/A
 *Post-condition: The prompt for Network information was displayed on screen
 *Clean up: N/A
 *Param N/A
 *returns IPaddress and port to connect to the network protocol 
 */
char dispNetWorkPlayInput()

/*Pre-condition: N/A
 *Post-condition: The Local Play Mode was displayed on screen
 *Clean up: N/A
 *Param name player's name is displayed during play mode
 *Param score score is displayed on screen
 *returns N/A
 */
void dispLocalPlayMode(char* name, unsigned score)

/*Pre-condition: N/A
 *Post-condition: The menu for game help was displayed on screen
 *Clean up: N/A
 *Param N/A
 *returns N/A
 */
void dispInGameHelpMenu()
