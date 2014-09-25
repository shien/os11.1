TARGET = os11.1

CC = clang
CFLAGS = -Wall -O2 -g

$(TARGET): os11.1.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(TARGET)
