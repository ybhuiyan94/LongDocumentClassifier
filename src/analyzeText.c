#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>
#include <math.h> 

#define MAXWORDSIZE 25
#define MAXWORDSTRACKED 9999
#define CATEGORYCOUNT 3

void initializeTracking(FILE *weights);

char *trackingStrings[MAXWORDSTRACKED];
int trackingVector[MAXWORDSTRACKED];
double weightVector[MAXWORDSTRACKED][CATEGORYCOUNT];
int totalWords = 0;
 
//Declaring Variables.
int main(int argc, char **argv) { 
  // FILE *article = fopen(argv[1], "r");
  FILE *weights = fopen(argv[1], "r");

  initializeTracking(weights);
  
// //Reading the words from the file.
  
//   fclose(file);
// //Opening 2nd file.
//   file2 = fopen("article2.txt","r");
//   while(fscanf(file2,"%s",status)==1) {
// //Checking if words match and assigning 1 or 0's.
//   for(i=0;i<totalWords;i++) {
//   if(strcmp(status, words[i])==0) {
//   index[i] = 1;
//   		}
//   	}
//   }
//   fclose(file2);
// //Test
//   for(i=0;i<totalWords;i++) {
//   printf("%s %d \n",words[i],index[i]);
//   }
  return 0;
}

void initializeTracking(FILE *weights) {
  int i, y;
  char *tempString;

  // Initialize tracking arrays
  for(i = 0; i < MAXWORDSTRACKED; i++) {
    trackingStrings[i] = (char *)malloc(MAXWORDSIZE);
    for(y = 0; y < CATEGORYCOUNT; y++) {      
      weightVector[i][y] = 0;
    }
  }

  while(fscanf(weights, "%s %lf %lf %lf", &trackingStrings[totalWords],
      &weightVector[totalWords][0], 
      &weightVector[totalWords][1],
      &weightVector[totalWords][2]) == 4)  {
    printf("%s %lf %lf %lf\n", &trackingStrings[totalWords],
      weightVector[totalWords][0], 
      weightVector[totalWords][1],
      weightVector[totalWords][2]);
      totalWords++;
      i++;
  }





}
   
 
//multiplication of 2nd and 3rd array 
 
//get the sum 
 
