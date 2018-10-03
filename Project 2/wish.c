#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void check_bltn(char *cmd, char *arg);
char *input, *bltn_cmd, *argmnt;
size_t i_size = 64;
size_t command;
char *delimiters = "&\\/:;=- ";
char cmd_args[100];

int main(int argc, char const *argv[])
{
  input = (char *)malloc(i_size * sizeof(char));
  //if more than one argument is given, throw error and exit
  if (argc > 2)
  {
    perror("An error has occurred.\n");
    exit(1);
  }

  //if no argument is given, run in interactive mode
  else if (argc == 1)
  {
    bltn_cmd = strtok(input, delimiters);
    while (input != NULL)
    {

      for (argmnt = strtok(cmd_args, delimiters);
           argmnt;
           argmnt = strtok(NULL, delimiters))
      {
        printf("%s",argmnt);
      }

      check_bltn(bltn_cmd, argmnt);
      printf("wish> ");
      command = getline(&input, &i_size, stdin);
      // if (commands separated by &)
      // {
      //   /*run each command within the */
      // }
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

    while (!feof(wish_file))
    {
      command = getline(&input, &i_size, wish_file);
    }

    fclose(wish_file);
    exit(0);
  }

  free(input);
  return 0;
}

void check_bltn(char *cmd, char *arg)
{

  if (strcmp(cmd, "exit") == 0)
  {
    if (arg == NULL)
    {
        exit(0);
    }
    else
    {
      perror("An error has occurred.\n");
      exit(1);
    }
  }

  else if (strstr(cmd, "cd") != NULL)
  {

    chdir(arg);
  }

  else if (strstr(cmd, "path") != NULL)
  {
    /* code */
  }

  else
  {
    /* code */
  }
}