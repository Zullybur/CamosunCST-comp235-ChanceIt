#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../interfaces/getCon.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/probability.h"

#define FILEPATH	"../../Design Documents/UserManual/"
#define PRINT_LIM1	18
#define MAX_NAME_LEN 	17
#define MAX_LINE_LEN 	50
//#define MAX_RESP_LEN 	1
#define MAX_IP_LEN 	45
#define MAX_PORT_LEN 	5
#define NULL_TERM	'\0'

void displayLocalPlayGetName(char* player1, char* player2,_Bool opponentHuman)
{
	char strName1[MAX_NAME_LEN], strName2[MAX_NAME_LEN];
	unsigned i;
	
	printf("Local Play Mode \n -----------------------------\n");
	printf("Player 1 - enter name: \n");
	scanf("%16s", strName1);

	for(i = 0 ; i < strlen(strName1); i++)
	{
		player1[i] = strName1[i];
	}

	player1[i] = NULL_TERM;
 
	if (opponentHuman)
	{
		printf("Player 2 - enter name: \n");
		scanf("%16s",strName2);
		printf("\n -----------------------------\n");

		for(i = 0 ; i < strlen(strName2); i++)
		{
			player2[i] = strName2[i];
		}
		player2[i] = NULL_TERM;
	}
	system("clear");
	
}

void displayRules()
{
	FILE *fp;
	unsigned i = 0;
	
	char fileP[] = FILEPATH "rules.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];

		
	for(i = 0; i <= PRINT_LIM1; i++ )
	{
		fgets(buff,MAX_LINE_LEN, (FILE*)fp);
		printf("%s", buff);
	}

	char response;
	response = getch();
		
	while(feof(fp) == 0)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%s", buff);
	}
	
	response = getch();	
	system("clear");
	
	//if (response == "\n")
	//{
		//fclose(fp);
		//system("clear");
	//} 
	
	//else if (toupper(response[0]) == "R")
	//{
		//fclose(fp);
		//system("clear");
		//displayRules();	
	//}
	//TALK TO TEAMMEMBERS ABOOT DISPLAY RULES AGAIN WITH R			
	
}

unsigned displayMainMenu()
{

	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-MainPage.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	
	while(feof(fp) == 0)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%s",buff);
	}	
	
	while (1)
	{
		char response;
		response = getch();
		unsigned retVal = 0;

		//POSSIBLE ERROR WITH VALIDATION
		switch(response){
			case 'L':
			case 'l':
				system("clear");
				fclose(fp);
				retVal = 1;
				return retVal;
			case 'N':
			case 'n':
				system("clear");
				fclose(fp);
				retVal = 2;
				return retVal;			
			case 'V':
			case 'v':
				system("clear");
				fclose(fp);
				exit(0); //TO BE IMPLEMENTED
			case 'R':
			case 'r'://DO WE WANNA RETURN A NUMBER VALUE FOR THIS AS WELL?
				system("clear");
				fclose(fp);
				retVal = 3;
				return retVal;
			case 'E':
			case 'e'://IS THIS THE FUNCTION THAT WILL EXIT THE PROGRAM
				fclose(fp);
				system("clear");
				exit(0);
			default: 
				printf("\nPlease enter a proper selection: ");

		}
	}
}

unsigned displayLocalSelectOpponent()
{
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-LocalPlay.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	
	while(feof(fp) == 0)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%s",buff);
	}	
	
	while(1)
	{
		char response;
		response = getch();
		unsigned retVal = 0;

		//POSSIBLE ERROR WITH VALIDATION
		switch(response){
			case 'S':
			case 's':
				system("clear");
				fclose(fp);
				retVal = 1;
				return retVal;
			case 'M':
			case 'm':
				system("clear");
				fclose(fp);
				retVal = 2;
				return retVal;			
			case 'P':
			case 'p':
				system("clear");
				fclose(fp);
				retVal = 0;
				return retVal;
			case 'E':
			case 'e':
				fclose(fp);
				system("clear");
				exit(0);
			default: 	
				printf("\nPlease enter a proper selection: ");
		}
	}
}

unsigned displayNetworkSelectMode()
{
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-NetworkPlay.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];

	while(feof(fp) == 0)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%s",buff);
	}	
	
	while (1)
	{
		char response;
		response = getch();
		unsigned retVal;
		
		switch(response){
			case 'H':
			case 'h':
				system("clear");
				fclose(fp);
				retVal = 1;
				return retVal;
			case 'C':
			case 'c':
				system("clear");
				fclose(fp);
				retVal = 2;
				return retVal;			
			case 'P':
			case 'p':
				system("clear");
				fclose(fp);
				retVal = 0;
				return retVal;
			case 'E':
			case 'e':
				fclose(fp);
				system("clear");
				exit(0);	
			default: 
				printf("\nPlease enter a proper selection: ");
		
		}
	}
}

void displayInGameHelpMenu() //Work in progress
{
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-GameHelp.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];

	while(feof(fp) == 0)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%s",buff);
	}	
	
	char response;
	response = getch();
	fclose(fp);
}

void displayNetworkPlayInput(char* IPaddress, unsigned* port)
{
	
	char strPort[5];
	char *strIP = (char*)calloc(MAX_IP_LEN, sizeof(char));
	unsigned i;
	
	printf("Network Play Mode \n -----------------------------\n");
	printf("Enter Server Information: \n Port: \n");
	scanf("%s", strPort);
	
	printf("Address: \n");
	scanf("%s", strIP);
	printf("\n -----------------------------\n");
	
	for (i = 0; i < strlen(strIP) + 1; i++)
	{
		IPaddress[i] = strIP[i];
	}
	
	free(strIP);
	*port = atoi(strPort);
	
}


unsigned displayTurn(char* p1Name,unsigned p1Score,unsigned firstRoll, unsigned rollCounter, unsigned roundScore,
                              unsigned die1, unsigned die2, unsigned turnScore, char* p2Name, unsigned p2Score, _Bool activePlayer)
{
	printf("Active Player: %s\n", (activePlayer ? p2Name : p1Name));
	printf("Current Round: %u \n", rollCounter);
	printf("-----------------------------\n");
	printf("First roll: %u \n", firstRoll);
	printf("Turn score: %u \n\n", turnScore);
	printf("You rolled: %u + %u = %u \n\n PLACE HOLDER HERE. SORRY, NO DICE. \n\n", die1, die2, roundScore);
    printf("%s, score: %u \n", p1Name, p1Score);
    printf("%s, score: %u \n", p2Name, p2Score);
	printf("-----------------------------\n");
	
	printf("(R)oll \n");
	printf("(S)top \n");
	printf("(P)robability \n\n");
	printf("(H)elp \n");
	printf("(F)orfeit \n");
	
	while (1)
	{
		char response;
		response = getch();
		unsigned retVal;
		
		//POSSIBLE ERROR WITH VALIDATION
		//charAt[0] then cast to an integer to use in the switch statement
		//char respVal = response;
		
		switch(response){
			case 'R':
			case 'r':
				system("clear");
				retVal = 1;
				return retVal;
			case 'S':
			case 's':
				system("clear");
				retVal = 2;
				return retVal;			
			case 'P':
			case 'p':
				system("clear");
				retVal = 3;
				return retVal;
			case 'H':
			case 'h':
				system("clear");
				retVal = 4;
				return retVal;
			case 'F':
			case 'f':
				system("clear");
				retVal = 0;
				return retVal;
			default: 
				printf("\nPlease enter a proper selection: ");
		}
	}
}

void displayProbability(double result){
	char response;
	printf("Probablity is :%f\n\n",result);
	printf("Please press ENTER to go back to Game");
	response = getch();
}
