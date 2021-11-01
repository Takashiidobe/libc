#include <stdio.h>
#include <stdlib.h>

// A Red-Black Tree

typedef struct RBNode {
  int data;
  char color;
  struct RBNode *left, *right, *parent;
} RBNode;

void left_rotate(RBNode **root, RBNode *x) {
  RBNode *y = x->right;
  x->right = y->left;
}
