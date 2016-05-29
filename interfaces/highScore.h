// Pre: a file for highscore exists
// Post: The highscore was displayed on screen
// Clean up: N/A
// Param N/A
// returns N/A
 void getHighScore();

// Pre: a file for highscore exists
// Post: The highscore has been amended with new information, if necessary
// Clean up: N/A
// Param:  name a pointer to the player's name
// Param:  date a pointer to the date of the game play
// Param:  score takes in the value of the player’s score 
// Returns: N/A
void amendHighScore(char* name, char* date, unsigned score);