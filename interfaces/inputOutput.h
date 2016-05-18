// Pre: N/A
// Post: The screen was updated to display new information
// Clean-Up: N/A
// Param: name is a pointer to player's name
// Param: firstRoll displays the value of the firstRoll
// Param: round displays the number of round 
// Param: roundScore displays the current round score
// Param: die1 displays the first die
// Param: die1 displays the second die
// Param: score displays the player's score
// Param: opponentScore displays the opponent's score
// Returns: 1 for roll, 2 for stop, 3 for probably, 4 for help, 0 for forfeit
void displayTurn(char* name, unsigned firstRoll, unsigned round, unsigned roundScore, unsigned die1, unsigned die2, unsigned score, unsigned opponentScore); 

// Pre: N/A
// Post: The rules was displayed on the screen
// Clean-Up: N/A
// Param N/A
// Returns N/A
void displayRules();


// Pre: A highscore file exists
// Post: The highscore was displayed on the screen
// Clean-Up: N/A
// Param N/A
// Returns N/A
void displayHighScore();

// Pre: N/A
// Post: The main menu was displayed on the screen and the user selected a game		type
// Clean-Up: N/A
// Param N/A
// Returns: 1 for local play, 2 for network play 
unsigned displayMainMenu();

// Pre: N/A
// Post: The Network Selection Mode was displayed on screen
// Clean-Up: N/A
// Param: N/A
// Returns: 1 for human player, 2 for computer player, 0 to previous menu
unsigned displayNetworkSelectMode();

// Pre: N/A
// Post: The prompt for network information was displayed on screen, and IPaddress and port variables were updated
// Clean-Up: N/A
// Param: IPaddress pointer to the variable holding the ipaddress 
// Param: port pointer to the variable holding the port
// Returns: N/A
void displayNetWorkPlayInput(char* IPaddress, unsigned* port);

// Pre: N/A
// Post: The Local Play mode was displayed on screen
// Clean-Up: N/A
// Param: N/A
// Returns: 1 for single player, 2 for multiplayer, 0 to return to previous menu
unsigned displayLocalSelectOpponent();

// Pre: N/A
// Post: The player names were assigned to the given char* 
// Clean-Up: N/A
// Param: player1 is a pointer to player 1's name
// Param: player2 is a pointer to player 2's name
// Returns: N/A
void displayLocalPlayGetName(char* player1, char* player2);


// Pre: N/A
// Post: The menu for in-game help was displayed on screen
// Clean-Up: N/A
// Param N/A
// Returns N/A
void displayInGameHelpMenu();
