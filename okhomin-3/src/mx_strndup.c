#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *result = NULL;
    size_t length = mx_strlen(s1);

    if (n < length) {
        length = n;
    }
    result = mx_strnew((int)length);
    return mx_strncpy(result, s1, length);
}
