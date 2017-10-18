#include <stdio.h>
#include <string.h>

void print(int argc, char **argv) {
	printf("\narguments:\n");
	for (int i = 0; i < argc; i++) {
		printf("\n[%d]: %s", i, argv[i]);
	}
	printf("\n");
}

unsigned long decimalFromHex(const char *str) {
	printf("decimalFromHex: %s", str);
	size_t len = strlen(str);

	if (len == 0) {
		return 0;
	}
	
	int n = 0;
	for (int i = (len - 1); i >= 0; i--) {
		switch (str[i]) {
			case '0':
				n = 0;
				break;

			case '1':
				n = 1;
				break;

			case '2':
				n = 2;
				break;

			case '3':
				n = 3;
				break;

			case '4':
				n = 4;
				break;

			case '5':
				n = 5;
				break;

			case '6':
				n = 6;
				break;

			case '7':
				n = 7;
				break;

			case '8':
				n = 8;
				break;

			case '9':
				n = 9;
				break;

			case 'a':
			case 'A':
				n = 10;
				break;

			case 'b':
			case 'B':
				n = 11;
				break;

			case 'c':
			case 'C':
				n = 12;
				break;

			case 'd':
			case 'D':
				n = 13;
				break;

			case 'e':
			case 'E':
				n = 14;
				break;

			case 'f':
			case 'F':
				n = 15;
				break;
		}

		printf("\nn:%d", n);
	}

	printf("\n");

	return n;
}
