#include <stdio.h>
#include <stdlib.h>

int myCat(char *filename);
//create a string for storing lines from fgets()
char *line;

int main(int argc, char *argv[])
{

	//if no file is specified in command line
	if (argc == 1){
		exit(0);
	}

	//if multiple files
	else{
		int i = 1;
		//files printed out until end of file list
		while (i < argc){
			myCat(argv[i]);
			i = i + 1;
		}
	}

	return 0;
}

int myCat(char *filename){
	//open file for reading
	FILE *fptr = fopen(filename, "r");


	//get number of lines in the file
	int nlines = 0;
	char chrs;
	chrs = fgetc(fptr);

	while (chrs != EOF){
		if (chrs == '\n')
		{
			nlines = nlines + 1;
		}
		
		chrs = fgetc(fptr);
	}

	//if file is unable to open, print error message
	if (fptr == NULL) {
		perror("my-cat: cannot open file\n");
		exit(1);
	}


	//for each line in the file, print line
	else
	{
		while (!feof(fptr))
		{	
			fgets(line, nlines, fptr);
			printf("%s", line);
			
		}


	}

	//close file, clear processor resources
	fclose(fptr);

	printf("Printed %d lines from file '%s'. \n\n\n", nlines, filename);


	return 0;
}