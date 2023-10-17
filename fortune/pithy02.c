#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main(int argc, char * argv[]){

	const char filename[] = "pithy.txt";
	FILE *fp;
	char buffer[BSIZE]; // used to read text from the file
	char *r, *entry;
	int count = 1;

	fp = fopen(filename, "r");
	if(fp==NULL){
		fprintf(stderr, "Unable to open file %s\n", filename);	
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
		printf("%d, %s\n",count, entry);
		count++;

	}

	fclose(fp);

	return 0;
}
