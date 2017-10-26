#include "Color.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* limits value at given pointer to 255.0 */
void checkColorComponent(unsigned char *value) {
        if (*value > 255.0) {
                *value = 255.0;
        }
}

Color colorWith(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {

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

	printf("(red: %d, green: %d, blue: %d, alpha %d)", color.red, color.green, color.blue, color.alpha);
	printf("\n");
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
		case 3: {
				int c = 0;
				while (c < 3) {
					int val = n >> (4 * (2 - c)) & 0xf;
					switch (c) {
						case 0:
							color.red = val;
							break;

						case 1:
							color.green = val;
							break;

						case 2:
							color.blue = val;
							break;

						case 3:
							color.alpha = val;
							break;

							defaul:
							break;
					}
					c++;
				
				}
		}
		break;

		case 4: {
			int c = 0;
		}
		break;

		case 6:
		break;

		case 8:
		break;
	}

	
	
		

	int x = 0xff;
	printf("\ncolorForHex: %s, n: %ld", hex_str, n);
	

	int shifted = x >> 4;
	int n_final = x & 0xf0;
	printf("\nn: %d (%x), shft: %d, final: %d (%x)", x, x, shifted, n_final, n_final);

	return color;
}

