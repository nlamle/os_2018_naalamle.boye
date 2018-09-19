//load the file, check and handle errors

//take parameters for search term

//for each word in the file, look for search term

//if term exists, add entire line to data structure

//for each item in the data structure, print to console

//close file, clear processor resources

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *line;
int myGrep(char *search_term, char *filename);


int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("my-grep: searchterm[file..]\n");
		exit(1);
	}

	//multiple files
	int i = 1;
	else{
		while (i < argc){
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

		//get number of lines in the file
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
		char *matching_line;

		while (nlines > 0){

			if (strstr(fstream, search_term)){
				matching_line = strstr(fstream, search_term);
				printf("%s\n", matching_line);
			}

			nlines = nlines - 1;

		}

		fclose(fstream);
	}
}