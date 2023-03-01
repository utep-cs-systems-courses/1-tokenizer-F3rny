#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
int main()

{

  char checkpoint[100];

  char name[100];

  char command[100];

  char** token = NULL;

  List* history = init_history(); // initialize list





  while (1) // loop till user quits

    {

      printf("Enter character 'c' to write string , 'h' to view history , 'g' get history, 'q' to quit \n");

      scanf("%s", &checkpoint);

      getchar(); //consume the newline char left in input buffer

      printf("\n");





      switch(checkpoint[0]){

      case 'c':

	printf("ENter a string of words after the '$':\n");

	printf("$ ");

	fgets(name, sizeof(name), stdin);

	printf("%s", name);



	token = tokenize(name);

	print_tokens(token);

	add_history(history, name);

	free_tokens(token);

	break;

      case 'h':

	print_history(history);

	break;

      case 'g':

	printf("Please enter a number by using command (!#)\n");

	scanf("%s", &command);

	getchar();

	int index = atoi(command + 1);

	char *h = get_history(history , index); // grabs string

	break;

      case 'q':

	goto done;



      default:

	printf("PLease select a valid option\n");

	break;



      }

    }

 done:

  printf("History freed\n");



  free_history(history);



  printf("You exited the program! Goodbye!");

  return 0;

}
