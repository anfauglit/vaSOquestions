#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *MaxLetterToNewString(char **str, int size) {
	// a little observation about how arrays are stored in memory (elements of arrays are stored sequentially)
	// and what a character array is, i.e. sequence of null terminated characters provide intuition to the following:
	// consider array of words as a sequence of characters with '\0' as a separator between the words 
	// scan the sequence while checking for the end of the current word, i.e. '\0' character
	char *result = malloc((size + 1) * sizeof(*result));

	int nullCounter = 0, max = 0, i = 0;
	char c;

	while (nullCounter <= size) {
		c = *(*str + i++);
		if (c == '\0') { // we reached the end of the word
			++nullCounter;
			result[nullCounter - 1] = max;
			max = 0;
		} else if (c > max)
			max = c;
	}

	result[nullCounter] = '\0';
	return result;
}

void main() {
	char* arr[] = {"hello", "and", "good", "morniny"};

	int size = sizeof(arr) / sizeof(char*);
	char *result;
	result = MaxLetterToNewString(arr, size);
	printf("%s\n", result);

	free(result);
}
	
