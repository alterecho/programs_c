#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_dec.h"
#include "hex_dec.h"

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

	
	/* binary -> decimal */
	if (strcmp("-bd", argv[1]) == 0) {
		printf("\ndecimal value of '%s' = %ld\n", argv[2], decFromBinStr(argv[2]));
	}
	/* decimal -> binary */
	else if (strcmp("-db", argv[1]) == 0) {
		int n = atoi(argv[2]);
		printf("\nbinary value of '%d' = %s\n", n, binStrFromDec(n));
	}
	/* decimal -> hex */
	else if (strcmp("-dh", argv[1]) == 0 || strcmp("-dx", argv[1]) == 0) {
		int n = strtol(argv[2], NULL, 10);
		hex_t hex_str = hexStrFromDec_alloc(n);
		printf("\nhex value of '%s' = %s\n", argv[2], hex_str);
		free(hex_str);
	}
       /* unrecognized */
	else {
		printf("unrecognised conversion specifier '%s'", argv[1]);
	}

	printf("\n");
	return 0;
}
