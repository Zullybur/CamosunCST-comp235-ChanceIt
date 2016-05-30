#include "../interfaces/random.h"
#include "../interfaces/dice.h"
#define MIN    1
#define MAX    6

int rollDice(){
    int rollNum = getRandomInt(MIN, MAX);
    return rollNum;
}