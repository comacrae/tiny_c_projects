#include <stdio.h>
#include <string.h>
#include <ctype.h>

char is_term(char* input);

int main(int argc, char* argv[]){

  char buff[64];
  char* match;
  char* delims = " ,.!?:;\"'";
  char nato_to_ch = '\0';

  fputs("Enter a NATO word or phrase: ", stdout);
  fgets(buff,64,stdin);
  match = strtok(buff, delims);

  while(match != NULL){
    nato_to_ch = is_term(match); // get letter corresonding to NATO term (if valid)

    if(nato_to_ch != '\0') // only print valid chars, not endline
      putchar(nato_to_ch);
    match = strtok(NULL,delims);
  }
  putchar('\n');

  return(0);
}

char is_term(char *term){ // function gets token, checks if it's a NATO term, and returns corresponding char. If invalid return '\0'
  int nato_idx;
  char *nato_ltr,*term_ltr;

  const char *nato[] = {
      "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
      "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
      "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
      "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
      "Xray", "Yankee", "Zulu"
  };

  nato_idx = tolower(term[0]) - 'a';

  if( (nato_idx > -1) && (nato_idx <26) ){ // if valid nato_idx (letter is between A-Z)
    nato_ltr = nato[nato_idx] + 1;
    term_ltr = term + 1;

    while(*nato_ltr == *term_ltr && *term_ltr != '\0' && *nato_ltr != '\0'){
      nato_ltr++;
      term_ltr++;
    }

    if(*nato_ltr == '\0'){ // if pointing at terminating char, then term is a NATO letter
      return(*nato[nato_idx]); // get first NATO char
    }else{
      return('\0');
    }

  }else{
    return('\0');
  } 
}
