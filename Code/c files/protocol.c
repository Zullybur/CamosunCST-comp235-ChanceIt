#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "../interfaces/getCon.h"
#include "../interfaces/socket.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/probability.h"
#include "../interfaces/computerPlayer.h"

#define STOP        "stop\n"
#define YES         "Y\n"
#define NO          "n\n"
#define HELLO		"HELLO:\0"
#define BYE         "GOODBYE:\0"

//Check if the game is over
int gameOver(char* response) {
	printf("%s\n", response);
	readLine(response);
	printf("%s\n", response);
}

//Returns the name of the opponent
void whoIsOpp(char* lineBuffer, char* reply) {
	sscanf(lineBuffer, "Opponent: %c[16]", reply);
	reply[16] = '\0';
}

// Build the initial name submission for the server
char* buildName(char* helloName, char* localPlayer, unsigned length) {
    strlcpy(helloName, HELLO, length);
    //printf("TEST1: %s", helloName);
    strlcat(helloName, localPlayer, length);
    //printf("TEST2: %s", helloName);
    strlcat(helloName, "\n\0", length);
    //printf("TEST3: %s", helloName);
    return helloName;
}

// Get a player response
void getHumanResponse(char* printBuf) {
	char cmd;

	LOOP:cmd = getche();
	printf("\n");
	
	switch(cmd)
	{
		case 'Y':
		case 'y':
			// printf("Case: Y\n");
			sendToServer(YES);
			break;
		case 'N':
		case 'n':
			printf("Waiting for opponent... \n");
			sendToServer(NO);
			break;
		case 'S':
		case 's':
			// printf("Case: s\n");
			sendToServer(STOP);
			break;
		default:
			printf("Oops - want to give that another go, friend?\n");
			goto LOOP;
	}
}

//Begins the network game
void playNetwork(_Bool humanFactor, char* localPlayer) {
	char printBuf[30];
	unsigned firstRoll, die1, die2, evaSays;
	int goFirst;
	DecisionParams params;
	//char IP[45];
	int port;
	
	// Get server information
	//displayNetworkPlayInput(IP, &port);
	// TEST PURPOSES:
	char* IP = "52.38.98.137";
	port = 1092;

	//Connect to the server
	connectToServer(IP, port);

	// Calculate array length based on strings + 1, and an extra for \n
	unsigned length = strlen(HELLO) + 1 + strlen(localPlayer) + 1 + 1;
	char helloName[length];
	buildName(helloName, localPlayer, length);

	sendToServer(helloName);			//Send the register command

	readLine(printBuf);					//Receive IS IT ME YOU'RE LOOKING FOR
	printf("Waiting for opponent...\n\n");			//Print the received text
	readLine(printBuf);					//Receive Opponent: <name>
	// Save and print opponent name
	char oppName[17];
	whoIsOpp(printBuf, oppName);

	while(1)
	{
		//send the server a response
		if(!strncmp(printBuf, "chance-it?", 10))
		{
			if (humanFactor) {
				getHumanResponse(printBuf);
			} else {
			// 	printf("AI STATE:\nround: %u\nroll: %u\nturn score: %u\np1Score: %u\np2Score: %u\nprobability: %f\n", 
			// 		params.roundNumber, params.rollCounter, params.turnScore,
			// 		params.p1Score, params.p2Score, params.probability);

				if (getDecision(params) == 2) {
					printf("gonna say no to that\n");
					sendToServer(NO);
					printf("Waiting for opponent... \n");
				} else {
					printf("Eva wants your body...\n");
					sendToServer(YES);
				}
			}
		// Parse initial turn score
		} else if (!strncmp(printBuf, "Turn Starting Score: ", 21)) {
			sscanf(printBuf, "Turn Starting Score: %d[5]-%d[5]", &params.p1Score, &params.p2Score);
		// Parse game over line
		} else if (!strncmp(printBuf, "You Win!", 8) || !strncmp(printBuf, "You Lose", 8)) {
			gameOver(printBuf);	break;
		// Parse out turn number
		} else if (!strncmp(printBuf, "Turn#: ", 7)) {
			sscanf(printBuf, "Turn#: %d[2]", &params.roundNumber);
		// Parse out roll number
		} else if (!strncmp(printBuf, "Roll#: ", 7)) {
			sscanf(printBuf, "Roll#: %d[3]", &params.rollCounter);
		// Our dice roll
		} else if (!strncmp(printBuf, "You Rolled: ", 12)) {
			if (params.roundNumber == 1) {
				sscanf(printBuf, "You Rolled: [%d,%d]", &die1, &die2);
				firstRoll = die1 + die2;
				params.probability = getProbability(firstRoll);
			}
		// Parse out current round total
		} else if (!strncmp(printBuf, "Running Turn Score: ", 20)) {
			sscanf(printBuf, "Running Turn Score: %d[4]", &params.turnScore);
		}
		// printf("DEBUG: entering 'grab more lines'\n");
		readLine(printBuf);
		printf("%s\n", printBuf);
	}
	closeConnection();
}