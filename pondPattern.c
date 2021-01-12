#include <stdio.h>
#include <string.h>

int main () {
	// obviously str can be generated dynamically 
	// notice that the string is 4 chars longer than required
	char str[] = "##..##..##..##..##..";

	int n = 0;
	int len = strlen(str);

	for (int i = 0; i < 8; ++i) {
		n = i % 2;
		// switching back and forth between null character '\0' and '.'
		str[len - 2] = n * 46; //46 - ASCII code for a full stop 
		// using pointer arithmetic we send to function either first element
		// or third
		printf("%s\n%s\n", str + n * 2, str + n * 2);
	}
	
	return 0;
}

