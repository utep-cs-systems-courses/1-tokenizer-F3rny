#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
if(c == ' ' || c ==  '\t')
   return 1;
 else
   return 0;
}

int non_space_char(char c){
  if(c != ' ' && c != '\t')
    return 1;
  else
    return 0;
}

char *word_start(char *str){
  while(*str != '\0' && space_char(*str)){
    str++;
  }
  return str;
  
}

char *word_terminator(char *word){
/* Returns a pointer terminator char following *word */
  while(*word != '\0' && space_char(*word)){
    word++;
  }
  if(*word != '\0' && non_space_char(*word+1)){
    while(*(word+1) != '\0' && (non_space_char(*word) )){
      word++;
    }
    return word-1;

  }
  else{
    return word;
  }
}

int count_words(char *str){
/* Counts the number of words in the string argument. */
 int count = 0;
 int inword = 0;
 while(*str != '\0'){
   if(space_char(*str)){
     inword = 0;
   }
   else if(inword == 0){
     inword = 1;
     count++;
   }
   str++;
 }
 return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
