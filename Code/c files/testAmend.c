#include <stdio.h>
#include "../interfaces/highScore.h"

int main()
{

	char* Butt = "Butt";
	char* Head = "Head";
	char* Knob = "Knobs";
	char* George = "George";
        char* Joffrey = "Joffrey";
        char* Chair = "Chair";

	amendHighScore(Butt, 200);
	amendHighScore(Head, 600);
	amendHighScore(Knob, 2000);
	amendHighScore(George, 500);
        amendHighScore(Joffrey, 800);
        amendHighScore(Chair, 1000);
	
	
	return 1;

}
