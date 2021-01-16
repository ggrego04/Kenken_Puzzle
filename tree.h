#ifndef TREE_H
#define TREE_H

typedef struct tree_node{
   int **table;
   int table_size;
   int moves;
   int x_zero;
   int y_zero;
   struct tree_node *children[4];
   struct tree_node *father;
}TREE_NODE;

typedef struct{
   TREE_NODE *root;
   int size;
}TREE;

int initTreeNode(TREE_NODE **node);
void PrintTreeNode(TREE_NODE **tn);

#endif