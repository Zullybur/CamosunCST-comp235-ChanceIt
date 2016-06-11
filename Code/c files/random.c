#include <stdlib.h>
#include <time.h>
#include "../interfaces/random.h"

void randomInit()
{
	srand((unsigned)time(NULL));
}

int getRandomInt(int min, int max)
{
	int delta = max - min;

	if(delta <= 0)
	{
		return 0;
	}

	delta++;
	return rand() % delta + min;
}
