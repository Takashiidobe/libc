#include <stdio.h>
#include <stdlib.h>

#define ARENA_SIZE 1024 * 1024 * 2

static char arena[ARENA_SIZE];
static size_t curr = 0;

void *alloc(size_t size) {
  if (curr + size >= ARENA_SIZE) {
    return NULL;
  }
  void *ptr = &arena[curr];
  curr += size;
  return ptr;
}

int clear() {
  for (size_t i = 0; i < ARENA_SIZE; i++) {
    arena[i] = 0;
  }
  return 1;
}
