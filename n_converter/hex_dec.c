#include <stdio.h>

char *hexStrFromDec(long decimal) {
	long n = decimal;
	
	while(n > 16) {
		long quot = n / 16;
		printf("\nquot:%ld", quot);
		long rem = n % 16;
		printf("\nquot: %ld, rem: %ld", quot, rem);	
		n = quot;
	}

	printf("\n");

	return NULL;

}
