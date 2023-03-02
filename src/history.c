#include "history.h"
#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

List* init_history(){
/* Create the linked list to keep the history */
  List* history = (List*) malloc(sizeof(List));
  history -> root = NULL;
  //printf("init mate\n");
  return history;

}
void add_history(List *list, char *str){
  Item *temp = (Item*) malloc(sizeof(Item));
  temp-> next = NULL;
  
  int sindex = 0;
  while(*(str+sindex) != '\0'){
    sindex++;

  }
  temp->str = copy_str(str, sindex);
  if(list -> root == NULL){
    list-> root = temp;
    temp -> id = 1;
  }
  else{
    Item *current_Item = list -> root;
    int id_next = 2;
    while(current_Item-> next != NULL){
      id_next += 1;
      current_Item = current_Item -> next;
    }
    temp -> id = id_next;
    current_Item -> next = temp;
    
  }
  
}
char *get_history(List *list, int id){
  Item *current = list -> root;
    while(current != NULL){
      if(current -> id == id){
	printf("ID : (%d) String: -> (%s)\n", current->id, current->str);
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
