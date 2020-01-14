#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *s = b;

    while (len--) {
        *s++ = c;
    }
    return b;
}
