#include "libmx.h"

void mx_printstr(const char *s);

void mx_print_strarr(char **arr, const char *delim) {
    if (!*arr || !arr || !delim) {
        return;
    }
    while (*arr) {
        mx_printstr(*arr);
        if (*(arr + 1)) {
            mx_printstr(delim);
        }
        arr++;
    }
    mx_printstr("\n");
}
