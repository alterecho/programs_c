#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "Color.h"
#include <stdlib.h>

	

int main(int argc, char **argv) {
	
	if (argc == 1) {
		printf("\nno arguments\n");
		return 1;
	}

	Color c = colorForHex(argv[1]);
	printColor(c, "clr");
	
	return 0;
}
