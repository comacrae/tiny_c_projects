#include <stdio.h>
#include <string.h>

char isterm(char* term);

int main()
{
  char phrase[64];
  char *match;
  char ch;

  printf("Enter a NATO phrase: ");
  fgets(phrase,64,stdin);

  match = strtok(phrase, " ");
  while(match){
    if((ch = isterm(match)) != '\0'){
      putchar(ch);
    }
    match = strtok(NULL, " "); // null is used to keep searching for the same string
  }
  putchar('\n');
  return 0;
}

char isterm(char* term){
  printf("%s","Fuck");
  const char* nato[] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};

  int x;
  char *n, *t;

  t = term;
  for(x = 0; x < 26; x++){

    n = nato[x];
    while(*n != '\0')
    {
      if((*n|0x20) != (*t|0x20)) // trick to convert to uppercase using bit operator
        break;
      
      n++;
      t++;
    }
  }

  if(*n=='\0'){
    return (*nato[x]);
  }
  printf(*n);
  return('\0');
}