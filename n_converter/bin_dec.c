#include <stdio.h>
#include <string.h>
#include "functions.h"

/** 
 * returns the decimal value for the given binary value (string represented) 
 * formula: 101 = 1x2^2 + 0x2^1 + 1x2^0  
 * */
long decFromBinStr(const char *bin_str) {
	size_t len = strlen(bin_str);

	/* the decimal to return */
	long dec = 0;

	/* loop through each character (right to left) */
	for (int i = (len - 1); i >= 0; i--) {

		/* the current character */
		char c = bin_str[i];

		/* the binary value the current character represents */
		short bin = 0;

		/* set the binary value to 1, if current character is '1' */
		if (c == '1') {
			bin = 1;
		}
		
		/* the power of 2 the current binary value is to be multiplied */
		long pow2 = 1;

		/* calculate the power of 2 value */
		for (size_t j = 0; j < ((len - 1) - i) ; j++) {
			pow2 *= 2;
		}
		
		/* multiply the power of 2 value with the binary and add it to the total decimal */
		dec += bin * pow2;
	}

	return dec;
}

char binCharFromDec(int decimal) {
	char c = 'x';
	
	if (decimal == 0) {
		c = '0';
	} else if (decimal == 1) {
		c = '1';
	}

	return c;
}

/** returns the string represntation of the binary value for the given decimal */
const char *binStrFromDec(long decimal) {
	long n = decimal;

	char *dec_str = NULL;

	/* keep dividing until the number is less than 2 */
	while (n > 1) {
		
		//quotient
		long quot = n / 2;

		//remainder
		long rem = n % 2;
		
		/* get thae character equivalent of the remainder (char '0' is different from int '0), to prepend */
		char c = binCharFromDec(rem);

		/* prepend the character */
		prependChar(c, &dec_str);
		
		n = quot;

		/* if the quotient is less than 2, prepend it to the result, since loop stops after this iteration */
		if (n <= 1) {
			c = binCharFromDec(n);
			prependChar(c, &dec_str);
		}		
	}
	
			
	return dec_str;
}
