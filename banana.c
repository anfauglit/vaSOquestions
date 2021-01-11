#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int helper(int number, int divisor) {
	int n = 0;
	while (number % divisor == 0) {
		n++;
		number /= divisor;
	}
	return n;
}

int countBanana(const char *str) {
	int capitalCounter = 0;
	int banana = 1;
	const int hashBanana = 8 * 9 * 5;

	for (int i = 0; i < strlen(str); ++i) {
		switch (str[i]) {
			case 'A':
				capitalCounter++;
			case 'a':
				banana *= 2;
				break;
			case 'N':
				capitalCounter++;
			case 'n':
				banana *= 3;
				break;
			case 'B':
				capitalCounter++;
			case 'b':
				banana *= 5;
				break;
		} 
	}

	banana = banana % hashBanana == 0 ? helper(banana, hashBanana) : 0; 

	return banana - capitalCounter > 0 ? capitalCounter : banana;
}

int main (int argc, char **argv) {
	
	char *bananas[] = {"Banana", "banana", "BANANAbanana", "Ban", "BAnanaB"};
	
	for (int i = 0; i < 5; ++i) {
		printf("%i\n", countBanana(bananas[i]));
	}

	return 0;
}
