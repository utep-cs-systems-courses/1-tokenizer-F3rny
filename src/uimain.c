#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char name[100];
  while(1){
    printf("$ ");
    fgets(name, sizeof(name), stdin);
    printf("%s", name);
    break;
  }
  char *first = word_start(name);
  char *last = word_terminator(name);
  printf("This is the first character after whitespace: %c\n", *first);
  printf("This is the last character of the first word: %c\n", *last);
  printf("%d\n", count_words(name));
  return 0;
}

