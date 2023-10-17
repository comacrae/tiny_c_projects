#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char* argv[]){

  const char *nato[] = {
   "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
   "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
   "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
   "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
   "Xray", "Yankee", "Zulu"
  };
  char ch;
  FILE *f;

  if(argc < 2){
    fprintf(stderr, "Must enter path of a file to be read.\n");
    exit(1);
  }

  f = fopen(argv[1],"r"); // get file pointer
  if(f == NULL){
    fprintf(stderr, "Unable to open file.\n");
    exit(1);
  }

  while((ch = fgetc(f)) != EOF){
    if(isalpha(ch))
      printf("%s ", nato[(toupper(ch) - 'A')]);
  }
    putchar('\n');
  
  fclose(f);


  return(0);
}