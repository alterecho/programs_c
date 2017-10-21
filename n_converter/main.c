#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_dec.h"
#include "hex_dec.h"

int main(int argc, char **argv) {

	unsigned int n = 100;
	printf("\nhex:%x, dec:%d\n", n, n);
	
	char *str = hexStrFromDec(1200);

	if (argc == 1) {
		printf("no arguments given\n");
		return 1;
	} else if (argc == 2) {
		printf("not enough conversion details\n");
		return 1;
	}

	if (strcmp("-bd", argv[1]) == 0) {
		printf("\ndecimal value = %ld\n", decFromBinStr(argv[2]));
	} else if (strcmp("-dh", argv[1]) == 0 || strcmp("-dx", argv[1]) == 0) {
		int n = strtol(argv[2], NULL, 10);
		printf("\ndecimal value = %s\n", hexStrFromDec(n));
	} else {
		printf("unrecognised conversion specifier '%s'", argv[1]);
	}


	return 0;
}
