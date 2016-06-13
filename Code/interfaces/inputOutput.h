typedef struct DisplayTurn{
	char* p1Name;
	unsigned p1Score;
	unsigned firstRoll;
	unsigned rollCounter;
	unsigned roundScore;
	unsigned die1;
	unsigned die2;
	unsigned turnScore;
	char* p2Name;
	unsigned p2Score;
	_Bool activePlayer;
	unsigned turnCounter;
} DisplayTurn;


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
// Returns: 1 for roll, 2 for stop, 3 for probability, 4 for help, 0 for forfeit
unsigned displayTurn(DisplayTurn turn);

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
void displayNetworkPlayInput(char* IPaddress, int* port);

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
// Param: For twoPlayer param, pass 0 for singleplayer 
// Returns: N/A
void displayLocalPlayGetName(char* player1, char* player2, _Bool opponentHuman);

// Pre: N/A
// Post: The menu for in-game help was displayed on screen
// Clean-Up: N/A
// Param N/A
// Returns N/A
void displayInGameHelpMenu();


// Pre: N/A
// Post: The menu for in-game help was displayed on screen
// Clean-Up: N/A
// Param N/A
// Returns N/A
void displayProbability();

//Pre: N/A
//Post: Dice are displayed on screen
//Cleanup: N/A
//Params: Two unsigned numbers that are >= 1 && =< 6
//Return: N/A
void printDie(unsigned die1, unsigned die2);

//Pre: N/A
//Post: fail message is displayed to screen
//Clean-up: N/A
//Params: active player name, an unsigned int >= 1 && =< 6 and the name of the inactive player
//Return: N/A
void displayFailRoll(char* playerName, unsigned firstRoll, char* opponentName);

//Pre: N/A
//Post: stop round screen is displayed
//Clean-up: N/A
//Params: active player name, an unsigned int representing score for the round and the name of the inactive player
//Return: N/A
void displayStopTurn(char* playerName, unsigned score, char* opponentName);

//Pre: N/A
//Post: Endgame screen is displayed
//Clean-up: N/A
//Params: first player name, their int score, their opponent's name, opponent's score
//Return: N/A
void endGameScreen(char* playerName, unsigned p1Score, char* opponentName, unsigned opScore, _Bool isHighscore);
