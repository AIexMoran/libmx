#include "libmx.h"

char *mx_strnew(int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *str);

char *mx_strdup(const char *str) {
    char *result = mx_strnew(mx_strlen(str));

    return mx_strcpy(result, str);
}
