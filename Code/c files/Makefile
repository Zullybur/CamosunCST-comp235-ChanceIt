all: ChanceItSub1

ChanceItSub1: main.o game.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o
	    gcc main.o game.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o -o ChanceItSub1

main.o: main.c
	    gcc -c main.c

game.o: game.c
		gcc -c game.c

localTurn.o: localTurn.c
		gcc -c localTurn.c

dice.o: dice.c
		gcc -c dice.c

probability.o: probability.c
		gcc -c probability.c

inputOutput.o: inputOutput.c
		gcc -c inputOutput.c

getCon.o: getCon.c
		gcc -c getCon.c

random.o: random.c
		gcc -c random.c

computerPlayer.o: computerPlayer.c
		gcc -c computerPlayer.c
