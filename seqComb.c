#include <stdio.h>

// https://stackoverflow.com/questions/65687430/combining-two-given-sequences-into-a-new-increasing-sequence#65687430
// Some OP comments are left in place

int main() {
	//Inputting sequence a and b
	int n = 3, m = 4;
//	int a[1001], b[1001]; // do you really going to input manually so many values? Ofc you can use some form of redirection to ease the process
	int a[] = {1, 3, 4};
	int b[] = {1, 2, 3, 5};
	int c[7];
	
	if (scanf("%d", &n) != 1 || n <= 0 || n > 1000)
		return 1;
/*
	// input validation

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		// input validation
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		// input validation
	}


	//Combine two sequence into c
	int c[1001]; // should be the size of |a| + |b|
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		c[i+n] = b[i];
	}
*/
	// two indexing variables one for each set
	int k = 0; // for a set a
	int l = 0; // for a set b

	// merging two arrays in O(n + m) time where the OP approach was O(n^2)
	for (int i = 0; i < m + n; ++i) {
		if ((a[k] <= b[l] && k < n) || l == m) 
			c[i] = a[k++];
		else
			c[i] = b[l++];
	}
/*
	// Selection sort algoriphm done wrong. What's wrong? After you putted the minimal element at the beginning of the resulting array
	// you should move the beginning of the interval where you do you searching for the next minimal  element

	//Arrange sequence c in increasing order
	int mid;
	for (int i = 0; i < (n+m-1); i++) {
		for (int j = 1; j < (n+m); j++) {
			if (c[i] > c[j])
			{
				mid = c[i];
				c[i] = c[j];
				c[j] = mid;
			}
		}
	}

*/
	//Printing c
	for (int i = 0; i < (n+m); i++) {
		printf("%d ", c[i]);
	}

	return 0;

}

// from an answer
/*
while (i < n && j < m) {
	if (a[i] <= b[j])
	c[k++] = a[i++];
	else
	c[k++] = b[j++];
}
while (i < n) {
	c[k++] = a[i++];
}
while (j < m) {
	c[k++] = a[j++];
}
*/
