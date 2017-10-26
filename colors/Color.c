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

Color colorForInt(long n, char componentsCount, long bitsPerComponent) {
        printf("\ncolorForInt: %ld (%lx), %d, %ld", n, n, componentsCount, bitsPerComponent);
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
                
                unsigned char shift = bitsPerComponent * ((componentsCount - 1) - c);
                unsigned char value = (n >> shift) & filter;
 		
		printf("\nvalue: %d, shift: %d, filter: %lx(%ld)", value, shift, filter, filter);
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
        Color color = ColorZero;
        long hex_length = strlen(hex_str);

	char *end;
	long n = strtol(hex_str, &end, 16);
	if (end != NULL && strlen(end) != 0) {
		printf("\n%s not a hex (end: %s)\n", hex_str, end);
		return color;
	}
 
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
