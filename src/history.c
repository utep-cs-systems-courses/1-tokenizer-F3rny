#include "history.h"
#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

List* init_history(){
/* Create the linked list to keep the history */
  List* history = malloc(sizeof(List));
  history -> root = NULL;
  //printf("init mate\n");
  return history;

}
void add_history(List *list, char *str){
  Item *temp = malloc(sizeof(Item));
  if(list -> root = NULL){
    temp -> id = 0;
  }
  else{
    list -> root -> id + 1;
  }
  int sindex = 0;
  while(*(str+sindex) != '\0'){
    sindex++;

  }
  char *str_copy = malloc((sindex+1) * sizeof(char)), c;
  sindex = 0;
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
void print_history(List *list){
  Item *current = list -> root;
  while(current != NULL){
    printf("%d -> %s ", current-> id, current->str);
    current = current -> next;
       
  }
}
void free_history(List *list){
  free(list);

}
