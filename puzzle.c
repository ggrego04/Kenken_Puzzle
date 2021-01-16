#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "tree.h"
#define N 50

int read(char *file,int table[][N]){
   FILE *fp1 = fopen(file, "r");
   char line[100];
   int countlines=0;
   while (fgets(line, sizeof(line), fp1))
      countlines++;
   printf("%d",countlines);
   int size=countlines;
   fclose(fp1);
   int i=0,j=0;
   int num;
   FILE *fp2=fopen(file, "r");
   while(fscanf(fp2,"%d",&num)!=EOF){
      //reads %d and %c and stores in the respected table   
      table[i][j]=num;                         //n and table size is increased
      j++;                              //ch is increased
      if(j==size){
         j=0;
         i++;
      }
      
   }
   // while (fgets(line, sizeof(line), fp2)){
   //   for(i=0;i<100;i++){
   //      if(line[i]>=0){
   //         table[j][k]=line[i];
   //         k++;
   //      }
   //   }
   //   j++;
   // }
   return size;
}
int main(int argc,char* argv[]){
   // if(argc!=3){
   //     exit(-1);
   // }else 
   int table_size=N;
   int table[table_size][table_size];
   char *word;
   char *inputfile;
   char *outputfile;
   word=argv[1];
   TREE *t=NULL;
   if(strcmp(word,"breadth")==0){
      //printf("OK");
      inputfile=argv[2];
      outputfile=argv[3];
   }
   int i=0,j=0;
   table_size=read(inputfile,table);
   printf("%s, %s, %d\n",inputfile,outputfile,table_size);
   for(i=0;i<table_size;i++){
      for(j=0;j<table_size;j++){
         printf("%d ",table[i][j]);
      }
      printf("\n");
   }
   
   // for(i=0;i<table_size;i++){
   //    for(j=0;j<table_size;j++){
   //       printf("%d ",t->root->table[i][j]);
   //    }
   //    printf("\n");
   // }
}