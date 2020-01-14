#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *s1_c = s1;
    const unsigned char *s2_c = s2;

    while (n--) {
        if (*s1_c != *s2_c) {
            return *s1_c - *s2_c;
        }
        s1_c++;
        s2_c++;
    }
    return 0;
}
