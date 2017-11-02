#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"

#include "hex_dec.h"

char hexCharForDec(long decimal);

/** Returns a string representing the hexadecimal value, for the given decimal */
hex_t hexStrFromDec_alloc(dec_t decimal) {

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
			prependChar(c, &hex_str);
		
			n = quot;

			/* if the quotient is less than 16, prepend the hexadecimal 
			 * equivalent of the quotient to the return string */
			if (n < 16) {
				c = hexCharForDec(n);
				prependChar(c, &hex_str);
			}
		}
	}
       /* set the hexadecimal equivalent of the decimal as the return string */	
	else {
		char c = hexCharForDec(n);
		prependChar(c, &hex_str);
	}


	return hex_str;
}

dec_t decFromHex(hex_t hex) {

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

/* returns the decimal equivalent for the given hexadecimal character (0 to f) */
int decForHexChar(char c) {
	printf("\ndecForHexChar: %c\n", c);
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': case 'A': return 10;
		case 'b': case 'B': return 11;
		case 'c': case 'C': return 12;
		case 'd': case 'D': return 13;
		case 'e': case 'E': return 14;
		case 'f': case 'F': return 15;
		default: return -1;
	}
}

