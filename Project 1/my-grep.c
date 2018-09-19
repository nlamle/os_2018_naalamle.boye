//load the file, check and handle errors

//take parameters for search term

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
	FILE *fstream = fopen(filename, "r");

	//if file is unable to open, print error message
	if (fstream == NULL) {
		perror("my-grep: cannot open file\n");
		exit(1);
	}

	else{

		//get number of lines in the file using characters
		//a line ends when a newline character is reached
		int nlines = 0;
		char chrs;
		chrs = fgetc(fstream);

		while (chrs != EOF){
			if (chrs == '\n')
			{
				nlines = nlines + 1;
			}

			chrs = fgetc(fstream);
		}

		//while not at the end of the file stream,
		//get lines in the file, check if search term is in line
		while(!feof(fstream)){
			fgets(line, nlines, fstream);
			if (strstr(line, search_term))
			{
				printf("%s\n", line);
			}
		}

		fclose(fstream);
	}

	return 0;
}