CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -O2
TARGET=zeller
OBJS=main.o utils.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.d: %.c
	$(CC) -MM $(CFLAGS) $< -o $@
-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	rm -f *.o *.exe *.out *.d zeller
