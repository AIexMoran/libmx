#include "libmx.h"

static int length_without_spaces(char *str) {
    int length = 0;

    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            length++;
        }
    }
    return mx_strlen(str) - length;
}

char *mx_del_extra_spaces(const char *str) {
    char *result = NULL;
    char *trim_str = mx_strtrim(str);
    int counter = 0;

    if (!trim_str)
        return NULL;
    result = mx_strnew(length_without_spaces(trim_str));
    for (int i = 0; i < mx_strlen(trim_str); i++) {
        if (!mx_isspace(trim_str[i])) {
            result[counter++] = trim_str[i];
        }
        else if (!mx_isspace(trim_str[i + 1])) {
            result[counter++] = ' ';
        }
    }
    return result;
}
