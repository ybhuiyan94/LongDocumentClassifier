#include  <stdio.h> 
#include <string.h>
#include <ctype.h>


#define BUFFERSIZE 999999 // # of characters to be read from each file
#define MAXWORDSIZE 25
#define MAXWORDSTRACKED 9999
#define CATEGORYCOUNT 3

void initTrackingArrays(FILE *weights);
void readText(FILE *article);
int isLetter(char c);
void wordFound(char* word);

char trackingStrings[MAXWORDSTRACKED][MAXWORDSIZE];
int trackingVector[MAXWORDSTRACKED];
double weightVector[MAXWORDSTRACKED][CATEGORYCOUNT];
int totalWords = 0;
 
//Declaring Variables.
int main(int argc, char **argv) { 
  FILE *weights = fopen(argv[1], "r");
  FILE *article = fopen(argv[2], "r");

  initTrackingArrays(weights);
  close(weights);
  readText(article);
  close(article);

  int x = 0;
  while(x < totalWords){
    printf("%s %d %lf %lf %lf\n", &trackingStrings[x],
      trackingVector[x],
      weightVector[x][0], 
      weightVector[x][1],
      weightVector[x][2]);
    x++;
  }
  
  return 0;
}

void initTrackingArrays(FILE *weights) {
  int i, y;
  char *tempString;

  // Initialize tracking arrays to 0 or null
  for(i = 0; i < MAXWORDSTRACKED; i++) {
    for(y = 0; y < MAXWORDSIZE; y++) {
      trackingStrings[i][y] = '\0';
    }
    for(y = 0; y < CATEGORYCOUNT; y++) {      
      weightVector[i][y] = 0;
    }
  }

  while(fscanf(weights, "%s %lf %lf %lf", &trackingStrings[totalWords],
      &weightVector[totalWords][0], 
      &weightVector[totalWords][1],
      &weightVector[totalWords][2]) == 4)  {
      totalWords++;
  }
}

// This function will open a text file and read it word by word,
// convert each word to lowercase, and then track each word.
void readText(FILE *file){
  char in[BUFFERSIZE];  // will hold contents of file
  char c;         // used to temporarily store characters from the file
  char word[MAXWORDSIZE];
  int i, y;

  // initialize char array to null
  for(i = 0; i < BUFFERSIZE; i++){
    in[i] = '\0';
  }

  i = 0;
  while(i <= totalWords){
    trackingVector[i] = 0;  // initialize all to 0 (false)
    i++;
  }

  // read file and store in in[]
  i = 0;
  while((c = getc(file)) != EOF)
    {
      in[i] = c;
      i++;
    } 

    // read contents of file word by word
    i = 0;
    while(i < BUFFERSIZE){
      // set word to null
      for(y = 0; y < MAXWORDSIZE; y++){
        word[y] = '\0';
      }
      y=0;

      // keep adding to word until non letter
      while((isLetter(c = in[i]) == 1) &&
          (y < MAXWORDSIZE-1)){
        word[y] = c;
        y++;
        i++;
      }
      i++;

      // if word is not null, convert to lowercase and track
      if(strlen(word) != 0) {
        for(y = 0; y < MAXWORDSIZE-1; y++){
          word[y] = tolower(word[y]);
        }
        wordFound(word);
      }


    }
}

// Returns 1 if letter, 0 if not
int isLetter(char c) {
  if((c >= 0 && c <= 9) ||
    (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z')){
    return 1;
  }

  return 0;
}

// if we are tracking that word set its status to 1 (true)
void wordFound(char* word) {
  int x = 0;
  while(x < totalWords){
    if(strcmp(word, trackingStrings[x]) == 0) {
      trackingVector[x]  = 1;
      break;
    }
    x++;
  }
}
   
 
//multiplication of 2nd and 3rd array 
 
//get the sum 
 
