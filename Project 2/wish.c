#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  char *input;
  size_t i_size = 64;
  size_t command;
  input = (char*)malloc(i_size * sizeof(char));

  //if more than one argument is given, throw error and exit
  if(argc>2)
  {
    perror("arguments must be one or none.");
    exit(0);
  }


  //if no argument is given, run in interactive mode
  else if(argc == 1)
  {  
    char* end = "exit";

    while (input != end) {
      printf("wish> " );
      command = getline(&input, &i_size, stdin);
    }

  }


  //if an argument (file name) is given, run in batch mode
  else
  {
    FILE *wish_file = fopen(argv[1], "r");

    if (wish_file == NULL)
    {
      perror("error opening file.");
      exit(0);
    }

    while(!feof(wish_file))
    {
      command = getline(&input, &i_size, wish_file);
    }

  }




  free(input);
  return 0;
}
