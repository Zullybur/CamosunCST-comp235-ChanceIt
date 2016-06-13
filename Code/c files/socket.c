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

#define BUFF_SIZE 1024

static int mySocket;
static char buffer[BUFF_SIZE];
static int buf_pos = 0;
static int buf_max = 0;

//Connect to the server with the provided IP and port
void connectToServer(char* ip, int port)
{
	struct sockaddr_in dest; 

    mySocket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&dest, 0, sizeof(dest));             //zero the struct
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(ip);  		//set destination IP number
    dest.sin_port = htons(port);             //set destination port number
	
	connect(mySocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
}

//Send the provided string to the server
int sendToServer(char* msg)
{
	if(send(mySocket, msg, strlen(msg),0) < 0)
	{
		return 0;
	}
	return 1;
}

//Receive data from the server
int readLine(char* lineBuffer)
{
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

//Close the socket
void closeConnection()
{
	close(mySocket);
}