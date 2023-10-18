#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

  char buff[64];
  char* match;
  char* delims = " ,.!?:;\"'";

  fputs("Enter some words: ", stdout);
  fgets(buff,64,stdin);
  match = strtok(buff, delims);
  while(match != NULL){
    printf("%s\n", match);
    match = strtok(NULL,delims);
  }


  return(0);
}