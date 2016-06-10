#include "../interfaces/highScore.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILEPATH	"../../Design Documents/highScore.txt"


_Bool submitScore(unsigned score, char* name){
	return amendHighScore( name,  score); 
}
           
_Bool submitTieScore(unsigned score, char* player1, char* player2){

	_Bool result = amendHighScore( player1,  score);
	return amendHighScore( player2,  score) || result;
}


void getHighScore(){
	
	FILE *f;
	if( access( FILEPATH, F_OK) != -1){
		printf(" Top Ten Scores\n");
		printf("--------------------------------------------\n");
		f = fopen(FILEPATH, "r");
		int i;
		for (i = 1; i <= 10; i++){
			char name[50] = {0};
			fscanf(f, "%s", name);
			char date[50] = {0};
			fscanf(f, "%s", date);
			char score[50] = {0};
			fscanf(f, "%s", score);
			if (feof(f)){
				break;
			}
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
}

_Bool amendHighScore(char* name, unsigned score){
	_Bool result = 0;
	Score newScore;
	strcpy(newScore.name, name);
	newScore.score = score;
	//set date
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strcpy(newScore.date, asctime(timeinfo));
	//maybe in own function
	newScore.date[0] = newScore.date[20];
	newScore.date[1] = newScore.date[21];
	newScore.date[2] = newScore.date[22];
	newScore.date[3] = newScore.date[23];
	newScore.date[11] = '\0';
	newScore.date[10] = newScore.date[9];
	//newScore.date[9] = newScore.date[8];
	if (newScore.date[8] == ' ')
        {
                newScore.date[9] = '0';
        } else
        {
                newScore.date[9] = newScore.date[8];
        }
	newScore.date[8] = '-';
	newScore.date[7] = newScore.date[6];
	newScore.date[6] = newScore.date[5];
	newScore.date[5] = newScore.date[4];
	newScore.date[4] = '-';
	

	int isAdded = 0;
	Score highScores[11];

	unsigned i = 0;
	FILE *f;
	if( access( FILEPATH, F_OK) != -1){
		f = fopen(FILEPATH, "r");
		char line[50];
		while(1){
			Score nextScore;
			fscanf(f, "%s", nextScore.name);
			if(feof(f)){
				i--;
				break;
			}
			nextScore.name;
			fscanf(f, "%s", nextScore.date);
			if (feof(f)){
				i--;
				break;
			}
			fscanf(f, "%s", line);
			if (feof(f)){
				i--;
				break;
			}
			if (!(nextScore.score = atoi(line))){
				i--;
				break;
			}
			if (isAdded || nextScore.score >= newScore.score){
				highScores[i] = nextScore;
			}else{
				result = 1;
				highScores[i++] = newScore;
				isAdded = !isAdded;
				highScores[i] = nextScore;
			}
			if (i >= 9){
				i = 9;
				break;
			}
			i++;
		}
		if (!isAdded && i < 9){
			highScores[++i] = newScore;
		}
		fclose(f);
	}else{
		i = 0;
		highScores[0] = newScore;
	}
	f = fopen(FILEPATH, "w");
	unsigned j = 0;
	char line[50];
	for (; j <= i; j++){
		fputs(highScores[j].name, f);
		fprintf(f, "\n");
		fputs(highScores[j].date, f);
		fprintf(f, "\n");
		if (0 > sprintf(line,"%d\n", highScores[j].score) ){
			break;
		}
		fputs(line, f);
	}
	fclose(f);
	return result;

}
