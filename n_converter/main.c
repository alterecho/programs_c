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
		printf("\ndecimal value = %ld\n", decFromBinStr(argv[2]));
	}
	/* decimal -> hex */
	else if (strcmp("-dh", argv[1]) == 0 || strcmp("-dx", argv[1]) == 0) {
		int n = strtol(argv[2], NULL, 10);
		printf("\ndecimal value = %s\n", hexStrFromDec(n));
	}
       /* unrecognized */
	else {
		printf("unrecognised conversion specifier '%s'", argv[1]);
	}

	printf("\n");
	return 0;
}
