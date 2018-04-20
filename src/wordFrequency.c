#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 999999	// # of characters to be read from each file
#define MAXWORDSIZE 15
#define MAXWORDSTRACKED 1000

void processText(FILE *file);
int isLetter(char c);
void trackWord(char* word);
void sortTracked();
void writeFile();
void initFromFile();

char tracked[MAXWORDSTRACKED][MAXWORDSIZE];	// string array
int count[MAXWORDSTRACKED];					// int array
int wordsTracked = 0;						// current count of words in tracked array

int main(int argc, char **argv) {	
	FILE *article = fopen(argv[1], "r");

	processText(article);
    sortTracked();
    writeFile();
    
    fclose(article);
}

// This function will open a text file and read it word by word,
// convert each word to lowercase, and then track each word.
void processText(FILE *file){
	char in[BUFFERSIZE];	// will hold contents of file
	char c; 				// used to temporarily store characters from the file
	char word[MAXWORDSIZE];
	int i, y;

	// initialize count array to 0
	for(i = 0; i < MAXWORDSTRACKED; i++){
		count[i] = 0;
	}

	// initialize char array to null
	for(i = 0; i < BUFFERSIZE; i++){
		in[i] = '\0';
	}

	// initialize tracking arrays
	initFromFile();

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
    		for(y = 0; y < MAXWORDSIZE-1; y++)
    			word[y] = tolower(word[y]);
    		trackWord(word);
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

// Function takes a word and tracks if
// if it is a new word, adds to the end of the list and count = 1
// if word already found, count++ for that index
void trackWord(char* word) {
	int length;
	int found = -1;
	int i;

	// return if we are at max words tracked
	if(wordsTracked == MAXWORDSTRACKED){
		return;
	}

	wordsTracked++;

	i = 0;
	while(i < MAXWORDSTRACKED) {

		if(strcmp(word, tracked[i]) == 0){
			found = i;
			break;
		}
		i++;
	}

	if(found == -1){
		// printf("here1");
		strcpy(tracked[wordsTracked-1], word);
		count[wordsTracked-1]++;
	} else {
		wordsTracked--;
		count[found]++;
	}


}

// sorts the tracked strings and counts in decreasing numerical order
// Bubble sort
void sortTracked(){
	int i,k;
	int tempInt;
	char tempWord[MAXWORDSIZE];

	for(i = 0; i<MAXWORDSTRACKED-1; i++) {
    	for(k = 0; k<MAXWORDSTRACKED-1-i; k++) {
        	if(count[k] < count[k+1]) {
            	tempInt = count[k];
            	strcpy(tempWord, tracked[k]);
            	count[k] = count[k+1];
            	strcpy(tracked[k], tracked[k+1]);
            	count[k+1] = tempInt;
            	strcpy(tracked[k+1], tempWord);
        	}
    	}
	}	

}

void initFromFile(){
	int lineLength = MAXWORDSIZE + 10;			// used to reserve space for count after word in line
	char line[lineLength];

	FILE *init = fopen("output.txt", "r+");
	if(init == '\0'){
		return;
	}

	while (fgets(line, sizeof(line), init)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }

    fclose(init);

}

// Writes count to file "output.txt" with each line in
// the format:
// word 42
void writeFile(){
	FILE *out = fopen("output.txt", "w+");
	int i;

	for(i = 0; i < MAXWORDSTRACKED; i++){
    	if(count[i] != 0){
    		fprintf(out, "%s %d\n", &tracked[i], count[i]);
    	}
    }

    fclose(out);

}