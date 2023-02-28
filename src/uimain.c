#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
int main()
{
  char checkpoint;
  char name[100];
  char** token = NULL;
  List* history = init_history(); // initialize list

  while (1) // loop till user quits
 {
     printf("ENter a string of words after the '$':\n");
     printf("$ ");
     fgets(name, sizeof(name), stdin);
     printf("%s", name);

     token = tokenize(name);
     print_tokens(token);
     add_history(history, name);
     
     printf("Enter character 'h' for history , '>' for String, 'q' to quit \n");
     scanf("%c", &checkpoint);
     getchar(); //consume the newline char left in input buffer
     printf("\n");

     if(checkpoint == '>'){
       char *h = get_history(history , atoi(name)); // grabs string
       if(h != NULL){
	 char **tokens = tokenize(h);
	 printf("History: %s\n", h);
	 print_tokens(tokens);
	 free_tokens(tokens);
       }
     }
     else if(checkpoint == 'h'){
       print_history(history);
     }
     else if(checkpoint == 'q'){
       break;
     }
     else{
       printf("Invalid char\n");
     }
     
     free_history(history);
 }

  return 0;
}
