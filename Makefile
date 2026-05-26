CC=gcc

zeller: main.o utils.o
	$(CC) main.o utils.o -o zeller

main.o: main.c utils.h
	$(CC) -c main.c

utils.o: utils.c utils.h
	$(CC) -c utils.c

clean:
	rm -rf *.o zeller *.out
