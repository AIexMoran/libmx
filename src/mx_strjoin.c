#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *result = NULL;

    if (!s1 && !s2) {
        return NULL;
    }
    if (!s1) {
        result = mx_strnew(mx_strlen(s2));
        return mx_strcpy(result, s2);
    }
    if (!s2) {
        result = mx_strnew(mx_strlen(s1));
        return mx_strcpy(result, s1);
    }
    result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(result, s1);
    mx_strcat(result, s2);
    return result;
}
