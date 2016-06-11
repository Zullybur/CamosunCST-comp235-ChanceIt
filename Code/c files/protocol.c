#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
<<<<<<< HEAD
#include "../interfaces/getCon.h"
#include "../interfaces/socket.h"
#include "../interfaces/inputOutput.h"
=======
#include "getCon.h"
#include "socket.h"
>>>>>>> 1052d38659df739359478b2b97eeb77cf5782dcf

#define STOP        "stop\n"
#define YES         "Y\n"
#define NO          "n\n"
#define HELLO		"HELLO:\0"
#define BYE         "GOODBYE:\0"

//Check if the game is over
int isGameOver(char* response) {
	if(strncmp(response, "You Win!", 8) == 0 || strncmp(response, "You Lose", 8) == 0)
	{
		return 1;
	}
	return 0;
}

//Returns the name of the opponent
char* whoIsOpp(char* lineBuffer) {
	char* reply;
	sscanf(lineBuffer, "Opponent: %s", reply);
	return reply;
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

//Begins the network game
void playNetwork(_Bool humanFactor, char* localPlayer) {
	char printBuf[30];
	char* oppName;
	char cmd;
	int goFirst;
	char IP[45];
	int port;
	
	// Get server information
	displayNetworkPlayInput(IP, &port);

	//Connect to the server
	connectToServer(IP, port);

	// Calculate array length based on strings + 1, and an extra for \n
	unsigned length = strlen(HELLO) + 1 + strlen(localPlayer) + 1 + 1;
	char helloName[length];
	buildName(helloName, localPlayer, length);

	sendToServer(helloName);			//Send the register command

	readLine(printBuf);					//Receive from server
	printf("%s\n", printBuf);			//Print the received text
	readLine(printBuf);
	
	while(1)
	{
		//send the server a response
		if(!strncmp(printBuf, "chance-it?", 10))
		{
			printf("%s\n", printBuf);
			printf("\n");
			cmd = getch();
			
			switch(cmd)
			{

				case 'y':
					sendToServer(YES);
					break;
				case 'n':
					sendToServer(NO);
					break;
				case 's':
					
				default:
					sendToServer(STOP);
					break;
			}
		}
		//Print the game over message
		else if(isGameOver(printBuf))
		{
			printf("%s\n", printBuf);
			readLine(printBuf);
			printf("%s\n", printBuf);
			break;
		}
		//Get the opponent name
		else if(!strncmp(printBuf, "Opponent:",9)){
			printf("%s\n", printBuf);
			oppName = whoIsOpp(printBuf);
		}
		//Print lines
		else
		{
			printf("%s\n", printBuf);
		}
		readLine(printBuf);
	}
	closeConnection();
}