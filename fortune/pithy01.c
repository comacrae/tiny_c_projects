#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256

int main(int argc, char * argv[]){

	const char filename[] = "pithy.txt";
	FILE *fp;
	char buffer[BSIZE]; // used to read text from the file
	char *r;

	fp = fopen(filename, "r");
	if(fp==NULL){
		fprintf(stderr, "Unable to open file %s\n", filename);	
		exit(1);
	}

	while( ! feof(fp) ){
		r = fgets(buffer, BSIZE, fp); // load BSIZE chars from FILE ptr to char buffer
		if(r == NULL) 
			break;
		printf("%s\n",buffer);
	}

	fclose(fp);

	return 0;
}
