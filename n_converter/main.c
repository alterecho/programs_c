#include <stdio.h>

#include "bin_dec.h"

int main(int argc, char **argv) {
	long n = decFromBinStr("1111");
	printf("\ndec=%ld\n", n);	
	return 0;
}
