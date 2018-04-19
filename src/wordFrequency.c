#include <stdio.h>
#include <string.h>
#include <string.h>


#define BUFFERSIZE 999999	// # of characters to be read from each file
#define MAXWORDSIZE 15
#define MAXWORDSTRACKED 1000

int isLetter(char c);
void trackWord(char* word);
void sortTracked();

char tracked[MAXWORDSTRACKED][MAXWORDSIZE];
int count[MAXWORDSTRACKED];
int wordsTracked = 0;

int main(int argc, char **argv) {
	char in[BUFFERSIZE];	// will hold contents of file
	char c; 				// used to temporarily store characters from the file
	FILE *file;
	int i, y;
	char word[MAXWORDSIZE];

	for(i = 0; i < MAXWORDSTRACKED; i++){
		count[i] = 0;
	}

	// initialize char array to null
	for(i = 0; i < BUFFERSIZE; i++){
		in[i] = '\0';
	}

	// read file and store in in[]
	file = fopen(argv[1], "r");
	i = 0;
	while((c = getc(file)) != EOF)
    {
      in[i] = c;
      i++;
    } 

    printf("%s\n", &in);

    i = 0;
    while(i < BUFFERSIZE){
    	// set word to null
    	for(y = 0; y < MAXWORDSIZE; y++){
			word[y] = '\0';
		}
    	y=0;
    	while((isLetter(c = in[i]) == 1) &&
    			(y < MAXWORDSIZE-1)){
    		word[y] = c;
    		y++;
    		i++;
    	}
    	i++;

    	if(strlen(word) != 0) {
    		for(y = 0; y < MAXWORDSIZE-1; y++)
    			word[y] = tolower(word[y]);
    		trackWord(word);
    	}


    }

    // sortTracked();

    for(i = 0; i < MAXWORDSTRACKED; i++){
    	if(count[i] != 0){
    		printf("%s %d\n", &tracked[i], count[i]);
    	}
    }


}

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

void sortTracked(){
	int i,k;
	int tempInt;
	char tempWord[MAXWORDSIZE];



for(i = 0; i<MAXWORDSTRACKED-1; i++) {
    for(k = 0; k<MAXWORDSTRACKED-1-i; k++) {
        if(count[k] < count[k+1]) {
            tempInt = count[k];
            count[k] = count[k+1];
            count[k+1] = tempInt;
        }
    }
}

}