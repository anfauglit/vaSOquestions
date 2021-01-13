// https://stackoverflow.com/questions/65697929/how-to-return-empty-string-from-a-function-in-c/65699176#65699176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

char *find_LCP(char *str1, char *str2) {

	int a = strlen(str1);
	int b = strlen(str2);
	int min = a < b ? a : b;

	// allocating memory for lcp
	char *lcp = calloc((min + 1), sizeof(*lcp));

	for (int i = 0; i < min; i++){
		if(str1[i] == str2[i])
			lcp[i] = str1[i];
	}

	return lcp;
}

char *prefix(const char *s1, const char *s2) {
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0') ++i;

	char *lcp = calloc((i + 1), sizeof(*lcp));
	memcpy(lcp, s1, i);
	return lcp;
}

	
int main() {

	char str1[MAX_LEN], str2[MAX_LEN];
	char * lcp;

	while (1) {
		scanf("%s", str1);
		scanf("%s", str2);
		lcp = prefix(str1, str2);
		printf("\nLongest common prefix: '%s'\n", lcp);
		free(lcp);
	}

	return 0;
}
