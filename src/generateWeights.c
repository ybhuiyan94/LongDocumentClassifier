#include  <stdio.h> 
#include <string.h>

#define BUFFERSIZE 999999 // # of characters to be read from each file
#define MAXWORDSIZE 25
#define MAXWORDSTRACKED 9999
#define CATEGORYCOUNT 3

void initArrays();
void readFreqFile(FILE *in, int category);
void calculateWeights();
void writeFile();

char trackingStrings[MAXWORDSTRACKED][MAXWORDSIZE];
double weightVector[MAXWORDSTRACKED][CATEGORYCOUNT];
int totalWords = 0;

int main(int argc, char **argv) {
	FILE *in;
	int i;

	initArrays();

	for(i = 1; i <= CATEGORYCOUNT; i++){	// read each file
		in = fopen(argv[i], "r");
		readFreqFile(in, i-1);
		fclose(in);
	}

	calculateWeights();
	writeFile();
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
	int found = -1;
	int i;

	// read line by line
	while(fscanf(in, "%s %d", &word, &freq) == 2)  {
			for(i = 0; i < totalWords; i++) {
				// check if we are already tracking this word
				if(strcmp(word, trackingStrings[i]) == 0){
					found = i;
					break;
				}
			}

			// put word and freq in correct locations
			if(found == -1) {
				strcpy(trackingStrings[totalWords], word);
				weightVector[totalWords][category] = (double) freq;
				totalWords++;
			} else {
				weightVector[found][category] = (double) freq;
			}
  }
}

// for each weight, frequencyInCategory/totalFrequency
// PROPORTIONAL
void calculateWeights() {
	int i, y;
	double sum;

	for(i = 0; i < totalWords; i++) {
		// sum of each line
		sum = 0;
		for(y = 0; y < CATEGORYCOUNT; y++) {
			sum += weightVector[i][y];
		}

		// calculate each weight
		for(y = 0; y < CATEGORYCOUNT; y++) {
			weightVector[i][y] = weightVector[i][y] / sum;
		}
	}
}

// // for each weight, frequencyInCategory/totalFrequency
// // EVEN SPLIT
// void calculateWeights() {
// 	int i, y;
// 	int found[CATEGORYCOUNT];
// 	int sum;

// 	for(i = 0; i < totalWords; i++) {
// 		for(y = 0; y < CATEGORYCOUNT; y++) {
// 			if(weightVector[i][y] > 0.0) {
// 				found[y] = 1;
// 			} else {
// 				found[y] = 0;			
// 			}
// 		}

// 		sum = found[0] + found[1] + found[2];

// 		// calculate each weight
// 		for(y = 0; y < CATEGORYCOUNT; y++) {
// 			weightVector[i][y] = (double) found[y]/ (double) sum;
// 		}
// 	}
// }

void writeFile(){
	FILE *out = fopen("weights.txt", "w+");
	int i, y;

	for(i = 0; i < totalWords; i++) {
    	fprintf(out, "%s %lf %lf %lf\n", &trackingStrings[i],
    	 weightVector[i][0], weightVector[i][3] ,weightVector[i][2]);
    }

  fclose(out);
}
