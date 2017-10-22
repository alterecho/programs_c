#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char hexCharForDec(long decimal);

char *hexStrFromDec(long decimal) {

	printf("\nhexStrFromDec: %ld", decimal);
	long n = decimal;
	
	char *hexString = (char *)malloc(sizeof(char) * 10);
	printf("\nchar size: %ld, ptr: %ld", sizeof(char), sizeof(char *));
	printf("\nhexString len alloc: %ld", strlen(hexString));
	strcpy(hexString, "\0");
	printf("\nhexString len: %ld", strlen(hexString));

	while(n > 16) {

		long quot = n / 16;
		
		long rem = n % 16;
		
		char c = hexCharForDec(rem);
		const char char_str[] = {c, '\0'};
		
		hexString = (char *)realloc(hexString, sizeof(char) * (strlen(hexString) + 1));
		strcat(hexString, char_str);
		
		printf("\nAFT: quot: %ld, rem: %ld, hex_char:%c, hex_str: %s, strlen: %ld, sizeof: %ld", quot, rem, c, hexString, strlen(hexString), sizeof(hexString));	
		n = quot;
	}

	printf("\n");

	return hexString;

}

char hexCharForDec(long decimal) {
	printf("\nhexCharFoDec: %ld\n", decimal);
	switch (decimal) {
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'a';
		case 11: return 'b';
		case 12: return 'c';
		case 13: return 'd';
		case 14: return 'e';
		case 15: return 'f';
		default: return 'x';
	}
}
