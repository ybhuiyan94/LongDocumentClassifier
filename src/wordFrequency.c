#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 9999	// # of characters to be read from each file

int main(int argc, char **argv){
	char in[BUFFERSIZE];	// will hold contents of file
	char c; 				// used to temporarily store characters from the file
	FILE *file;
	int i;

	// initialize char array to null
	for(i = 0; i< BUFFERSIZE; i++){
		in[i] = '\0';
	}

	file = fopen(argv[1], "r");

	i = 0;
	while((c = getc(file)) != EOF)
    {
      in[i] = c;
      i++;
    } 

    printf("%s\n", &in);
}