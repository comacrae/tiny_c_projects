#include <stdio.h>
#include <string.h>
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
  char buff[64];
  char ch;
  int i;

  printf("Enter a word or phrase: ");
  fgets(buff, 64, stdin);

  i = 0;
  while(buff[i] && i < 64){
    ch = toupper(buff[i++]);
    if(isalpha(ch))
      printf("%s ",nato[ch-'A']);
  }

  putc('\n',stdout);

  return(0);
}