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
        size_t dest_length = 0;

	if (*dest == NULL) {
			
	} else {
		dest_length = strlen(*dest);
	}
	
	printf("\nstrlen of %s = %ld", *dest, dest_length);
        /* resize the string to accomodate an extra character (to prepend) */
        *dest = (char *)realloc(*dest, dest_length + 1);

        /* offset the existing string by 1 byte, to accomodate (prepend) the given character */
        memmove(&(*dest)[1], &(*dest)[0], dest_length);

        /* set the given character first character (now empty/garbage?) of the string */
        (*dest)[0] = c;

	printf("\ndest:%s\n\n", *dest);
}
