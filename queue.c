#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// int main(){
//    QUEUE *queue=NULL;
//    initQueue(&queue);
//    int table1[4]={1,2,3,4};
//    int table2[4]={6,7,8,9};
//    enqueue(table1,queue);
//    enqueue(table2,queue);
// //    enqueue(3,queue);
// //    enqueue(4,queue);
   
//    int length=queue->length;
//    printf("Queue = %d\n",length);
//    printf("OK\n");
//    int i=0,j=0;
//    int *retval = malloc(sizeof(int*));
//    // for(i=0;i<length;i++){
//    //    dequeue(queue,retval);
// 	//    printf("%d\n",*retval);
//    // }
//    NODE *p =queue->head;
//    for(i=0;i<4;i++){
//       for(j=0;j<4;j++){
//          printf("%d ",p->tn->table[i][j]);
//       }
//    }
// }

int initQueue(QUEUE **queue) {
   *queue = (QUEUE *) malloc(sizeof(QUEUE));
   if ((*queue) == NULL) return EXIT_FAILURE;
   (*queue)->head = (*queue)->tail = NULL;
   (*queue)->length = 0;
   return EXIT_SUCCESS;
}

int enqueue (TREE_NODE *tree_node, QUEUE *q)  {
   NODE *p = NULL;
   if (q == NULL){ return EXIT_FAILURE; }
   p = (NODE *)malloc(sizeof(NODE));
   if ( p == NULL ) {
      printf("System out of memory...\n");
      return EXIT_FAILURE;
   }
   p->tn = tree_node;
   p->next = NULL;
   if (q->length == 0)
      q->head = q->tail = p;
   else { // append on end
      q->tail->next = p;
      q->tail = p;
   }
   (q->length)++;
   return EXIT_SUCCESS;
}
TREE_NODE dequeue(QUEUE *q, TREE_NODE *retval){
   NODE *p= NULL;// copy pointer used for free()
   if ((q == NULL) || (q->head == NULL)){
      printf("Sorry, queue is empty \n");
      exit(-1);
   }
   if (retval == NULL) { 
      printf("Retval is null"); 
	   exit(-1); 
   }
   p = q->head;
   retval = q->head->tn;
   q->head = q->head->next;
   free(p);
   --(q->length);
   if (q->length == 0) {
      q->tail = NULL;
   }
}

