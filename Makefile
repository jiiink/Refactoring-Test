CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11 -O2
TARGET = app

SRCS = bad_code.c
APP_SRCS = app_main.c
TEST_SRCS = test_bad_code.c
TEST_TARGET = test_app

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(APP_SRCS) $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRCS) $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) $(TEST_TARGET)

lint:
	clang-tidy $(SRCS) $(APP_SRCS) -- $(CFLAGS)

run:
	./$(TARGET)
