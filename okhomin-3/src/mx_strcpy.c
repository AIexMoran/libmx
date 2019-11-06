#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *save = dst;

    while (*src) {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = *src;
    return save;
}
