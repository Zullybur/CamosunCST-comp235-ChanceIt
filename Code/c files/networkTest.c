#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "getCon.h"

#define MAXRCVLEN 	200
#define PORTNUM 	1099
#define IP_CONN 	"52.38.98.137"
#define STOP 		"stop\n"
#define YES 		"Y\n"
#define NO 		"n\n"
#define HELLO 		"HELLO:C\n"
#define BYE 		"GOODBYE:C\n"

char* readLine(char* text)
{
	
}

int main()
{
    char buffer[MAXRCVLEN];
    char wait[MAXRCVLEN];
    char turnOrder[MAXRCVLEN];
    char game[MAXRCVLEN];
    char chanceIt[MAXRCVLEN];
    char cmd;
    int len, mySocket;
    //int playing = 1;
    struct sockaddr_in dest; 

    mySocket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&dest, 0, sizeof(dest));				//zero the struct
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(IP_CONN);	//set destination IP number
    dest.sin_port = htons(PORTNUM);				//set destination port number
 
    connect(mySocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));

    send(mySocket, HELLO, sizeof(HELLO), 0);

	//Receive "IS IT ME YOU'RE LOOKIN FOR?"
	len = recv(mySocket, wait, MAXRCVLEN, 0);
	printf("%s", wait);

	//Receive "Opponent: [Opponent Name]"
	len = recv(mySocket, buffer, MAXRCVLEN, 0);
	printf("%s", buffer);

	//Receive "Your roll was: [Roll Number]. Opponent roll was: [Roll Number]. [Name] goes first"
	len = recv(mySocket, turnOrder, MAXRCVLEN, 0);
	printf("%s", turnOrder);
	
    if(turnOrder[15] > turnOrder[37])
    {
        cmd = getche();		
        if(cmd == 's')
        {
            if(send(mySocket, STOP, sizeof(STOP), 0) < 0)
			{
				printf("Send STOP error\n");
			}
			else
			{
				printf("STOP OCCURED IN IF\n");
				//playing = 0;
				close(mySocket);
			}
		}
        else if(cmd == 'y' || cmd == 'Y')
        {
            if(send(mySocket, YES, sizeof(YES), 0) < 0)
			{
				printf("Send YES error\n");
			}
			else
			{
				printf("YES OCCURED IN IF\n");
			}
        }
        else if(cmd == 'n' || cmd == 'N')
        {
            if(send(mySocket, NO, sizeof(NO), 0) < 0)
			{
				printf("Send NO error\n");
			}
			else
			{
				printf("NO OCCURED IN IF\n");
			}
        }
    }
    
    //Receive Turn information
    while(1)
    {
	    /* 
		Receive
		Turn Starting Score: [Score]-[Opponent Score]
		Turn#: [Turn Number]
		Roll#: [Roll Number]
		You Rolled: [[Roll 1], [Roll 2]]
		Running Turn Score: [Total Turn Score]
		--
		*/
		len = recv(mySocket, game, MAXRCVLEN, 0);
		printf("%s", game);
	
		//Receive "chance-it? [Y/n]"
		len = recv(mySocket, chanceIt, MAXRCVLEN, 0);
		printf("%s", chanceIt); 
		
        cmd = getche();
	printf(YES);
	printf(NO);		
        if(cmd == 's')
        {
            if(send(mySocket, STOP, sizeof(STOP), 0) < 0)
			{
				printf("Send STOP error\n");
			}
			else
			{
				close(mySocket);
				break;
			}
        }
        else if(cmd == 'y' || cmd == 'Y')
        {
            if(send(mySocket, YES, sizeof(YES), 0) < 0)
			{
				printf("Send YES error\n");
			}
			else
			{
				printf("YES OCCURED IN LOOP\n");
			}
        }
        else if(cmd == 'n' || cmd == 'N')
        {
            if(send(mySocket, NO, sizeof(NO), 0) < 0)
			{
				printf("Send NO error IN LOOP\n");
			}
			else
			{
				printf("NO OCCURED IN LOOP\n");
			}
        }

    }
    //close(mySocket);
    return 1;
}
