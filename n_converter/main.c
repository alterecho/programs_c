#include <stdio.h>
#include <string.h>
#include "bin_dec.h"

int main(int argc, char **argv) {

	if (argc == 1) {
		printf("no arguments given\n");
		return 1;
	} else if (argc == 2) {
		printf("not enough conversion details\n");
		return 1;
	}

	if (strcmp("-bd", argv[1]) == 0) {
		printf("\ndecimal value = %ld\n", decFromBinStr(argv[2]));
	} else {
		printf("unrecognised conversion specifier '%s'", argv[1]);
	}


	return 0;
}
