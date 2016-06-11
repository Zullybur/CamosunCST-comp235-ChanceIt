#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "getCon.h"

#define BUFF_SIZE   1024
#define PORTNUM     1099
#define IP_CONN     "52.38.98.137"
#define STOP        "stop\n"
#define YES         "Y\n"
#define NO          "n\n"
#define HELLO       "HELLO:John Malkovich\n"
#define BYE         "GOODBYE:John Malkovich\n"

static int mySocket;
static char buffer[BUFF_SIZE];
static int buf_pos = 0;
static int buf_max = 0;
static int goFirst;

void connectToServer()
{
	struct sockaddr_in dest; 

    mySocket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&dest, 0, sizeof(dest));             //zero the struct
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(IP_CONN);  //set destination IP number
    dest.sin_port = htons(PORTNUM);             //set destination port number
	
	connect(mySocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
}

void registerWithServer()
{
	send(mySocket, HELLO, sizeof(HELLO), 0);
}

void unregisterWithServer()
{
	send(mySocket, BYE, sizeof(BYE), 0);
}

void writeToServer()
{
	char cmd = getche();
	
	switch(cmd)
	{
		case 'y':
		send(mySocket, YES, sizeof(YES),0);
		
		case 'n':
		send(mySocket, NO, sizeof(NO),0);
		
		case 's':
		send(mySocket, STOP, sizeof(STOP),0);
	}
	
}

int readLine(char* lineBuffer)
{
	/*
	buf_max += recv(mySocket, buffer, BUFF_SIZE, 0);
	
	if(strncmp(buffer, "IS IT", 5) == 0)
	{
		printf("%s", buffer);
	}
	else if(strncmp(buffer, "Opponent", 8) == 0)
	{
		printf("%s", buffer);
	}
	else if(strncmp(buffer, "Your", 4) == 0)
	{
		int myScore;
		int opScore;
		sscanf(buffer, "%d %d", myScore, opScore);
		if (myScore > opScore)
		{
			goFirst = 1;
		}
		else
		{
			goFirst = 0;
		}
		printf("%s", buffer);
	}
	else if(strncmp(buffer, "Turn", 4))
	{
		printf("%s", buffer);
	}
	*/
	int i = 0;
	while(buf_pos < buf_max)
	{
		if(buffer[buf_pos] == '\n')
		{
			lineBuffer[i] = '\0';
			buf_pos++;
			return i;
		}
		else
		{
			lineBuffer[i++] = buffer[buf_pos++];
		}
	}
	buf_max = recv(mySocket, buffer, 1024, 0);
	buf_pos = 0;
	return (i + readLine(&lineBuffer[i]));
}

int main()
{
char lineBuffer[1024];
connectToServer();
registerWithServer();
readLine(lineBuffer);
printf("%s", lineBuffer);
close(mySocket);
}
