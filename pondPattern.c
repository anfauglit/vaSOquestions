#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/65676765/how-to-repeat-rows-in-a-matrix-in-c/65677167#65677167

int main () {

	int rows = 0;
	int cols = 0;

	/* From the example provided I assume that the number of columns
	 * and rows should be a multiple of 2
	 * even though the OP hasn't explicitly mentioned it
	*/

	scanf("%d %d", &rows, &cols);

	// generating the base string
	// notice that the string is 2 chars longer than required
	char *str = malloc(sizeof(*str) * (cols + 1) * 2 + 1);
	for (int i = 0; i < cols / 2; ++i) {
		strcpy(str + i * 4, "##..");
	}
	strcpy(str + strlen(str), "##");

	int n = 0;
	int len = strlen(str);

	for (int i = 0; i < rows; ++i) {
		n = i % 2;
		// switching back and forth between null character '\0' and '.'
		str[len - 2] = n * 35; //35 - ASCII code for a '#' 
		// using pointer arithmetic we send to function either first element
		// or third
		printf("%s\n%s\n", str + n * 2, str + n * 2);
	}

	free(str);
	
	return 0;
}

