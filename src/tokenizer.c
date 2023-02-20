#include "history.h"
#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"



int space_char(char c){

  if(c == ' ' || c ==  '\t')

    return 1;

  else

    return 0;

}



int non_space_char(char c){

  if(c != ' ' && c != '\t' && c != '\0')

    return 1;

  else

    return 0;

}



char *word_start(char *str){

  while(space_char(*str)){

    str++;

  }
  if(non_space_char(*str)){
      return str;
  }
    return 0;


}



char *word_terminator(char *word){

  /* Returns a pointer terminator char following *word */

  while(non_space_char(*word)){
    word++;
  }
  if(space_char(*word)){
    return word;
  }
  return 0;
}



int count_words(char *str){

  /* Counts the number of words in the string argument. */

  int count = 0;

  while(str){
    str = word_start(str);
    if(str){

      count++;
      str = word_terminator(str);

    }

  }

  return count;

}
char *copy_str(char *inStr, short len){
  char *outStr = malloc(sizeof(char) * (len+1));
  int i = 0;
  while(i < len){
    outStr[i] = inStr[i];
    i++;
  }
  outStr[len+1] = '\0';
  return outStr;

}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){

}

/* Prints all tokens. */
void print_tokens(char **tokens){

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){

}
