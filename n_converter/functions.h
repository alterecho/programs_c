#include <stdlib.h>
#include <string.h>

/* ! causes "undefined symbol" error without static. Should try extern ! */
/** prepends the given character to the given string */
static inline void prependChar(const char c, char **dest) {

	if (dest == NULL) {
		return;
	}
	
	
	printf("\naikjdjf");
	printf("\nprependChar: %c, %s", c, *dest);
        size_t length_dest = 0;
	size_t length_new = length_dest + 1;
	if (*dest == NULL) {
		length_new = 2;			
	} else {
		length_dest = strlen(*dest);
		length_new = length_dest + 1 + 1;
	}
	
	printf("\nstrlen of %s = %ld, new length: %ld", *dest, length_dest, length_new);
	 
        /* resize the string to accomodate an extra character (to prepend) */
        *dest = (char *)realloc(*dest, sizeof(char) * length_new);

        /* offset the existing string by 1 byte, to accomodate (prepend) the given character */
        memmove(&(*dest)[1], &(*dest)[0], length_dest);

        /* set the given character first character (now empty/garbage?) of the string */
        (*dest)[0] = c;
	printf("\nstrlen: %ld", strlen(*dest));
	(*dest)[length_new - 1] = '\0';

	printf("\ndest:%s\n\n", *dest);
}
