#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    int subs = mx_count_substr(str, sub);
    int subs_length = mx_strlen(sub) * subs;
    int replace_length = mx_strlen(replace) * subs;
    char *result = NULL;
    int index = 0;

    if (!*str || !*sub) {
        return NULL;
    }
    result = mx_strnew(mx_strlen(str) - subs_length + replace_length);
    while ((index = mx_get_substr_index(str, sub)) != -1) {
        mx_strncat(result, str, index);
        mx_strcat(result, replace);
        str += index + mx_strlen(sub);
    }
    mx_strcat(result, str);
    return result;
}
