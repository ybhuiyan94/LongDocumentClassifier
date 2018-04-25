#include  <stdio.h> 
#include  <stdlib.h> 
#include <string.h>
#include <math.h> 
#include <ctype.h>

#define BUFFERSIZE 999999 // # of characters to be read from each file
#define MAXWORDSIZE 25
#define MAXWORDSTRACKED 9999
#define CATEGORYCOUNT 3

void initArrays();
void readFreqFile(FILE *in, int category);

char trackingStrings[MAXWORDSTRACKED][MAXWORDSIZE];
double weightVector[MAXWORDSTRACKED][CATEGORYCOUNT];
int totalWords = 0;

int main(int argc, char **argv) {
	FILE *in;
	int i;

	initArrays();

	for(i = 1; i <= CATEGORYCOUNT; i++){
		in = fopen(argv[i], "r");
		readFreqFile(in, i);
	}
}

// put strings in string array, frequencies in weightVector
void initArrays() {
	int i, y;
	// Initialize tracking arrays to 0 or null
  for(i = 0; i < MAXWORDSTRACKED; i++) {
    for(y = 0; y < MAXWORDSIZE; y++) {
      trackingStrings[i][y] = '\0';
    }
    for(y = 0; y < CATEGORYCOUNT; y++) {      
      weightVector[i][y] = 0;
    }
  }

  
}

void readFreqFile(FILE *in, int category) {
	char word[MAXWORDSIZE];
	int freq;

	while(fscanf(in, "%s %d", &word, &freq) == 2)  {
			printf("%s %d\n", &word, freq);
      totalWords++;
  }
}
