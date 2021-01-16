#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int initTreeNode(TREE_NODE **node) {
   *node= (TREE_NODE *) malloc(sizeof(TREE_NODE));
   if ((*node) == NULL) return EXIT_FAILURE;
   return EXIT_SUCCESS;
}

void PrintTreeNode(TREE_NODE **tn){
   // int i=0,j=0;
   // for(i=0;i<(*tn)->table_size;i++)
   //    printf("----");
   // for(i=0;i<(*tn)->table_size;i++){
   //    printf("|");
   //    for(j=0;j<(*tn)->table_size;i++){
   //       printf(" %d |",(*tn)->table[i][j]);
   //    }
   // }
   // for(i=0;i<(*tn)->table_size;i++)
   //    printf("----");

   //printf("%d\n",(tn)moves);
}
// int printTreeNode(TREE_NODE **node){
//    if ((*node) == NULL){printf("NULL NODE\n"); return EXIT_FAILURE;}
//    int i,j;
//    for (i=0;i<(*node)->table_size;i++){
//       printf("---");
//    }
//    printf("\n");

//    for (i=0;i<(*node)->table_size;i++){
//       for (j=0;j<(*node)->table_size;j++){
//          printf(" %d  ",(*node)->table[i][j]);
//       }
//       printf("\n");
//    }
//    for (i=0;i<(*node)->table_size;i++){
//       printf("---");
//    }
//    printf("\n");
//    return EXIT_SUCCESS;
// }

int main(){
   int size=4;
   int table1[size][size];
   int i=0,j=0,count=0;
   for(i=0;i<size;i++){
      for(j=0;j<size;j++){
         table1[i][j]=count;
         count++;
         printf("%d ",table1[i][j]);
      }
   }
   TREE *tree;
   //tree->root->table=table1;
   tree->root->moves=3;
   // tree->root->table_size=size;
   // tree->root->x_zero=0;
   // tree->root->y_zero=0;
   // tree->root->father=NULL;
   // tree->root->children[4]=NULL;
   TREE_NODE *p=tree->root;
   PrintTreeNode(&p);
}