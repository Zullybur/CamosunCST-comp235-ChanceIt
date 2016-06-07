#include <stdio.h>
#include "../interfaces/highScore.h"

int main()
{

	char* Butt = "Boob";
	char* Head = "Frog";
	char* Knob = "Chair";
	amendHighScore(Butt, 200);
	amendHighScore(Head, 600);
	amendHighScore(Knob, 2000);
	getHighScore();
	
	return 1;

}
