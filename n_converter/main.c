/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_dec.h"
#include "hex_dec.h"


/** supported conversions:
  * -bd: binary -> decimal
  * -db: decimal -> binary
  * -dh, -dx: decimal -> hexadecimal
  * -hd, xd: hexadecimal -> decimal
**/

int main(int argc, char **argv) {

	/* return if there are no arguments */
	if (argc == 1) {
		printf("no arguments given\n");
		return 1;
	}
	/* return if there are not enough arguments (conversion type and value) */
	else if (argc == 2) {
		printf("not enough conversion details\n");
		return 1;
	}

	const char *conversion_str = argv[1];
	char *value_str = argv[2];
	
	/* binary -> decimal */
	if (strcmp(conversion_str, "-bd") == 0) {
		printf("\ndecimal value of '%s' = %ld\n", value_str, decFromBinStr(value_str));
	}

	/* decimal -> binary */
	else if (strcmp(conversion_str, "-db") == 0) {
		int n = atoi(value_str);
		printf("\nbinary value of '%d' = %s\n", n, binStrFromDec(n));
	}

	/* decimal -> hex */
	else if (strcmp(conversion_str, "-dh") == 0 || strcmp(conversion_str, "-dx") == 0) {
		int n = strtol(value_str, NULL, 10);
		hex_t hex_str = hexStrFromDec_alloc(n);
		printf("\nhex value of '%s' = %s\n", value_str, hex_str);
		free(hex_str);
	}

	/* hex -> decimal */ 
	else if (strcmp(conversion_str, "-hd"), conversion_str == 0 || strcmp(conversion_str, "-xd") == 0) {
		dec_t decimal = decFromHex(value_str);
		printf("\ndecimal value of '%s' = %lld", value_str, decimal);
	}

       /* unrecognized */
	else {
		printf("unrecognised conversion specifier '%s'", argv[1]);
	}

	printf("\n");
	return 0;
}
