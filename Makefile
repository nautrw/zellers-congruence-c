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
ifeq ($(OS),Windows_NT)
	del /s *.o *.d *.out $(TARGET).exe
else
	rm -f *.o *.d *.out $(TARGET)
endif