#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char op, name[100];
  
  while(1){
    scanf("%c", &op);
    if(op == '@'){
      scanf("\n");
      fgets(name , 100, stdin);
      printf("%s", name);
    }
    else
      continue;
    
  }
  return 0;
}
