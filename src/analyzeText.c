#include  <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <math.h>


#define BUFFERSIZE 999999 // # of characters to be read from each file
#define MAXWORDSIZE 25
#define MAXWORDSTRACKED 9999
#define CATEGORYCOUNT 3

void initTrackingArrays(FILE *weights);
void readText(FILE *article);
int isLetter(char c);
void wordFound(char* word);
void predict();
double sigmoid(double score);

char trackingStrings[MAXWORDSTRACKED][MAXWORDSIZE];
int trackingVector[MAXWORDSTRACKED];
double weightVector[MAXWORDSTRACKED][CATEGORYCOUNT];
int totalWords = 0;
int articleWords = 0;
 
//Declaring Variables.
int main(int argc, char **argv) { 
  FILE *weights = fopen(argv[1], "r");
  FILE *article = fopen(argv[2], "r");

  initTrackingArrays(weights);
  fclose(weights);

  readText(article);
  fclose(article);

  predict();

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

// if we are tracking that word increment its count
void wordFound(char* word) {
  int x = 0;

  articleWords++;
  while(x < totalWords){
    if(strcmp(word, trackingStrings[x]) == 0) {
      trackingVector[x]++;
      break;
    }
    x++;
  }
}

void predict() {
  int x;
  double moneyScore = 0;
  double politicsScore = 0;
  double sportsScore = 0;
  double sum;

  for(x = 0; x < totalWords; x++) {
    moneyScore += (double) trackingVector[x] * weightVector[x][0];
    politicsScore += (double) trackingVector[x] * weightVector[x][1];
    sportsScore += (double) trackingVector[x] * weightVector[x][2];
  }

  sum = moneyScore + politicsScore + sportsScore;

  printf("Money: %lf\n", moneyScore/sum);
  printf("Politics: %lf\n", politicsScore/sum);
  printf("Sports: %lf\n", sportsScore/sum);

  // moneyScore = sigmoid(moneyScore);
  // politicsScore = sigmoid(politicsScore);
  // sportsScore = sigmoid(sportsScore);

  // printf("Money: %lf\n", moneyScore);
  // printf("Politics: %lf\n", politicsScore);
  // printf("Sports: %lf\n", sportsScore);

}

// x/sqrt(1+x^2)
double sigmoid(double score) {
  int wordsFound = 0;
  int i;

  for(i = 0; i < totalWords; i++) {
    if(trackingVector[i] > 0){
      wordsFound += trackingVector[i];
    }
  }
  score = score*(double)wordsFound/(double)articleWords;

  score = score/sqrt(1+score*score);

  return score;
}
 
