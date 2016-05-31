all: ChanceItSub1

ChanceItSub1: main.o game.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o
	    gcc main.o game.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o -o ChanceItSub1

main.o: main.c ../interfaces/inputOutput.h ../interfaces/game.h ../interfaces/random.h
	    gcc -c main.c 

game.o: game.c ../interfaces/game.h ../interfaces/inputOutput.h ../interfaces/localTurn.h
		gcc -c game.c

localTurn.o: localTurn.c ../interfaces/localTurn.h ../interfaces/probability.h ../interfaces/inputOutput.h ../interfaces/dice.h ../interfaces/computerPlayer.h
		gcc -c localTurn.c

dice.o: dice.c ../interfaces/dice.h ../interfaces/random.h
		gcc -c dice.c

probability.o: probability.c ../interfaces/probability.h
		gcc -c probability.c

inputOutput.o: inputOutput.c ../interfaces/inputOutput.h ../interfaces/getCon.h
		gcc -c inputOutput.c

getCon.o: getCon.c ../interfaces/getCon.h
		gcc -c getCon.c

random.o: random.c ../interfaces/random.h
		gcc -c random.c

computerPlayer.o: computerPlayer.c ../interfaces/computerplayer.h
		gcc -c computerPlayer.c
