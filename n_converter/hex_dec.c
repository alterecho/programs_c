#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void prependChar(const char c, char *dest);
char hexCharForDec(long decimal);

char *hexStrFromDec(long decimal) {

	printf("\nhexStrFromDec: %ld", decimal);
	long n = decimal;
	
	char *hex_str = (char *)malloc(sizeof(char) * 10);
	strcpy(hex_str, "\0");

	if (n >= 16) {
		while(n >= 15) {
			long quot = n / 16;	
			long rem = n % 16;
			char c = hexCharForDec(rem);
			const char char_str[] = {c, '0'};
		
			size_t hex_str_length = strlen(hex_str);
			prependChar(c, hex_str);
		
			printf("\nAFT: quot: %ld, rem: %ld, hex_char:%c, hex_str: %s, strlen: %ld, sizeof: %ld", quot, rem, c, hex_str, strlen(hex_str), sizeof(hex_str));	
			n = quot;

			if (n < 16) {
				c = hexCharForDec(n);
				prependChar(c, hex_str);
			}
		}
	} else {
		char c = hexCharForDec(n);
		prependChar(c, hex_str);
	}


	printf("\n");

	return hex_str;

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


inline void prependChar(const char c, char *dest) {
	printf("\nprependChar: %c, %s", c, dest);
	size_t dest_length = strlen(dest);
	dest = (char *)realloc(dest, dest_length + 1);
	memmove(&dest[1], &dest[0], dest_length);
	dest[0] = c;
	printf("\ndest: %s\n", dest);
}
