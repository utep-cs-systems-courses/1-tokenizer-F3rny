#include "history.h"
#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

List* init_history(){
/* Create the linked list to keep the history */
  List* history = malloc(sizeof(List));
  history -> root = NULL;
  printf("init mate\n");
  return history;

}
void add_history(List *list, char *str){
  printf("in add");
  Item *temp = malloc(sizeof(Item));
  printf("made temp");
  if((list -> root) = NULL){
    temp -> id = 0;
    printf("id is equal to 0");
  }
  else{
    list -> root -> id++;
  }
  int sindex = 0;
  char *str_copy = malloc((sizeof(str+1) * sizeof(char))),c;
  do{
    c = *(str_copy + sindex) = *(str + sindex);
    sindex++;
  }while(c);
  temp -> str = str_copy;
  temp -> next = list -> root;
  list -> root = temp;

}
char *get_history(List *list, int id){
  Item *current = list -> root;
    while(current != NULL){
      if(current -> id == id){
	return current -> str;
      }
      current = current -> next;
    }
  return NULL;
}
