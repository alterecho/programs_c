#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "Color.h"

int main(int argc, char **argv) {
	
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
	
	
	Color c = colorWith(100.0, 200.0, 255.0, 355.0);
	printColor(c, "myColor");
	
	Color c_str = colorWithString("ffff");
	printColor(c_str, "from String");

	decimalFromHex("fa1F");	

	return 0;
}
