CC = clang
CFLAGS = -g -O0 -Wall -Werror

LIBS = $(shell find ../lib/ -type f -name "*.c")
TEST_FILES = $(shell find . -type f -name "*.h")

.PHONY: test test_clean
test: 
	$(CC) $(CFLAGS) $(LIBS) tests.c $< -o out/tests 
	out/tests

clean:
	- $(RM) out/tests

