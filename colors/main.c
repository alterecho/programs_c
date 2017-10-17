#include <stdio.h>
#include "functions.h"
#include "Color.h"

int main(int argc, char **argv) {
	print(argc, argv);
	
	Color c = colorWith(100.0, 200.0, 255.0, 355.0);
	printColor(c, "myColor");
	
	return 0;
}
