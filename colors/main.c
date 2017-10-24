#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "Color.h"
#include <stdlib.h>

	

int main(int argc, char **argv) {

	int n = atoi("1fa");
	printf("\nn:%d\n", n);
	return 1;
	
	if (argc == 1) {
		printf("\nno arguments\n");
		return 1;
	}
	
	if (strcmp(argv[1], "-dh") == 0) {
		
	} else if (strcmp(argv[1], "-hd") == 0) {
		
	} else {
		printf("\nunrecognized conversion specifier '%s'\n", argv[1]);
		return 1;
	}	

	if (argc == 2) {
		printf("no values given\n");
		return 1;
	}
	
	return 0;
}
