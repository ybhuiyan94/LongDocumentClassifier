#include<stdio.h> 
#include<stdlib.h> 
 
//Declaring the 3 arrays. 
void categoryArrays(String words[],int status[], double weights[][]) 
 
//Declaring Variables. Number of indexes should be 15 or 1000 or 9999999? 
int main(){ 
  FILE *file; 
  FILE *file2; 
  char c; 
  int size = 999999999; 
  String words[size]; 
  int status[size]; 
  double weights[size][3]; 
  double sum1,sum2,sum3; 
  int size1,size2,size3; 
   
//intialize arrays to null 
  for( int i = 0; i < size; i++){ 
    words[i] = '\0'; 
  } 
  for( int j = 0; j < size; j++){ 
    status[j] = '0'; 
  } 
  for( int k = 0; k < size; k++){  //will change to nested forloop for all 3 columns. 
    weights[k] = '0.0'; 
  } 
 
//open and read file 
  fp = fopen(file, "r"); 
  while((c = getc(file)) != EOF){ 
    words[i] = c; 
  } 
   
 
//multiplication of 2nd and 3rd array 
 
//get the sum 
 
