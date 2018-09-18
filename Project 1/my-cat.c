#include <stdio.h>
#include <stdlib.h>

int myCat(char *filename);

int main(int argc, char *argv[])
{

	//if no file is specified in command line
	if (argc == 1){
		exit(0);
	}

	//if multiple files
	else{
		//files printed out until end of file list
		int i = 1;
		while (i < argc){
			myCat(argv[i]);
			//printf("%s\n", argv[i]);
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



	printf("There are %d lines in the file '%s'.\n\n", nlines, filename);
	
	char lines[nlines];


	//if file is unable to open, print error message
	if (fptr == NULL) {
		perror("my-cat: cannot open file\n");
		exit(1);
	}

	

//for each line in the file, store in a buffer, then print line
	else{
		
		while (nlines > 0){
			
			char *next_line = fgets(lines, 100, fptr);
			printf("%s", next_line);
			nlines = nlines - 1;
			
		}


	}
//close file, clear processor resources
	fclose(fptr);

	return 0;
}