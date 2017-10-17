#include <stdio.h>

void print(int argc, char **argv) {
	printf("\narguments:\n");
	for (int i = 0; i < argc; i++) {
		printf("\n[%d]: %s", i, argv[i]);
	}
	printf("\n");
}
