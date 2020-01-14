#include "libmx.h"

char *mx_strncat(char *restrict s1, const char *restrict s2, size_t n) {
    char *save = s1;

    s1 += mx_strlen(s1);
    mx_strncpy(s1, s2, n);
    return save;
}
