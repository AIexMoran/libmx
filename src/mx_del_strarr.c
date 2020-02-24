#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **del_arr = *arr;

    while (*del_arr) {
        mx_strdel(del_arr);
        del_arr++;
    }
    free(*arr);
    *arr = NULL;
}
