#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char** argv){

  const char* alphabet[] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
  char ch;
  FILE* fp = NULL;

  if(argc < 2){
    fprintf(stderr, "Error: Filename not provided\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if(fp == NULL){
    fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
    exit(1);
  }

  while((ch = fgetc(fp)) != EOF){
    if(isalpha(ch)){
      printf("%s ", alphabet[toupper(ch) - 'A']);
    }
  }
  putchar('\n');

  fclose(fp);
  return 0;
}