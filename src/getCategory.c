#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>
#include <math.h> 
 
//Declaring Variables.
int main() { 
  FILE *file;
  FILE *file2;  
  int i;
  int size = 9999; 
  int totalWords = 0;
   
//opening file and intializing arrays to null
  file = fopen("Article1.txt","r");
  char *words[size];
  int index[size];
  for(i=0;i<100;i++) {
  words[i] = (char *)malloc(20);
  index[i] = 0;
  }
  char status[20];
//Reading the words from the file.
  while(fscanf(file,"%s",status)==1) {
  strcpy(words[totalWords], status);
  totalWords++;
  }
  fclose(file);
//Opening 2nd file.
  file2 = fopen("Article2.txt","r");
  while(fscanf(file2,"%s",status)==1) {
//Checking if words match and assigning 1 or 0's.
  for(i=0;i<totalWords;i++) {
  if(strcmp(status, words[i])==0) {
  index[i] = 1;
  		}
  	}
  }
  fclose(file2);
//Test
  for(i=0;i<totalWords;i++) {
  printf("%s %d \n",words[i],index[i]);
  }
  return 0;
  }
   
 
//multiplication of 2nd and 3rd array 
 
//get the sum 
 
