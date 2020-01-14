#include "libmx.h"

char *mx_strdup(const char *str) {
    char *result = mx_strnew(mx_strlen(str));

    return mx_strcpy(result, str);
}
