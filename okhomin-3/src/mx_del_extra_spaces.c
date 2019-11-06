#include "libmx.h"

char *mx_strtrim(const char *str);
int mx_strlen(const char *str);
void mx_strdel(char **str);
bool mx_isspace(char c);
char *mx_strnew(const int size);
static int mx_length_without_spaces(char *str);

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }
    char *trim_str = mx_strtrim(str);
    int result_length = mx_length_without_spaces(trim_str);
    char *result = mx_strnew(result_length);
    int counter = 0;

    if (!result) {
        return NULL;
    }
    if (!trim_str) {
        return (char *)str;
    }
    for (int i = 0; i < mx_strlen(trim_str); i++) {
        if (!mx_isspace(trim_str[i])) {
            result[counter] = trim_str[i];
            counter++;
        }
        else if (!mx_isspace(trim_str[i + 1])) {
            result[counter] = ' ';
            counter++;
        }
    }
    mx_strdel(&trim_str);
    return result;
}

static int mx_length_without_spaces(char *str) {
    int length = 0;

    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            length++;
        }
    }
    return mx_strlen(str) - length;
}
