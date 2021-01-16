/** @file  console.h
 *  @brief This is a kenken puzzle game
 * 
 *  This program can read a template of a kenken puzzle,
 *  gives the user the ability to play the game by himself
 *  while it makes the necessary checks after the user types
 *  something in the command line and it also autoplays given
 *  an empty template. 
 * 
 *  @author Gregory Gregoriades
 *  @bug No known bugs.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 26
void PrintTable(int ,int [N][N],int [],char [],int [N][N],int);


/** 
 *  @brief Reads a .txt file given by the user
 * 
 *  The function reads a .txt file given by the user
 *  which contains numbers and characters in the form {16* (1,1) (2,2)}.
 *  number 16 is the wanted result,* is the sign of the mathematical 
 *  equation and the numbers in the () are the coordinates of the
 *  requested equation in the kenken puzzle table. The first number 
 *  in the .txt is the size of the table. Then when fscanf reads %d%c
 *  it stores the %d in a table that contains the results and the %c
 *  in a table that contains the signs of each equation. Then it reads
 *  the coordinates in the (), it finds them in the kenken puzzle table
 *  and puts the respected letter given by a character ch, whom we declared
 *  at the start of the function. This character is increasing after the data
 *  of the respected result are read. At the end it returns the size of the
 *  table results table.
 * 
 *  @param *filename The address of the .txt file given by the user
 *  @param size The size of the kenken puzzle table
 *  @param n[] The table that contains the results
 *  @param c[] The table that contains the signs
 *  @param puzzle[][] The table that contains the kenken puzzle
 *  @param size2 The size of the results' and signs' tables
 *  @return size2 The size of the results' and signs' tables
 */
int readFile(char *fileName,int size,int n[],char c[],int puzzle[][N],int size2){
   FILE *fp = fopen(fileName, "r");      //declaring the file pointer            
   if (fp==NULL){
      //if the pointer is null then the .txt cannot be read  
       printf("file can't be read");
       exit(-1);
   }
   //variables declaration
   int i=0;
   int j=0;
   int p=0;
   int x,y;
   char sign;
   int number;
   char ch='a';
  
   fscanf(fp,"%d",&size);                 //reads the size of the table
   while(fscanf(fp,"%d%c",&number,&sign)!=EOF){
      //reads %d and %c and stores in the respected table
      size2++;                            //n and table size is increased
      n[i++]=number;
      c[j++]=sign;
      while(fscanf(fp," (%d,%d) ",&x,&y)>0){
         puzzle[x-1][y-1]=ch;             //adds the correct character in the coordinates read, indicated by ch
      }
      ch++;                               //ch is increased
      
   }


   fclose(fp);
   return size2;
	
}

/**
 *  @brief Prints the current kenken puzzle
 * 
 *  This function is called by the main function. First it prints
 *  a line that contains the wanted results with the equation sign 
 *  and the character that represents them in the table. Afterwards,it prints 
 *  out the current kenken puzzle table that contains characters
 *  and at the left of each character it prints the containing number
 *  in the valtable. Valutable at first contains zeros, then after the 
 *  user gives a value to be included in the given coordinates it's added
 *  in the valtable. Now if the respected coordinates of the table contain 
 *  zero, then the function prints nothing next to the character, if it 
 *  contains a number higher than zero, then it is printed next to the character.
 * 
 *  @param table_size The size of the kenken puzzle table
 *  @param table[][] The kenken puzzle table
 *  @param num [] The results table
 *  @param signs[] The signs table
 *  @param valtable[][] The table that contains the values given by the user
 *  @param numsize The size of the results and signs table
 *  @return Void
 */ 
void PrintTable(int table_size,int table[][N],int num[],char signs[],int valtable[][N],int numsize){
   int i;
   int j;
   int k;
	char ch='a';
   for(i=0;i<numsize;i++){
      printf("%c=%d%c  ",(ch++),num[i],signs[i]);
   }
   printf("\n");
   for(i=0;i<table_size;i++){
      printf("+------");
   }
   printf("+\n");
   for(i=0;i<table_size;i++){
      for(j=0;j<table_size;j++){
         if(valtable[i][j]==0){
            printf("|  %c   ",table[i][j]);
         }else{
            printf("|  %d%c  ",valtable[i][j],table[i][j]);
         }
      }
      printf("|\n");
      for(k=0;k<table_size;k++){
         printf("+------");
      }
      printf("+\n");
   } 
}
/**
 *  @brief Prints the current kenken puzzle in an output .txt file
 *  
 *  Does exactly the same thing with PrintTable, but it prints it out
 *  in a .txt file and saves it.
 * 
 *  @param table_size The size of the kenken puzzle table
 *  @param table[][] The kenken puzzle table
 *  @param num [] The results table
 *  @param signs[] The signs table
 *  @param valtable[][] The table that contains the values given by the user
 *  @param numsize The size of the results and signs table
 *  @return Void
 */ 
void PrintOutput(int table_size,int table[][N],int num[],char signs[],int valtable[][N],int numsize){
   FILE *fp=fopen("output.txt","w");
   int i;
   int j;
   int k;
	char ch='a';
   for(i=0;i<numsize;i++){
      fprintf(fp,"%c=%d%c  ",(ch++),num[i],signs[i]);
   }
   fprintf(fp,"\n");
   for(i=0;i<table_size;i++){
      fprintf(fp,"+------");
   }
   fprintf(fp,"+\n");
   for(i=0;i<table_size;i++){
      for(j=0;j<table_size;j++){
         if(valtable[i][j]==0){
            fprintf(fp,"|  %c   ",table[i][j]);
         }else{
            fprintf(fp,"|  %d%c  ",valtable[i][j],table[i][j]);
         }
      }
      fprintf(fp,"|\n");
      for(k=0;k<table_size;k++){
         fprintf(fp,"+------");
      }
      fprintf(fp,"+\n");
   } 
}

/**
 *  @brief Checks if a number can be placed in the table
 * 
 *  After the user gives the coordinates and the requested value
 *  this function is called to check if the value passes the criteria 
 *  and can be placed in the requested position in the values table.
 *  First it checks that the number is not already in the same row, or
 *  column, then it checks if the sum, or product (it depends from
 *  the sign) of the respected result is equal to the result. If the value 
 *  doesn't pass the criteria the function returns 0, indicated by the flag
 *  declared in the beginning of the function. If it passes all the criteria
 *  then it returns 1.
 * 
 *  @param x The x coordinate of the position given by the user
 *  @param y The y coordinate of the position given by the user
 *  @param val The value given by user
 *  @param size The size of the kenken puzzle
 *  @param puzzle[][] The kenken puzzle table
 *  @param letter The character contained in the kenken puzzle table in the given coordinates
 *  @param number The result that is represented by the letter in the kenken puzzle table
 *  @param sign The sign that is required for the respected result
 *  @param values[][] The table that contains all the values guiven by user
 *  @return flag Acts like a boolean variable. 0 for false, 1 for true
 * 
 */ 
int Check(int x,int y,int val,int size,int puzzle[][N],char letter,int number,char sign,int values[][N]){
   int i,j;
   int flag=1,flag2=1;
   int sum=0,product=1;
   
   //The row check
   for(i=0;i<size;i++){
      if((values[x][i]==val)&&(i!=y)){
         flag=0;
         break;
      }
   }
   if(flag==1){
      //if is not already false then check column
      for(i=0;i<size;i++){
         if((values[i][y]==val)&&(i!=x)){
            flag=0;
            break;
         }
      }
   }
   
   if(flag==1){
      values[x][y]=val;                      //adds the value in the table temporary
      if(sign=='+'){
         for(i=0;i<size;i++){
            for(j=0;j<size;j++){
               if(puzzle[i][j]==letter){
                  if(values[i][j]!=0){       //if the table contains 0 in the coordinates of the respected result
                     sum=sum+values[i][j];
                  }else{
                      flag2=0;               //then the second flag is 0. That means the value is always correct
                  }
               }
            }
         }
         //if the sum is not equal to the result and there are no zeros in the coordinates with the same letter
        if((sum!=number)&&(flag2==1)){
            flag=0;                          //doesn't pass the criteria
            values[x][y]=0;                  //value removed from the table
        }
         
      }else if(sign=='*'){
            for(i=0;i<size;i++){
               for(j=0;j<size;j++){
                  if(puzzle[i][j]==letter){
                     if(values[i][j]!=0){                //if the table contains 0 in the coordinates of the respected result
                        product=product*values[i][j];
                     }else{
                         flag2=0;                        //then the second flag is 0. That means the value is always correct
                     }
                  }
               }
            }
            //if the product is not equal to the result and there are no zeros in the coordinates with the same letter
            if((product!=number)&&(flag2==1)){
                flag=0;                                  //doesn't pass the criteria
                values[x][y]=0;                          //value removed from the table
            }
      }
   }    
   return flag;
}

/**
 *  @brief Reads the values the user gives and places them in the table if correct
 * 
 *  This function is used so that the user can play the game. It prints
 *  out first the instructions on how to enter values, remove them or
 *  end the game. If the user doesn't enter the values with the format 
 *  mentioned by the instructions, or if the puts a bigger value than
 *  the size of the table or a value smaller than zero or the coordinates 
 *  entered are not valid etc. then an error message will appear explaining 
 *  the current mistake, then it asks the value again. If it passes the 
 *  entry check and the value is bigger than zero, it calls the check 
 *  function to check if the value can be placed in the given coordinates. 
 *  If it passes the entry check and the value is zero then it erases the
 *  value in the given coordinates. If the user enters 0,0=0, then the 
 *  function PrintOutput is called to print the table in a .txt file. If the 
 *  table is completed and there are no mistakes then the user completes the puzzle
 * 
 *  @param size The size of the kenken puzzle table
 *  @param puzzle[][] The kenken puzzle table
 *  @param num[] The results table
 *  @param signs[] The signs table
 *  @param values[][] The table that contains the values given by user
 *  @param numresults The size of the results and signs table
 *  @return Void.
 */ 
void Play(int size,int puzzle[][N],int num[],char signs[],int values[][N] ,int numresults){

   int x,y,val;
   int finished=0;
   
      int playable=0;               //a variable that indicates if the value can be placed in the requested coordinates
      printf("Enter your command in the following format: \n");
      printf(">i,j=val: for entering val at position (i,j)\n");
      printf(">i,j=0  : for clearing cell (i,j)\n");
      printf(">0,0=0  : for saving and ending the game \n");
      printf("Notice: i,j,val numbering is from [1..4]\n");
      printf(">");
      do{
      int flag=0;
      while(flag==0){
         int Scanner=scanf("%d , %d = %d",&x,&y,&val);

         //if the Scanner doesn't read the charactters as given above the loop runs again
         if(Scanner!=3){
            while (getchar() != '\n') {};         
            printf("wrong format of command\n");
            printf(">");
         }else if (Scanner==3){
            if((val>size)||(val<0)){
               printf("val Cannot exceed %d or be less than 0\n",size);
               printf(">");
            }else if((x>size)||(y>size)){
               printf("i,j must be within the given boundaries\n");
               printf(">");
            }else if((values[x-1][y-1]>0)&& val != 0){
               printf("this cell of the table already includes a value\n");
               printf(">");
            }else{
               flag=1;
            }
         }
      }
      if((x!=0)&&(y!=0)&&(val==0)){
         values[x-1][y-1]=0;                       //value removed from the table
        PrintTable(size,puzzle,num,signs,values,numresults);
      }else{
         if((x==0)&&(y==0)&&(val==0)){
            printf("thank you for playing\n");
            finished=1;                         
         }else if((x!=0)&&(y!=0)&&(val!=0)){
               playable=Check(x-1,y-1,val,size,puzzle,puzzle[x-1][y-1],num[(puzzle[x-1][y-1])-'a'],signs[(puzzle[x-1][y-1])-'a'],values);
               if(playable==1){
                  PrintTable(size,puzzle,num,signs,values,numresults);
               }else{
                  PrintTable(size,puzzle,num,signs,values,numresults);
                  printf("Wrong move!! Try again\n");
               }
            }
         
      }
      int i,j;
      int count=0;
      for(i=0;i<size;i++){
         for(j=0;j<size;j++){
            if(values[i][j]!=0){
               count++;
            }
         }
      }
      if(count==(size*size)){
         finished=1;
      }
      
      
      printf("> ");
   }while(finished==0);
   printf("Congratulations!!You finished the puzzle successfully!\n");
   PrintOutput(size,puzzle,num,signs,values,numresults);
}

int AutoPlay(int x,int y,int val,int size,int puzzle[][N],int num[],char signs[],int values[][N] ,int numresults){
   int j,i;
   int playable=0;
   int k=1;
   int flag=1;
   // for(i=0;i<size;i++){
   //    for(j=0;j<size;j++){
   //       if(values[i][j]==0){
   //          flag=0;
   //       }
   //    }
   // }
   // if(flag==1){
      
   //    return 0;
   // }else{
      for(k=1;k<=size;k++){
         playable=Check(x,y,k,size,puzzle,puzzle[x][y],num[(puzzle[x][y])-'a'],signs[(puzzle[x][y])-'a'],values);
         if(playable==1){
            if(y==size){
               AutoPlay(x+1,1,k,size,puzzle,num,signs,values,numresults);
            }else{
                AutoPlay(x,y+1,k,size,puzzle,num,signs,values,numresults);
             }
      }
  }
   PrintTable(size,puzzle,num,signs,values,numresults);



}
/**
 *  @brief calls all the functions that are needed to run the program
 * 
 *  This is the main function of the program. It declares the needed variables,
 *  creates and initializes tha values table, reads the first number from the .txt
 *  file so that it can be used later as the kenken puzzle size and calls all the 
 *  functions in order to read a file, print out, play and autoplay
 * 
 *  @return 0
 */ 
int main(int argc,char* argv[]){

   char* filename;
   int i,j;
   int numresults=0;
   int puzzlesize;
   int num[M];
   char signs[M];
   int kenkenpuzzle[N][N];
   int values[N][N];
   
   if(argc!=3){
       exit(-1);
   }else if((argv[1][0]== '-')&&(argv[1][1]=='i')){   
      numresults=readFile(argv[2],puzzlesize,num,signs,kenkenpuzzle,numresults);
      FILE *fp = fopen(argv[2], "r");
      fscanf(fp,"%d",&puzzlesize);
      fclose(fp);

   //initialization of values table
   for(i=0;i< puzzlesize;i++){
      for(j=0;j< puzzlesize;j++){
         values[i][j]=0;
      }
   }
   PrintTable(puzzlesize,kenkenpuzzle,num,signs,values,numresults);
   Play(puzzlesize,kenkenpuzzle,num,signs,values,numresults);
   }else if((argv[1][0]== '-')&&(argv[1][1]=='s')){
      numresults=readFile(argv[2],puzzlesize,num,signs,kenkenpuzzle,numresults);
      FILE *fp = fopen(argv[2], "r");
      fscanf(fp,"%d",&puzzlesize);
      fclose(fp);

   //initialization of values table
   for(i=0;i< puzzlesize;i++){
      for(j=0;j< puzzlesize;j++){
         values[i][j]=0;
      }
   }
   PrintTable(puzzlesize,kenkenpuzzle,num,signs,values,numresults);
   AutoPlay(0,0,1,puzzlesize,kenkenpuzzle,num,signs,values,numresults);
   }

   else{
      printf("Error loading program\n");
      printf("%s\n",argv[1]);
      exit(-1);
   }
   //symbol=argv[1];
//    printf("%s",argv[1]);
//    // if((argv[1]!= "-i")||(argv[1]!="-s")){
//    //    printf("Error loading program\n");
//    //    printf("%c",argv[1]);
//    //    exit(-1);
//    // }
   
//   // numresults=readFile(*argv[3],puzzlesize,num,signs,kenkenpuzzle,numresults);
//    FILE *fp = fopen("kk4x4.txt", "r");
//    fscanf(fp,"%d",&puzzlesize);
//    fclose(fp);

//    //initialization of values table
//    for(i=0;i< puzzlesize;i++){
//       for(j=0;j< puzzlesize;j++){
//          values[i][j]=0;
//       }
//    }
//    PrintTable(puzzlesize,kenkenpuzzle,num,signs,values,numresults);

   
   AutoPlay(0,0,1,puzzlesize,kenkenpuzzle,num,signs,values,numresults);


   return 0;
}















