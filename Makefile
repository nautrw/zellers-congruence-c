CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -O2
TARGET=zeller
OBJS=main.o utils.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.exe *.out zeller
