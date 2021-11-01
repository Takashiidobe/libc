#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode BSTNode;

typedef struct BSTNode {
  void *val;
  BSTNode *left;
  BSTNode *right;
} BSTNode;

typedef struct BSTree {
  BSTNode *root;
  size_t len;
  int (*cmp)(const void *, const void *);
  void (*print)(const void *);
} BSTree;

BSTree *new_bst(int (*cmp)(const void *, const void *),
                void (*print)(const void *)) {
  BSTree *tree = malloc(sizeof(BSTree));
  tree->cmp = cmp;
  tree->print = print;
  tree->len = 0;
  tree->root = NULL;
  return tree;
}

BSTNode *new_bstnode(void *val) {
  BSTNode *node = malloc(sizeof(BSTNode));
  node->val = val;
  return node;
}

void bstree_add(BSTree *tree, void *val) {
  BSTNode *node = new_bstnode(val);
  if (!tree->root) {
    tree->root = node;
  } else {
    BSTNode *curr = tree->root;
    while (curr != NULL) {
      if (tree->cmp(curr->val, val) > 0 && curr->left != NULL) {
        curr = curr->left;
      } else if (tree->cmp(curr->val, val) > 0 && curr->left == NULL) {
        curr->left = node;
      } else if (tree->cmp(curr->val, val) < 0 && curr->right != NULL) {
        curr = curr->right;
      } else if (tree->cmp(curr->val, val) < 0 && curr->right == NULL) {
        curr->right = node;
      } else {
        break;
      }
    }
  }
  tree->len++;
}

int cmp(const void *a, const void *b) {
  const int arg1 = *(const int *)a;
  const int arg2 = *(const int *)b;
  return (arg1 > arg2) - (arg1 < arg2);
}

void print(const void *a) { printf("Node Value: %d\n", *(int *)a); }

void bstree_inorder(BSTree *tree, BSTNode *root) {
  if (root != NULL) {
    bstree_inorder(tree, root->left);
    tree->print(root->val);
    bstree_inorder(tree, root->right);
  }
}

void bstree_postorder(BSTree *tree, BSTNode *root) {
  if (root != NULL) {
    bstree_postorder(tree, root->right);
    tree->print(root->val);
    bstree_postorder(tree, root->left);
  }
}

// int main() {
//   BSTree *tree = new_bst(cmp, print);
//   bstree_add(tree, (void *)20);
//   bstree_add(tree, (void *)30);
//   bstree_add(tree, (void *)40);
//   bstree_add(tree, (void *)50);
//   bstree_add(tree, (void *)60);
//   bstree_add(tree, (void *)10);
//   bstree_inorder(tree, tree->root);
//   bstree_postorder(tree, tree->root);
// }
