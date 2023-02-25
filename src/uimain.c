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
  printf("word_start:\n ");
  printf(&(*word_start(name)));
  printf("word_terminator:\n ");
  printf(&(*word_terminator(name)));
  printf("The amonut of words: %d\n", count_words(name));
  char *copy = copy_str(name,5);
  printf("Copy_str: \"%s\"\n", copy);
  char **token = tokenize(name);
  printf("Printing Tokens ...\n");
  printf("-----------------------\n");
  print_tokens(token);
  printf("-----------------------\n");
  printf("Freeing...\n");
  free_tokens(token);
  return 0;
}

