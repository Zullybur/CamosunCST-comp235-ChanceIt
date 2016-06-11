all: ChanceIt

ChanceIt: main.o game.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o protocol.o socket.o
		gcc -std=c99 main.o game.o socket.o protocol.o localTurn.o dice.o probability.o inputOutput.o getCon.o random.o computerPlayer.o -o ChanceIt

main.o: main.c ../interfaces/inputOutput.h ../interfaces/game.h ../interfaces/random.h
		gcc -std=c99 -c main.c 

game.o: game.c ../interfaces/game.h ../interfaces/inputOutput.h ../interfaces/localTurn.h
		gcc -std=c99 -c game.c

protocol.o: protocol.c ../interfaces/protocol.h ../interfaces/socket.h ../interfaces/inputOutput.h ../interfaces/getCon.h
		gcc -std=c99 -c protocol.c

socket.o: socket.c ../interfaces/socket.h
		gcc -std=c99 -c socket.c

localTurn.o: localTurn.c ../interfaces/localTurn.h ../interfaces/probability.h ../interfaces/inputOutput.h ../interfaces/dice.h ../interfaces/computerPlayer.h
		gcc -std=c99 -c localTurn.c

dice.o: dice.c ../interfaces/dice.h ../interfaces/random.h
		gcc -std=c99 -c dice.c

probability.o: probability.c ../interfaces/probability.h
		gcc -std=c99 -c probability.c

inputOutput.o: inputOutput.c ../interfaces/inputOutput.h ../interfaces/getCon.h
		gcc -std=c99 -c inputOutput.c

getCon.o: getCon.c ../interfaces/getCon.h
		gcc -std=c99 -c getCon.c

random.o: random.c ../interfaces/random.h
		gcc -std=c99 -c random.c

computerPlayer.o: computerPlayer.c ../interfaces/computerPlayer.h
		gcc -std=c99 -c computerPlayer.c
