#include "libmx.h"

char *mx_arr_to_str(char **arr) {
    char *result = NULL;
    char *save = NULL;

    if (!arr || !*arr)
        return NULL;
    result = mx_strdup(arr[0]);
    for (int i = 1; i < mx_arr_size(arr); i++) {
        save = result;
        result = mx_strjoin(result, arr[i]);
        mx_strdel(&save);
    }
    return result;
}
