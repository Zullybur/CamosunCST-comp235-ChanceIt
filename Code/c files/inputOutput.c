#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../interfaces/getCon.h"
#include "../interfaces/inputOutput.h"
#include "../interfaces/probability.h"

#define SCORE_BORDER	"----------------------------------"
#define FILEPATH	"../../Design Documents/UserManual/"
#define SCORE_FILEPATH  "../../Design Documents/highScore.txt"
#define PRINT_LIM1	18
#define MAX_NAME_LEN 	17
#define MAX_LINE_LEN 	50
#define MAX_BUFF	2000
//#define MAX_RESP_LEN 	1
#define MAX_IP_LEN 	45
#define MAX_PORT_LEN 	5
#define NULL_TERM	'\0'


void displayStopTurn(char* playerName, unsigned score, char* opponentName)
{
	system("clear");

	printf("--------------------\n");
	printf("%s like the noble Kenny Rogers, you knew to fold em' rather than hold em'.\n", playerName);
	printf("Your score for the round is %u.\n\n",score);
	printf("%s, hopefully you can show a modicum of judgement on your turn.\n",opponentName);
	printf("Press the any key to continue...\n");
	printf("--------------------\n");

	char response;
	response = getch();

}

void displayFailRoll(char* playerName, unsigned firstRoll, char* opponentName)
{

	system("clear");
	
	printf("--------------------\n");
	printf("%s like Icarus, your hubris has cost you dearly.\n", playerName);
	printf("You have re-rolled your first roll:  %u \n\n",firstRoll);
	printf("Your score for the round is ZERO. Do not pass go, do not collect $200.\n\n");
	printf("It is now %s's turn. Do not repeat the mistakes of your opponent.\n",opponentName);
	printf("Press any key to continue...\n");
	printf("--------------------\n");

	char response;
	response = getch();

}

void displayLocalPlayGetName(char* player1, char* player2,_Bool opponentHuman)
{

	system("clear");
	char input;
	unsigned i;
	
	printf("Local Play Mode \n -----------------------------\n");
	printf("Player 1 - enter name: \n");
	//scanf("%16s", strName1);

	for (i = 0; i < MAX_NAME_LEN - 1; i++)
	{ 
		input = getc(stdin);
		if (input == '\n') {
			// End of input
			break;
		}
		player1[i] = input;
		
	}
	if (input != '\n')
	{
		char tmp;
		do {
			tmp = getc(stdin);
		} while (tmp != '\n' && tmp != EOF);
	}
	
	player1[i] = NULL_TERM;
 
	if (opponentHuman)
	{
		printf("Player 2 - enter name: \n");
		//scanf("%16s",strName2);
		for (i = 0; i < MAX_NAME_LEN - 1; i++)
		{	
			
			input = getc(stdin);
			if (input == '\n') 
			{
				// End of input
				break;
			}
			player2[i] = input;
		}
		if (input != '\n')
		{
			char tmp;
			do {
				tmp = getc(stdin);
			} while (tmp != '\n' && tmp != EOF);
		}		
		
		printf("\n -----------------------------\n");
		player2[i] = NULL_TERM;
	}
	system("clear");
	
}

void displayRules()
{

	system("clear");
	FILE *fp;
	unsigned i = 0;
	
	char fileP[] = FILEPATH "rules.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	int c;
		
	for(i = 0; i < PRINT_LIM1; i++ )
	
	{
		fgets(buff,MAX_LINE_LEN, (FILE*)fp);
		printf("%s", buff);
	}

	char response;
	response = getch();
	
	
	while((c = fgetc(fp)) != EOF)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%c%s", c,buff);
	}
	fclose(fp);	
	response = getch();	
	system("clear");
	
	
}

unsigned displayMainMenu()
{
	system("clear");

	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-MainPage.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	int c;	

	while((c = fgetc(fp)) != EOF)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%c%s",c,buff);
	}	
	printf("\n");
	
	while (1)
	{
		char response;
		response = getch();
		unsigned retVal = 0;

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
				retVal = 4;
				return retVal;
			case 'R':
			case 'r':
				system("clear");
				fclose(fp);
				retVal = 3;
				return retVal;
			case 'E':
			case 'e':
				fclose(fp);
				system("clear");
				exit(0);
			default: 
				printf("Please enter a proper selection: \n");

		}
	}
}

void displayHighScore()
{

		
	system("clear");

	
	FILE *fp;
	fp = fopen(SCORE_FILEPATH, "r");
        char buff[MAX_BUFF];
        int c, i;
	//char *displayName = calloc(16,sizeof(char));
	//char *displayScore = calloc(4,sizeof(char));
	//char *displayDate = calloc(11,sizeof(char));
	
	printf("Top Ten Scores\n%s\n",SCORE_BORDER);
	
        while((c = fgetc(fp)) != EOF)
        {

		fgets(buff,32,(FILE*)fp);
		//displayName[0] = c;
		printf("|%c", c);
		for (i = 1; i < 16;i++)
		{
			
			if (buff[i - 1] == NULL_TERM)
			{
				printf(" ");
			} else 
			{
				printf("%c", buff[i]);
			}
			
			//printf(" ");
		}

		printf("|");

		fgets(buff,12,(FILE*)fp);
		for (i = 0; i < 4; i++)
		{
			
			if (buff[i] == NULL_TERM)
			{
				printf(" ");
			} else
			{
				printf("%c",buff[i]);
			}
			
			//printf(" ");
		}	
		
		printf("|");
		fgets(buff,26, (FILE*)fp);

		for (i = 0; i < 11; i++)
		{
			//printf(" ");
			
			if (buff[i] == NULL_TERM)
			{
				printf(" "); 
			} else 
			{
				printf("%c",buff[i]);
			}
			
		}
		printf("|\n");			

        }
	printf("%s\n",SCORE_BORDER);
	printf("Press any key to return to previous screen\n");
	char response;
        response = getch();
        fclose(fp);
	/*

	FILE *f;
        if( access( "../../Design Documents/highScore.txt", F_OK) != -1){
                printf(" Top Ten Scores\n");
                printf("--------------------------------------------\n");
                f = fopen("../../Design Documents/highScore.txt", "r");
                int i;
                for (i = 1; i <= 10; i++){
                        if (feof(f))
			{
				break;
			}
			
			char name[50] = {0};
                        fscanf(f, "%s", name);
                        char date[50] = {0};
                        fscanf(f, "%s", date);
                        char score[50] = {0};
                        fscanf(f, "%s", score);
                        //if (feof(f)){
                          //      break;
                        //}
                        printf(" %d%s| %s | ",i, (i < 10 ? "  " : " "), date);
                        int j = 0;
                        for (; j < 16 && name[j]; j++){
                                printf("%c", name[j]);
                        }
                        for (; j < 16; j++){
                                printf(" ");
                        }
                        printf(" | %s\n", score);
                }
                printf("--------------------------------------------\n");
                printf("Press Enter to return to the Main Menu.\n");
                fclose(f); 	
	}
	*/
}

unsigned displayLocalSelectOpponent()
{
	system("clear");
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-LocalPlay.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	int c;	

	while((c = fgetc(fp)) != EOF)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%c%s",c,buff);
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
				printf("Please enter a proper selection: \n");
		}
	}
}

unsigned displayNetworkSelectMode()
{

	system("clear");
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-NetworkPlay.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	int c;
	
	while((c = fgetc(fp)) != EOF)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%c%s",c,buff);
	}

	printf("\n");	
	
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
				printf("Please enter a proper selection: \n");
		
		}
	}
}

void displayInGameHelpMenu() //Work in progress
{

	system("clear");
	FILE *fp;
	char fileP[] = FILEPATH "UM-SS-GameHelp.txt";
	fp = fopen(fileP, "r");
	char buff[MAX_LINE_LEN];
	int c;

	while((c = fgetc(fp)) != EOF)
	{
		fgets(buff,MAX_LINE_LEN,(FILE*)fp);
		printf("%c%s",c,buff);
	}	
	printf("\n");	
	char response;
	response = getch();
	fclose(fp);
}

void displayNetworkPlayInput(char* IPaddress, unsigned* port)
{

	system("clear");
	
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
                              unsigned die1, unsigned die2, unsigned turnScore, char* p2Name, unsigned p2Score, _Bool activePlayer, unsigned turnCounter)
{
	system("clear");
	printf("Active Player: %s\n", (activePlayer ? p2Name : p1Name));
    	printf("Current Round: %u/20 \n", turnCounter);
	printf("Current Roll: %u \n", rollCounter);
	printf("-----------------------------\n");
	printf("First roll: %u \n", firstRoll);
	printf("Turn score: %u \n\n", turnScore);
	printf("You rolled: %u + %u = %u \n\n PLACE HOLDER HERE. SORRY, NO DICE. \n\n", die1, die2, roundScore);
  	
	//switch(die1)
	//{
	//	case 1:
	//		printf();		
	//}

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
				printf("Please enter a proper selection: \n");
		}
	}
}

void displayProbability(double result){
	system("clear");

	printf("--------------------\n");
	printf("It is probably quite probable that the probability for you next roll is:.\n");
	printf("%.2f...\n\n",result);
	printf("Remember, knowledge is power!\n");
	printf("Press the any key to continue...\n");
	printf("--------------------\n");

	char response;
	//printf("Probablity is :%.2f\n\n",result);
	//printf("Please press any key to go back to game.\n");
	response = getch();
}


