CC = clang
CFLAGS = -Wall -Werror
RELEASE_FLAGS = -O3
BUILD_DIR = build
RELEASE_DIR = release 
SRC_DIR = src
LIB_DIR = lib
INCLUDE_DIR = ../lib

SRCS = $(shell find $(SRC_DIR)/ -type f -name "*.c")
LIBS = $(shell find $(LIB_DIR)/ -type f -name "*.c")
INCLUDE_LIBS = $(shell find $(INCLUDE_DIR)/crypto -type f -name "*.c")
PROGS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SRCS))
RELEASE_PROGS = $(patsubst $(SRC_DIR)/%.c,release/%,$(SRCS))

all: $(PROGS)

build/md5sum: $(SRC_DIR)/md5sum.c $(LIBS)
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) $(INCLUDE_DIR)/crypto/md5.c $(LIBS) $< -o $@ 

build/%: $(SRC_DIR)/%.c $(LIBS)
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) $(LIBS) $< -o $@ 

clean:
	rm -r $(BUILD_DIR)
	rm -r $(RELEASE_DIR)

release: $(RELEASE_PROGS)

release/%: $(SRC_DIR)/%.c $(INCLUDE_LIBS) $(LIBS)
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE_LIBS) $(RELEASE_FLAGS) $< -o $@ 

test:
	shellspec

define HELP_TEXT
make                  build all utils
make release          build all utils for release
make test             run tests for utils 
endef

export HELP_TEXT

help:
	@echo "$$HELP_TEXT"
