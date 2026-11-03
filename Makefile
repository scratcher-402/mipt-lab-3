CC = gcc
TARGET = lab3
SRCS = $(wildcard *.c)

all: $(TARGET)

$(TARGET):
	$(CC) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

.PHONY: all clean
