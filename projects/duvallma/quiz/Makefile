CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme:
	gcc -o testme -g testme.c $(CFLAGS)
	./testme

clean:
	rm -f testme *.o *.gcov *.gcda *.gcno *.so *.out