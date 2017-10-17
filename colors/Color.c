#include "Color.h"
#include <stdio.h>

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
	Color c;
	return c;
}

void printColor(Color color, const char *tag) {
	if (tag == NULL) {
		printf("\n");
	} else {
		printf("\n%s:", tag);
	}

	printf("\n(red: %f, green: %f, blue: %f, alpha %f)", color.red, color.green, color.blue, color.alpha);
	printf("\n");
}

