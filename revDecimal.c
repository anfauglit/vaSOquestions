#include <stdio.h>

//https://stackoverflow.com/questions/65688362/is-there-a-more-efficient-way-to-reverse-decimal-numbers

int main() {
/*
	while(1)
	{
		int a, result;
		// get a number
		scanf("%d",&a);

		result=(a%10*10)+(a/10);
		printf("%d\n",result);

	}
*/
	int a;
	int rev;

	while (1) {
		a = 1;
		rev = 0;

		scanf("%d",&a);
		do {
			rev *= 10;
			rev += a % 10;
			a /= 10;
		} while (a);

		printf("Reversed: %i\n", rev);
	}
}
