struct Color {
	double red;
	double green;
	double blue;
	double alpha;
};

typedef struct Color Color;

Color colorWith(double red, double green, double blue, double alpha);
void printColor(Color color, char *tag);
