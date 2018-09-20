//load the file, check and handle errors

//take parameters for search term and file name

//for each word in the file, look for search term

//if term exists, print line to console

//close file, clear processor resources

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *line;
int myGrep(char *search_term, char *filename);


int main(int argc, char *argv[])
{

	//if no file or search term specified
	if (argc == 1)
	{
		printf("my-grep: searchterm[file..]\n");
		exit(1);
	}

	//if no filename is specified
	else if (argc == 2){
		char input_line[500];
		printf("Write some lines: \n");
		while(fgets(input_line, 100, stdin) && getc(stdin) == '\n')
		{
			if (getc(stdin) == '\n'){
				printf("%s\n", line);
			}
		}
	}

	//multiple files, for each file, call myGrep function
	else
	{
		int i = 1;
		while (i < argc)
		{
			myGrep(argv[1], argv[i+1]);
			i = i + 1;
		}
	}

	return 0;

}


int myGrep(char *search_term, char *filename){

	//if search term is empty string
	if (strcmp("", search_term) == 0){
		exit(0);
	}

	else{

		FILE *fstream = fopen(filename, "r");

		//if file is unable to open, print error message
		if (fstream == NULL) {
			perror("my-grep: cannot open file\n");
			exit(1);
		}

		else{

			//get number of lines in the file using characters
			//a line ends when a newline character is reached
			size_t nlines = 0;
			char chrs;
			chrs = fgetc(fstream);

			while (!EOF){
				if (chrs == '\n')
				{
					nlines = nlines + 1;
				}

				chrs = fgetc(fstream);
			}

			line = (char *)malloc(nlines * sizeof(char));

			//while not at the end of the file stream,
			//get lines in the file, check if search term is in line
			while(!feof(fstream)){
				getline(&line, &nlines, fstream);
				if (strstr(line, search_term))
				{
					printf("%s\n", line);
				}
			}

			free(line);
			fclose(fstream);
		}
	}

	return 0;
}
