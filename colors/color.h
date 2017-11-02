#ifndef COLOR_H
#define COLOR_H

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

typedef struct Color Color;

Color colorWith(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
Color colorForHex(const char *str);
void printColor(Color color, const char *tag);

static const Color ColorZero = {0, 0, 0, 0};

#endif
