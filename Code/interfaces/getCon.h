// Sets up new terminal settings
// Pre: N/A
// Post: New terminal settings are set up
// Return N/A
// Cleanup: Call resetTermios() to reset terminal settings
void initTermios(int echo);

// Resets the terminal settings to the previous settings
// Pre: N/A
// Post: Terminal settings are reset
// Return N/A
// Cleanup N/A
void resetTermios(void);

// Gets a single char from the terminal
// Pre: N/A
// Post: N/A
// Param echo 1 for echo on 0 for echo off
// Return the char from the terminal
// Cleanup N/A
char getch_(int echo);

// Calls getch_ with echo on
// Pre: N/A
// Post: N/A
// Return The char from the terminal
// Cleanup N/A
char getch(void);

// Calls getch_ with echo off
// Pre: N/A
// Post: N/A
// Return the char from the terminal
// Cleanup N/A
char getche(void);