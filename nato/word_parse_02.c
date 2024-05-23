#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char isterm(char * term);

int main(int argc, char * argv[])
{
  FILE * fp;
  char buff[64] = "";
  int ch, offset;

  if(argc < 2)
  {
    fprintf(stderr, "Please enter the name of the input file.\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if(fp == NULL)
  {
    fprintf(stderr, "Unable to open file named %s\n", argv[1]);
    exit(1);
  }

  offset = 0;
  while((ch = fgetc(fp)) != EOF)
  {
    if(isalpha(ch))
    {
      buff[offset++] = ch;

      if(offset >= 64)
      {
        fprintf(stderr, "The word %s is too long\n", buff);
        exit(1);
      }
    }else{
      buff[offset] = '\0';
      putchar(isterm(buff));
      offset = 0;
    }
  }
  putchar('\n');
  fclose(fp);

  
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