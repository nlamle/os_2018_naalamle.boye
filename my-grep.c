//load the file, check and handle errors

//take parameters for search term

//for each word in the file, look for search term

//if term exists, add entire line to data structure

//for each item in the data structure, print to console

//close file, clear processor resources

#include <stdio.h>
#include <stdlib.h>

char *line;

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("my-grep: searchterm[file..]\n", argv[1], argv[2]);
		exit(1);
	}


	else{
		FILE *fstream = fopen(filename, "r");

		//if file is unable to open, print error message
		if (fstream == NULL) {
			perror("my-grep: cannot open file\n");
			exit(1);
		}


	//get number of lines in the file
		size_t nlines = 0;
		char chrs;
		chrs = fgetc(fstream);

		while (chrs != EOF){
			if (chrs == '\n')
			{
				nlines = nlines + 1;
			}

			chrs = fgetc(fptr);
		}





	//for each line in the file, store in a buffer, then print line
		else{

			char *matching_line;

			while (getline(&line, &nlines, fstream) != NULL){

				if (getline(&line, &nlines, fstream), strstr(argv[1])){
					matching_line = getline(&line, &nlines, fstream);
					printf("%s\n", matching_line);
				}

			}


		}
	//close file, clear processor resources
		fclose(fptr);
	}

	
	return 0;
}