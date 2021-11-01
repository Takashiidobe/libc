#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode SLLNode;

typedef struct SLLNode {
  void *val;
  SLLNode *next;
} SLLNode;

typedef struct SLList {
  SLLNode *head;
  SLLNode *tail;
  size_t len;
} SLList;

SLList *new_slist() {
  SLList *slist = malloc(sizeof(SLList));
  return slist;
}

SLLNode *new_slnode(void *val) {
  SLLNode *node = malloc(sizeof(SLLNode));
  node->val = val;
  return node;
}

void slist_push_back(SLList *list, void *val) {
  SLLNode *new_node = new_slnode(val);
  if (list->len == 0) {
    list->head = new_node;
  } else {
    list->tail->next = new_node;
  }
  list->tail = new_node;
  list->len++;
}

void slist_push_front(SLList *list, void *val) {
  SLLNode *new_node = new_slnode(val);
  if (list->len == 0) {
    list->head = new_node;
  } else {
    new_node->next = list->head;
  }
  list->head = new_node;
  list->len++;
}

void *slist_pop_front(SLList *list) {
  assert(list->len > 0);
  void *popped = list->head->val;
  list->head = list->head->next;
  list->len--;
  return popped;
}

void slist_for_each(SLList *list, void *(*fn)(void *)) {
  SLLNode *curr = list->head;
  while (curr != NULL) {
    curr->val = (*fn)(curr->val);
    curr = curr->next;
  }
}
