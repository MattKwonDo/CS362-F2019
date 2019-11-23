CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

randomtestcard1: dominion.o rngs.o
	printf "*** BEGIN RandomTestCard1 ***\n" >> randomtestresults.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	printf "*** RandomTestCard1 gcov ***\n" >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	printf "*** END   RandomTestCard1 ***\n" >> randomtestresults.out

randomtestcard2: dominion.o rngs.o
	printf "*** BEGIN RandomTestCard2 ***\n" >> randomtestresults.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	printf "*** RandomTestCard2 gcov ***\n" >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	printf "*** END   RandomTestCard2 ***\n" >> randomtestresults.out

randomtestcard3: dominion.o rngs.o
	printf "*** BEGIN RandomTestCard3 ***\n" >> randomtestresults.out
	gcc -o randomtestcard3 -g randomtestcard3.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard3 >> randomtestresults.out
	printf "*** RandomTestCard3 gcov ***\n" >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	printf "*** END   RandomTestCard3 ***\n" >> randomtestresults.out

randomtestresults: randomtestcard1 randomtestcard2 randomtestcard3

testme:
	gcc -o testme -g testme.c $(CFLAGS)
	./testme

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
