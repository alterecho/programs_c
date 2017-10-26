struct Color {
	double red;
	double green;
	double blue;
	double alpha;
};

typedef struct Color Color;

Color colorWith(double red, double green, double blue, double alpha);
Color colorForHex(const char *str);
void printColor(Color color, const char *tag);

