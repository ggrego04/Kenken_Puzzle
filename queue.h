#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

typedef struct node{
   TREE_NODE *tn;
   struct node *next;
   struct node *previous;
}NODE;

typedef struct{
   int	length;
   NODE *head;
   NODE *tail;
}QUEUE;

int initQueue(QUEUE **queue);
int enqueue(TREE_NODE *tn, QUEUE *q);
TREE_NODE dequeue(QUEUE *q, TREE_NODE *retval);

#endif