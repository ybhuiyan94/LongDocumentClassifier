#include <stdio.h>
#include <string.h>
#include <string.h>


#define BUFFERSIZE 9999	// # of characters to be read from each file
#define MAXWORDSIZE 15

int isLetter(char c);

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

    // i = 0;
    // while(i < BUFFERSIZE){
    // 	y=0;
    // 	while(isLetter(in[i]) == 1){
    // 		c = word[i];
    // 		word[y] = c;
    // 		y++;
    // 		i++;
    // 	}
    // 	word[y] = '\0';
    // 	i++;
    // 	    printf("%s\n", &word);
    // }

}

int isLetter(char c){
	if((c >= 0 && c <= 9) ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z')){
		return 1;
	} else {
		return 0;
	}
}