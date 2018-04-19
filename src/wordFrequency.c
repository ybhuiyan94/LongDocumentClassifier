#include <stdio.h>
#include <string.h>
#include <string.h>


#define BUFFERSIZE 999999	// # of characters to be read from each file
#define MAXWORDSIZE 15
#define WORDSTRACKED 9999

int isLetter(char c);

char tracked[WORDSTRACKED][MAXWORDSIZE];

int main(int argc, char **argv){
	char in[BUFFERSIZE];	// will hold contents of file
	char c; 				// used to temporarily store characters from the file
	FILE *file;
	int i, y;
	char word[MAXWORDSIZE];


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
    	printf("%d: ", i);
    	for(y = 0; y < MAXWORDSIZE; y++){
			word[y] = '\0';
		}
    	y=0;
    	while(isLetter(c = in[i]) == 1){
    		word[y] = c;
    		y++;
    		i++;
    	}
    	i++;
    	printf("%s\n", &word);


    }

}

int isLetter(char c){
	if((c >= 0 && c <= 9) ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z')){
		return 1;
	}

	return 0;
}