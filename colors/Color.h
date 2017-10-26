#ifndef COLOR_H
#define COLOR_H

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

typedef struct Color Color;

static inline Color ColorZero() {
	Color c = {0, 0, 0, 0};
	return c;
}

typedef ColorZeror() ColorZero;

Color colorWith(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
Color colorForHex(const char *str);
void printColor(Color color, const char *tag);

#endif
