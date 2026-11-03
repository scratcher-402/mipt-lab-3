CC = gcc
TARGET = lab3
SRCS = $(wildcard *.c)
TEST_DIR = tests
TEST_FILES = $(wildcard $(TEST_DIR)/*)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $@

clean:
	rm -rf $(TARGET)

test: $(TARGET)
	@for file in $(TEST_FILES); do \
		echo "----------------------------------------"; \
		echo "Running test: $$file"; \
		./$(TARGET) < "$$file"; \
	done

.PHONY: all clean test
