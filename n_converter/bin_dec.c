#include <stdio.h>
#include <string.h>

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
