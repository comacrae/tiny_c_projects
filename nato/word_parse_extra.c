#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

int main(int argc, char* argv[]){

  FILE *fp;
  char* buff =  (char*) malloc(sizeof(char) * BUF_SIZE); // just for practice malloc'ing honestly

  if(argc < 2){
    fprintf(stderr,"You must enter a filepath to be parsed.");
    exit(1);
  }

  fp = fopen(argv[1],"r");

  if(fp == NULL){
    fprintf(stderr, "File cannot be read.");
    exit(1);
  }

  while(!feof(fp)){
    buff = fgets(buff,BUF_SIZE,fp); // parsing stops 

    for( int i = 0; i < sizeof(buff) / sizeof(char); i++){ 
    }
  }

  return(0);
}