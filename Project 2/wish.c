#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  if(argc>2){
   exit(0);
  }

  char *input;
  size_t i_size = 64;
  size_t command;

  input = (char*)malloc(i_size * sizeof(char));
  char* end = "exit";

  while (input != end) {
    printf("wish> " );
    command = getline(&input, &i_size, stdin);
  }

  free(input);

  return 0;
}
