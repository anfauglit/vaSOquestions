#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// https://stackoverflow.com/questions/65649852/segmentation-fault-11-finding-words-in-file-in-c

#define MAXSTR 1000

int findMatches (const char *filename, char **request, int size) {

	char buffer[MAXSTR]; //buffer
	char *token; // storing beginning position of a token in string

	FILE *file; 

	if ((file = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Error\n");
	}

	while(fgets(buffer, MAXSTR, file) != NULL) {
		buffer[strlen(buffer) - 1] = '\0'; // removing trailing new line character
		token = strtok(buffer, " "); // tokenizing string read from the file

		for (int i = 0; i < size; i++) {
			if (strcmp(request[i], token) == 0) {
				printf("%s\n", token);
				while (token = strtok(NULL, " "))
					printf("%s\n", token);
				break; // move to the next line in file
			}
		}
	}
	return 0;
}


int main (int argc, char *argv[]) {

	findMatches("sample.txt", &argv[1], argc - 1);

	return 0;
}

