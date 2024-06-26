#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isterm(char * term);

int main(int argc, char * argv[])
{
  FILE * fp;
  char phrase[64];
  char *match;
  char ch;

  if(argc < 2)
  {
    fprintf(stderr, "Please enter the name of the input file.\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if(fp == NULL)
  {
    fprintf(stderr, "Unable to open file named %s\n", argv[1]);
  }

  while(!feof(fp))
  {
    fgets(phrase, 64, fp);
    match = strtok(phrase, " ");
    while(match)
    {
      if((ch = isterm(match)) != '\0')
      {
        putchar(ch);
      }
      match = strtok(NULL, " ,.!?=()[]{}'\""); // null is used to keep searching for the same string
    }
  }
  return 0;
}

char isterm(char* term){
  const char* nato[] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};

  int x;
  const char *n;
  char *t;

  for(x = 0; x < 26; x++){

    t = term;
    n = nato[x];
    while(*n != '\0')
    {
      if((*n|0x20) != (*t|0x20)) // trick to convert to uppercase using bit operator
        break;
      
      n++;
      t++;
    }
    if(*n=='\0'){
      return (*nato[x]);
    }
  }

  return('\0');
}