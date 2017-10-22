#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void prependChar(const char c, char *dest);
char hexCharForDec(long decimal);

/** Returns a string representing the hexadecimal value, for the given decimal */
char *hexStrFromDec(long decimal) {

	long n = decimal;

	/* allocate for null terminator */	
	char *hex_str = (char *)malloc(sizeof(char) * 10);
	strcpy(hex_str, "\0");

	/* if decimal is 16 or greater, keep dividing until the quotient is less than 16 */
	if (n >= 16) {
		while(n >= 15) {
			long quot = n / 16;	
			long rem = n % 16;
			char c = hexCharForDec(rem);
			const char char_str[] = {c, '0'};
		
			size_t hex_str_length = strlen(hex_str);
			prependChar(c, hex_str);
		
			n = quot;

			/* if the quotient is less than 16, prepend the hexadecimal 
			 * equivalent of the quotient to the return string */
			if (n < 16) {
				c = hexCharForDec(n);
				prependChar(c, hex_str);
			}
		}
	}
       /* set the hexadecimal equivalent of the decimal as the return string */	
	else {
		char c = hexCharForDec(n);
		prependChar(c, hex_str);
	}


	return hex_str;
}

/* returns the hexadecimal character (0 to f), for the given decimal */
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


/* prepends the given character to the given string */
inline void prependChar(const char c, char *dest) {
	size_t dest_length = strlen(dest);

	/* resize the string to accomodate an extra character (to prepend) */
	dest = (char *)realloc(dest, dest_length + 1);

	/* offset the existing string by 1 byte, to accomodate (prepend) the given character */
	memmove(&dest[1], &dest[0], dest_length);

	/* set the given character first character (now empty/garbage?) of the string */
	dest[0] = c;
}
