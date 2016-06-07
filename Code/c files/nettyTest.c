#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "getCon.h"

#define MAXRCVLEN       1
#define PORTNUM         1099
#define IP_CONN         "52.38.98.137"
#define STOP            "stop\n"
#define YES             "y\n"
#define NO                      "n\n"
#define HELLO           "HELLO:C\n"
#define BYE             "GOODBYE:C\n"
#define REPLY_LEN	3000

int main()
{
    char buffer[MAXRCVLEN];
    char wait[MAXRCVLEN];
    char turnOrder1[MAXRCVLEN];
    char turnOrder2[MAXRCVLEN];
    char turnOrder3[MAXRCVLEN];
    char game[MAXRCVLEN];
    char chanceIt[MAXRCVLEN];
    char cmd;
    char myRoll;
    char opRoll;
    char server_reply[REPLY_LEN];
    int len, mysocket;
    int playing = 1;
    struct sockaddr_in dest;

    mysocket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&dest, 0, sizeof(dest));                             //zero the struct
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(IP_CONN);  //set destination IP number
    dest.sin_port = htons(PORTNUM);                             //set destination port number

    connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
    send(mysocket,HELLO, sizeof(HELLO), 0);

    len = recv(mysocket, server_reply, REPLY_LEN, 0);
    printf("Should print IS IT ME...\n");
    puts(server_reply);

   

    len = recv(mysocket, server_reply,REPLY_LEN, 0);
    printf("Should print Opponent roll");
    puts(server_reply);

}
