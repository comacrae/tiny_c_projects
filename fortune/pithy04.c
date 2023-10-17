#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main(int argc, char * argv[]){

	const char filename[] = "pithy.txt";
	FILE *fp;
	char buffer[BSIZE]; // used to read text from the file
	char *r, *entry;
	char **buffers;
	int count = 0;

	fp = fopen(filename, "r");
	if(fp==NULL){
		fprintf(stderr, "Unable to open file %s\n", filename);	
		exit(1);
	}

	buffers = (char**) malloc(sizeof(char*) * 100);

	if(buffers == NULL){
		fprintf(stderr, "Unable to allocate memory\n");	
		exit(1);
	}

	while(! feof(fp)){

		r = fgets(buffer, BSIZE, fp); // load BSIZE chars from FILE ptr to char buffer
		if(r == NULL) 
			break;

		entry=(char *) malloc(sizeof(char) * (strlen(buffer)+1));

		if(entry == NULL){
			fprintf(stderr, "Unable to allocate memory\n");
			exit(1);
		}



		strcpy(entry,buffer); // to entry from buffer

		*(buffers + count) = entry;
	}

	fclose(fp);

	for(int i = 0; i < count; i++){
		printf("%d %s\n", i, *(buffers + i));
	}

	return(0);
}



