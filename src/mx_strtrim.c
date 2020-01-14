#include "libmx.h"

char *mx_strtrim(const char *str) {
    int l_spaces = 0;
    int r_spaces = 0;
    char *result = NULL;
    int l_str = 0;

    if (str)
        l_str = mx_strlen(str);
    else
        return NULL;
    while (mx_isspace(str[l_spaces])) {
        l_spaces++;
    }
    while (mx_isspace(str[l_str - r_spaces - 1])) {
        r_spaces++;
    }
    if (l_spaces == l_str)
        return mx_strnew(0);
    result = mx_strnew(l_str - l_spaces - r_spaces);
    return mx_strncpy(result, str + l_spaces, l_str - l_spaces - r_spaces);
}
