#include "../interfaces/probability.h"

double getProbability(int sum){
	double result = 0;
	switch(sum){
		case 7: 
			result = 6;
			break;
		case 6: 
		case 8:
			result = 5;
			break;
		case 5:
		case 9:
			result = 4;
			break;
		case 4:
		case 10:
			result = 3;
			break;
		case 3:
		case 11:
			result = 2;
			break;
		case 2:
		case 12:
			result = 1;
			break;
		default: 
			break;
	}
	return result/36;
}