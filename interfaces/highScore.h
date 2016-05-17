#include<stdio.h>

/*Pre-condition: a file for highscore exists
 *Post-condition: The highscore was displayed on screen
 *Clean up: N/A
 *Param N/A
 *returns N/A
 */

 void getHighScore(char info);

/*Pre-condition: a file for highscore exists
 *Post-condition: The highscore has been amended with new information
 *Clean up: N/A
 *Param  name takes in the name of the player
 *Param  date   takes in the date of the game play
 *Param score   takes in the player’s score 
 *returns N/A
 */

 void amendHighScore(char* name, char* date, unsigned score);
