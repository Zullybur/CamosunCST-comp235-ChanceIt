// Generate a randomized integer value between the given parameters
// Pre: randomInit has been called once, and min < max
// Post: N/A
// Clean-Up: N/A
// Returns: an integer in the set [min,max]
int getRandomInt(int min, int max);

// Initializes the random module, must be called before any other functions 
// Pre: N/A
// Post: N/A
// Clean-Up: N/A
void randomInit();
