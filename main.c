#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void CreateAndWrite(char* result, char* extension){
		char buf[100];
		sprintf(buf,"%s.%s","outputFile",extension);

		FILE *fh = fopen (buf, "wb");
		if (fh != NULL) {
		fwrite (result, sizeof (result), 1, fh);
		fclose (fh);
		}
}

int main (int argc, char **argv) {
	char str[] = "Hello World!";

	CreateAndWrite(str, ".txt");

	
	return 0;
}

