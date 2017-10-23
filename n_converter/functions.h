#include <stdlib.h>
#include <string.h>

/* ! causes "undefined symbol" error without static. Should try extern ! */
/** prepends the given character to the given string */
static inline void prependChar(const char c, char *dest) {
        size_t dest_length = strlen(dest);

        /* resize the string to accomodate an extra character (to prepend) */
        dest = (char *)realloc(dest, dest_length + 1);

        /* offset the existing string by 1 byte, to accomodate (prepend) the given character */
        memmove(&dest[1], &dest[0], dest_length);

        /* set the given character first character (now empty/garbage?) of the string */
        dest[0] = c;
}
