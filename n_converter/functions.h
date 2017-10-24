#include <stdlib.h>
#include <string.h>

/* ! causes "undefined symbol" error without static. Should try extern ! */
/** prepends the given character to the given string */
static inline void prependChar(const char c, char **dest) {

	if (dest == NULL) {
		return;
	}
	
        size_t length_dest = 0;
	size_t length_new = 0;
	
	/* if the string is empty, set the size to be allocated. strlen(NULL) crashes */
	if (*dest == NULL) {
		/* 1 for the current char + 1 for the null terminator */
		length_new = 2;			
	} else {
		length_dest = strlen(*dest);

		/* 1 for the new char that will be prepended + 1 for the null terminator */
		length_new = length_dest + 1 + 1;
	}
	
        /* resize the string to accomodate an extra character (to prepend) */
        *dest = (char *)realloc(*dest, sizeof(char) * length_new);

        /* offset the existing string by 1 byte, to accomodate (prepend) the given character */
        memmove(&(*dest)[1], &(*dest)[0], length_dest);

        /* set the given character first character (now empty/garbage?) of the string */
        (*dest)[0] = c;

	/* NULL terminate the string */
	(*dest)[length_new - 1] = '\0';
}
