#include "Color.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* limits value at given pointer to 255.0 */
void checkColorComponent(double *value) {
        if (*value > 255.0) {
                *value = 255.0;
        }
}

Color colorWith(double red, double green, double blue, double alpha) {

	checkColorComponent(&red);
	checkColorComponent(&green);
	checkColorComponent(&blue);
	checkColorComponent(&alpha);

	Color c;

	c.red = red;
	c.green = green;
	c.blue = blue;
	c.alpha = alpha;

	return c;
}

Color colorWithString(const char *str) {
	printf("\ncolorWithString: %s", str);
	
	size_t len = strlen(str);
	printf("\nlength: %lu", len);
	printf("\nbef:%s", str);

	Color c;
	return c;
}

void printColor(Color color, const char *tag) {
	if (tag == NULL) {
		printf("\n");
	} else {
		printf("\n%s: ", tag);
	}

	printf("(red: %f, green: %f, blue: %f, alpha %f)", color.red, color.green, color.blue, color.alpha);
	printf("\n");
}

Color colorForInt(long n, char componentsCount, long bitsPerComponent) {
	printf("\ncolorForInt: %ld, %d, %ld", n, componentsCount, bitsPerComponent);
	Color color;

	char c = 0;

	long filter = 0x0;
	switch (bitsPerComponent) {
		case 4:
			filter = 0xf;
			break;

		case 8:
			filter = 0xff;
			break;

		default:
			break;
	}

	while (c < componentsCount) {
		
		unsigned char shift = (componentsCount - 1) - c;
		unsigned char value = (n >> shift) & filter;

		switch (c) {
			case 0:
				color.red = value / filter * 255.0;
				break;

			case 1:
				color.green = value / filter * 255.0;
				break;
			case 2:
				color.blue = value / filter * 255.0;
				break;

			case 3:
				color.alpha = value / filter * 255.0;
				break;

			default:
				break;
		}	
	
		c++;		
	}

	printColor(color, "return");

	return color;

}

Color colorForHex(const char *hex_str) {
	printf("\ncolorForHex:%s", hex_str);
	Color color;
	
	if (hex_str == NULL) {
		return color;
	}

	char *end;
	long n = strtol(hex_str, &end, 16);
	
	long hex_length = strlen(hex_str);

	switch (hex_length) {
		case 3: 
			color = colorForInt(n, 3, 4);
			break;

		case 4:
			color = colorForInt(n, 4, 4);
			break;

		case 6:
			color = colorForInt(n, 3, 8);
			break;

		case 8:
			color = colorForInt(n, 4, 8);
			break;
	}
	
	printColor(color, "return");
	return color;
}

