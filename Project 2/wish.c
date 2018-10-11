#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

char *buffer[10];
void error_message();
void exit_shell(char *args);
int run_command(char *arg, char *param);

int main(int argc, char const *argv[])
{

  char *input, *argmnt, *params;
  size_t i_size = 64;
  input = (char *)malloc(i_size * sizeof(char));

  //if more than one argument is given, throw error and exit
  if (argc > 2)
  {
    error_message();
    exit(1);
  }

  //if no argument is given, run in interactive mode
  else if (argc == 1)
  {
    while (input != NULL)
    {

      //re-set elements in buffer to NULL
      for (int count = 0; count < 10; count++)
      {
        buffer[count] = NULL;
      }

      printf("wish> ");
      getline(&input, &i_size, stdin);

      //split input into tokens
      char *p = strtok(input, " \n\t");
      int count = 0;
      while (p != NULL)
      {
        buffer[count] = p;
        count++;

        p = strtok(NULL, " \n\t");
      }

      //get the command(e.g. exit, path, cd etc.) and arguments and use as parameters
      //in run_command function
      argmnt = buffer[0];
      params = buffer[1];
      run_command(argmnt, params);
    }
  }

  //if an argument (file name) is given, run in batch mode
  else
  {
    FILE *wish_file = fopen(argv[1], "r");

    if (wish_file == NULL)
    {
      error_message();
      exit(1);
    }

    //loop through entire file and get each line, store as input
    while (!feof(wish_file))
    {
      //reset buffer
      for (int count = 0; count < 10; count++)
      {
        buffer[count] = NULL;
      }
      getline(&input, &i_size, stdin);
      char *p = strtok(input, " \n\t");
      int count = 0;
      while (p != NULL)
      {
        buffer[count] = p;
        count++;

        p = strtok(NULL, " \n\t");
      }
    }

    argmnt = buffer[0];
    params = buffer[1];
    run_command(argmnt, params);

    fclose(wish_file);
    exit(0);
  }

  free(input);

  return 0;
}

//function which prints out error message
void error_message()
{
  char error_message[30] = "An error has occurred.\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

//function to exit the shell if no arguments are given after exit command
void exit_shell(char *args)
{
  if (!args)
  {
    exit(0);
  }
  else
  {
    error_message();
  }
}

//function which runs a given line as a command
int run_command(char *cmd, char *args)
{
  char *ext = "exit", *cd = "cd", *path = "path";
  if (strcmp(cmd, ext) == 0)
  {

    exit_shell(args);
  }
  else if (strcmp(cmd, cd) == 0)
  {
    //checks if there are no arguments or more than one argument
    if (args == NULL || buffer[2] != NULL)
    {
      error_message();
    }
    chdir(args);
  }
  else if (strcmp(cmd, path) == 0)
  {
    /* code */
  }
  else
  {
    char *bin = "/bin/";
    char *usrbin = "/usr/bin/";
    char *path1 = malloc(strlen(buffer[0]) + strlen(bin) + 1);
    char *path2 = malloc(strlen(buffer[0]) + strlen(usrbin) + 1);
    strcat(path1, bin);
    strcat(path1, buffer[0]);
    strcat(path2, usrbin);
    strcat(path2, buffer[0]);

    if (access(path1, X_OK) == 0)
    {
      pid_t fk = fork();

      if (fk < 0)
      {
        error_message();
        exit(1);
      }
      else if (fk == 0)
      {
        char *const my_path[] = {path1, buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], NULL};
        execv(path1, my_path);
      }

      fk = wait(NULL);
    }
    else if (access(path2, X_OK) == 0)
    {
      pid_t fk = fork();

      if (fk < 0)
      {
        error_message();
      }
      else if (fk == 0)
      {
        char *const my_path2[] = {path2, buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], NULL};
        execv(path2, my_path2);
      }
      fk = wait(NULL);
    }
    else
    {
      error_message();
    }
    free(path1);
    free(path2);
  }

  return 0;
}
