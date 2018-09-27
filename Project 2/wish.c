#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_bltn(char *cmd);


int main(int argc, char const *argv[]) {

  char *input;
  size_t i_size = 64;
  size_t command;
  input = (char*)malloc(i_size * sizeof(char));

  //if more than one argument is given, throw error and exit
  if(argc>2)
  {
    perror("An error has occurred.\n");
    exit(1);
  }


  //if no argument is given, run in interactive mode
  else if(argc == 1)
  {  

    while (input != NULL) {
      check_bltn(input);
      printf("wish> " );
      command = getline(&input, &i_size, stdin);
    }
    exit(0);
  }


  //if an argument (file name) is given, run in batch mode
  else
  {
    FILE *wish_file = fopen(argv[1], "r");

    if (wish_file == NULL)
    {
      perror("An error has occurred.\n");
      exit(1);
    }

    while(!feof(wish_file))
    {
      command = getline(&input, &i_size, wish_file);
    }

    fclose(wish_file);
    exit(0);
  }




  free(input);
  return 0;
}

void check_bltn(char *cmd){

  if (strcmp(cmd,"exit\n") == 0)
  {
    exit(0);
  }

  else if (strcmp(cmd, "cd\n") == 0)
  {
    // chdir(arg);
    printf("hi\n");
  }

  else if (strcmp(cmd, "path\n") == 0)
  {
    /* code */
  }

  else{
    /* code */
  }

}