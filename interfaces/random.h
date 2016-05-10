#import <stdbool.h>
// Generate a randomized double value between the given parameters
// Pre: randomInit has been called, and min < max
// Post: N/A
// Returns: a double in the set [min, max)
double getRandomDouble(double min, double max);

// Generate a randomized integer value between the given parameters
// Pre: randomInit has been called, and min < max
// Post: N/A
// Returns: an integer in the set [min,max)
int getRandomInt(int min, int max);

// Generate a random double value as a percent of 1
// Pre: randomInit has been called
// Post: N/A
// Returns: a double in the set [0,1]
double getRandomPercent();

// Randomly generate a true or false response
// Pre: N/A
// Post: N/A
// Returns 0 for false or 1 for true as a _Bool data type
_Bool getRandomBool();

// Initializes the random class
// Pre: N/A
// Post: N/A
void randomInit();