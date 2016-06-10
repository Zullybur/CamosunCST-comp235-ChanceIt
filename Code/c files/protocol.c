#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "getCon.h"
#include "socket.h"

#define PORTNUM     1092
#define IP_CONN     "52.38.98.137"
#define STOP        "stop\n"
#define YES         "Y\n"
#define NO          "n\n"
#define HELLO       "HELLO:John Malkovich\n"
#define BYE         "GOODBYE:John Malkovich\n"

//Check if the game is over
int isGameOver(char* response)
{
	if(strncmp(response, "You Win!", 8) == 0 || strncmp(response, "You Lose", 8) == 0)
	{
		return 1;
	}
	return 0;
}

//Returns the name of the opponent
char* whoIsOpp(char* lineBuffer)
{
	char* reply;
	sscanf(lineBuffer, "Opponent: %s", reply);
	return reply;
}

//Begins the network game
int main()
{
	char printBuf[30];
	char* oppName;
	char cmd;
	int goFirst;
	connectToServer(IP_CONN, PORTNUM);	//Connect to the server
	sendToServer(HELLO);				//Send the register command
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