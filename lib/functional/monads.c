#include <stdbool.h>
#include <stdio.h>

// Maybe
typedef struct Maybe {
  void *just;
  bool nothing;
  void (*print)(const void *);
} Maybe;

const Maybe Nothing = (Maybe){.nothing = true};

Maybe returnMaybe(void *x) { return (Maybe){.just = x, .nothing = false}; }

Maybe bindMaybe(Maybe (*fn)(void *), Maybe m) {
  return m.nothing ? Nothing : fn(m.just);
}

void printMaybe(Maybe *m) {
  if (m->nothing)
    printf("Nothing\n");
  else
    m->print(m->just);
}

void print_fn(const void *i) { printf("%d\n", *(int *)i); }

Maybe map(Maybe *m) {
  if (m->nothing)
    return Nothing;
  return (Maybe){.just = &*(int *)m->just + 10};
}

// Either

typedef struct EitherInt {
  int i;
  char *error;
} EitherInt;

EitherInt returnInt(int i) { return (EitherInt){.i = i, .error = NULL}; }
EitherInt returnError(char *e) { return (EitherInt){.i = 0, .error = e}; }

EitherInt bindEither(EitherInt (*fn)(int), EitherInt m) {
  return (m.error != NULL) ? m : fn(m.i);
}

void printEither(EitherInt m) {
  if (m.error != NULL)
    printf("%s\n", m.error);
  else
    printf("%d\n", m.i);
}

EitherInt eitherFoo(int x) {
  return (x < 2) ? returnError("too small") : returnInt(x - 3);
}
EitherInt eitherBar(int x) {
  return (x > 0) ? returnError("not negative") : returnInt(x + 3);
}
EitherInt eitherBaz(int x) {
  return (x != 2) ? returnError("must be 2") : returnInt(x);
}
